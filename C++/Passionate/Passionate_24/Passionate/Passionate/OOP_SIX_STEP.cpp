#include "OOP_SIX_STEP.h"
#define _CRT_SECURE_NO_WARNINGS

Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) :accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(double money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "����ID : " << accID << endl;
	cout << "��  �� : " << cusName << endl;
	cout << "��  �� : " << balance << endl;
}

Account::~Account()
{
	delete []cusName;
}


void NormalAccount::Deposit(double money)
{
	Account::Deposit(money);	// ���� �߰�
	Account::Deposit(money * (interRate / 100.0));	//���� �߰�.
}

void HighCreditAccount::Deposit(double money)
{
	NormalAccount::Deposit(money);
	Account::Deposit(money * (specialRate / 100.0));
}

AccountHandler::AccountHandler() :accNum(0)
{
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

void AccountHandler::ShowMenu(void) const
{
	cout << "----menu----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� " << endl;
	cout << "2. �ſ�ŷڰ���" << endl;
	cout << "����:";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��  �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditlevel;

	cout << "[�ſ뿹�ݰ��� ����]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��  �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������ : "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditlevel;

	cout << endl;

	switch (creditlevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;

	}
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "�Ա�" << endl;
	cout << "����ID"; cin >> id;
	cout << "�Աݾ�"; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "���" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;	
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

int main()
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "���� :";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;

		case DEPOSIT:
			manager.DepositMoney();
			break;

		case WITHDRAW:
			manager.WithdrawMoney();
			break;

		case INQUIRE:
			manager.ShowAllAccInfo();
			break;

		case EXIT :
			return 0;

		default :
			cout << " Illegal selection" << endl;
		}
	}
	return 0;
}