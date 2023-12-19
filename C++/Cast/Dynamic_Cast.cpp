/* 
* dynamic casting�� ���� ��Ӱ��� ���ο��� ĳ��Ʈ�� ���� ����ð� �˻縦 �����Ѵ�
* Ptr / Ref �� ĳ��Ʈ�Ҷ� �̿밡��
* dynamic_cast�� ����ð��˻縦 �����Ѵ�.
* Ptr�� ���ؼ� ĳ������ �������� ������ => nullptr��
* Ref�� ���ؼ��� std::bad_cast �ͼ����� �߻��Ѵ�.

*/



#include<iostream>
using namespace std;

class Base
{
public:
	virtual ~Base() = default;
};

class Derived : public Base
{
public:
	virtual ~Derived() = default;
};

int main()
{
	Base* b;
	Derived* d = new (Derived);

	b = d;

	d = dynamic_cast<Derived*>(b);
}