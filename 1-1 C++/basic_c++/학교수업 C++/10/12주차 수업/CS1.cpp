
//#include<iostream>
//using namespace std;
//
//int main() {
//	//===================������ ����
//	//short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 }; // short�迭.
//	//int* pI = (int*)sArr; //���� ĳ�����ؼ� int �����ͷ� ����.
//	//int iData = *((short*)(pI + 2));
//	//printf("1�� ���� ���� : %d \n", iData);
//
//	//char cArr[2] = { 1,1 };
//	//short* pS = (short*)cArr;
//	//iData = *pS;
//
//	//printf("2�� ���� ���� : %d\n", iData);
//	//return 0;
//
//
//	//=============================
//
//	const int cint = 100;
//	// ���ȭ ���״�. ���� �Ұ�
//
//	int a = 0;
//	int* pInt = &a;
//
//	*pInt = 1;
//	pInt = nullptr;
//
//	int b = 0;
//	const int* pConstInt = &a;
//	// ����Ű�� �ִ� ���� ������ ���ȭ�ѰŴ�
//	//*pConstInt =100;�� �Ұ����ϴ�.
//	pConstInt = &b; // ������ �ٸ����� ����Ű�°� ����
//
//
//	int* const pIntConst = &a; 
//	// �����Ͱ� ����Ű�� �ִ� �ּҸ� ���ȭ
//	*pIntConst = 400;
//	//pIntConst = &b; 
//
//}



//10-16
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Shape {
//protected:
//	virtual void draw() = 0;
//public:
//	void paint() {
//		draw();
//	}
//};
//
//class Circle :public Shape {
//protected:
//	virtual void draw() { cout << "Cirlce" << endl; }
//};
//
//
//class Rect :public Shape {
//protected:
//	virtual void draw() { cout << "Rectangle" << endl; }
//};
//
//
//class Line :public Shape {
//protected:
//	virtual void draw() { cout << "Line" << endl; }
//};
//
//
//
//
//int main() {
//	int selector;
//
//	vector<Shape*> v;
//	vector<Shape*>::iterator it;
//
//	cout << "�׷��� �������Դϴ�." << endl;
//	while (true) {
//		cout << "���� :1, ����:2, ��κ���:3, ����:4 >>";
//		cin >> selector;
//		switch (selector) {
//		case 1: {
//			int n;
//			cout << "��:1, ��:2, �簢��:3 >> ";
//			cin >> n;
//
//
//			switch (n) {
//			case 1:
//				v.push_back(new Line());
//				break;
//
//			case 2:
//				v.push_back(new Circle());
//				break;
//
//			case 3:
//				v.push_back(new Rect());
//				break;
//
//			default:
//				cout << "�߸��� �����Դϴ�." << endl;
//				break;
//			}
//			break;
//		}
//
//		case 2: {
//			int n;
//			cout << "�����ϰ��� �ϴ� ���� �ε��� >>";
//			cin >> n;
//			if (n > v.size() || n < 0) { // ����ó��
//				cout << "�ε��� �Է� ����" << endl;
//				break;
//			}
//			it = v.begin();
//			v.erase(it + n);
//			break;
//		}
//
//
//		case 3: {
//			int i = 0;
//			for (it = v.begin(); it != v.end(); it++, i++) {
//				cout << i << ": ";
//				v.at(i)->paint();
//			}
//			break;
//		}
//		case 4:
//			return 0;
//
//		default:
//			cout << "�߸��� ����Դϴ�." << endl;
//			break;
//
//		}
//	}
//}




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int myints[] = { 10,20,30,40 };
	int* p;

	p = find(myints, myints + 4, 30);
	if (p != myints + 4)
		cout << "���� ã���� �ϴ� ���� " << *p << " �̴�" << endl;
	else
		cout << "���� ã���� �ϴ� ���� ����." << endl;

	vector<int> v(myints, myints + 4);
	vector<int>::iterator it;

	it = find(v.begin(), v.end(), 50);
	if (it != v.end())
		cout << "���� ã���� �ϴ� ���� " << *it << endl;
	else
		cout << "���� ã���� �ϴ� ���� ����" << endl;
	return 0;
}

// find(start,end) �� start~end ���� ���� �˻��� �����Ѵ�.
// ���� find�� start~end ���̿��� 30���� Ž���Ѵ�
// ���� ã�� ���� ���ٸ� ���ǹ����� 0�� ��ȯ�Ѵ�.


//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	vector<int>v = { 1,2,3,4,5,6,7,8,9 };
//
//	for (auto& n : v) {
//		cout << n << ",";
//	}
//	cout << endl;
//
//	reverse(v.begin(), v.end());
//
//	for (auto& n : v)
//	{
//		cout << n << ",";
//	}
//	cout << endl;
//	
//
//}




//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	vector<int>v = { 1,4,2,6,8,3,5,7,9 };
//
//	for (auto& n : v) {
//		cout << n << ",";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end());
//
//	for (auto& n : v)
//	{
//		cout << n << ",";
//	}
//	cout << endl;
//
//
//}



//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main() {
//	vector<int> v;
//	v.push_back(3);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(3);
//
//	size_t n = count(v.begin(), v.end(), 3);
//	cout << n;
//
//}



//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main() {
//	vector<int>v = { 1,2,3,4,5,6,7,8,9 };
//	vector<int>w = { 0,0,1,1,1,1,1 };
//	
//
//	copy(v.begin()+2,v.begin()+5,w.begin());
//
//	for (int i = 0; i < (int)w.size(); i++)
//		printf("%d ", w[i]);
//}
