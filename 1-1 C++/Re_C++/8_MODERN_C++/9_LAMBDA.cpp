#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable,
};

enum class Rarity
{
	Common,
	Rare,
	Unique,
};


class Item
{
public:
	Item() {}
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type){}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));  //���������� �޾��ְ� �ִ�
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));




	//���ٴ� �Լ� ��ü�� �ս��� ����� ����̴�.
	{
		struct IsUniqueItem    //�Լ���ü�� �Լ� �����ͺ��� ������ �����͸� ������ �� �ִ�.
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		struct FindItemByItemId
		{
			FindItemByItemId(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId;
			}


			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};
	}



	int itemId = 4;
	//Ŭ����(closure) : ���ٿ� ���� ������� ������� ��ü
	auto isUniqueLambda = [](Item& item) {return item._rarity == Rarity::Unique; }; //����ǥ����
	//�⺻ ĸ�� ��� : �������(&) vs ������(=)
	auto FindItemByItemId = [=](Item& item) {return item._itemId == itemId; };   //[] capture : �Լ� ��ü ���ο� ������ �����ϴ� ����� ����. (�Լ� �ܺο� �ִ� �ָ� ���ٰ� �� �� �ִ�.)
	auto FindItemByItemId2 = [&](Item& item) {return item._itemId == itemId; };   //�� ����ü���� int -> int&�� ���ٰ� �����ض� �� item�� �ּҰ����� Ȱ���ϰ� �ִ�.
	
	//�׸��� ��ó�� &, = �� ���ִ� �� �� ������, ����� ���� ���Ǿ����� �˱� ���� �Ʒ��� ���� ���ִ°͵� ������ ����̴�.
	auto FindItemByItemId2 = [&itemId](Item& item) {return item._itemId == itemId; };   



	auto findit = std::find_if(v.begin(), v.end(), FindItemByItemId);
	if (findit != v.end())
	{
		cout << "������ ID : " << findit->_itemId << endl;
	}

	



	return 0;
}