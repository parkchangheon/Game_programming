#include<iostream>
using namespace std;

//���м� - ĸ��ȭ
//���� �Ǵ� ���� ����ϰ� ����ڴ�.

// 1) ������ �����ϰ� �ǵ帮�� �ȵǴ� ���
// 2) �ٸ� ��η� �����ϱ� ���ϴ� ���
// public : ���� �� ��� ����
// protected : �� �ڼյ����׸� ���
// private : ���� ���ž�.


//��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ������ �ʴ´�.
//public: �θ�� ���� ���� �״�� (public-> public, protected-> protected, privated-> private) ��
//protected:(public-> protected, protected-> protected)
//private: �������� �� ���� �ڼյ����״� �ȹ����� (public-> private, protected-> private)


class Car
{
public: //������� ������
	void MoveHandle(){}
	void PushPedal() {}
	void OpenDoor() {}

	void TurnKey()  //����ڰ� �̰͸� �ϸ� �Ʒ� ���� �Ǵ� �κ��� �۵��ϰ� ����
	{
		RunEngine();
	}

private:
	//����� ����ڰ� ���� �Ǵ� �κ�
	void DisassembleCar() {}
	void RunEngine() {}
	void ConnectCircuit() {}

public:
};

class Berserker
{
public:
	int GetHp() { return _hp; }
	void SetHp(int hp) {
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	// ��� : ü�� 50 �̸��� �� ����Ŀ ��� �ߵ�
	void SetBerserkerMode()
	{
		cout << "�ſ� ������ " << endl;
	}

private:
	int _hp = 100;
};

class SuperBerserker : public Berserker {  //��� ���� ������

};

int main()
{
	Berserker b;
	b.SetHp(20);

}