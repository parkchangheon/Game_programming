
/*
double area(int r);
double area(int r) {
	return 3.14 * r*r;
}


int main() {
	std::cout << "Hello \n";
	int r = 4;
	double res = area(r);
	cout << res << endl;

	int h, w;
	cout << "h�� w �Է��ϼ���" << endl;
	cin >> h >> w;
	cout << h << ' '<<w;
	return 0;
}
*/


/*
int main() {
	char name1[6] = { 'G','r','a','c','e','\0' }; //cstring �������, �ι���(\0)�� ������ char �迭�� ��Ÿ��. �̰��� name1 ���ڿ�
	char name2[5] = { 'G','r','a','c','e' }; //���ڿ��� �ƴ϶�, �ܼ� ���� �迭�̴�.

	char name3[6] = "Grace";
	char name4[] = "Grace"; //�迭ũ�Ⱑ �ڵ����� 6���� �����.

}





int main() {

	char name[6];
	cin >> name;
	cout << name;
}
*/



//��й�ȣ ���� �Է��ϱ�
/*
#include<iostream>
#include<cstring>
using namespace std;


int main() {
	char pw[]="thisispw";
	char input_pw[10];
	while (true) {
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin >> input_pw;
		if (strcmp(input_pw, pw) == 0) {
			cout << "���α׷��� ���� �����մϴ�" << endl;
			break;
		}
		else {
			cout << "��ȣ ����" << endl;
		}
	}
}
*/




//�������� ���� ����� ������ ���� �� ����.
//�׷��Ƿ�, cin.getline�� �̿�

/*
#include<iostream>
#include<cstring>
using namespace std;


int main() {
	char addr[100];
	cin.getline(addr, 100);  //cin.getline(addr, 100,'\n');�� ����. �������� ���ڿ� �Է� ���� �����ϴ� ���� �����̴�.
	cout << addr;
	
}
*/



//������� ����� cstring�� �̿��� ����̴�. 
// ������, �̴� ũ�⿡ ���� ���ڿ��� ũ�Ⱑ �����Ǵ� ������ ������ ������,
//stringŬ������ ���忭�� ũ�⿡ ������ ���� �����̴�.

/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string song("Falling love with you");
	string elvis("Elvis");

	string singer;
	cout << song + " �� �θ� ������ �̸���? ";
	cout << " (ù���ڴ�"<<elvis[0] << ")  : " ;
	getline(cin, singer);
	if (singer == elvis) {
		cout << "�¾ҽ��ϴ�";
	}
	else {
		cout << "Ʋ�Ƚ��ϴ�." + elvis + "�Դϴ�" << endl;
	}

}

*/



/*
#include<iostream>
#include<string>

using namespace std;

int main() {
	string romio;
	string juliet;


	while (true) {
		cout << "�ι̿�>>";
		cin >> romio;
		cout<< "�ٸ���>>";
		cin >> juliet;


		if (romio == "����") {
			if (juliet == "����") {
				cout << "�ι̿��� �̰���ϴ�"<<endl;
			}
			else if (juliet == "��") {
				cout << "�ٸ����� �̰���ϴ�"<<endl;
			}
			else {
				cout << "�����ϴ�" << endl;
				break;
			}
		}



		if (romio == "��") {
			if (juliet == "����") {
				cout << "�ٸ����� �̰���ϴ�" << endl;
			}
			else if (juliet == "����") {
				cout << "�ι̿��� �̰���ϴ�" << endl;
			}
			else {
				cout << "�����ϴ�" << endl;
				break;
			}
		}




		if (romio == "����") {
			if (juliet == "����") {
				cout << "�ٸ����� �̰���ϴ�" << endl;
			}
			else if (juliet == "��") {
				cout << "�ι̿��� �̰���ϴ�" << endl;
			}
			else {
				cout << "�����ϴ�" << endl;
				break;
			}
		}

	}


}




#include<iostream>
using namespace std;

int main() {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < n + 1; m++) {
			cout << "*";
		}
		cout << endl;
	}
}
*/

