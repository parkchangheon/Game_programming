/*

#include<iostream>
#include<time.h>
using namespace std;


int main() {
	srand((unsigned int)time(0));
	int iNumber[25] = {};

	//1~25���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	//���� �����ֱ�
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	for (int i = 0; i < 25; i++) {
		cout << iNumber[i] <<' ';
	}

	int Bingo = 0;

	while (true) {
		system("cls"); //�����.

		//���ڸ� 5*5�� ����Ѵ�.
		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << '\t';
			}


			cout << endl;
		}


		cout << "Bingo Line : " << Bingo << endl;

		cout << "���ڸ� �Է��ϼ��� : (0�� ����) : ";
		int input;
		cin >> input;

		if (input == 0)
			break;

		else if (input < 0 && input>25)
			continue;


		bool flag = true;

		for (int i = 0; i < 25; i++) {
			if (input == iNumber[i]) {
				flag = false;

				iNumber[i] = INT_MAX;
				//�� �̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 ���� ��������
				break;
			}
		}

		if (flag)
			continue;

		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �Ѵ�. �׷��Ƿ� BIngo ������ �Ź� �ʱ�ȭ ���ش�.
		Bingo = 0;

		//����, ����, �� ���� �����ش�
		int iCheck1 = 0, iCheck2 = 0;
		for (int i = 0; i < 5; ++i) {

			iCheck1 = iCheck2 = 0;
			for (int j = 0; j < 5; ++j) {
				//���� �� ������ �����ش�.

				if (iNumber[i * 5 + j] == INT_MAX)
					++iCheck1;


				if (iNumber[j * 5 + i] == INT_MAX)
					++iCheck2;
			}

			if (iCheck1 == 5)
				++Bingo;

			if (iCheck2 == 5)
				++Bingo;
		}
		// �밢�� �ϳ�
		iCheck1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iCheck1;
		}

		if (iCheck1 == 5)
			++Bingo;


		iCheck1 = 0;

		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iCheck1;
		}

		if (iCheck1 == 5)
			++Bingo;
	}

	return 0;
}

*/






