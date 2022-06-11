//��Ÿũ����Ʈ �ǹ� �˰��� (�������� ���)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 501
int n, inDegree[MAX], tt[MAX], result[MAX];
vector<int> a[MAX];

void topology()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0) {
			result[i] = tt[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();

		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			result[y] = max(result[y], result[x] + tt[y]);

			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tt[i];        //�ɸ��� �ð� �Է¹޾��ش�.
		while (1) {
			int x;
			cin >> x;
			if (x == -1) break;  // ���������� �������� �־��ش�.

			inDegree[i]++;    //�������� �÷��ش�.
			a[x].push_back(i);
		}
	}
}