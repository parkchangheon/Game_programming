#include<iostream>
using namespace std;

class Player
{
public:
	int _id;
};

int GenerateId()
{
	static int s_id = 1; //static �پ����Ƿ� ���ÿ� �ö��� �ʰ� ������ ������ �ö󰣴�.
	return s_id++;
}

class Marine {
public:
	int _hp; //�� ��ü�� �������̰� �ȴ�


	void TakeDamage(int damage) {  //Ư�� ��������� �ǵ����, ��������� �������� �� �� �ִ�.
		_hp -= damage;
	}
	static void SetAttack() { //�����Լ����� ���������� ������
		s_attack = 100;
	}
	static int s_attack; // �����̶�� Ŭ���� ��ü�� ������ ����. ���赵 �����θ� ����
	//static Ȱ��� �޸��Ҵ��� �ѹ��� �ϰ� �Ǿ� �޸� ��� ������ �ִ�.
	//�ʱ�ȭ�� ȭ�� ������ ������ ���� 
	//����ȭ ���� �ʴ� �ٸ� .bss������ ����.
};

int Marine::s_attack = 0;

int main()
{
	Marine m1;
	m1._hp = 35;
	Marine::s_attack = 6;  //�ϳ��� �����ϸ� ��� �������� ���ݷ��� �����.

	m1.TakeDamage(10);

	Marine m2;
	m2._hp = 14;

	Marine::SetAttack();
	Marine m3;
	m2._hp = 11;

}