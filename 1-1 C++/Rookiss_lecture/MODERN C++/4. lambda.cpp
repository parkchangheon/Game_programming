#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare, 
	Unique
};

class Item
{
public:
	Item();
	Item(int itemId, Rarity rarity, ItemType type)
		: _itemId(itemId), _rarity(rarity), _type(type)
	{

	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};



//int main()
//{
//	vector<Item> v;
//	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
//	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
//	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
//	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));
//
//
//
//	
//	{
//		struct IsUniqueItem //�ش� ����ü�� ���������� ���� ����.
//		{
//			bool operator()(Item& item)
//			{
//				return item._rarity == Rarity::Unique;
//			}
//		};
//
//		auto findIt = std::find_if(v.begin(), v.end(), IsUniqueItem()); //�ش� find���� ������ �ɸ� �Լ��� �ѹ��� ���� �Ⱦ�
//		if (findIt != v.end())
//			cout << "������ ID : " << findIt->_itemId << endl;
//	}
//
//
//
//	{
//		int itemId = 4;
//		Rarity rarity = Rarity::Unique;
//		ItemType type = ItemType::Weapon;
//
//		//����(lambda)�� ����ϸ� ���� ������ ����� �� �� �ִ�.!!!
//		//���ٴ� [](){}�� ������ �ϴµ� �Ʒ��� ����
//
//		//Ŭ����(closure) = ���ٿ� ���� ������� ������� ��ü
//		auto IsUniquelambda = [](Item& item) {return item._rarity == Rarity::Unique; }; 
//
//		//[ ] ĸó(capture) : �Լ� ��ü ���ο� ������ �����ϴ� ����� ���� 
//		//�⺻ åó ��� : ��(����) ���(=)  <=>  �������(&)
//		//�����ϴ� �������� ĸó��带 �ٸ��� �� �� �� �ִ�.
//		auto findByItemIdLambda = [=](Item& item) {return item._itemId == itemId; };  //�ܺ��� ���� ���޹޾� itemId�� ��������.
//		auto findByItemIdLambda2 = [&](Item& item) {return item._itemId == itemId; };  //&�� �ٲٸ� =�� ���� �����ϱ�?
//		//&�� ���δٸ�, �޴� �Ű��������� ���, ���� �����̴� (&�� �پ)
//
//		auto findByItemIdLambda3 = [&itemId, rarity, type](Item& item) {return item._itemId == itemId && item._rarity == rarity && item._type == type; };
//		//�� ���ó�� �޴� �Ű������� ��/���� ��� ������ ���� ���� ����.
//
//		itemId = 1;
//
//		auto findIt = std::find_if(v.begin(), v.end(), findByItemIdLambda2); //�ش� find���� ������ �ɸ� �Լ��� �ѹ��� ���� �Ⱦ�
//		if (findIt != v.end())
//			cout << "������ ID : " << findIt->_itemId << endl;
//
//
//		auto findIt2 = std::find_if(v.begin(), v.end(), findByItemIdLambda3); //�ش� find���� ������ �ɸ� �Լ��� �ѹ��� ���� �Ⱦ�
//		if (findIt2 != v.end())
//			cout << "������ ID : " << findIt2->_itemId << endl;
//
//
//
//
//		class Knight
//		{
//		public:
//			auto ResetHpJob() // ���ٴ� � Ÿ������ return ���� ��Ȯ���� �ʾ� auto�� ���ϰ� ó���� ���ش�.
//			{
//				//auto f = []() {_hp = 200; }; // ������ ���� ������ ���     auto f = [this]() {this->_hp = 200; }; �̷����̴�. �̰� knight��ü�� �޾ƿ��⿡ �ǹٸ��� ���� ����̴�. 
//				auto f = [this]() {this->_hp = 200; };
//
//				return f;
//			}
//
//		public:
//			int _hp = 100;
//
//		};
//
//		Knight* k = new Knight();
//		auto job = k->ResetHpJob();
//		delete k;
//		job(); 
//		//�޸� ����
//
//	}
//
//
//
//	return 0;
//}