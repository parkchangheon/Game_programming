//8-6

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class BaseArray {
//private:
//	int capacity;
//	int* mem;
//
//protected:
//	BaseArray(int capacity = 100) {
//		this->capacity = capacity;
//		mem = new int[capacity];
//	}
//
//	~BaseArray() { delete[] mem; }
//
//	void put(int index, int val) { mem[index] = val; }
//	int get(int index) { return mem[index]; }
//	int getCapacity() { return capacity; }
//};
//
//
//
//class MyQueue :public BaseArray {
//	int front = 0;
//	int idx = 0;
//
//public:
//	MyQueue(int x) :BaseArray(x) { ; }
//
//	void enqueue(int a) {
//		idx++;
//		put(idx, a);
//		
//	}
//
//	int dequeue() {
//		if (idx < 0) {
//			exit(1);
//		}
//		++front;
//		idx--;
//		return get(front);
//		
//
//	}
//
//	int capacity() {
//		return getCapacity();
//	}
//
//	int length() {
//		return idx;
//	}
//};
//
//
//class MyStack : public BaseArray {
//	int top=0;
//public:
//	MyStack(int x) :BaseArray(x) { ; }
//
//	void push(int n) {
//		put(top,n);
//		top++;
//	}
//
//	int pop() {
//		top--;
//		int tmp = get(top);
//		return tmp;
//	}
//
//	int capacity() {
//		return getCapacity();
//	}
//
//	int length() {
//		return top;
//	}
//
//};
//
//
//int main() {
//
//	MyStack mStack(100);
//	int n;
//	cout << "���ÿ� ������ 5���� ������ �Է��϶�";
//	
//	for (int i = 0; i < 5; i++) {
//		cin >> n;
//		mStack.push(n);
//	}
//
//	cout << "���ÿ뷮:" << mStack.capacity() << ",����ũ��:" << mStack.length() << endl;
//	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�.";
//	while (mStack.length() != 0) {
//		cout << mStack.pop() << ' ';
//	}
//	cout << endl << "������ ���� ũ�� :" << mStack.length() << endl;
//}







//8-7
/*
#include<iostream>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	~BaseMemory() { delete[] mem; }
	void setData(int index, char data) { mem[index] = data; }
	char getData(int index) { return mem[index]; }
};

class ROM :public BaseMemory {
	int length;
public:
	ROM(long size, char memory[], int len) : BaseMemory(size) {
		length = len;
		for (int i = 0; i < len; i++)
			setData(i, memory[i]);
	;}
	char read(int index) { return getData(index); }
};

class RAM :public BaseMemory {
public:
	RAM(int size):BaseMemory(size){ ; }
	void write(int index, int data) { setData(index, data); }
	char read(int index) { return getData(index); }
};


int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++)
		mainMemory.write(i, biosROM.read(i));

	for (int i = 0; i < 5; i++)
		cout << mainMemory.read(i);
}


*/






//8-8

#include<iostream>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;

protected:
	Printer(string model, string mnfc, int left) {
		this->model = model;
		this->manufacturer = mnfc;
		this->availableCount = left;
	}
	bool print(int pages) {
		if (availableCount < pages) {
			cout << "������ �����մϴ�";
			return false;
		}

		for (int i = 0; i < pages; i++) {
			availableCount--;
		}
		return true;

	};

	string getModel(){ return this->model; }
	string getManufacture() { return this->manufacturer; }
	int getAvailableCount() { return this->availableCount; }
};

class InkPrinter : Printer {
	int availableInk;
public:
	InkPrinter(string model, string mnfc, int left, int availableInk):Printer( model,  mnfc,  left){
		this->availableInk = availableInk;
	}
	void show() {
		cout << "��ũ�� : " << getModel() << " " << getManufacture() <<" ���� ���� : "<< getAvailableCount() <<" ���� ��ũ "<< availableInk<<endl;
	}
	bool av_ink(int pages) {
		if (print(pages));
		else return false;

		if (availableInk < pages)
		{
			cout << "��ũ����"<<endl;
			return false;
		}
	
		for (int i = 0; i < pages; i++) {
			availableInk--;
		}
		return true;
		
	}

};

class LaserPrinter : Printer {
	int availabeToner;
public:
	LaserPrinter(string model, string mnfc, int left, int availabeToner) :Printer(model, mnfc, left) {
		this->availabeToner = availabeToner;
	}
	void show() {
		cout << "��ũ�� : " << getModel() << " " << getManufacture() <<" ���� ���� : "<< getAvailableCount() <<" ���� ��� "<< availabeToner<<endl;
	}

	bool av_toner(int pages) {
		if (print(pages));
		else  return false; 

		if (availabeToner < pages)
		{
			cout << "��� ����"<<endl;
			return false;
		}

		for (int i = 0; i < pages; i++) {
			availabeToner--;
		}

		return true;
	}
};



int main() {
	InkPrinter* inkjet = new InkPrinter("officejet v40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵� �Ǵ� �����ʹ� ������ ����.\n";
	inkjet->show();
	laser->show();


	char select= 'y';

	while (select == 'y') {
		int type, n;
		cout << "(1: ��ũ��, 2:������)�� �ż� �Է� >> ";
		cin >> type >> n;
		if (type == 1) {
			if (inkjet->av_ink(n))
				cout << "����Ʈ �Ͽ����ϴ�.\n";
		}

		else if (type == 2) {
			if (laser->av_toner(n))
				cout << "����Ʈ�Ͽ����ϴ�.\n";
		}
		inkjet->show();
		laser->show();

		cout << "��� ����Ʈ�ϰڽ��ϱ�?(y/n)";
		cin >> select;
		if (select == 'n')
			break;
		else if (select == 'y');
		else
			cout << "�߸��Է�";

	}

	delete inkjet;
	delete laser;



}