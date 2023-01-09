#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Knight {
public:
	Knight() { cout << "�⺻ ������" << endl; }
	Knight(const Knight& knight) { cout << "���� ������" << endl; };
	Knight(Knight&&)noexcept { cout << "�̵� ������" << endl; };
};

void Test_RValueReference(Knight&& knight)
{

}

template<typename T>
void Test_ForwardingRef(T&& param)    //���������̴�. (�ް��� ������ �ް�, �������� ������ ������) ������ const T&& param �Ǵ� ���� ������ ����ó�� ���ȴ�.
{
	//�Ʒ� �� ����� �˾Ƽ� �ڵ����� ����. (�ް� ������ ����, ������ ������ �̵� ����~ 
	TestCopy(std::forward<T>(param));
	
	//TestCopy(param); //�ް����� ver ( ���� ) 
	//TestCopy(std::move(param)); //������ ���� ver ( �̵� )

}

void TestCopy(Knight&& knight)
{


}


int main()
{
	//���� ���� ( universal_reference)
	//���� ���� (forwarding_reference)  c++17

	Knight k1;
	Test_RValueReference(std::move(k1));
	Test_ForwardingRef(std::move(k1));
	Test_ForwardingRef(k1); //������ �ȵɰŰ����� �ȴ�!!?    ==> ������ template�� �޾��ֱ� ����

	auto&& k2 = k1;   //�굵 �ް��̴�.
	auto&& k3 = std::move(k1); //��� �������̴�.


	Knight& k4 = k1;             //�ް�����
	Knight&& k5 = std::move(k1); //������ ����


	//������ : �ް��� �ƴ� �� = ���ϽĿ��� ����� ����� �Ұ����ϴ�.
	//������ ���� : �������� ������ �� �ִ� ���� Ÿ��
	Test_RValueReference(std::move(k5));  //k4, k5 �Ѵ� �ȵȴ�? ==> k4�� ���� �ް��̱� ������ �翬�� �ȵǴµ�, k5�� �� �ȵɱ�?
	//k5�� ������ ���� Ÿ���̱� �ѵ�, ���Ͻ��� ����� ����� �����ϴ�.... �ᱹ ������ ���� Ÿ���̱��ѵ�, k5 ��ü�� �ް��̶�� ������ �ִ�. 
	//�׷��� std::move�� �޾�����Ѵ�...



}