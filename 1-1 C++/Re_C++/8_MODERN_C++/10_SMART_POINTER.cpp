#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//�����ʹ� ���������� � �޸𸮸� �а� ���� ������ �ִµ�, �̰� �����ϱ⵵ �ϴ�..
//=>

class Knight
{
public:
	Knight() { cout << "Knight �����Ǿ���. " << endl; }
	~Knight() { cout << "Knight �Ҹ�Ǿ���. " << endl; }



	void Attack() 
	{
		if (_target.expired() == false)
		{
			shared_ptr<Knight> sptr = _target.lock();
			sptr->_hp -= _damage;
			cout << "target hp : " << sptr->_hp << endl;
		}
	}



public:
	int _hp = 100;
	int _damage = 10;
	//Knight* _target = nullptr;   //�������͸� �Ἥ!! �׷��� �ٲ㺸��
	weak_ptr<Knight> _target;      //��ü�� ���ư����� �ȳ��� ������ Ȯ���ϴ� �뵵�� ����� �����ϴ�.
	//���� : Knight ��ü�� �Ҹ�� ������ ������, ���� Attack ó�� expired�� ���� ��������� üũ + shared_ptr�� ��ȯ
	//�޸� �������� �����ο� ���̳� <-> ����� ���Ұ��̳�
};



//Shared_Ptr

//RefCounter
class RefCountBlock  //���� Ƚ���� ����
{
public:
	int _refCount = 1;  //��¥ ��� �긦 �����ϰ� �ִ���.
	int _weakCount = 1; //�̷��� weakPointer ��� RefCountBlock�� �����ϰ� �ִ���. 
};

template<typename T>
class SharedPtr //���� ī��Ʈ�� �Ѵ�. (����̳� �� �����͸� �����ϰ� �ֳ� ? �� ��ü�� �ƹ��� ����ϰ� ���� ������ delete)
{
public:
	SharedPtr() { }
	SharedPtr(T* ptr) : _ptr(ptr) {
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}
	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount ++; // ������ ��� �ִ� ī���� ++����
			cout << "RefCount : " << _block->_refCount << endl;

		}
	}

	void operator=(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;

		}
	}

	~SharedPtr() {
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;
			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;  //weak_ptr�� ����ϸ� ������ pointer�� refCounter�� 0�� �Ǿ�����
				cout << "Delete Data" << endl;

			}
		}
	}
public:
	T* _ptr = nullptr; //���� ��ü ������
	RefCountBloack* _block = nullptr;
};

int main()
{
	/*
	Knight* k1 = new Knight();
	Knight* k2 = new Knight();
	k1->_target = k2;
	k1->Attack();

	//�̶� k2�� ������ ������. ==>�Ҹ���Ѿ��ϴµ�
	delete k2; //�̷��� �ϸ�, ������ ���� Attack���� _target ó������ �ִ� ��Եɱ�? (ũ���ô� �ȳ���, �޸𸮴� ���ư����� ���°� �Ǿ���.)
	//�׷��� ���� Attack������ ������ �޸𸮸� ������ ����� �ʷ��ϴµ�, �̷��� ������ �׳� ��pointer�� ����߱� �����̴�.
	*/

	//����Ʈ �����ʹ� 
	//*** shared_ptr ***, weak_ptr, unique_ptr �� �ִ�.


	//SharedPtr<Knight> k2;
	////���� 
	//{
	//	SharedPtr<Knight> k1(new Knight());
	//	k2 = k1;
	//}

	shared_ptr<Knight> k1 = make_shared<Knight>();  //new Knight�ص� �Ǵµ� make_shared�� ������ �� ����.
	shared_ptr<Knight> k2 = make_shared<Knight>();
	//k1->_target = k2;
	

	k1->Attack();
	
	// �׷��� �̷� shared_ptr�� ������ �ִ�..! (����Ŭ ������ �ȵȴٴ°ǵ�, �Ʒ� ���̽��̴�.)
	k1->_target = k2;
	k2->_target = k1;
	//�̶� ���ΰ� ���θ� �ֽ��ϴ�, refcount�� �ϴ� ������ make_shared�ҋ� ī��Ʈ�� 1�� ���� ���װ�, ���ΰ� ���θ� Ÿ�������״� 2�� �����Ѵ�. �׸��� ����, k2�� � ������ delete�� �Ǿ��� ��
	// refcount�� 1 �پ���,
	//k1 [  2]
	//k2 [  1]
	
	//�� ���� �ɰ��̴�. �׸��� ��.... => �׷� ���̻� �������� ����.
	//�޸𸮰� ���� �Ҹ��� �ȵȴ�. (��ȯ ����...!!!)

	//�ذ��ϱ� ���ؼ��� �Ʒ�ó�� nullptr�� �о������ ����� �ִ�.
	//k1->_target = nullptr;
	//k2->_target = nullptr; 

	//������ �̰��� �ذ��ϱ� ���� weak_ptr�� ����Ѵ�.
	//��ȯ ������ �Ͼ �� �ִ� �κ��� weak_ptr�� �ٲ��ش�. �׸��� refcount�� weakcount�� �߰����ش�.



	//unique_ptr (���� �������͸� �����Ѿ��Ѵ�!!) (�Ѱ��ֱ� �ȵǾ, std:move�θ� �̵��� �����ϴ�)
	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr; ����


	return 0;

}