//#include<list>
//#include<deque>
//#include<map>
//#include<set>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//class Player
//{
//public:
//	virtual void Attack()
//	{
//		cout << "Player" << endl;
//	}
//};
//
//class Knight : public Player
//{
//public:
//	//void Attack() // �׷� �� Attack�� ���ʷ� ����ְ� ��������!? (������Ʈ�� ���� Ŀ���� ����)
//	//{
//	//	cout << "Knight" << endl;
//	//}
//	
//	//void Attack() const //�̷��� �����, Knight�� Attack�� Player�� Attack�� ������ �ڽ��� �����ε� ���� �ൿ��.
//	//{
//	//	cout << "Knight_const" << endl;
//	//}
//
//	//void Attack() override // �̷��� ����� �θ�� ���� ��ӹ����Ŵ�~ ��� �����ϰ� ����.
//	//{
//	//	cout << "Knight_override" << endl;
//	//}
//
//	void Attack() final //�̷��� �����, Knight�� ���������� ���� ��ӹ޴´ٰ� �˷���.
//	{
//		cout << "Knight_final" << endl;
//	}
//};
//
//int main()
//{
//	Knight* knight = new Knight(); 
//	knight->Attack();
//
//	Player* player = new Knight();
//	player->Attack(); //�ص� casting�ϸ� ����� ���� �ִ�. => Player�� ���. ������ Ÿ���� player�̹Ƿ�
//
//	//�׷��Ƿ� �����Լ�ȭ���ش�.
//
//
//	return 0;
//}