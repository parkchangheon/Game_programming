// �÷��̵� �ͼ� �˰���

// ���ͽ�Ʈ���� ���� �� ��忡�� �ٸ� �������� �Ÿ��� 1���� �迭�� ���� �̵��ϴ� ���� �ð�ȭ 



// 1�� ���ļ� ���� ��� ( 2->3 , 2->4 , 3->2 , 3->4 , 4->2, 4->3 ) 
// ex) 2->3 ���� ���� ����, 2->1 + 1->3 ���� ���� ����� ���Ѵ�.   9 vs 7 +����.    �׷� 1�� ���İ��� ����� �� ũ�Ƿ� ���� x 

// ... �̷������� 1, 2, 3, 4 �� ���İ��� ����� ����Ѵ�.

/*

#include<iostream>
#include<stdio.h>
using namespace std;

int number = 4;
int inf = 10000000;

int a[4][4] = {
	{0,5,inf,8},
	{7,0,9,inf},
	{2,inf,0,4},
	{inf,inf,3,0}
};

void floydWarshall() {
	//��� �迭�� �ʱ�ȭ ���ش�.
	int** d = new int* [number];
	for (int i = 0; i < number; ++i) {
		d[i] = new int[number];
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}


	//k�� ���İ��� ��� 
	for (int k = 0; k < number; k++) {
		// i �� ��� ���
		for (int i = 0; i < number; i++) {
			// j �� ���� ���
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];

			}
		}
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}

int main() {
	floydWarshall();
}


*/




