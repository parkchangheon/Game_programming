#include<iostream>
using namespace std;

//��ü���� ���α׷���

//��ü�� ���� �� ��� �÷��̾�, ����, ������ �� 
//gameroom ���� ������Ʈ�� ��ü

//Knight�� �����غ���
//�Ӽ�(������) : hp, attackrage, position(x,y)
//���(����) : Move, Attack, Die

//struct <-> class ���� ������, public, private ����
class Knight {
	
public:
	Knight() {  //����Ʈ ��������
		cout << "constuctor spawned" << endl;
		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}
	 //���� ������ = �������ε� ���� Ÿ������ �ڱ� �ڽ��� �޴´�.
	Knight(const Knight& knight)  // ���� ������� ����Ʈ k1�� ������, �� ����� ��.   ==> ���� Knight k2(k1) �̷������� ���
	{   // ���� 99% Ȯ���� const�� �ٿ������  ==> �ٸ��ָ� �޾Ƽ� �����ϴ� ���� ���� ���⿡ const�� �ٿ���
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	//��Ÿ ������
	Knight(int hp) {
		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	~Knight() {
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}
	//����Լ�(Ŭ���� �ȿ� �ִ�)
	void Move(int x, int y);
	void Attack();
	void Die();

public:
	//�������(Ŭ���� �ȿ� �ִ�)
	int _hp;
	int _attack;
	int _posX;
	int _posY;
};

void Move(Knight* knight, int x, int y) { //�Ϲ��Լ�
	knight->_posX = x;
	knight->_posY = y;
}


void Knight::Move(int x, int y)
{
	_posX = x;
	_posY = y;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack" << endl;

}

void Knight::Die()
{
	_hp = 0;
	cout << "Die" << endl;
}


//instantiate = ��ü�� �����.
int main()
{
	Knight k1;
	k1._hp = 100;
	k1._attack = 10;
	k1._posX = 0;
	k1._posY = 0;

	Knight k2;
	k2._hp = 80;
	k2._attack = 5;
	k2._posX = 1;
	k2._posY = 1;

	Move(&k1, 3, 3);
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();
	return 0;
}



//Move(&k1, 3, 3);      
//00522777  push        3
//00522779  push        3
//0052277B  lea         eax, [k1]   //�޸𸮷� �÷��ش� 
//0052277E  push        eax         //eax ���ÿ����� push
//0052277F  call        Move(0521442h)
//00522784  add         esp, 0Ch
//k1.Move(2, 2);
//00522787  push        2
//00522789  push        2
//0052278B  lea         ecx, [k1]   //�׳� �������Ϳ� �������
//0052278E  call        Knight::Move(052122Bh)




