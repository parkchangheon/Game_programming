//�߸��� ������ �� of Singleton

//#include<iostream>
//using namespace std;
//class Singleton {
//private:
//	static Singleton s; 
//
//public:
//	static Singleton& getInstace() {
//		return s;
//	}
//};
//
//
//Singleton Singleton::s;  //���������ν� �ʱ�ȭ
//
//int main() {
//	Singleton& s = Singleton::getInstace();
//	return 0;
//}

//������, ���������, �Ҹ��ڸ� private ó���� ������ x 
//==> �̷� ��쿡 static ��ü�� ���簡 �Ǿ� ����ϴ� �ǹ̸� �Ҿ������.
// 
// ���� �ʱ�ȭ 
//���α׷��� ���۰� ���ÿ� �ʱ�ȭ �Ǵ� ���� �����Ͽ�, ����ڰ� ���ϴ� ������ ��ü�� �ʱ�ȭ�� ���ִ� ��!!
//ex)
//static int num1 = 0;
//static int num2 = 0;
//static int num3 = 0;
//static int num4 = 0;
//static ���� ���� ���������� �������̷� ������ �Ǿ �ʱ�ȭ �Ǵ� ������ �����̴�.
// �������� ������� �ʱ�ȭ �Ǿ �����δ� ��� ���� ���� ��!


#include<iostream>
using namespace std;
class Singleton {
private:
	static Singleton s;

public:
	static Singleton& getInstace() {
		return s;
	}
};

class A {
public:
	A() {
		Singleton& s = Singleton::getInstace();
	}
};


Singleton Singleton::s;  //���������ν� �ʱ�ȭ

int main() {
	Singleton& s = Singleton::getInstace();
	return 0;
}



////////////////////////////////////////////////////////////////


//���������
//���� ���� => ���� �Ҵ� ���� ������ �ּҰ��� �����Ѵ�.
//���� ���� => ������ �����Ҵ��� �ް�, ������ ������ ���� ����.

//��ü�� ���簡 �̷������ ȣ��Ǵ� ������.


//����

//#include<string>
//using namespace std;
//
//class ChangHeon {
//
//	int age;
//	string name;
//protected:
//	string DNA;
//
//public:
//	ChangHeon(); //�������̰�
//	ChangHeon(int age, string name, string DNA);
//	~ChangHeon();
//
//	ChangHeon(ChangHeon& dRef);   //���Ⱑ ����������̴�.
//
//	//setter method
//	void setAge(int age) { this->age = age; }
//	void setName(string name) { this->name = name; }
//	void setDNA(string DNA) { this->DNA = DNA; }
//
//	//getter method
//	int getAge() { return age; }
//	string getName() { return name; }
//	string getDNA() { return DNA; }
//
//	ChangHeon* getSelf() { return this; }
//
//	void showInfo();
//	void grow(int age);
//	void shit(string food);
//};
//
//
//ChangHeon::ChangHeon(ChangHeon& dRef) {
//	name = dRef.getName();
//	age = dRef.getAge();
//	DNA = dRef.getDNA();
//
//	cout << name << "�̰� ����Ǿ���." << endl;
//}




//�̱��� ���� -> �ϳ��� �ν��Ͻ��� �����Ͽ� ����ϴ� ������ ����

//�����ڰ� ������ ȣ��ǵ� ������ �����Ǵ� ��ü�� �ϳ��̴�.
//���ʷ� ������ ���Ŀ� ȣ��� �����ڴ� �̹� ������ ��ü�� ��ȯ�Ѵ�.


//�޸� ���� ���� ����. => �ѹ��� new�� ���� ��ü�� �����Ѵٸ� �޸� ����
//�̱��� ������ �ν��Ͻ��� '����'  => �ٸ� Ŭ������ �ν��Ͻ����� �����͸� ��������

//���� ����ϴ� ����, ����� ��ü�� ������ �����ؼ� ����ϴ� ��Ȳ�� ����
//DB���� Ŀ�ؼ�Ǯ, ������Ǯ, ĳ��, �α� ��� ��ü ��.
//AOS : �� ��Ƽ��Ƽ���̳�, Ŭ�������� �ֿ� Ŭ�������� �ϳ��ϳ� �����ϴ°� ���ŷӱ� ������ �̱��� Ŭ������ ����� ��𼭵� �����ϵ��� ����
//Ȥ�� �ν��Ͻ��� �������� �ϳ��� ��°��� �����ϰ� ���� �� ���.


//���� ��� ��Ģ : �������⿡�� �̱��� �ν��Ͻ� ȥ�� �ʹ� ���� ���� �ϰų�, ���� �����͸� �����ϸ� �ٸ� Ŭ������ ���յ��� ������, ���� ��� ��Ģ�� �����.
//��Ƽ ������ ȯ�濡�� ����ȭ ó�� �����, �ν��Ͻ��� 2���� �����Ǵ� ������ �߻��� �� �ִ�.



//��Ƽ ������ ȯ�濡�� ������ �̱��� ����¹�!
