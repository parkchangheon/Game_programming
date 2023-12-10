#include<iostream>

using namespace std;

class Base
{
public:
	virtual ~Base() = default;

public:
	string name;
};

class Derived : public Base
{
public:
	virtual ~Derived() = default;

public:
	string d_name;
};


int main()
{
	Base* base = nullptr;
	Derived* derived = new Derived();

	base = derived;
	base->name = "baseClassName";
	//base->d_name = "DerivedClassName";	Base�� derived ����� ������ �� ����.
	
	derived = static_cast<Derived*>(base);

	derived->d_name = "DerivedClassName";
	cout << derived->name << " and " << derived->d_name;

	
	//ps
	Base* base2 = new Base();
	Derived* derived2 = static_cast<Derived*>(base2);

	
	//����1
	//������ Ÿ�ӿ��� ������ ��������, ��Ÿ�ӿ����� ũ���ð� �� �� �ִ�.	(��ü ������ ��� ������ �޸𸮸� �����) ==> Dynamic_cast�� ����ؾ��Ѵ�.
	//cout << derived2->d_name;	//Crash!
	//cout<< derived2->d_name;	//Crash!

	//����2
	//double* dou = new double(3.15);
	// int* integer = dou;
	// int* integer3 = static_cast<int*>(dou); �� 2���� ���ʿ� ���� �ȵ�.

	// int* integer2 = (int*)(dou); //����� ����ȯ���� �ٲٱ� ������, ���� �ȵǴ� ������� ����.
}