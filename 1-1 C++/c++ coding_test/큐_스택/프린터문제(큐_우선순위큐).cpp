#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 0;
    queue <pair<int, int>> queue; //�Ϲ� ť
    priority_queue<int> pri_queue; //�켱���� ť

    //�¾� �۾�
    for (int i = 0; i < priorities.size(); i++)
    {
        queue.push(make_pair(i, priorities[i]));  //ť�� ���� ������ �߿䵵�� ����
        //�켱���� ť�� �ִ´�.
        pri_queue.push(priorities[i]);
    }

    //ť�� �������� �ݺ�
    while (!queue.empty())
    {
        int index = queue.front().first;
        int value = queue.front().second;
        queue.pop();

        //�켱���� 1������ ���簪�� ���ٸ�,
        if (pri_queue.top() == value)
        {
            pri_queue.pop(); //�켱 ���� ť pop
            count++; //�ϳ��� ��������, ī��Ʈ�� �÷��ش�.

            if (index == location) {
                answer = count;
                break;
            }

        }

        else
            queue.push(make_pair(index, value));



    }



    return answer;
}