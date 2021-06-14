
//��ü ����� 1 
/*
#include<iostream>

using namespace std;

class Circle { 
public:
	int radius;
	double getArea();
}; // Ŭ���� �����

double Circle::getArea() {
	return 3.14 * radius * radius;
} // Ŭ���� ������ 




int main() {
	Circle pizza;
	pizza.radius = 3;
	double area = pizza.getArea();
	cout << "������ ������ : " << area << endl;

	Circle donut;
	donut.radius = 1;
	area = donut.getArea();
	cout << "������ ������ : " << area << endl;

}

*/


//ex
/*
#include<iostream>

using namespace std;

class Rectangle {
public:
	int height, width;
	int RectArea();
};

int Rectangle::RectArea() {
	return height * width;
}

int main() {
	Rectangle r;
	r.width = 10;
	r.height = 20;

	cout << r.RectArea();
}
*/




//������
/*
#include<iostream>

using namespace std;


class Circle {
public:
	int radius;
	double getArea();
	Circle();
	Circle(int r);
};

Circle::Circle() {
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}


double Circle::getArea() {
	return 3.14 * radius * radius;
}



int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "���� ������ " << area << endl;

	cout << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}
*/





//���� ������ ��� 
/*
#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};


Circle::Circle() :Circle(1) {}

Circle::Circle(int r) {
	radius = r;
	cout << "������" << radius << "�� ����" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "���� ������ " << area << endl;

	cout << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}

*/



//���� ������ Ȱ��

/*
class Point {
	int x, y;

public :
	Point();
	Point(int a, int b);
};


Point::Point() {
	x = 0, y = 0;
}

Point::Point(int a, int b) {
	x = a, y = b;
}




#include<iostream>

using namespace std;


class Point {
	int x, y;
public :
	Point();
	Point(int a, int b);

	void show() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};


Point::Point():Point(0,0){}
Point::Point(int a, int b) :x(a),y(b){}



int main() {
	Point origin;
	Point target(10, 20);
	origin.show();
	target.show();
}




#include<iostream>

using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();

	double getArea();
};


Circle::Circle() {
	radius = 1;
	cout << "������" << radius << "�� ����" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������" << radius << "�� ����" << endl;
}


Circle::~Circle() {
	cout << "������" << radius << "�� �Ҹ�" << endl;
}


double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "���� ������ " << area << endl;

	cout << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
	cout << endl;
}

*/




//�ζ��� �ڵ� ó�� 
/*
#include<iostream>
using namespace std;


class Circle {
	int radius;
public:
	Circle() {
		radius = 1;
	}// �ζ��� �ڵ�ó�� 
	Circle(int r);
	double getArea() {
		return 3.14 * radius * radius; // �ζ��� �ڵ�ó��
	}
};

Circle::Circle(int r) {
	radius = r;
}
*/



//����ü
/*
#include<iostream>

using namespace std;

struct StructCircle {
private:
	int radius;
public:
	StructCircle(int r) {
		radius = r;
	}
	double getArea();
};

double StructCircle::getArea() {
	return 3.14 * radius * radius;
}


int main() {
	StructCircle waffle(3);
	cout << "������" << waffle.getArea();
}



#include<iostream>
using namespace std;

#include "Circle.h"

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "���� ������ " << area << endl;

	cout << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
	cout << endl;
}







*/
