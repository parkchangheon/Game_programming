#include<iostream>
using namespace std;

void Test(char a[])
{
	a[2] = 'A';
}

void ChooseLottery(int numbers[])
{
	srand(unsigned(time(0))); //random seeds

	int count = 0;
	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);
		bool found = false;

		for(int i=0; i< count;i++)
		{ 
			//�̹� ã�� ��
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}
	
}


int main()
{
	char msg[] = { 'h','e','l','\0' };
	cout << msg << endl;

	const char* test1 = "Hello World";
	char test2[] = "Hello World";
	test2[0] = 'R';


	//�����ʹ� �ּҸ� ��� �ٱ���������,
	//�迭�� �� ��ü�� �����Ͱ� �پ��ִ� �����̴�.
	// ������ �迭�� ���� �ּҸ� ��Ÿ���� �ִ�.


	//�迭�� � �Լ��� ���ڷ� �ѱ�� �ȴٸ�?
	Test(test2);

	cout << test2 << endl;
	
	return 0;
}