//#include<iostream>
//#include<functional>
//using namespace std;
//
//
//class TEST {
//public:
//	typedef std::function<void* ()> TestFunction;
//	// stD::function�� ó���� �� �ִ� callable target�� ������ ����.
//	// �Ϲ��Լ�, lambda ��, bind expression, �Լ� ��ü, class ���� ��� �Լ� �� ��� ����
//
//	//��� ����� 
//	//std::function<����Ÿ��(�Է� �Ķ���͵�)> ����
//
//	//void print(int a, int b);
//	//std::function<void(int, int)> fp = print;
//};
//
//int main()
//{
//	
//}



//std::bind
//std:bind(�Լ��� �ּ�, ����1, ����2, ...);
//�����ϰ� ���ϸ� ȣ���� ������ ��ü�� �μ��� ���ε��ϴ°�.

//#include<iostream>
//#include<string.h>
//#include<functional>
//
////����
//
//void hello(const string& s)
//{
//	cout << s << endl;
//}
//
//int main()
//{
//	auto func = std::bind(hello, "hello world"); // ���ε� ����
//	func(); //ȣ��
//}

//#include<iostream>
//#include<functional>
//
//using std::placeholders::_1;   
// ���ڰ��� ���ο� �Լ��� ���ڷ� ���� �� �ֵ����Ѵ�.


//#include<iostream>
//#include<functional>
//
//int sum(int a, int b, int c)
//{
//	return a + b + c;
//}
//
//int main()
//{
//	/*auto func1 = std::bind(sum, std::placeholders::_1,2, 3);
//	std::cout << func1(1) << std::endl;*/
//	// placeholder�� ù��° �μ��� �Է��� �������̰�, 2��° 3��° �μ��� 2�� 3���� ����
//	// �� �ؿ� ¦��Ⱑ ���� �����ϴٴ� ��
//	//ex2)
//	/*auto func2 = std::bind(sum, std::placeholders::_1, std::placeholders::_2, 3);
//	std::cout << func2(1,4) << std::endl;*/
//}





//functional

//#include<iostream>
//#include<functional>
//
//using std::placeholders::_1;
//
//void print_number(int i)
//{
//	std::cout << i << std::endl;
//}
//
//void print_sum(int a, int b)
//{
//	std::cout << a + b << std::endl;
//}
//
//
//struct PrintNum
//{
//	void operator()(int i)const
//	{
//		std::cout << i << std::endl;
//	}
//};
//
//
//struct Foo
//{
//	int num_;
//	Foo(int num) : num_(num){}
//	void print_add(int i) const { std::cout << num_ + i << '\n'; }
//};
//
//int main()
//{
//	//�Ϲ� �Լ� ���
//	std::function<void(int)> f1 = print_number;
//	f1(10);
//
//	//���ٽ�
//	std::function<void(int)> f2 = [](int a) {print_number(a); };
//	f2(10);
//
//}



// �̱��� ����

//���ø����̼��� ���۵ɶ� � Ŭ������ �����ѹ��� �޸𸮸� �Ҵ��ϰ�
//�� �޸𸮿� �ν��Ͻ��� ����� ����ϴ� ������ �����̴�.

//ex) ������Ʈ�� ���� ���� ������ ��� ��ü�� ������ �����Ǹ� ���� ���� ����� ������ ���� �� ����
//�ν��Ͻ��� 1���� �����Ǵ� Ư¡�� ���� �̱��� ������ �̿��ϸ�, �ϳ��� �ν��Ͻ��� �޸𸮿� ����ؼ� ���� �����尡 ���ÿ� �ش�
//�ν��Ͻ��� �����Ͽ� ����� �� �ְԲ� �� �� �־� ��û�� ���� ������ ����ϸ� ȿ���� ���� �� �ִ�.
//���ü� ������ ����ؼ� �����ؾ���


//�̱��� ������ ����
//������ �޸� ������ �����鼭 �ѹ��� new�� �ν��Ͻ��� ����ϱ� ������ �޸� ���� ������ �� �ִ�.
//�̱������� ������� Ŭ������ �ν��Ͻ��� �����̱� ������ �ٸ� Ŭ������ �ν��Ͻ����� �����Ͱ����� ��Ȱ
//�ν��Ͻ��� ���������� �Ѱ��� �����ϴ� ���� �����ϰ� ���� ��� ����Ѵ�.
//�ι�° �̿�� ���ʹ� ��ü �ε� �ð��� �پ� ������ �������� ������ �ִ�.


//������
//�̱��� �ν��Ͻ��� �ʹ� ���� ���� �ϰų� ���� �����͸� ������ų ��쿡, �ٸ� Ŭ������ �ν��Ͻ��� ���� ���յ��� ������ 
//"���� ��� ��Ģ"�� �����ϰ� �ȴ�.

//�̴� ��ü ���� ���� ��Ģ�� ��߳��� ������ ������ ��������� ���������� ����� ������ �� �ִ�.
//���� ��Ƽ������ ȯ�濡�� ����ȭ ó���� ���ϸ� �ν��Ͻ��� 2�� ������ �� �ִ� ���ɤ����� ���� �� �ִ�.


//ex)

//�̱��� ���� ����

#include <cstddef>
class FileSystem {

public:
	static FileSystem& instance() {  // ���� �޼���� �ڵ� ��𿡼��� �̱��� �ν��Ͻ��� ������ �� �ְ� ��.
	// �����޼���� Ŭ������ �ν��Ͻ� ���� ȣ���� �����ϸ�, �ν��Ͻ������� ȣ���� �Ұ���.
	// ��ƿ��Ƽ �Լ��� ����µ� �����ϰ� ���ȴ�.
	// �̱����� ������ �ʿ�� �� ������ �ν��Ͻ� �ʱ�ȭ�� �̷�� ���ҵ� �Ѵ�.
		
		//������ �ʱ�ȭ
		if (instance_ == NULL) {
			instance_ =  new FileSystem();
		}
		return *instance_;
	}

private:
	FileSystem(){}
	static FileSystem* instance_; // ���� ��� ������ Ŭ���� �ν��Ͻ��� �����Ѵ�. private�̱⿡ �ۿ��� ���� �Ұ�.
};