//�������̵�, �����Լ�
/*
#include<iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }

};

class Derived :public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};

void main() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;
	pBase->f();
}
*/
// �� ���� �� f() �Լ��� �����Լ��� ������ �ȵǾ��ٸ� �׳� �Լ� �����ǰ� �Ǿ��� ���̳�, virtual �����Լ��� ���������Ƿ�, 
//����� //Derived::f() called �� �ι� ���´�

// �� ���� ���ε��� ���� Derived f()�� ȣ��.
// Base f()�� ���� ��� ȣ���� ���� �ð� �߿� Derived�� f() �Լ��� ���� ���ε� �ȴ�.


//�������̵��� ������, �� �Ļ�Ŭ�������� �ڽ��� ������ �°� �����Լ��� ������ �ϵ��� �ϴ°�.
// �ᱹ �������̵����� �������� ���� �� �� �ִ�.









//�������̵��� ���
/*
#include<iostream>

using namespace std;

class Base {
public:
	virtual void f() {cout << "Base::f() called" << endl;}
};

class Derived :public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

class GrandDerived :public Derived {
public:
	void f() { cout << "GrandDerived::f() called" << endl; }
};



int main() {
	GrandDerived g;
	Base* bp;
	Derived* dp;
	GrandDerived* gp;
	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}

*/




// �������̵��� ���� ���õ� �⺻ Ŭ������ �����Լ��� ȣ���� ����� �ִ�.  ==>���� ���� ������ ::�� ���� ���̴�.
/*
#include<iostream>
using namespace std;

class Shape {
public:
	virtual void draw() { cout << "--Shape--"; }
};


class Circle : public Shape {
public:
	int x;
	virtual void draw() { 
		Shape::draw(); 
		cout << "Circle" << endl;
	}
};

int main() {
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();
	pShape->Shape::draw();
}
*/




// ���� �������� �ٸ� ���ӻ� ( �������� ȣ�� ����)
/*
#include<iostream>
using namespace std;

void sendMessage(const char* msg)
{
	cout << msg << endl;
}

class Window {
public:
	void sendMessage(const char* msg) {
		cout << "window msg : " << msg << endl;
	}
	void run() {
		::sendMessage("Global Hello");
		sendMessage("Local Hello");
	}
};

int main() {
	Window window;
	window.run();
}
*/







// �Ҹ��ڿ� virtual�� �׻� �ٿ� �ִ°��� Ż�� �ȳ���.
/*
#include<iostream>
using namespace std;

class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};


int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();

	delete dp;
	delete bp;
}

*/




// �����ε��� �Ű� ������Ÿ���̳� ������ �ٸ� �Լ����� ������ �ߺ� �ۼ��ϴ� ���̴�.




/*
#include<iostream>
#include "shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

using namespace std;


int main() {
	Shape* pStart = NULL;
	Shape* pLast;

	pStart = new Circle();
	pLast = pStart;


	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Rect());

	// ���� ����� ��� ������ ȭ�鿡 �׸���
	Shape* p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}


	p = pStart;
	while (p != NULL) {
		Shape* q = p->getNext();
		delete p;
		p = q;
	}
}
*/






//�߻�Ŭ���� ���� ����
/*
#include<iostream>

using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0;
	virtual int substract(int a, int b) = 0;
	virtual double average(int a[], int size) = 0;
};


class GoodCalc :public Calculator {
public:
	int add(int a, int b) { return a + b; }
	int substract(int a, int b) { return a - b; }
	double average(int a[], int size) {
		double sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		return sum / size;
	}
};


int main() {
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->substract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}
*/






#include<iostream>
using namespace std;


class Calculator {
	void input() {
		cout << "���� 2���� �Է��Ͻÿ� : ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;

public:
	void run() {
		input();
		cout << "���� ����" << calc(a, b) << endl; 
	}
};


class Adder : public Calculator {
public:
	int calc(int a, int b) {
		return a + b;
	}
};

class Substractor : public Calculator {
public:
	int calc(int a, int b) {
		return a - b;
	}
};

int main() {
	Adder adder;
	Substractor substractor;

	adder.run();
	substractor.run();
}