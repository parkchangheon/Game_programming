#include<iostream>
#include<vector>
#include<string>
#include<string_view>

class spreadsheetCell
{
public:
	//������
	spreadsheetCell() = default;	//����Ʈ ������
	spreadsheetCell(double initialValue);
	spreadsheetCell(const spreadsheetCell& src); //���� ������

	void setValue(double value);
	double getValue() const;

	void setString(string_view inString);
	string getString()const;

private:
	double StringToDouble(string_view InString)const;
	string doubleToString(double value)const;

private:
	double m_value;
};   

class Foo
{
public:
	Foo(double value);

private:
	double m_value{ 5 };

};

class MyClass
{
public:
	MyClass(double value);

private:
	double m_value{ 0 };
	Foo m_foo;
};


class EvenSequence
{
public:
	EvenSequence(initializer_list<double> args)
	{
		if (args.size() % 2 != 0) {
			throw invalid_argument{ "initializer_list should "
			" contain even number of elements" };
		}

		//m_sequence.reserve(args.size()); // reserve�� �뷮 �̸� Ȯ�����̴�.
		//for (const auto& value : args)
		//	m_sequence.push_back(value);
	
		m_sequence.assign(args);
	}

	void dump() const
	{
		for (const auto& value : m_sequence)
		{
			cout << value << " ,";
		}
		cout << endl;
	}

private:
	vector<double> m_sequence;
};
