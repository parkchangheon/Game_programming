// �� ���� 
/*
#include<iostream>
using namespace std;

int arr[10] = { 3,7,8,1,5,9,6,10,2,4 };
int num = 10;

void quickSort(int* data, int start, int end) {
	if (start > end)
		return;

	int key = start; // Ű�� ù��° ���
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[i] <= data[key]) {
			i++;
		}
		while (data[j] >= data[key] && j>start)
		{
			j--;
		}

		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);

}



int main() {
	quickSort(arr, 0, num - 1);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
}

*/


//��� �Լ��� ���°��� POINT

// ����  ���� ����� �̿��ϹǷ�, O(NlogN) �� �ð� ���⵵�� �����µ�, 
// �־��� �ð����⵵�� O(N*N)�̴�.   => �ǹ����� �߸� �����ɶ�. ==> �̹� ������ �Ǿ��ִ� ���

//1 2 3 4 5 6 7 8 9 10 �̷��� �Ǿ��ִٸ�,
//1 �� �̹� ���� �׷� ������ 2~10�� �ٽ� ���� �ϹǷ�, ���� ������ ������ ���� ������� ����. ==>N^2