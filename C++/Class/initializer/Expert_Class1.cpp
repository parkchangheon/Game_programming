#include "Expert_Class1.h"

using namespace std;

int main()
{

}

spreadsheetCell::spreadsheetCell()
{
	m_value = 0;
}

spreadsheetCell::spreadsheetCell(double initialValue) : m_value{initialValue}
{

}

spreadsheetCell::spreadsheetCell(const spreadsheetCell& src)
{


}

void spreadsheetCell::setValue(double value)
{
	m_value = value;
}

double spreadsheetCell::getValue() const
{
	return m_value;
}

void spreadsheetCell::setString(string_view inString)
{
	m_value = StringToDouble(inString);
}

string spreadsheetCell::getString() const
{
	return doubleToString(m_value);
}

double spreadsheetCell::StringToDouble(string_view InString) const
{
	double number = 0;

	return number;
}

string spreadsheetCell::doubleToString(double value) const
{
	return to_string(m_value);
}


// ************ Foo && MyClass Class ************

Foo::Foo(double value) : m_value{value}
{
	cout << "Foo : m_value : " << m_value << endl;
}

MyClass::MyClass(double value) : m_value(value), m_foo{ m_value }
{
	cout << "MyClass::m_value = " << m_value << endl;
	// int main() { 1.2 }; ������,
	// 	Foo : 1.2
	// 	MyClass 1.2
	// �� ��밡 �ǳ�, �̰� ������ �ʱ����� ������ �ƴ�, Ŭ������ ���� ����.
	// ���� ������ �޶����ٸ�, ������ ���� ���� �� �� �ִ�.

	// �Ϲ����� ��� ���� �Ҵ��ϴ� �������� ��ü�� �̹� ������ ������ �ٲ�.
	// ������ �ʱ����� ���, ������ ����� �����ϴ� �������� �ʱⰪ�� ���� ����
	// ==> ���� �����ϴ� ��ĺ��� �� ȿ����.

}


