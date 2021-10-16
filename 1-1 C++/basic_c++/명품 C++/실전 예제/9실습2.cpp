//9-7

/*
#include<iostream>
using namespace std;

class Shape {
protected:
	string name;
	int width, height;

public:
	Shape(string n = "", int w = 0, int h = 0) {
		name = n;
		width = w; 
		height = h;
	}

	virtual double getArea() { return 0; }
	string getName() { return name; }
};


class Oval : public Shape {
public:
	Oval(string n, int a, int b) :Shape(n, a, b) { ; }
	double getArea() {
		return 3.14 * width * height;
	}
};


class Rect : public Shape {
public:
	Rect(string n, int a, int b) :Shape(n, a, b) { ; }
	double getArea() {
		return  width * height;
	}
};

class Triangular : public Shape {
public:
	Triangular(string n, int a, int b) :Shape(n, a, b) { ; }
	double getArea() {
		return  width * height*0.5;
	}
};


int main() {
	Shape* p[3];
	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30, 40);
	p[2] = new Triangular("�佺Ʈ", 30, 40);

	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
	for (int i = 0;i < 3; i++)
		delete p[i];
}
*/





//9-9

/*
#include<iostream>
using namespace std;

class Printer {
protected:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model, this->manufacturer = manufacturer,  this->availableCount = availableCount;
	}

	virtual void print(int pages) = 0;
	virtual void show() = 0;
};


class InkPrinter :public Printer {
	int availableInk;

public:
	InkPrinter(string model, string manufacturer, int availableCount, int availableInk) :Printer(model, manufacturer, availableCount) 
	{ this->availableInk=availableInk;}
	

	void print(int pages) {
		if (availableInk < pages || availableCount < pages)
			cout << "������ ��ũ�� �����մϴ� " << endl;
		else {
			availableInk -= pages;
			availableCount -= pages;
		}
	}

	void show() {
		cout << "��ũ : " << model << ", " << manufacturer << ", �������� " << availableCount << ", ���� ��ũ " << availableInk << endl;
	}
};



class LaserPrinter :public Printer {
	int availableToner;

public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) :Printer(model, manufacturer, availableCount)
	{
		this->availableToner = availableToner;
	}


	void print(int pages) {
		if (availableToner < pages || availableCount < pages)
			cout << "������ ��ũ�� �����մϴ� " << endl;
		else {
			availableToner -= pages;
			availableCount -= pages;
		}
	}

	void show() {
		cout << "������ : " << model << ", " << manufacturer << ", �������� " << availableCount << ", ���� ��� " << availableToner << endl;
	}
}; 



int main() {
	Printer *ip;
	Printer *lp;
	char c='y';
	ip = new InkPrinter("Officejet V40", "HP", 5, 10);
	lp = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����."<<endl;
	ip->show();
	lp->show();

	while (c == 'y') {
		int select, paper;
		cout << "������(1 : ��ũ��, 2: ������)�� �ż� �Է� >> ";
		cin >> select >> paper;

		if (select == 1) {
			ip->print(paper);
		}


		else if (select == 2) {
			lp->print(paper);

		}

		else {
			cout << " �߸��� �Է��Դϴ�. ";
			continue;
		}


		ip->show();
		lp->show();

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�? (y/n) >> ";
		cin >> c;


	}


}
*/


