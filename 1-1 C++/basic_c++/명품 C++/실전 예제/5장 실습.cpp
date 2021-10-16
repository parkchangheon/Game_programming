//���� 1.
/*
#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setradius(int r);
	double get_area();
};

void Circle::setradius(int r) {
	this->radius = r;
}

double Circle::get_area() {
	return this->radius * this->radius * 3.14;
}



void swap(Circle& x, Circle& y) {
	Circle tmp;
	tmp = x;
	x = y;
	y = tmp;
}


int main() {
	Circle a;
	Circle b(5);
	swap(a, b);

	cout << a.get_area() <<' '<< b.get_area();



}
*/



//2
/*
#include<iostream>
using namespace std;

void half(double& n) {
	n = n / 2;
}

int main() {
	double n = 20;
	half(n);
		cout << n;
}
*/




//3
/*
#include<iostream>

using namespace std;


void combine(string s1, string s2, string& s3) {
	s3 = s1 + " " + s2;
}//������ s3�� ���ֹǷ�


int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
}
*/





//4
/*
#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) {
		return true;
	}
	else {
		if (a > b)
			big = a;
		else
			big = b;
		return false;
	}
}


int main() {
	int a = 10, b = 20,c;
	bool result=bigger(a, b, c);
	cout << result<<' '<<c;
}
*/





//5
/*
#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� " << radius << "�� ��" << endl; }
};

void increaseBy(Circle& a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y); // x�� �������� 15�� ���� ������� �Ѵ�. 
	x.show(); // "�������� 15�� ��"�� ����Ѵ�. 
}
*/




//6
/*
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char& find(char a[], char c, bool& success) {
	int len = sizeof(a);
	for (int i = 0; i < len; i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
}


int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}
*/



//7��
/*
#include<iostream>
using namespace std;


class MyIntStack {
	int p[10] = { NULL ,};;
	int tos;
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	this->tos = 0;
}

bool MyIntStack::push(int n) {
	if (tos < 10) {
		p[tos] = n;
		tos++;
	}
	else {
		return false;
	}

	return true;
}

bool MyIntStack::pop(int& n) {
	tos--;
	if (tos < 0)
		return false;
	else {
		n = p[tos];
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i))
			cout << i << ' ';
		else
			cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n))
			cout << n << ' ';
		else
			cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}
*/


//8�� ****�߿�****

/*
#include<iostream>
using namespace std;

class MyIntStack {
	int* p; // ���� �޸𸮷� ����� ������
	int size; // ������ �ִ� ũ��
	int tos; //������ ž

public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};


MyIntStack::MyIntStack(int size) { //���� �迭 �ʱ�ȭ
	this->size = size;
	p = new int[size];
	tos = 0;
}


MyIntStack::MyIntStack(MyIntStack& s) { //���� ������ 
	this->p = new int[s.size];
	this->size = s.size;
	this->tos = s.tos;
	//������� ���� ������ �� ������
	//���⼭���ʹ� ���� ����
	for (int i = 0; i <= s.tos; i++)
		this->p[i] = s.p[i];
}


MyIntStack::~MyIntStack() {
	delete[]p;
	p = NULL;
}



bool MyIntStack::push(int n) {
	if (tos > size)
		return false;
	else {
		p[tos++] = n;
		return true;
	}
}


bool MyIntStack::pop(int& n) {
	if (tos < 0)
		return false;
	else {
		n = p[--tos];
		return true;
	}
}


int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);

	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "���� a���� ���� ��" << n << endl;
	b.pop(n);
	cout << "���� b���� ���� ��" << n << endl;

}
*/




//9��
/*
#include<iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};

Accumulator::Accumulator(int value) {
	this->value = value;
}

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; //�ڱ� �ڽ� ���� ����
}


int Accumulator::get() {
	return value;
}


int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}
*/




//10
/*
#include<iostream>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += text; }
	void print() {cout << text << endl;}
};

Buffer& append(Buffer& s, string g) {
	s.add(g);
	return s;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
}
*/

