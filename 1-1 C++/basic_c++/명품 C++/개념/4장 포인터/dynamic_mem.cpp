//�޸� �Ҵ� �� ��ȯ

//�޸� �Ҵ�.
//�Ϲ������δ� ���α׷� �ۼ� �ܰ迡�� �ʿ��� �޸𸮸� Ȯ���ϱ� ���� ����, ��ü, �迭�� �������� �����Ѵ�.
//�׷��� ���� �߿� �ʿ��� ��ŭ �޸𸮸� �Ҵ� �ް� �ʿ� ������ ��ȯ�ϴ� ���� �޸� �Ҵ� ��ȯ ��Ŀ������ �ʿ��ϴ�.

//new�� delete �����ڸ� ����Ѵ�.

//����

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// �ڷ��� *�����ͺ��� = new �ڷ���
//	int* pInt = new int; 
//	char* pChar = new char;
//	//Circle* pCircle = new Circle();   Ŭ���� Ÿ���� ��ü�Ҵ�.
//
//	delete pInt;
//	delete pChar;
//
//	//������ Ÿ���� ũ�⸸ŭ �����κ���, �޸𸮸� �Ҵ�ް� �ּҸ� �����Ѵ�.
//
//
//	int* p = new int;
//	if (!p) {
//		return;
//	}
//
//	*p = 5;
//	int n = *p;
//	delete p;
//
//
//	int* pInt = new int(2);  //2�� �ʱ�ȭ�� int ���� �Ҵ�.
//	char* pchar = new char('a');


	// *********** ���ǻ��� ***************

	//delete�� �޸� ��ȯ�� �������� ���� ������ ���� ���� ������ �߻���.
	
	//int n;
	//int* p = &n;
	//delete p; //p�� �����Ҵ��� ������ �ƴ�.

	//int* p = new int;
	//delete p;
	//delete p; //�ߺ� ��ȯ �Ұ�.



//}

#include<iostream>
using namespace std;


int main()
{
	int* p;
	
	p = new int;
	if (!p){
		cout << "�޸� �Ҵ� �Ұ���.";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << *p << endl;

	delete p;
}
