#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator VecIt;
typedef __int64 id;
using id2 = int;

id playerId = 0; //�̷������ε� Ȱ�밡��

typedef void (*MyFunc)();
using MyFunc2 = void(*)();

template<typename T>
using List = std::list<T>;


enum PlayerType
{
	PT_Knight,
	PT_Mage,
	PT_Archer
};

enum MonsterType
{
	/*PT_Knight,*/ // �״�� Ȱ���ϸ�, PlayerType�� ����Ʈ�� �򰥸��� ������ ���� ��
	MT_Knight      // �׷��� �̷������� �տ� ���ڸ� �ٿ��ش�.
};

enum class ObjectType //�̷��� ���� �ٸ� ������ Ŭ�������� ���� �̸��ᵵ ���� ����
{
	//�̸����� ������ ����
	//�Ϲ����� ��ȯ ����. --> double value = ObejctType::Player�̷��� �ȵ� �ҰŸ� static_cast<�ڷ���>
	Player,
	Monster,
	Projectile
};

class Player
{
public:
	virtual void Attack()
	{
		cout << "Player!!" << endl;
	}
};


class Knight : public Player
{
public:
	void Attack() override  //������ override (���� ���ʰ� �ƴ϶� ��ӹ��� �Լ� ������ �ϴ°Ŵ�~) 
	{
		//final�� ����, ���̻� override���� �ʴ´ٴ� ��
		cout << "Knight!!" << endl;
	}
};




Knight* FindKnight()
{
	cout << "FindKnight" << endl;
	return nullptr;
}


void Test(int a)
{
	cout << "TEST(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

class NullPtr
{
public:
	template<typename T>
	operator T* () const {  //�����Ͱ� � �����̶� ġȯ����
		return 0;
	}

	//�� � Ÿ���� ��� �����Ϳ͵� ġȯ����
	template<typename C, typename T>
	operator T C::* ()const
	{
		return 0;
	}

private :
	//void operator&() const; //�ּҰ� ������ ���´�.(���� ��Ÿ��)
	void operator&() const = delete; // �̰� ���� ���뽺Ÿ��

}_NullPtr;


int main()
{
	int* ptr = _NullPtr;   //nullptr ��� ���Ƿ� ����, _NullPtr�� ����!
	Test(0);      //ù��° ���� ���
	Test(NULL);   //ù��° ���� ���
	Test(_NullPtr);// �ι�° ���� ���

	//override final



	auto knight = FindKnight();
	if (knight == _NullPtr)  //�� knight�� == 0�̸� auto�� ���� �߻� ���� ����.
	{
		
	}

	void(Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _NullPtr)
	{

	}

	

	return 0;
}