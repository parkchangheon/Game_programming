//Quiz 1


//1-1
/*
int main() {
	for (int i = 1; i < 101; i++) {

		cout << i << '\t';
		if (i % 10 == 0) {
			cout << endl;
		}
		
	}
}
*/




//1-2
/*
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << "x" << j << "=" << i * j<<'\t';
		}
		cout << endl;
	}
}
*/




//1-3
/*
int main() {
	int a, b;
	cout << "�� ���� �Է��϶�>>";
	cin >> a >> b;

	int res = a > b ? a : b;
	cout << "ū�� = " << res;
}
*/




//1-4
/*
int main() {
	double arr[5];
	double max = 0;
	cout << "5���� �Ǽ��� �Է��϶�";

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	cout << "���� ū�� = " << max;
	
}
*/



//1-5
/*
int main() {
	char s[100];
	int count = 0;
	cout << "���ڵ��� �Է��϶�(100�� �̸�)";
	cin.getline(s, 100);
	for (int i = 0; i < 100; i++) {
		if (s[i] == 'x')
			count += 1;
	}
	cout << "x�� ������ " << count;
}

*/


//1-6
/*
int main() {
	string s1, s2;
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> s1;
	cout << "����ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> s2;
	if (s1 == s2)
		cout << "�����ϴ�" << endl;
	
}
*/




//1-7
/*
int main() {
	
	while (1) {
		char s1[100];
		cout << "�����ϰ������ yes�� �Է��ϼ���>>";
		cin.getline(s1, 100);

		if (strcmp(s1,"yes")==0) {
			cout << "�����մϴ�";
			break;
		}
	}

}


*/




//1-8**
/*
int main() {
	char s[100];
	cout << "5���� �̸��� ;�� �����Ͽ� �Է��ϼ���\n"<<">>";
	string ans;
	int max = 0;
	int n = 0;

	for (int i = 0; i < 5; i++) {
		cin.getline(s, 100, ';');
		cout << i << ':' << s;
		cout << endl;

		if (max < strlen(s)) {
			max = strlen(s);
			n = i;
			ans = s;
		}
	}
	cout << "���� �� �̸���" << ans << endl;
}
*/


//1-9
/*
int main() {
	string name, addr;
	int age;

	cout << "�̸���?";
	cin >> name;
	cout << endl;

	cout << "�ּҴ�?";
	cin >> addr;
	cout << endl;

	cout << "���̴�?";
	cin >> age;
	cout << endl;

	cout << name << "," << addr << "," << age;

}



*/




//1-10

/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cout << "���ڿ� �Է�>>";
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << s[j];
		}
		cout << '\n';
	}

}
*/



//1-14
/*
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int hap = 0;
	char coffee[100];
	int su;
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500�� �Դϴ�." << endl;
	
	while (hap <= 20000) {
		int tmp = 0;
		cout << "�ֹ�>>";
		cin >> coffee >> su;

		if (strcmp(coffee, "����������")==0) {
			tmp += 2000 * su;
			hap += tmp;
			cout << tmp << "�� �Դϴ�. ���ְ� �弼��"<<endl;
		}

		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) {
			tmp += 2300 * su;
			hap += tmp;
			cout << tmp << "�� �Դϴ�. ���ְ� �弼��"<<endl;
		}

		else if (strcmp(coffee, "īǪġ��") == 0) {
			tmp += 2500 * su;
			hap += tmp;
			cout << tmp << "�� �Դϴ�. ���ְ� �弼��"<<endl;
		}

	}
	
	cout << hap << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�~";
}

*/





//1-15

#include<iostream>
#include<cstring>
using namespace std;

int main() {

	int a, c;
	char b;

	while (true) {
		cout << "?";
		cin >> a >> b >> c;
		switch (b) {
		case '+':cout << a << " " << b << " " << c << " = " << a + c << endl; break;
		case '-':cout << a << " " << b << " " << c << " = " << a - c << endl; break;
		case '*':cout << a << " " << b << " " << c << " = " << a * c << endl; break;
		case '/':cout << a << " " << b << " " << c << " = " << a / c << endl; break;
		case '%':cout << a << " " << b << " " << c << " = " << a % c << endl; break;
		default: cout << "�߸��� ������ �Դϴ�." << endl;

		}

	}
}
