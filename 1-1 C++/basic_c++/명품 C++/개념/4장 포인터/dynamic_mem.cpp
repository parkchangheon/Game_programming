//�޸� �Ҵ� �� ��ȯ

//�޸� �Ҵ�.
//�Ϲ������δ� ���α׷� �ۼ� �ܰ迡�� �ʿ��� �޸𸮸� Ȯ���ϱ� ���� ����, ��ü, �迭�� �������� �����Ѵ�.
//�׷��� ���� �߿� �ʿ��� ��ŭ �޸𸮸� �Ҵ� �ް� �ʿ� ������ ��ȯ�ϴ� ���� �޸� �Ҵ� ��ȯ ��Ŀ������ �ʿ��ϴ�.

//new�� delete �����ڸ� ����Ѵ�.

//���� �Ҵ� => �������� �����.


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

//#include<iostream>
//using namespace std;
//
//
//int main()
//{
//	int* p;
//	
//	p = new int;
//	if (!p){
//		cout << "�޸� �Ҵ� �Ұ���.";
//		return 0;
//	}
//
//	*p = 5;
//	int n = *p;
//	cout << "*p = " << *p << endl;
//	cout << "n = " << *p << endl;
//
//	delete p;
//}

class Circle {
	int r;
public:
	Circle() {};
	Circle(int r) {};
};





// �迭�� ���� �Ҵ� �� ��ȯ
//�ڷ��� *�����ͺ��� =  new �ڷ���[�迭�� ũ��]
//delete[] �����ͺ���
#include<iostream>
using namespace std;
int main() {

	////�迭�� �ʱ�ȭ�� �Ұ����ϴ�.
	////int* Array = new int[10](20);
	//int* Array = new int[] { 10, 20, 30, 40 }; //������ �̿Ͱ��� �ʱ�ȭ�� �����ϴ�.

	//int *arr = new int[3];
	//if (!arr)
	//	return;

	//for (int i = 0; i < 3; i++) {
	//	cout << arr[i] << endl;
	//}

	//delete[] arr;

	Circle* ArrCircle = new Circle;   //������ Circle() ȣ��
	Circle* ArrCircle2 = new Circle(30); // ������ Cricle(30) ȣ��

	delete ArrCircle;
	delete ArrCircle2;


	
}