#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//rvalue �� std::move�� Ȱ��

class Pet
{

};


class Knight {
public:

	Knight()
	{
		cout << "Knight()" << endl;
	}

	//���� ������
	Knight(const Knight& knight) 
	{
		cout << "Knight_const" << endl;
	}

	//�̵�������
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	//���� ���� ������.
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		//��������
		_hp = knight._hp;
		if(!knight._pet)
			_pet = new Pet(*knight._pet);  //�ٵ� ����� ���� ������ ������ �ƴϾ���...!
		//��������� knight �� �����͸� ���� ���� �ߛ���~ �ϸ鼭 �����ְ�, �� ������ ���� �������.
		//������ c++ 11 ������ �׳� �ʿ���� �ָ� �̵���� �� ������ �ʿ䰡 ���ٴ� ��Ʈ�� �ش�.

	}

	//�̵� ���� ������.
	void operator=(Knight&& knight) noexcept    //�� knight�� �� �̻� ��� ���Ѵ�~
	{
		cout << "operator=(Knight&& knight)" << endl;

		//���� ����� �ص� ����
		_hp = knight._hp;
		_pet = knight._pet; //���沨 ���� ���ž�.

		knight._pet = nullptr;


	}


	void PrintInfo()
	{


	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) { }                  
void TestKnight_LValue_Copy(Knight& knight) { }          //knight������ �ٰ� �˾Ƽ���!
void TestKnight_ConstLValue_Copy(const Knight& knight) {  /* ������ ���⿡ PrintInfo ���� �Ϲ� �Լ����� ȣ�� ����..... ==> const�� �����ֵ鸸 ����� ������ �������� �ִ�. */  } //������ ������ ReadOnly

void TestKnight_RValue_Copy(const Knight&& knight) {} //������ ����   // ������ �ְ� �а��⵵ ������, ȣ��ǰ� knight�� Ȱ�� �����״� �ʰ� �˾Ƽ��� (�̵� ���) ;;;  ���� ���� ���ص� ��

int main()
{
	// - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
	// - rvalue : lvalue�� �ƴ� ������ ( �ӽð�, ������, ����, i++)

	Knight A1;

	TestKnight_Copy(A1); //����
	TestKnight_LValue_Copy(A1); //����x
	TestKnight_ConstLValue_Copy(Knight());  // RValue�� �����ؼ� �ӽ���

	//TestKnight_RValue_Copy(A1); //�ݴ�� �̹��� �갡 �ް��� ������.
	TestKnight_RValue_Copy(Knight()); //�츮�� ������ �ӽð��� ������, �޸� ���, stack�� �ö��ִµ�, �츮�� �װ� ���� ���°Ŵ�
	TestKnight_RValue_Copy(static_cast<Knight&&>(A1)); //�̷��� �ް��� static_cast�ص� �����Ѵ�!


	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	Knight k3;
	k3 = static_cast<Knight&&>(k2);   //k2�� ���� ������ ����, ���� k2�� �Ⱦ��Ŵ�.(Ȥ�ó� �� �� ������ k2�� �Լ� ������ nullptr�� �¾��ߴ�)
	//���� �� k2�� pet�� ����´�. (k2�� ������ k3�� �����ϴ� ����)  
	//�� �׷� �� ����!!    => ����� �����͸� �����ؿ��� ������ ��������, �̵��� �� �� ������ �����̴�.

	k3 = std::move(k2); //�ٷ� ������ static_cast�ؼ� �̵���Ű�� �Ͱ� ���� �����̴�.
	//�ַ� unique �����Ϳ��� ���ٵ� �̰� �̵��� ��~~���ؼ� (���ϳ��� �����ؾ��ϴ� �����Ͱ� �ʿ��� �� ���ȴ�)   ==> �ڿ��� �ٷﺸ�ڴ�~!

	return 0;
}