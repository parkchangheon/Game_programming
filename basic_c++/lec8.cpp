// ���

/*
#include<iostream>
using namespace std;

class phone {
	void call();
	void receive();
};


class MobilePhone : public phone {
	void connectWireless();
	void recharge();
};

class MusicPhone : public MobilePhone {
	void downloadMusic();
	void play();
};

*/




#include<iostream>
#include<string>
using namespace std;

class point {
	int x, y;
public :
	void set(int x, int y) { this->x = x, this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};


class colorpoint : public point {
	string color;

public :
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void colorpoint::showColorPoint(){
	cout << color << ":";
	showPoint();
}
/*
int main() {
	point p;
	colorpoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();
}
*/


/*
int main() {
	colorpoint cp;
	colorpoint* pder = &cp;
	point* pbase = pder; // ��ĳ���� ( �Ļ� Ŭ���� �����Ͱ� �⺻ Ŭ���� �����Ϳ� ġȯ)

	pder->set(3, 4);
	pbase->showPoint();

	pder->setColor("Green");
	pder->showColorPoint();
//��������� pbase�� point ������ �����Ƿ�, pder�� ��ӹ��� point �κи� ���� ����
}

*/



//protected ���� ���� 
//���� ������

// private, public, protected




/*
#include<iostream>
using namespace std;

class base {
public:
	virtual void f() {
		cout << "base::f() called" << endl;
	}
};

class derived : public base {
public:
	virtual void f() { cout << "derived::f() called " << endl; }
};

int main() {
	derived d, *pder;
	pder = &d;
	pder->f(); //=> ���⼱ ����Ų��� �� ��ȯ

	base* pbase;
	pbase = pder;
	pbase->f();  //����� ���� �Լ��� ��ǵǾ� �������ε����� ���ο� �Լ� ����
}
// ���� ���ε��̶� �Ļ�Ŭ������ ����, �⺻ Ŭ������ ���� �����ͷ�,
// �����Լ��� ȣ���ϴ� ���
//��ü ���� �������̵��� �Ļ� Ŭ������ �Լ��� ã�� ����
*/



