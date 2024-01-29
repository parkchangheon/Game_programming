#include "VirtualDestructor.h"

VDFirst::VDFirst(const char* str)
{
	strOne = new char[strlen(str) + 1];
}

VDFirst::~VDFirst()
{
	cout << "~First()" << endl;
	delete []strOne;
}

VDSecond::VDSecond(const char* str1, const char* str2) : VDFirst(str1)
{
	strTwo = new char[strlen(str2) + 1];
}

VDSecond::~VDSecond()
{
	cout << "~Second()" << endl;
	delete []strTwo;
}


//int main()
//{
//	VDFirst* ptr = new VDSecond("simple", "complex");
//	delete ptr;
//	return 0;
//}

// ~First �� ȣ���� �ȴ�.
// ��ü �Ҹ��� VDFirst�� �����ͷ� ����Ͽ�, ~First�� ȣ���� �Ȱ�.


// VDSecond�� �޸� ������ �߻��Ѵ�.
// ��ü �Ҹ���������� delete �����ڿ� ���� ������ ������ �ڷ����� ������� ��� �Ҹ��ڰ� ȣ��Ǿ���.
// �̸� ���ؼ� �Ҹ��ڿ� virtual ������ �߰��ؾ��Ѵ�.

// delete�� VDFirst �����Ϳ��� ����.
// ������ virtual �̹Ƿ�, ~VDSecond�� ȣ��

//~VDSecond�� ����ǰ�, ~VDFirst�� �����.


