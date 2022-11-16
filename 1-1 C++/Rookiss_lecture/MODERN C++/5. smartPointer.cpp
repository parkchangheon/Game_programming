#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

//smart pointer 
//����
//�����ʹ� ���������� �޸𸮸� �а� ������ �����ѵ�, ������ �޸𸮸� ������ ū�ϳ���.


class Knight
{
public:
	~Knight() { cout << "����Ʈ �Ҹ�" << endl; }
	Knight() { cout << "����Ʈ ����" << endl; }


	void Attack()
	{
		if (_target)  //Ÿ���� ������ �̻��� �޸𸮸� �ǵ�� �ִ�.
		{
			_target->_hp -= _damage;
			cout << "HP : " << _target->_hp << endl;
		}
	}


public:
	int _hp = 100;
	int _damage = 100;
	Knight* _target = nullptr;

};


class RefCountBlock  //����Ƚ���� �����ϴ� Ŭ����
{
public:
	int _refCount = 1;
};

template<typename T>
class SharedPtr 
{
	//�����͸� �����ϴ� �ֵ��� ī��Ʈ�ؼ� 0�� �ƴϸ� delete ó�� x
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr) 
		{
			block = new RefCountBlock();
			cout << "RefCount" << block->_refCount <<endl;
		}
	}

	~SharedPtr() 
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount" << block->_refCount << endl;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}


public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};

int main()
{
	Knight* k1 = new Knight();
	Knight* k2 = new Knight();

	k1->_target = k2;  //Ÿ�� ������ ����µ�
	delete k2;		   //������ �����?!?!!
	k1->Attack();	   //���� �߻�. 

	//����Ʈ ������ : �����͸� �˸´� ��å�� ���� �����ϴ� ��ü( �����͸� �����ؼ� ��� )
	//shared_ptr, weak_ptr, unique_ptr


	//shared ptr(�ٽ�)



	return 0;
}