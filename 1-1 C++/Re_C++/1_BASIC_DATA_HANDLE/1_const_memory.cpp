#include<iostream>
using namespace std;

// �ѹ� �������� ���� �ٲ��� ���� ����
// constant => const (������ ���ȭ �Ѵ�)
// const => �ʱⰪ�� ����������Ѵ�.

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3; //�ʱⰪ�� �������־����. (invincible�� ���� �޸𸮰� �Ҵ�Ǿ��ִ°� �ƴ϶�, �׳� invincible�� ������, �����Ϸ��� 3���� �׳� ġȯ��)

// DATA ����
// .data =>�ʱⰪ�� ���� ��� 
int a;
// .bss => �ʱⰪ�� �ִ� ���
int b = 2;
// .rodata => �б� ���� ������
const char* msg = "Hello World";


int main()
{
	//���ÿ��� (esp, ebp)
	//const��� �ص�, �Լ����� ������ �Ǹ�, ���� �޸𸮿� ������.

	const int WHATEVER = 4;
}