#include<iostream>
using namespace std;

// 1) �ּ� ������ (&)
// 2) ��� ������ (+ -)
// 3) ���� ������ (*)
// 4) ���� ��� ������ 

class Player
{
public:
	int hp;  // +0
	int damage; // +4
};

Player globalInfo;

void PrintInfoPTR(Player* player)
{
	player->hp = 10;
	player->damage = 5;
	
	//�����ʹ� *�� �������� �տ� ���̳� �ڿ� ���̳Ŀ� ���� const�ǹ̰� �޶���.
	//�ּҰ� ��ü�� ������ ���� �ʰ� �ϴ���   vs    ���޵Ǿ�� �����͸� ���� ���� �ʰ� �ϳ�
	//ex)
	player = &globalInfo; //�ּҰ��� �ٲ۴�
	player->hp = 1000;


	//*�տ� ���δٸ�    ==> ������ �����͸� �ٲ��� ���Ѵ�.
	/*const Player* player;*/


	//*�ڿ� ���δٸ�    ==> �ּҰ��� �ٲ��� ����.
	/*Player* const player;*/
	
}


void PrintInfoREF(const Player& player)
{
	//const �� ���̸� ������ �Ұ���
	//player.hp = 11;
	//player.damage = 6;
}


int main()
{
	int number = 1;
	int number2 = 2;

	// 1) �ּ� ������ (&)
	// - �ش� ������ �ּҸ� �˷��ֶ�
	int* pointer = &number;


	//2) ��� ������ (+-)
	pointer += 1;
	// �����Ϳ��� + - �� ��� �������� 1�� ���ϰų� ����
	// ���� �� ���ڸ� ���ϰ� ���� ���� �ƴ� Ÿ�� ũ�⸸ŭ �̵�


	//3) ���� ������ (*)
	// - ��Ż�� Ÿ�� �ش� �ּҷ� �����̵�
	number = 3;
	*pointer = 4;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerptr = &player;
	(*playerptr).hp =100;


	// 4) ���� ��� ������ (->)
	playerptr->hp = 200;
	playerptr->damage = 20;



	
	//�������� ���
	int& reference = number;
	//���� ���� ����? => ���� ���޶����� ����
	//�������Ŀ� . �� ����ؼ� �ս��� ����� �����ϱ� ������
	Player& reference2 = player;


	Player info;

	//������ ����
	PrintInfoPTR(&info);

	//���� ����
	PrintInfoREF(info);


	//������ null�� ���Ұ� �����ʹ� nullptr�� ��밡��
	// null check�� �����ϴ�.


	// - ���� ��쵵 ����ؾ��Ѵٸ�, nullptr (��üũ)
	// - �ٲ��� �ʰ� �д� �뵵(readOnly)�� ����Ѵٸ� const ref&
	// - �� �� �Ϲ������� ref (��������� ȣ���� �� OUT�� ���δ�)


	//�����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	PrintInfoREF(*playerptr);

	//������ ����ϴ��� �����ͷ� �Ѱ��ַ���
	PrintInfoPTR(&reference2);
	return 0;
}