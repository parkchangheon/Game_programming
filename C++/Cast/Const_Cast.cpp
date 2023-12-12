#include<iostream>
#include<stdio.h>

using namespace std;

//const_cast 
// const�� ����� �����͸� const�� Ǯ���� �� �ִ�.
// �����Ͱ� �ƴ� �Ϲ� ������ const�� Ǯ���� �� ����.
// �Լ� ������, ��� �Լ��� ���� const�� Ǯ���� �� ����.

int main()
{
	const int num = 10;
	const int* p = &num;

	int* p2 = const_cast<int*>(p);
	*p2 = 30;

	printf("&num = %x, p=%x, p2=%x \n", &num, p, p2);	//72eff7f4
	printf("num = %d, p=%d, p2=%d \n", num, *p, *p2);	//num = 10, p=30, p2=30

	// num, p, p2 ��� �ּҰ��� �Ȱ�����, 
	// ����Ű�� ���� ��� �ٸ���.

}