//#include<iostream>
//#include<vector>
//#include<list>
//#include<deque>
//#include <map>
//#include <set>
//using namespace std;
////map
//
//class Player
//{
//public:
//	Player() : _playerId(0) {}
//	Player(int playerId) : _playerId(playerId) {}
//
//
//public:
//	int _playerId;
//
//};
//
//template<typename T1, typename T2>
//struct Pair
//{
//	T1 t1;
//	T2 t2;
//};
//
//int main()
//{
//	vector<Player*> v; //������ ���� ���Ϳ� ����Ʈ�� ���� �����̳��� ������.
//					   //=> 10������ �����ߴٰ� ��������.
//
//	for (int i = 0; i < 100000; i++)
//	{
//		Player* p = new Player(i);
//		v.push_back(p);  //��� �����Ҵ����� �����ؼ� ���� �����̳ʿ� �־��ٰ� ��������
//	}
//
//	//5������ �����ߴٰ� ��������
//	for (int i = 0; i < 50000; i++)
//	{
//		int randIndex = rand() % v.size();
//		Player* p = v[randIndex];
//		delete p;
//
//		v.erase(v.begin() + randIndex);
//	}
//	//5������ �幮�幮 �� �����Ŵ�.
//
//	//ID = 2�� �÷��̾ ID = 1�� �÷��̾ �����ϰ� �ʹ�.
//	//Q)�̶� ID=1���� player�� ã���ּ���. 
//	//A) ���� ���ͷ� ã�ƺ��� ������ ������ ���鼭 ã�ƾ��Ѵ�.  ==> searching�� ���� ������ �ִ�.
//
//	//���� �����̳�   --> �о���� ������ ���� �̷����°� �ƴ϶�, ���� ������ �ִ� ������  ����.
//
//	// map : ���� ���� Ʈ�� (AVL)
//	// - ��� ���
//
//	class Node {
//	public:
//		Node* _left;
//		Node* _right;
//
//		pair<int, Player*> _data; //�Ʒ��� �����͵��� �ѹ��� �̷��� �����ϰ� �ִ�.
//		/*int _key;
//		Player* _value;*/
//
//
//
//	};
//	 //[key, map]
//	map<int, int>m;
//
//	//�Ǻ��ϴ� ����
//	pair<map<int, int>::iterator, bool> ok;
//
//	ok = m.insert(make_pair(1, 100));
//	ok = m.insert(make_pair(1, 100)); //�̷��� �ι� �־ �ҿ��� ����, ���� �ٲ㵵 ���� �ٲ��� �ʴ´�.
//	//���� ����ٸ�, �׳� ���õȴ�.
//
//
//	//10������ �����Ű�� 
//	for (int i = 0; i < 100000; i++)
//	{
//		m.insert(pair<int,int>(i, i*100));
//	}
//
//	//5������ ������Ѻ���
//	for (int i = 0; i < 50000; i++)
//	{
//		int randomValue = rand() % 50000;
//
//		//key���� �̿��ؼ� �����غô�
//		m.erase(randomValue);
//
//	}
//
//	// A) �ſ� ������ ã�� �� ����.
//	map<int, int>::iterator findIt =  m.find(10000); //key���� 1���� �ָ� ã�ƺ���~~~~
//	if (findIt != m.end())
//		cout << "ã��" << endl;
//	else
//		cout << "��ã��" << endl;
//
//
//	//map ��ȸ
//	//�����Ͱ� ���ڵ��� �پ� �ִ°� �ƴϴ�.
//	//for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
//	//{
//	//	//(*it) �� �������� ���� ���µ�, �̰� pair<const int, int>& p = (*it) ���� �����̴�.
//	//	int key = (*it).first;     //it->first
//	//	int value = (*it).second;  // p.second��� �ᵵ �ȴ�.
//
//	//	cout << key << " " << value << endl;
//	//}
//
//
//	//���� ������ �߰��ϰ� ������ �����Ѵٰ� ������,
//	//map<int, int> ::iterator it = m.find(300);
//	//if (it != m.end()) {
//	//	(*it).second = 400;
//	//}
//
//	//else
//	//	m.insert(300, 23041);
//
//	//���� ������ �߰��ϰ� ������ �����Ѵٰ� ������ 2��° ���
//	//m[5] = 500; //5��� Ű���� ������, 500�� �־��ش�.
//
//
//	//�߰��� insert(key, value)
//	//������ erase(key)
//	//ã��� find(key);
//	//�ݺ��� map::iterator(*it)pair<key, value>
//
//
//
//
//
//	//**********************************************************
//	//set, multimap, multiset
//
//	//key = value�� ��찡 set�̴�.
//	//set (Ű�� �ܵ������� Ȱ��) -> Ű ��ü�� �������� ���
//	set<int> s;
//	//�ֱ�
//	s.insert(10); //�ٷ� ������ �ֱ� ����
//	s.insert(40);
//	s.insert(30);
//	s.insert(100);
//	s.insert(90);
//	s.insert(80);
//	s.insert(70);
//
//	//�����
//	s.erase(30);
//
//	//ã��
//	set<int>::iterator newit = s.find(100);
//	if (newit == s.end())
//		cout << "����.";
//
//	for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
//	{
//		cout << (*i) << endl;
//	}
//
//
//
//
//
//	//multimap, multiset  ==> map���� �ߺ� Ű�� ����ϴ°� multimap   || set���� �ߺ� Ű�� ����ϴ°� multiset
//	multimap<int, int> mm;
//	mm.insert(make_pair(1, 100));
//	mm.insert(make_pair(1, 200));
//	mm.insert(make_pair(1, 300));
//	mm.insert(make_pair(2, 400));
//	mm.insert(make_pair(3, 500));
//
//	mm.erase(1);  //���� �̷��� �ϸ�, �ϳ��� ��������, �� ��������
//	//�� ��������.
//
//	multimap<int, int>::iterator itFind = mm.find(1);
//	if (itFind != mm.end())
//		mm.erase(itFind);
//	
//	mm.equal_range(1); // iterator�� ������ ��� �ǳ��ְ� �ִ�.
//
//
//	return 0;
//}