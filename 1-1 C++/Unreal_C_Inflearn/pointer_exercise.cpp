#include<iostream>
using namespace std;

struct StatInfo
{
	int hp;     // +0
	int attack; // +4
	int defence;// +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);

int main()
{

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	cout << "�κ� �����߽��ϴ�.";
	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	CreateMonster(&monster);
}


StatInfo CreatePlayer()
{
	StatInfo ret;
	cout << "�÷��̾� ����" << endl;
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;
	info->hp = 50;
	info->attack = 7;
	info->defence = 3;
}