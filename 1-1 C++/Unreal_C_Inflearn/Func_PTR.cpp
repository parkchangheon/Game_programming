#include<iostream>
using namespace std;


int Add(int a, int b) 
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Knight {
public:
	//����Լ�
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	};
public:
	int _hp;
};

typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];
typedef int(*PFUNC)(int, int); //�Լ� ������
typedef int(Knight::* PMEMFUNC)(int, int); //��� �Լ� ������



class Item 
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId; // �������� �����ϱ� ���� ID
	int _rarity; // ��͵�
	int _ownerId; // ������ ID
};

Item* FindItemByItemId(Item items[], int itemCount, int itemId)
{
	//���� üũ

	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		//TODO ���� 
		if (item->_itemId == itemId)
			return item;
	}
	return nullptr;
}

//�̷��� ������ �ؼ� �Ű������� _itemId, _rarity, _ownerId ����� ����� �ָ�,
//Item* FindItemByRarity(Item items[], int itemCount, int rarity) �� ���� ���� ������ ��������
//�̷��� ���������� ��Ʊ� ������ �̸� �����ϱ� ���� ������ ���� ó���� ���ش�.

typedef bool(ITEM_SELECTOR)(Item* item, int);

//�Ϸ��� ó���� ���ֱ� ���� �Լ��� ���ڷ� �޴´�. -> Main���� ���ӻ� Ȯ���ϱ�
Item* FindItem(Item items[], int itemCount, /*�Լ�*/ ITEM_SELECTOR* itemSelector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (itemSelector(item, value))
			return item;
	}
	return nullptr;
}

bool IsRareItem(Item* item, int )
{
	return item->_rarity >= 2;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;
	//int* Pointer = &a;

	typedef int DATA;
	DATA* Pointer = &a;

	//�Լ�
	/*int Add(int a, int b);*/
	typedef int(FUNC_TYPE)(int , int );
	using FUNC_TYPE2 = int(int a, int b); //���� ������ �Լ���.

	//1) ������
	//2) ���� �̸�
	//3) ������ Ÿ��
	FUNC_TYPE* fn;
	fn = Add; // ���� SUB�� ����ٸ�, �� �Լ� �����͸� �ٲپ� SUB�� ��ä

	//�Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = Add(1, 2);
	cout << result << endl;

	int result2 = fn(5, 5);
	cout << result2 << endl;

	int result3 = (*fn)(5, 5);
	cout << result3 << endl;

	Item items[10] = {};
	items[3]._rarity = 2;
	FindItem(items, 10, IsOwnerItem, 100);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp;
	(k1.*mfn)(1, 1);

	Knight* k2 = new Knight();
	
	(*k2.*mfn)(1, 1);

	delete k2;

	return 0;
}


//int main()
//{
//	//���
//	int (*fn)(int, int);
//	fn = Add;
//	fn(1, 2);
//}