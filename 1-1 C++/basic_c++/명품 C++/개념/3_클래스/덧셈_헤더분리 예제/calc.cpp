#include<iostream>
using namespace std;

#include"calc.h"
#include"add.h"

void calculator::run() {
	cout << "�ΰ��� ���� �Է��Ͻÿ�";
	int a, b;
	cin >> a >> b;
	add add(a, b);
	cout << "����� : " << add.process();
}