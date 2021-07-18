//6-1��
/*
#include<iostream>

using namespace std;

int add(int* a, int b ,int *c=NULL) {
	int hap = 0;
	for (int i = 0; i < b; i++) {
		hap += a[i];
		if (c != NULL)
			hap += c[i];
	}
	return hap;
}


int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };

	int c = add(a, 5);
	int d = add(a, 5, b);

	cout << c << endl;
	cout << d << endl;

}

*/

//6-2��
/*
#include<iostream>
using namespace std;

class Person {
	int id;
	double weight;
	string name;
public:
	Person(int a, string b, double c );
	void show() { cout << id << ' ' << weight << ' '<<name << endl; }
};

Person::Person(int a= 1, string b="Grace",double c=20.5){
	this->id=a;
	this->name = b;
	this->weight = c;
}

int main() {
	Person grace, ashely(2, "Ashely"), helen(3, "Helen", 32.5);
	grace.show();
	ashely.show();
	helen.show();
}
*/




//6-3
/*
#include<iostream>
using namespace std;

int big(int a, int b, int c=NULL) {
	int m;
	m = a > b ? a : b;
	if (c != NULL)
		m = (m > c ? m : c);
	return m;
}

int main() {
	int x = big(3, 5);
	int y = big(300, 6);
	int z = big(30, 60, 50);

	cout << x << ' ' << y << ' ' << z;
}

*/



//6-5
/*
#include<iostream>
using namespace std;

class ArrayUtility {
public:
	static void intToDouble(int source[], double dest[], int size);
	static void doubleToInt(double source[], int dest[], int size);

};


void ArrayUtility::intToDouble(int source[], double dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = (double)source[i];
	}
}

void ArrayUtility::doubleToInt(double source[], int dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = (int)source[i];
	}
}



int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9,8.8,7.7,6.6,5.5 };
	
	ArrayUtility::intToDouble(x, y, 5);
	for (int i = 0; i < 5; i++)
		cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5);
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << endl;
}

*/




//6-6
/*
#include<iostream>

using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};



int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* tot = new int[size];
	for (int i = 0; i < size / 2; i++) {
		tot[i] = s1[i];
	}

	for (int i = size / 2,j=0; i < size; i++,j++) {
		tot[i] = s2[j];
	}

	return tot;
}


int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* rmtot = new int[size/2];
	int cnt;

	for (int i = 0; i < size/2; i++) {
		cnt = 0;
		for (int j = 0; j < size / 2; j++) {
			if (s1[i] == s2[j]) {
				cnt++;
			}
		}
		if (cnt == 0) {
			rmtot[i] = s1[i];
			retSize++;
		}
	}
	if (retSize == 0)
		return NULL;
	return rmtot;
}


int main() {
	int arr[5];
	int arr2[5];

	int size = 0, retSize = 0;

	int* p;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++) {
		cin >> arr2[i];
	}
	
	size = (sizeof(arr) + sizeof(arr2))/sizeof(int);
	cout << "��ģ ���� �迭�� ����Ѵ�.";

	p = ArrayUtility2::concat(arr, arr2, size);
	for (int i = 0; i < size; i++) {
		cout << p[i]<<' ';
	}

	cout << endl << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ ";
	p = ArrayUtility2::remove(arr, arr2, size, retSize);
	cout << retSize << endl;
	for (int i = 0; i < retSize; i++) {
		cout << p[i]<<' ';
	}
}
*/



//6-7
/*
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); } // ���� �߻� �õ�.
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min = 0, int max = 32767) {
	int a = 0;
	while (true) {
		a = rand() % (max + 1);
		if (min <= a)
			break;
	}
	return a;
}

char Random::nextAlphabet() {
	char b = 0;
	while (true) {
		b = rand() % 'z';
		if (b >= 'a' || ('A' <= b && b <= 'Z'))
			break;
	}
	return b;
}

double Random::nextDouble() {
	double c = 0;
	double max = 32767;
	c = rand() / max;
	return c;
}

int main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�\n";

	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100) << ' ';
	}

	cout << endl << "���ĺ��� �����ϰ� 10���� ����մϴ�\n";

	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << ' ';
	}

	cout << endl << "������ �Ǽ��� 10���� ����մϴ�\n";

	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
		if (i == 4) cout << endl;
	}
}
*/



//6-8
/*
#include<iostream>
#include<string>
using namespace std;

class Trace {
public:
	static string tagInf[100];
	static string debugInf[100];
	static int count;
	static void put(string tag, string debug);
	static void print(string tag="all");
};

int Trace::count = 0;
string Trace::tagInf[100];
string Trace::debugInf[100];

void Trace::put(string tag, string debug){
	tagInf[count] = tag;
	debugInf[count] = debug;
	count++;
}

void Trace::print(string tag) {
	if (tag == "all") {
		cout << "----��� Trace ������ ����մϴ�. ----\n";
		for (int i = 0; i < count; i++) {
			cout << tagInf[i] << ":" << debugInf[i] << endl;
		}
	}

	else {
		cout << "----" << tag << "�±��� Trace ������ ����մϴ�. ----\n";
		for (int i = 0; i < count; i++) {
			if (tagInf[i] == tag)
				cout << tagInf[i] << ":" << debugInf[i] << endl;
		}
	}
}

void f() {
	int a, b, c;
	cout << "�ΰ��� ������ �Է��ϼ���>>";
	cin >> a >> b;

	Trace::put("f()" ,"������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");

	cout << "����" << c << endl;

}

int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");
	Trace::print();
}

*/




//6-9

/*
#include<iostream>
#include<string>
using namespace std;

class Board {
public:
	static string* str;
	static int count;
	static void add(string s); // static ���ֱ�
	static void print(); //static ���ֱ� 
};

int Board::count = 0;
string* Board::str = new string[100];


void Board::add(string s) {
	str[count]=s;
	count++;
}

void Board::print() {
	cout << endl << "*************�Խ����Դϴ�****************"<<endl;
	for (int i = 0; i < count; i++)
		cout << str[i]<<endl;
}



int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�");
	Board::add("�ڵ������ ���� �̿����ּ���");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ�� �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}
*/






