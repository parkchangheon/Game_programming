#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Knight
{

};

Knight* FindKnight()
{
	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

//NULLPTR�� ������.

class NullPtr {
public:
	template<typename T>
	operator T* ()const //� Ÿ���� �����Ϳ͵� ġȯ�� ����.
	{
		return 0;
	}

	template<typename C, typename T>
	operator T C::* ()const
	{
		return 0;
	}

private:
	void operator&() const; //�ּҰ��� ���´�.

};

const NullPtr _NullPtr;

int main()
{
	int* ptr = NULL; //define NULL 0
	Test(0);
	Test(NULL); // �̷��� �ϸ� �Ѵ� int a �� �޴� �Լ��� ȣ���Ѵ�.
	// NULL = 0 �̹Ƿ�
	Test(nullptr);

	auto knight = FindKnight();
	if ( knight == nullptr)
	{

	}

	return 0;

}