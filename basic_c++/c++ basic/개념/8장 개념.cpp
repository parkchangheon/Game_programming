//protected ��ü ����

/*
#include<iostream>
#include<string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};


class ColorPoint :public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	bool equals(ColorPoint p);
};


void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}


bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}



int main() {
	Point p;
	p.set(2, 3);
	//p.x = 5;
	//p.y = 5; ���� �Ұ�

	p.showPoint();

	ColorPoint cp;
	//cp.x = 10;
	//cp.y = 10; ���ٺҰ�

	cp.set(3, 4);
	cp.setColor("RED");


	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("RED");
	cout << ((cp.equals(cp2)) ? "true" : "false");
}

*/





// Ŭ���� �����ڴ� ���������� ��ӿ��� �����ÿ�, �⺻�����ڰ� ������ �Ǵµ�, �̶� �⺻ �����ڰ� �־����.
//ex)

//class A {
//public:
//	A() { cout << "������ A" << endl; }
//	A(int x) { cout << " �Ű� ���� ������ A " << x << endl; }
//};
//
//
//class B :public A {
//public:
//	B() {
//		cout << "������ B ȣ��";
//	}
//};




//ex2)

//class A {
//public:
//	A() { cout << "������ A" << endl; }
//	A(int x){ cout << "�Ű����� ������ A" << endl; }
//};
//
//
//class B : public  A {
//public:
//	B() { cout << "B ������"; }
//	B(int x):A(x+3){ cout << "�Ű����� ������ B" << endl; }
//};






//��� ����� ������ �Ű� ���� ����

/*
#include<iostream>
#include<string>
using namespace std;


class TV {
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};


class WideTV :public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size) { this->videoIn = videoIn; }
	bool getVideo() { return videoIn; }
};


class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) :WideTV(size, true) { this->ipAddr = ipAddr; }
	string getIpAddr() { return ipAddr; }
};


int main(){
	SmartTV htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << htv.getVideo() << endl;
	cout << "ip= " << htv.getIpAddr() << endl;
}
*/




//private ��� ���
/*

#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};


class Derived :private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public: 
	void showB() { cout << b; }
};


int main() {
	Derived x;
	x.a = 5; //a�� Derived Ŭ������ ��ӵ�����, private ����̹Ƿ� ���� �Ұ�
	x.setA(10); // private ����� ����Ǿ� Derived�� ��ӵǾ����Ƿ�, Ŭ���� �ܺο��� ���� �Ұ�
	x.showA();

	x.b = 10; //b�� private �����̱� ����
	x.setB(); // protected �̱⿡ �ܺο����� ���� ����
	x.showB(); // public �̱� ������ �ܺο��� ���� ����
}
*/






//protected ��� ���
/*
#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};


class Derived :protected Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};


int main() {
	Derived x;
	x.a = 5; //a�� Derived Ŭ������ ��ӵ�����, private ����̹Ƿ� ���� �Ұ�
	x.setA(10); // protected ����� ����Ǿ� Derived�� ��ӵǾ����Ƿ�, Ŭ���� �ܺο��� ���� �Ұ�
	x.showA();

	x.b = 10; //b�� private �����̱� ����
	x.setB(); // protected �̱⿡ �ܺο����� ���� ����
	x.showB(); // public �̱� ������ �ܺο��� ���� ����
}
*/






// ����� ��ø �ɶ� ���� ���� ���
/*
#include<iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};


class Derived :private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { 
		setA(5);   //setA�� Base�� protected ����̹Ƿ�, ���� ����
		showA();
		cout << b;
	}
};


class GrandDerived :private Derived {
	int c;
protected:
	void setAB(int x) {
		setA(x); // private �Ӽ����� ����Ǿ�, Derived Ŭ������ ��ӵǱ� ������, ���� �Ұ���
		showA(); // �������� 
		setB(x); // protected ����̱� ������ ���� ����
	}
};
*/





//���� ��� ���� 

//class MusicPhone :public MP3, public MobilePhone {
//public:
//	void dial();
//};




/*
#include<iostream>
using namespace std;

class Adder {

protected:
	int add(int a, int b) { return a + b; }
};


class Sub {
protected:
	int minus(int a, int b) { return a - b; }
};


class Calculator :public Adder, public Sub {
public:
	int calc(char op, int a, int b);
};


int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+':
		res = add(a, b);
		break;
	case '-':
		res = minus(a, b);
		break;
	}
	return res;
}


int main() {
	Calculator handCalculator;
	cout << "2+4 = " << handCalculator.calc('+', 2, 4) << endl;

}
*/




//���� ����� ������

// ���� ����  �� 
/*
class BaseIO {
public:
	int mode;
};


class In :public BaseIO {
public:
	int readPos;
};

class Out :public BaseIO {
public:
	int writePos;
};


class InOut :public In, public Out {
public:
	bool safe;
};


int main() {
	InOut ioObj;
	ioObj.readPos = 10;
	ioObj.writePos = 10;
	ioObj.safe = true;
	ioObj.mode = 5; // �̋� mode�� in�� ������, out�� ������ ��ȣ�ϴ�.

}
*/


//�̷��� ������ �ذ��ϱ� ���� ���� ����� ���
//class In : virtual public BaseIO {
//public:
//	int readPos;
//};
//
//class Out :virtual public BaseIO {
//public:
//	int writePos;
//};
