//�����Լ�
//
//��ӹ��� Ŭ�������� ������ �Ұ����� ����ϰ�, �θ� Ŭ�������� �����س��� �Լ��̴�.
//virtual ���� �ɾ���� ������ �����ϴ�.
//������ �����Ѽ��� �Ļ� Ŭ�������� ������ �ϸ�, ������ ���ǵǾ��� ������� ��� ���Ӱ� ������ �������� ��ü�Ѵ�.
//
//�����Ϸ��� �Լ��� ȣ���� ��, �ſ� ������ ������ ��ġ�� �Ǵµ�, �����Ϸ��� �Լ��� ȣ���ϴ� �ڵ带 ������ Ÿ�ӿ�
//������ �޸� �ּҷ� ��ȯ�Ѵ�. ==> ���� ���ε�
//�Ϲ� �Լ��� ��� ���� ���ε��� �Ѵ�.
//
//�Ϲ��Լ��� �����ε��ϰ� �ȴٸ�, �������ε����� ���� ������ ���� �� �ִ�.
//
//�����Լ��� �ƴ� ������ ���, �θ�Ŭ������ �����ͷ� ����Լ��� ȣ���Ҷ�, �����Ϸ��� ���� Ÿ���� ����
//�� Ÿ�Կ� �´� ����Լ��� ȣ���Ѵ�.


//#include<iostream>
//using namespace std;
//
//class Parent {
//public:
//	void print() {
//		cout << "�̰��� parent �Դϴ�." << endl;
//	}
//};
//
//class Child : public Parent{
//public:
//	void print() {
//		cout << "�̰��� child �Դϴ�." << endl;
//	}
//};
//
//
//void main() {
//	Parent* p = new Parent;
//	Child* c = new Child;
//
//	p->print();
//	p = c;
//	p->print();
//}

// �̷� ��� parent�� 2�� ȣ��ȴ�.


//===========================

//#include<iostream>
//using namespace std;
//
//class Parent {
//public:
//	virtual void print() {
//		cout << "�̰��� parent �Դϴ�." << endl;
//	}
//};
//
//class Child : public Parent {
//public:
//	virtual void print() {
//		cout << "�̰��� child �Դϴ�." << endl;
//	}
//};
//
//
//void main() {
//	Parent* p = new Parent;
//	Child* c = new Child;
//
//	p->print();
//	p = c;
//	p->print();
//}
//parent, child ������ ����� �ȴ�.




#include<iostream>
using namespace std;

class Parent {
public:
	virtual void func1() {
		cout << "�̰��� parent func1 �Դϴ�." << endl;
	}

	virtual void func2() {
		cout << "�̰��� parent func2 �Դϴ�." << endl;
	}

	void func3() {
		cout << "�̰��� parent func3 �Դϴ�." << endl;
	}
};

class Child : public Parent {
public:
	virtual void func1() {
		cout << "�̰��� child func1 �Դϴ�." << endl;
	}
};


void main() {
	Parent* p = new Parent;
	Child* c = new Child;

	p->func1();
	c->func1();

	p->func2();
	c->func2();

	p->func3();
	c->func3();
}