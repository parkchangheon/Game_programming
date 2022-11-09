#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int number = 30;
	vector<int> v;
	v.push_back(11);
	v.push_back(31);
	v.push_back(20);
	v.push_back(40);
	v.push_back(70);
	v.push_back(90);
	v.push_back(100);

	/*vector<int>::iterator it = v.end();*/
	//������ ���͸��� ����ؼ� Ư�� �����͸� ã���� �ߴٸ�
	//for���� ���� ������ �˻縦 �ؼ� ã���� break�� �����.
	
	//������ algorithm find�� Ȱ���Ѵٸ�,
	vector<int>::iterator it = find(v.begin(), v.end(), number);
	//���ٷ� ������ �����ϴ�.

	if (it == v.end())
		cout << "Cant find the thing!" << endl;

	struct CanDivide11 {
		bool operator()(int n)
		{
			return (n % 11) == 0;
		}
	};

	vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivide11()); //������ ù��° ���̸� �����ش�.
	if (itFind == v.end())
		cout << "Cant find the thing!" << endl;
	

	struct IsOdd {
		bool operator()(int n)
		{
			return (n % 2) != 0;
		}
	 };

	int n = count_if(v.begin(), v.end(), IsOdd());
	cout << n << endl;

	//��� �����Ͱ� ������ �����ϴ���
	bool b1 = all_of(v.begin(), v.end(),IsOdd()); //��γ�?
	bool b2 = any_of(v.begin(), v.end(), IsOdd());//�ϳ���?
	bool b3 = none_of(v.begin(), v.end(), IsOdd());// ����?

	// ��� �����Ͱ� �����ϴ���!


	struct MultiplyBy3 {
		void operator()(int& n) {
			n *= 3;
		}
	};

	for_each(v.begin(), v.end(), MultiplyBy3()); //��� �����͸� ������� *3�� ���־���.


	{ //Ȧ���� �����͸� �ϰ� �����ϰ� �ʹ�
		/*for (vector<int>::iterator it = v.begin(); it != v.end(); )
		{
			if ((*it % 2) != 0)
				it = v.erase(it);
			else
				++it;
		}*/
		v.clear();
		v.push_back(11);
		v.push_back(31);
		v.push_back(20);
		v.push_back(40);
		v.push_back(70);
		v.push_back(90);
		v.push_back(100);
		
		remove(v.begin(), v.end(), 20);
		remove_if(v.begin(), v.end(), IsOdd());
		v.erase(remove_if(v.begin(), v.end(), IsOdd()));
	}

	return 0;

}