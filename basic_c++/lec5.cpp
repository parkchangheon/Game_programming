/*

#include<iostream>
using namespace std;

int big(int a, int b) {
	if (a > b)
		return a;
	else return b;

}

int big(int a[], int size) {
	int res = a[0];
	for (int i = 1; i < size; i++) {
		if (res < a[i])
			res = a[i];
		return res;
	}
}


int main() {
	int arr[5] = { 1,9,-2,8,6 };
	cout << big(2, 3) << endl;
	cout << big(arr, 5) << endl;
}

*/



/*
#include <iostream>
using namespace std;

// ���� ����
void f(char c = ' ', int line = 1);

// �Լ� ����
void f(char c, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++)
			cout << c;
		cout << endl;
	}
}

int main() {
	f(); // ���ٿ� ��ĭ�� 10�� ����Ѵ�.
	f('%'); // �� �ٿ� '%'�� 10�� ����Ѵ�.
	f('@', 5); // 5 �ٿ� '@' ���ڸ� 10�� ����Ѵ�.
}





#include<iostream>
using namespace std;


class MyVector {
	int* p;
	int size;
public:
	MyVector(int n = 100) {
		p = new int[n];
		size = n;
	}
	~MyVector() { delete[] p; }
};

int main() {
	MyVector* v1, * v2;
	v1 = new MyVector();
	v2 = new MyVector(1024);
	cout << v1 << endl;
	cout << v2;


	delete v1;
	delete v2;
}






class Person {
public:
	double money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;
	static void addShared(int n) {
		sharedMoney += n;
	}
};

int Person::sharedMoney = 10;
//static ��ü�� ���α׷��� ������ �����Ѵ�.
//���α׷� ������ ��� ����
//��ü�� ��������� �̹� ����
// ��ü�� ������� ������ ����



//���

Person lee;
lee.sharedMoney = 500;

*/



/*
#include <iostream>
using namespace std;

class Person {
public:
	double money; // ���� ������ ��
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // ����
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static ���� ����. ���� ������ ����
int Person::sharedMoney = 10;  // 10���� �ʱ�ȭ

// main() �Լ�
int main() {
	Person han;
	han.money = 100; // han�� ���� ��=100	
	han.sharedMoney = 200; // static ��� ����, ����=200

	Person lee;
	lee.money = 150; // lee�� ���� ��=150
	lee.addMoney(200); // lee�� ���� ��=350
	lee.addShared(200); // static ��� ����, ����=400

	cout << han.money << ' '
		<< lee.money << endl;
	cout << han.sharedMoney << ' '
		<< lee.sharedMoney << endl;
}
*/



/*
#include<iostream>
using namespace std;


class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return a > b ? a : b; }
	static int min(int a, int b) { return a > b ? b : a; }
};

// Math Ŭ������ ����� �����Լ����� static ����� ĸ��ȭ�� ���α׷�


int main() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(1, 8) << endl;
}
*/

//static ��� �Լ��� static ����� ���� �����ϴ�



