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
//
//class Knight
//{
//public:
//	Knight()
//	{
//		cout << "basic inti" << endl;
//	}
//
//	Knight(int a, int b) {
//		cout << a << "," << b << endl;
//	}
//
//	Knight(initializer_list<int> li)  
//	{
//		cout << "initializer_list inti" << endl;
//	}
//};
//
//
//int main()
//{
//	//�߰�ȣ �ʱ�ȭ
//	int a = 0;
//	int b(0);
//	int c = { 0 };
//
//	Knight k1;
//	Knight k2 = k1; //���Կ����� x 
//	Knight k3; 
//	k3 = k1; //���Կ�����o
//
//	//1) �����̳ʿ͵� �߾�︲
//	int arr[] = { 1,2,3,4 };
//	vector<int> v2(10, 1); //���� �ʱ�ȭ 
//	vector<int> v3{ 1,2,3,4 };
//
//	//2)
//	int x = 0;
//	double y(x); //�̷��� �����ص� ������ ���µ�, ������ ȣȯ�Ǵ°� �ƴ϶� ������ �ս��� �����ϴ�.
//	//==>
//	double y{ x };
//
//	//3)
//	Knight k4{};
//	Knight k5{ 1,2,3,4,5 };  //�̷��� �޾��ְ� �ʹٸ� ��� �ؾ��ұ�? ==> ��ó�� initializer_list�� �޾��ش�.
//
//	//ex) 
//	Knight k_test{ 1,2 }; //�̷��� �ϸ� ���� �����ڴ� ����� ȣ��ɱ�. initializer_list�ϱ�? or int int �ϱ� 
//	//==> initializer_list�� �켱���� ��������. (�ٵ� �ٸ� �����ڸ� ����������, initializer_list�� �Ա⿡ ���� ���� �ʴ�.)
//
//
//	return 0;
//}