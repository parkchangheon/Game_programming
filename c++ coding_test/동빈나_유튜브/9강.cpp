// c++ STL sort ����غ��� 


/*
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a[10] = { 9,3,1,2,4,5,1,2,5,7 };
	sort(a, a + 10); //�޸��� �ּҸ� ���� ������ ����. ù�ּ��� 9, ������ �ּ��� 7
	for (int i = 0; i < 10; i++)
		cout << a[i]<<' ';
}

*/



// ���� ������ ���� ���غ���

/*
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
	//return a < b; // �������� ����
	return a > b;   // �������� ����
}

int main() {
	int a[10] = { 9,3,1,2,4,5,1,2,5,7 };
	sort(a, a + 10,compare);
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
}
*/




//�����͸� ��� �����ϴ� ���
/*
#include<iostream>
#include<algorithm>

using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	//���� ������ ������ ���� ����
	bool operator<(Student& student) {
		return this->score < student.score;//�� ������ ���ٸ� �켱������ ����. (�����ͺ��� ���)
	}
};

int main() {
	Student students[] = {
		Student("Na",90),
		Student("KIM",100),
		Student("Lee",55)
	};
	sort(students, students + 3);

	for (int i = 0; i < 3; i++) {
		cout << students[i].name<<' ';
	}
}
*/


