/*
//8�� �պ� ����

//�ϴ� ������ �ɰ��� ���߿� ��ģ��.
//NlogN

#include<iostream>
using namespace std;

int num = 8;
int sorted[8]; // ���� �迭�� �ݵ�� ���� ������ 

void merge(int a[], int m, int middle, int n) {
	int i = m; // ���� �迭 ������ 
	int j = middle + 1; // ������ �迭 ������

	int k = m; // ��ĥ �迭�� �� ���� �ε����� ����Ŵ

	while (i <= middle  && j <= n) {  // �� left, right�� ���� ���� �ݺ�
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++; // ��ģ �� �ε��� ����������
	}
	//���� �����͵鵵 ����
	if (i > middle) {  //i�� ���� �����ٸ� ���� j���� �ڴ� �޿�
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else { //j�� ���� �����ٸ�
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		// ������ ����... �׸��� ����
		merge(a, m, middle, n);
	}
}

int main() {
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(arr, 0, num - 1);

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}
*/
