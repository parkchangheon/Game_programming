#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)    //�ѹ��� ������������ ~
            q.push((100 - progresses[i]) / speeds[i]);

        else                                    //������������ ������ �Ϸ� �� �߰�.
            q.push((100 - progresses[i]) / speeds[i] + 1);
    }


    while (!q.empty())
    {
        int cnt = 1;
        int current = q.front();
        q.pop();
        while (!q.empty() && q.front() <= current)
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);

    }

    return answer;
}