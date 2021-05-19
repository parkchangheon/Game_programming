
/*
#include<iostream>

using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle* p;
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}




#include<iostream>

using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {

	Circle circleArr[3];

	circleArr[0].setRadius(10);
	circleArr[1].setRadius(20);
	circleArr[2].setRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������ " << circleArr[i].getArea() << endl;


	Circle* p;
	p = circleArr;
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << "��" <<"������"<< endl;
		p++;
		}
	}

}




#include<iostream>

using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}



int main() {
	Circle circle[2][3];

	circle[0][0].setRadius(1);
	circle[0][1].setRadius(2);
	circle[0][2].setRadius(3);
	circle[1][0].setRadius(4);
	circle[1][1].setRadius(5);
	circle[1][2].setRadius(6);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << circle[i][j].getArea() << endl;
		}
	}
	return 0;
}



//���� �޸� �Ҵ� �� ��ȯ




#include<iostream>
using namespace std;

int main() {
	int* p = new int;

	if (!p) {
		cout << "�޸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << '\n';
	cout << " n = " << n << '\n';

	delete p;

}




#include <iostream>
using namespace std;

int main() {
	cout << "�Է��� ������ ������?";
	int n;
	cin >> n;
	if (n <= 0) return 0;
	int* p = new int[n];
	if (!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "��° ���� : ";
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "��� = " << sum / n << endl;

	delete[] p;
}



#include<iostream>
using namespace std;

class Circle {
	int radius;

public:
	Circle() { radius = 1; };
	Circle(int r) { radius = r; };
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

Circle::~Circle() {
	cout << "�Ҹ��� ����";
}

int main() {
	Circle* p, * q;

	p = new Circle;
	q = new Circle(30);

	cout << p->getArea() << endl<< q->getArea() << endl;
	delete p;
	delete q;
}




#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
}



int main() {
	cout << "�����ϰ��� �ϴ� ���� ����?";
	int n, radius;
	cin >> n; // ���� ���� �Է�

	Circle* pArray = new Circle[n]; // n ���� Circle �迭 ����
	for (int i = 0; i < n; i++) {
		cout << "��" << i + 1 << ": "; // ������Ʈ ���
		cin >> radius; // ������ �Է�
		pArray[i].setRadius(radius); // �� Circle ��ü�� ���������� �ʱ�ȭ
	}

	int count = 0; // ī��Ʈ ����
	Circle* p = pArray;
	for (int i = 0; i < n; i++) {
		cout << p->getArea() << ' '; // ���� ���� ���
		if (p->getArea() >= 100 && p->getArea() <= 200)
			count++;
		p++;
	}
	cout << endl << "������ 100���� 200 ������ ���� ������ "
		<< count << endl;

	delete[] pArray; // ��ü �迭 �Ҹ�
}

*/



/*
class Circle {
	int radius;
public:
	Circle() { this->radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
};
*/





/*
#include<iostream>

using namespace std;

int main() {
	string str;
	string address("����� ���ϱ� �Ｑ�� 389");
	string copyAddress(address); // copyAddress�� address�� �����Ѵ�.

	cout << copyAddress;


	char text[] = { 'l','o','v','\0' };
	string title(text);
}







#include<iostream>

using namespace std;

int main() {
	string* p = new string("C++");

	cout << *p;
	p->append(" Great!!");
	cout << *p;

	delete p;
}
*/




/*
#include<iostream>
#include<string>

using namespace std;

int main() {
	string names[5];

	for (int i = 0; i < 5; i++) {
		cout << "�̸� >> ";
		getline(cin, names[i], '\n');
	}

	string latter = names[0];
	for (int i = 1; i < 5; i++){
		if (latter < names[i])
			latter = names[i];
	}
	cout << "������ ���� �ڿ� ������ ���ڿ��� " << latter << endl;
}
*/



/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "���ڿ��� �Է��ϼ���(�ѱ� �ȵ�) " << endl;
	getline(cin, s, '\n'); // ���ڿ� �Է�
	int len = s.length(); // ���ڿ��� ����

	for (int i = 0; i < len; i++) {
		string first = s.substr(0, 1); // �� ���� ���� 1���� ���ڿ��� �и�
		string sub = s.substr(1, len - 1); // ������ ���ڵ��� ���ڿ��� �и�
		s = sub + first; // �� ���ڿ��� �����Ͽ� ���ο� ���ڿ��� ����
		cout << s << endl;
	}
}


#include<iostream>
#include<string>
using namespace std;

int main() {
	string a("Hello C++");
	cout << a.length() << endl;
	a.append("!!");
	cout << a << endl;
	cout << a.at(6) << endl;
	cout << a.find("C") << endl;
	int n = a.find("+++");
	cout << n << endl;
	a.erase(1, 3);
	cout << a << endl;
}



*/