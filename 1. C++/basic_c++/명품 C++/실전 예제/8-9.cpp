#include "8-9.h"
#include<iostream>
using namespace std;


int main() {

	cout << "**** �Ѽ��а��� ���Ű��� ȯ���մϴ� ****" << endl;
	while (true)
	{
		int selecter;

		reservation* r = new reservation();
		seat* s = new seat();


		cout << "���� : 1, ��� : 2, ���� : 3, ������ : 4 >> ";
		cin >> selecter;

		if (selecter == 4)
			break;

		else if (selecter == 2)
			continue;

		else if (selecter == 3)
		{
			s->seat_show();
		}
		else if (selecter == 1)
		{
			int time_selecter;
			cout << " 07�� :1, 12�� :2, 17�� :3 >> ";
			cin >> time_selecter;

			s->plane_seat(time_selecter);

			int seat_number;
			string name;
			cout << "�¼� ��ȣ >> ";
			cin >> seat_number;

			cout << "�̸� �Է� >> ";
			cin >> name;

			s->set_seat(time_selecter - 1, seat_number, name);


		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

	}
}