
//vector�� ����

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	vector<pair <int, string> >v;
//	v.push_back(pair<int, string>(90, "���ϴ�"));
//	v.push_back(pair<int, string>(23, "�̲õ�"));
//	v.push_back(pair<int, string>(44, "������"));
//
//	sort(v.begin(), v.end());
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i].second << ' ';
//	}
//
//	return 0;
//}
//







//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool compare(pair<string, pair<int, int>> a,  pair<string, pair<int, int>> b) {
//	if (a.second.first == b.second.first) {
//		return a.second.first > b.second.first;
//	}
//	else
//	{
//		return a.second.second > b.second.second;
//
//	}
//}
//
//int main() {
//	vector<pair<string, pair<int, int>>> v;
//	v.push_back(pair<string, pair<int, int>> ("��â��",pair<int,int>(26, 100)) );
//	v.push_back(pair<string, pair<int, int>>("��â��", pair<int, int>(23, 101)));
//	v.push_back(pair<string, pair<int, int>>("�̽ſ�", pair<int, int>(53, 99)));
//	v.push_back(pair<string, pair<int, int>>("������", pair<int, int>(52, 99)));
//
//
//	sort(v.begin(), v.end(), compare);
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i].first << ' ';
//	}
//
//}
