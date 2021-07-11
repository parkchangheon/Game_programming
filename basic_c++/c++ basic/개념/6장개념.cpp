//�Լ� �ߺ�
/*
#include<iostream>

using namespace std;

int big(int a, int b) {
	return (a > b ? a : b);
}

int big(int a[], int size) {
	int m=a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > m)
			m = a[i];
	}
	return m;
}

int main() {
	int arr[5] = { 1,2,99,2,4 };
	cout << big(2, 3) << endl;
	cout << big(arr, 5) << endl;
}

*/




//����Ʈ �Ű�����
/*
#include<iostream>
#include<string>

using namespace std;

void star(int a = 5);
void msg(int id, string text = " ");

void star(int a) {
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}

void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}

int main() {
	star();
	star(10);

	msg(10);
	msg(10, "Hello");
}
*/


//�������� ���, 
//void f(int* p = NULL);
//void g(int x[] = NULL);
//void h(*s = "Hello");

//�� ���� ǥ���� �����ϴ�.



//�Լ� �ߺ� ����2)
/*
#include<iostream>

using namespace std;

void printer(char ch = '*', int num = 10) {
	for (int i = 0; i < num; i++) {
		cout << ch;
	}
	cout << endl;
}

int main() {
	printer();
	printer('%');
	printer('&', 20);
}
*/




// �����ڿ����� �ߺ�
/*
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
	~MyVector() { delete[]p; }
};


int main() {
	MyVector* v1, * v2;
	v1 = new MyVector(); // ����Ʈ ���� �迭 100 ���� �Ҵ�.
	v2 = new MyVector(200); // ���� �迭 200 ���� �Ҵ�.

	delete v1;
	delete v2;

}
*/





//�ߺ� �Լ��� ��ȣ��
//1. �Ű����� ���� ��ȣ�� 
//2. ���� �Ű������� ��ȣ��
//3. ����Ʈ �Ű������� ��ȣ��

//1.
//float al(float a);
//float ar(double a);



//2. 
/*
#include<iostream>

using namespace std;

int add(int a, int b) {
	return a + b;
}

int add(int a, int& b) {
	b = b + a;
	return b;
}

int main() {
	int s = 10, t = 20;
	cout << add(s, t); // ��ȣ�ϴ�!
}

*/



//3. 
/*
#include<iostream>
#include<string>

using namespace std;

void msg(int id) {
	cout << id << endl;
}


void msg(int id, string s = "") {
	cout << id << ":" << s << endl;
}

int main() {
	msg(5,"goodmorning"); //������ ������
	msg(6);// ���� �������� ��ȣ��

}
*/





//static!!!
//static�� �ش� Ŭ������ ��� ��ü�� �����ϴ� �������� ����!
/*
#include<iostream>
using namespace std;;

class person {
public:
	double money;
	void addMoney(int money) {
		this->money += money;
	}

	//static���� ǥ���� �������/�Լ����� person��ü���� �����ϴ� �������� ǥ��. 
	// ���� money�� ��ü�� ������ ������ ���� ǥ��.

	static int sharedMoney;
	static void addShared(int n) {
		sharedMoney += n;
	}
};


//static ��� ������ �ܺο� ���� ������ ����Ǿ�� �Ѵ�.
int person::sharedMoney = 10;// �̷��� ������ Ŭ���� �ۿ� ������ ����.

int main() {
	person han;
	han.money = 100; //���ε� 100
	han.sharedMoney = 200; // ���� 200

	person lee;
	lee.money=150;
	lee.addMoney(200); //���ε� 350
	lee.addShared(200); // ���� 400

	cout << han.money << lee.money << endl;
	cout << han.sharedMoney << lee.sharedMoney << endl;
	// person::sharedMoney�� �����ص� �Ȱ���.
}
*/





/*
#include<iostream>
using namespace std;;

class person {
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


int person::sharedMoney = 10;

int main() {
	person::addShared(50);
	cout << person::sharedMoney << endl;

	person han;
	han.money = 100;
	han.sharedMoney = 200;
	person::sharedMoney = 300;
	person::addShared(100);

	cout << han.money << ' ' << person::sharedMoney << endl;
}
*/



//static�� ĸ��ȭ

// ���������� �����Լ��� �������� ���� Ŭ������ static ����� �����ϸ鼭 ĸ��ȭ�� ��Ű�����Ѵ�.
/*
#include<iostream>
using namespace std;

class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return a > b ? a : b; }
	static int min(int a, int b) { return a > b ? b : a; }
};

int main() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(10, 8) << endl;
}

*/




//static ����� ������ �������� ����ϴ� ��
/*
#include<iostream>

using namespace std;

class Circle {
private:
	static int numOfCirlce;
	int radius;

public:
	Circle(int r = 1);
	~Circle() { numOfCirlce--; }
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircle() { return numOfCirlce; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCirlce++;
}


int Circle::numOfCirlce = 0;      // 0���� �ʱ�ȭ���ش�.


int main() {
	Circle* p = new Circle[10];
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;

	delete[]p;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;

	Circle a;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;

	Circle b;
	cout << "�����ϰ� �ִ� ���� ���� = " << Circle::getNumOfCircle() << endl;
}
*/


// 10 0 1 2




//static �Լ��� static ��� ������ ���� �ϰų�  static �Լ��� ȣ�Ⱑ��.
//ex_
/*
class person {
public:
	double money;
	static int sharedmoney;

	int total() {                   // non-static �Լ��� static�̳� non-static ����� ��� ������ �����ϴ�.
		return money + sharedmoney;
	}
};




class person {
public:
	double money;
	static int sharedMoney;

	static void addShared(int n) {
		this->sharedMoney += n;  // thos�� ����ϸ� ������ ������ ����.
	}
};

*/