//#include <string>
//#include <vector>
//#include<iostream>
//#include<algorithm>
//
//
//using namespace std;
//
////string solution(vector<string> participant, vector<string> completion) {
////    string answer = "";
////
////    sort(participant.begin(), participant.end());
////    sort(completion.begin(), completion.end());
////    for (int i = 0; i < completion.size(); i++)
////    {
////        if (participant[i] != completion[i])
////            return participant[i];
////    }
////    return participant[participant.size()-1];
////}
//
//#include<unordered_map>
//string solution(vector<string> participant, vector<string> completion) {
//    string answer = "";
//    unordered_map<string, int> strMap; //unordered_map�� �ߺ��� �����͸� ������� �ʴ´�.->������ key�� ������ �����Ͱ� ������, �ؽ� �浹�� ���� ������ ������ �� �ִ�.
//    for (auto elem : completion)
//    {
//        if (strMap.end() == strMap.find(elem))  //������ �߰����ְ�
//            strMap.insert(make_pair(elem, 1));
//        else  //������ ī��Ʈ�� �÷��ִ� ������� 
//            strMap[elem]++;
//    }
//
//    for (auto elem : participant)
//    {
//        if (strMap.end() == strMap.find(elem)) //���ٸ� ���� ���Ұ� �������Ѿִ�.
//        {
//            answer = elem;
//            break;
//        }
//
//        else {                                  // �ִٸ� ��� �ϳ� ���ش�.
//            strMap[elem]--;
//            if (strMap[elem] < 0)
//            {
//                answer = elem;
//                break;
//            }
//        }
//    }
//
//    return answer;
//}
//
//
//int main()
//{
//    vector<string> parti = { "leo", "leo","kiki", "eden"};
//    vector<string> comp = { "eden", "kiki" };
//    solution(parti, comp);
//    //unordered_map<string, int> strMap;
//    //cout << strMap.size() << endl;
//    //
//    //for (auto elem : parti)
//    //{
//    //    if (strMap.end() == strMap.find(elem)) //end�� �߸� ���ٴ� ���̴�.
//    //        strMap.insert(make_pair(elem, 1));
//    //    else
//    //        strMap[elem]++; //�ִٸ� ī��Ʈ�� ���������ش�.
//    //    
//    //}
//    //cout << strMap["kiki"]<<endl;
//    //cout << strMap["leo"]<<endl;
//    //cout << strMap.size() << " " << endl;
//}