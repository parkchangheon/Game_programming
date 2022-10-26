#include<iostream>
using namespace std;

void HelloWorld()
{
	cout << "Hello World " << endl;
}
void HelloNumber(int number)
{
	cout << "Hello World " << number << endl;
}

class Knight {
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100;
};

class Functor
{
public:
	void operator()()  //()�� �����ε� �ҰŰ�, ()�� �Լ��ϱ� �ٿ��ִ� ���̴�.
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator()(int num)
	{
		cout << "Functor Test2" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}

private:
	int _value = 0;
};

class MoveTask
{
public:
	void operator()()
	{
		cout << "�ش� ��ǥ�� �÷��̾� �̵�" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};



int main()
{
	//�Լ� ��ü (Functor) : �Լ�ó�� �����ϴ� ��ü 
	// 
	//�Լ� ������ ����
	void(*pfunc)(void);
	pfunc = &HelloWorld; // ������ �Ѱ��ٶ� ������
	(*pfunc)();
	
	//�Լ� �������� ����
	// 1) �ñ״�ó�� �ȸ����� ����� �� ����.
	// 2) ���¸� ���� �� ����.
	//pfunc = &HelloNumber;

	//�Լ� ��ü��?
	//�Լ�ó�� �����ϴ� ��ü -> �ϴ� Class�� ������ش�.
	//() ������ �����ε��� ���� �Լ�ó�� ����Ѵ�.
	HelloWorld();

	Functor functor; //�Լ� �����Ϳ� �ٸ��� ���°��� ��� �ִ�.
	functor();
	bool ret = functor(3);

	//��¿�� ����ұ�??
	//MMO���� �Լ� ��ü�� ����ϴ� ���� 
	//Ŭ�� <-> ����
	//���� : Ŭ�� ������ ��Ʈ��ũ ��Ŷ�� �޾Ƽ� ó��
	// 
	// 
	//ex) Ŭ�� : ��(5,0) ��ǥ�� �̵�������! ��� ��Ŷ�� ������ => ������ üũ�ϰ� �̵���Ŵ
	//Command Pattern
	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	//������ �����ϴ� �κ�
	task();

	return 0;
}