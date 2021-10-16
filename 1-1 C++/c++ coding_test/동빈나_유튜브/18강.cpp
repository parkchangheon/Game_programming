// Union Find ������ ã�� => ���μ� ã��
// ���� ��ĥ��, �θ� �ڱ⺸�� �� ���� ������ �����Ͽ�, ���� (������ �ȵ� ���¿����� �ڱ��ڽ��� �θ�� ���´�)
// ����Լ��� ����Ͽ�, �ڽ��� �θ�� ���� ���� �������ش�.

/*

#include<iostream>

using namespace std;


int getparent(int parent[], int x) {
	//����Լ��� ���� �κ�
	if (parent[x] == x)
		return x;

	//���� ����Ű�� �ִ� �θ��尡 �޶�, ���� ��� ã�� ���� ����
	return parent[x] = getparent(parent, parent[x]);
}


//�� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

	if (a < b)
		return parent[b] = a;
	else 
		return parent[a] = b;
}



//���� �θ� �������� Ȯ��
int findParent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);

	if (a == b)
		return 1;
	else
		return 0;
}


int main() {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	printf("1�� 5�� ����Ǿ� �ֳ���?? %d \n", findParent(parent, 1, 5));
}
*/

















