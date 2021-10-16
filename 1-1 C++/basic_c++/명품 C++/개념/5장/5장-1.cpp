
//���� ���� ȣ��, �ּҿ� ���� ȣ��


//�ּ�
//#include<iostream>
//using namespace std;
//
//void swap(int* a, int* b) {
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//
//int main() {
//	int x = 5, y = 10;
//	swap(&x, &y);
//	cout << x << ' ' << y;
//}





// ���� ���� �Ű� ������ ������ ����� ȣ��
/*
#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }

};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius= " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius= " << radius << endl;

}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius" << radius << endl;
}

void increase(Circle c) { // ��ü c�� �����ڰ� ������ �Ǿ�� �ϳ� ������� ����
	int r = c.getRadius();
	c.setRadius(r + 1);
}//��ü c�� �Ҹ��� ����



int main() {
	Circle waffle(30);
	increase(waffle); //������ �״�� ����
	cout << waffle.getRadius() << endl; //�ٲ��� �ʾ���
}
*/


//�ּҿ� ���� ȣ��
/*
#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }

};

Circle::Circle() {
	radius = 1;
	cout << "������ ���� radius= " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius= " << radius << endl;

}

Circle::~Circle() {
	cout << "�Ҹ��� ���� radius" << radius << endl;
}

void increase(Circle *c) { // ��ü c�� �����ڰ� ������ �Ǿ�� �ϳ� ������� ����
	int r = c->getRadius();
	c->setRadius(r + 1);
}//��ü c�� �Ҹ��� ����



int main() {
	Circle waffle(30);
	increase(&waffle); //������ �״�� ����
	cout << waffle.getRadius() << endl; //�ٲ��� �ʾ���
}

*/



/*

#include<iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int radius) { this->radius = radius; }

};

Circle getCircle() {
	Circle tmp(30);
	return tmp;
}


int main() {
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	cout << c.getArea() << endl;
}

*/



//������ ���������� ���� �����ϴ� ���� �ƴ϶�, �׳� �̸��� �޸��ϰ� ��������� ����




/*
#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;

	int& refn = n;

	n = 4;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;


	refn = i;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;

}

*/








/*
#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int x = 1, y = 2;
	swap(x, y);
	cout << x << ' ' << y << endl;
}

*/



/*


#include<iostream>
using namespace std;

char& find(char s[], int index) {
	return s[index]; // s[index] ���� ����
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S'; // name[0]='S'
	cout << name << endl;

	char& ref = find(name, 2); //ref�� name[2]�� ���� ����
	ref = 't';
	cout << name << endl;
}


*/



//���������
/*
class Circle{
	Circle(Circle &c);
}

Circle src(30);

Circle dest(src); => src��ü�� �����Ͽ� dest ��ü�� �����϶�.




#include<iostream>

using namespace std;

class Circle {
private:
	int radius;

public:
	Circle(Circle& c);
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle(Circle& c) {
	this->radius = c.radius;
	cout << "���� ������ ����" << radius << endl;
}



int main() {
	Circle src(30);
	Circle dest(src);

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;

}

*/








