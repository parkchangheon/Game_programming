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






/*
#include<iostream>
#include<time.h>
using namespace std;

enum AI_MODE {
	AM_EASY=1,
	AM_HARD
};


int main() {
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int AiNumber[25] = {};

	//1~25���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		AiNumber[i] = i + 1;

	}

	//���� �����ֱ�
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		//ai ���ڵ� �����ش�.

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = AiNumber[idx1];
		AiNumber[idx1] = AiNumber[idx2];
		AiNumber[idx2] = iTemp;
	}


	int Bingo = 0,AiBingo=0;

	int Aimode;
	
	//ai ���̵��� �����Ѵ�.
	while (true) {
		system("cls");
		cout << "1.Easy" << endl;
		cout << "2.Hard" << endl;
		cout << "Ai ��带 �����ϼ���";
		cin >> Aimode;

		if (Aimode>=AM_EASY || Aimode<=AM_HARD)
			break;
	}

	
	//Ai Easy ���� ���� AI�� ���� ����� * �� �ٲ��� �ʴ� ���� ����� ���� ���� �ϳ��� �ٲٴ� �Ű�, HARD�� �ش� �ٿ� �ִ� ���� �ٲ۴�.
	

	// ���� �ȵ� ��� �迭
	int NoneSelect[25] = {};
	//���� �ȵ� ���� ������ �����Ѵ�
	int NoneSelectCount = 0;

	while (true) {
		system("cls"); //�����.

		//���ڸ� 5*5�� ����Ѵ�.
		cout << "=================Player====================" << endl;
		for (int i = 0; i < 5; ++i) {

			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << '\t';
			}
			cout << endl;
		}


		cout << "Bingo Line : " << Bingo << endl<<endl;
		cout << "================= Ai ====================" << endl;


		switch (Aimode) {
		case AM_EASY:
			cout << "AIMODE : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMODE : HARD" << endl;
			break;
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (AiNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << AiNumber[i * 5 + j]<<"\t";
			}
			cout << endl;
		}

		//ai ���� �� ���� ����Ѵ�.
		cout << "AiBingo Line = " << AiBingo << endl;

		if (Bingo >= 5)
		{
			cout << "Player �¸�" << endl;
			break;
		}

		else if (AiBingo >= 5) {
			cout << "Ai �¸�" << endl;
			break;
		}

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

		for (int i = 0; i < 25; ++i)
		{
			if (AiNumber[i] == input)
			{
				AiNumber[i] = INT_MAX;
				break;
			}
		}


		//ai �� �����Ѵ�. (��忡 ���� �޶���)
		switch (Aimode) {
		case AM_EASY:
			// ���� �ȵ� ���� ��� �����
			NoneSelectCount = 0;

			for (int i = 0; i < 25; i++) {
				if (AiNumber[i] != INT_MAX)
				{
					//*�� �ƴ� ������ ��� NoneSelectCount�� �ε����� Ȱ���Ѵ�. ���� �ȵ� ��Ͽ� �߰��Ҷ����� ������ 1�� �������Ѽ� �� ���� �ȵ� ������ �����ش�.    0~ ī��Ʈ �߰�.
					NoneSelect[NoneSelectCount] = AiNumber[i];
					++NoneSelectCount;
				}
			 }
			//��� �����ֱ� => ���� �ȵ� ����� ������ ������ �ϳ��� ���ڸ� ��� ���� ���� �ڵ�
			input = NoneSelect[rand() % NoneSelectCount];
			break;
			
		case AM_HARD:
			break;

		}

		//AI�� ������ ���ڸ� *�� �ٲ��ش�
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == input) {
				iNumber[i] = INT_MAX;
				break;
			}
		}

		//AI�� ������ ���ڸ� �ٲ��ش�
		for (int i = 0; i < 25; ++i) {
			if (AiNumber[i] == input) {
				AiNumber[i] = INT_MAX;
				break;
			}
		}




		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �Ѵ�. �׷��Ƿ� BIngo ������ �Ź� �ʱ�ȭ ���ش�.
		Bingo = 0;
		AiBingo = 0;


		//����, ����, �� ���� �����ش�
		int iCheck1 = 0, iCheck2 = 0;
		int iAiCheck1 = 0, iAiCheck2 = 0;

		for (int i = 0; i < 5; ++i) {

			iCheck1 = iCheck2 = 0;
			iAiCheck1 = iAiCheck2 = 0;

			for (int j = 0; j < 5; ++j) {
				//���� �� ������ �����ش�.

				if (iNumber[i * 5 + j] == INT_MAX)
					++iCheck1;


				if (iNumber[j * 5 + i] == INT_MAX)
					++iCheck2;

				if (AiNumber[i * 5 + j] == INT_MAX)
					++iAiCheck1;

				if (AiNumber[j * 5 + i] == INT_MAX)
					++iAiCheck2;
			}

			if (iCheck1 == 5)
				++Bingo;

			if (iCheck2 == 5)
				++Bingo;

			if (iAiCheck1 == 5)
				++AiBingo;

			if (iAiCheck2 == 5)
				++AiBingo;
		}
		// �밢�� �ϳ�
		iCheck1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iCheck1;

			if (AiNumber[i] == INT_MAX)
				++iAiCheck1;
		}

		if (iCheck1 == 5)
			++Bingo;

		if (iAiCheck1 == 5)
			++AiBingo;


		iCheck1 = 0;
		iAiCheck1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iCheck1;

			if (AiNumber[i] == INT_MAX)
				++iAiCheck1;
		}

		if (iCheck1 == 5)
			++Bingo;

		if (iAiCheck1 == 5)
			++AiBingo;
	}

	return 0;
}


*/


