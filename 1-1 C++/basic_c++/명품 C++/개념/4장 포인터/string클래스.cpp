//��Ʈ�� Ŭ������ Ȱ���� ���ڿ� ���

//string ����ϴ� ����� 2���� ����� �ִ�.
//c-string �� string Ŭ�����̴�.

//1) string Ŭ���� 
//#include<iostream>
//#include<string>
//using namespace std;
//
////2) c-string�� �ʱ⿡ �Ҵ���� �޸� ũ�� �̻��� ���ڿ��� ������ �� ����, ���α׷� �ۼ��� ������� �ִ�
//int main()
//{
//	string str = "I Love ";
//	str.append("C++");
//
//	string* p = new string("win");
//	cout << *p;
//
//	p->append(" the game?");
//	cout << *p;
//	delete p;
//
//}



//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	//string ���
//	string str;
//	string address("����� ");
//	string copyadd(address);
//
//	//c-string
//	char text[] = { 'L','O','V','E' };
//	string title(text);
//
//	cout << str << endl;
//	cout << address << endl;
//	//....
//}



//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string name[5];
//
//	for (int i = 0; i < 5; i++) {
//		cout << "�̸� >> ";
//		getline(cin, name[i], '\n');
//	}
//
//	string latter = name[0];
//	for (int i = 1; i < 5; i++)
//	{
//		if (latter < name[i])
//			latter = name[i];
//	}
//
//}




#include<iostream>
#include<string>
using namespace std;

//int main() {
//	string s;
//
//	cout << "�Ʒ� ���ڿ� �Է�" << endl;
//	getline(cin, s, '\n');
//	int len = s.length();
//
//	for (int i = 0; i < len; i++)
//	{
//		string first = s.substr(0, 1);
//		string sub = s.substr(1, len - 1);
//		s = sub + first;
//		cout << s << endl;
//	}
//}


//int main()
//{
//	string s;
//	cout << "�Է� : " << endl;
//	getline(cin, s, '\n');
//
//	int sum = 0;
//	int startindex = 0;
//
//	while (true) {
//		int findex = s.find('+', startindex);
//		if (findex == -1)
//		{
//			string part = s.substr(startindex);
//			if(part == "")break;
//			cout << part << endl;
//			sum += stoi(part);
//			break;
//		}
//		int count = findex - startindex;
//		string part = s.substr(startindex, count);
//	}
//}