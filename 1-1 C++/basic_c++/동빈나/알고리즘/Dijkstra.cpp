// ���� Ž������ Ǫ�� ��� ( O(n^2 ) �ð� ���⵵�� �ɸ� )

//#include<iostream>
//using namespace std;
//
//int number = 6;
//int INF = 1000000000;
//
////��ü �׷��� �ʱ�ȭ
//int a[6][6] = {
//	{0,2,5,1, INF, INF},
//	{2,0,3,2,INF,INF},
//	{5,3,0,3,1,5},
//	{1,2,3,0,1,INF},
//	{INF,INF,1,1,0,2},
//	{INF,INF,5, INF,2,0}
//};
//bool v[6]; //�湮 ����
//int d[6];  //�ִ� �Ÿ�
//
////���� �ּ� �Ÿ��� ������ ������ ��ȯ 
//int getSmallIndex() {
//	int min = INF;
//	int index = 0;
//	for (int i = 0; i < number; i++)
//	{
//		if (d[i] < min && !v[i]) {
//			min = d[i];
//			index = i;
//		}
//	}
//	return index;
//}
//
//
//// ���ͽ�Ʈ�� �����ϴ� �Լ��Դϴ�.
//void dijkstra(int start)//Ư�� �������� ������...
//{
//	for (int i = 0; i < number; i++){
//		d[i] = a[start][i]; //Ư���������� �ֺ� ���� �������ش�.
//	}
//	v[start] = true; //���� �ִ� ��� �湮���� üũ
//	for (int i = 0; i < number - 2; i++) {
//		int current = getSmallIndex(); // 
//		v[current] = true; //���� �湮�� ��忡 �湮 ó���� ���ش�.
//		for (int j = 0; j < 6; j++) { 
//			if(!v[j]) //��带 �湮���� �ʾҴٸ�,
//				if (d[current] + a[current][j] < d[j]) { //���ļ� ���� ������ ����... �� ���� ��忡�� ���� ������ ���� ���! 
//					d[j] = d[current] + a[current][j];
//				}
//		}
//	}
//}





// ���� Ư¡�� ����ϴ� ���

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int number = 6;
int INF = 100000000;

vector<pair<int, int>> a[7];
int d[7];  //�ּҺ��

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;  //�� ������ ����մϴ�.

	//����� ������� ó���ϹǷ� ť�� ����մϴ�.
	while (!pq.empty())
	{
		int current = pq.top().first;
		//ª�� ���� ���� ������ ����ȭ �����ش�.
		int distance = -pq.top().second;
		pq.pop();

		//�ִܰŸ��� �ƴ� ��� ��ŵ�ϵ��� ����
		if(d[current]<distance)
			continue;

		for (int i = 0; i < a[current].size(); i++)
		{
			//���õ� ����� ���� ���
			int next = a[current][i].first;
			//���õ� ��� ���ļ� ���� ���� ���� ���
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}

		}
	}

}