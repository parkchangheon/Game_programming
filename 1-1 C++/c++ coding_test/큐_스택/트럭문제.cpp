//��Ǯ��
/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = weight;
    vector<int> finish_truck;
    queue <pair<int, int>> now_ing; //�� Ʈ���� ���� & �ҿ� �ð�(--����)

    while (!truck_weights.empty())
    {
        int next_truck = truck_weights.front();

        if (!now_ing.empty()) {
            if (now_ing.front().second < 0) {
                finish_truck.push_back(now_ing.front().first);
                bridge_length += 1;
                weight += now_ing.front().first;
            }
        }


        if (bridge_length > 0 && weight >= next_truck)
        {
            now_ing.push(make_pair(next_truck, time--));
            bridge_length -= 1;
            weight -= next_truck;
        }



        answer++;
    }


    return answer;
}
*/



#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int idx = 0; //���� ����� �ε���
    int sum = 0; //���� �ٸ��� �ö���ִ� ���� ���� ����
    queue<int> now_ing; // ���� �ٸ��� �ǳʴ� Ʈ�� üũ ť

    while (1)
    {
        if (idx == truck_weights.size())  //������ Ʈ���϶�
        {
            answer += bridge_length;
            break;
        }

        answer++; //�ð��� ����

        int tmp = truck_weights[idx];

        //Ʈ���� �ٸ��� �ǳ�����,
        if (now_ing.size() == bridge_length) //���� �ٸ� ���� (0���� ä����) = �ٸ� ��ü ����
        {
            sum -= now_ing.front(); //�ٸ� ���Կ��� Ʈ�� ���� ���ְ�
            now_ing.pop();          //�ٸ� ���ÿ��� Ʈ���� pop
        }

        if (sum + tmp <= weight) //�������� ������ �� �ִٸ�
        {
            now_ing.push(tmp);
            sum += tmp;
            idx++;
        }
        else
            now_ing.push(0); // ������ �Ұ����ϴٸ�, �׳� ī���͸� �ø���. (0�� �־������ν�, ť�� ��� �ð� üũ)

    }


    return answer;
}