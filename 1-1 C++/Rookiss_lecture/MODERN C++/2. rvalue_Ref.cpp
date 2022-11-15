#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;
//������ ���� (rvalue - reference)
//int a = 3;���� 3�� ������ 

class Pet
{
public :

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	//���� ������.
	Knight(const Knight& knight) // �������ڸ��� ���� ����
	{
		cout << "Knight()" << endl;
		
		//���� ����
		_hp = knight._hp;
		if (knight._pet)
			_pet = new Pet(*knight._pet);

	}



	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	void operator=(const Knight* knight)
	{
		cout << "operator=(const knights&)" << endl;
	}


	void operator=(Knight&& knight) noexcept
	{

		cout << "operator=(Knight&&)" << endl;

		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;
	}



public:
	int _hp = 100;
	Pet* _pet;
};


void TestKnight_Copy2(Knight* k) {}


void TestKnight_Copy(Knight k) {}
void TestKnight_LValueRef(Knight& knight) {}   //�� �� �������� �ϰ� ������ ����
void TestKnight_ConstLValueRef(const Knight& knight) {} //�� �� ������ �ѱ�� �ϰ͵� ���� 


void TestKnight_RValue(Knight&& knight) { };   //������ ���� ==> �а� ���⵵ �ٵǴµ�, ���̻� Ȱ������ �ʾ�! �̵����


int main()
{
	//�ް�(lvalue) vs ������(rvalue)
	// - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
	// - rvalue : lvalue�� �ƴ� ������ (�ӽð�, ������,����, i++ ��) 

	Knight k1;

	TestKnight_Copy2(&k1);


	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	TestKnight_ConstLValueRef(Knight());


	TestKnight_RValue(Knight()); //�Ϲ����� �ް� k1�� ���޴´�. -> ������ ���޴� Knight() �������� ����.
	TestKnight_RValue(static_cast<Knight&&>(k1));





	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	//�̵� (����´�)
	Knight k3;
	//k3 = static_cast<Knight&&>(k2);
	//������ �Ʒ��� ���� ���� ����.
	k3 = std::move(k2);

	//�̰��� (����������) -> �̵��� ���� ���� 
	//����Ʈ �����͸� ���� ���� ���µ�, 
	//���⼭ ����ũ �����ʹ� �����Ͱ� �� �ϳ��� �����ϵ��� �Ҷ� ��
	std::unique_ptr<Knight> uptr = std::make_unique<Knight>();
	std::unique_ptr<Knight> uptr2 = std::move(uptr); //�����͸� �̵� ��ų�� ���

	
	//�� ������ ���� ���� �ʾƵ� �Ǵ� ������, Ȥ�� ������ ��ü�� �̾��Ҷ� �ʿ��ϴ�.
	


	return 0;
}