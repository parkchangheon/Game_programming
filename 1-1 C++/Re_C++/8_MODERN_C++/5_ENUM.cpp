#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

//unscopped enum (�������� enum) �ٸ� �������� �Ʒ� �������� ����� �� ���Եȴ�.
enum PlayerType
{
	Knight,
	Archer,
	Mage,
};

enum MonsterType
{
	MS_Knight, //�̸��� ��ģ��.(MS�� ����)
};

//���� ������ �ذ��ϱ� ���� �Ʒ��� ���� enum class�� ������ش�.
//�̸����� ������ ���ϳ�, �Ϲ��� ��ȯ�� ���� �ʾ� ������ casting�������...
enum class ObjectType
{
	Player,
	Monster,
	Projectile,
};

int main()
{
	double value = Knight; //�Ϲ����� enum Ȱ��� (�Ϲ��� ��ȯ)
	//double value2 = ObjectType::Player; //�Ϲ����� ��ȯ x 
	double value2 = static_cast<double>(ObjectType::Player); //�Ϲ����� ��ȯ x 


	return 0;
}