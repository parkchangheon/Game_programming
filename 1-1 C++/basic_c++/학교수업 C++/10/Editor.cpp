#include<iostream>
#include<vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() {
		draw();
	}
};

class Circle :public Shape {
protected:
	virtual void draw() { cout << "Cirlce" << endl; }
};


class Rect :public Shape {
protected:
	virtual void draw() { cout << "Rectangle" << endl; }
};


class Line :public Shape {
protected:
	virtual void draw() { cout << "Line" << endl; }
};




int main() {
	int selector;
	vector<Shape *> v;
	vector<Shape*>::iterator it;

	cout << "�׷��� �������Դϴ�."<<endl;
	while (true) {
		cout << "���� :1, ����:2, ��κ���:3, ����:4 >>";
		cin >> selector;
		switch (selector) {
		case 1: {
			int n;
			cout << "��:1, ��:2, �簢��:3 >> ";
			cin >> n;
			switch (n) {
			case 1:
				v.push_back(new Line());
				break;

			case 2:
				v.push_back(new Circle());
				break;

			case 3:
				v.push_back(new Rect());
				break;

			default:
				cout << "�߸��� �����Դϴ�." << endl;
				break;
			}
			break;
		}

		case 2: {
			int n;
			cout << "�����ϰ��� �ϴ� ���� �ε��� >>";
			cin >> n;
			if (n > v.size() || n < 0) { // ����ó��
				cout << "�ε��� �Է� ����" << endl;
				break;
			}
			it = v.begin();
			v.erase(it + n);
			break;
		}
		case 3: {
			int i = 0;
			for (it = v.begin(); it != v.end(); it++, i++) {
				cout << i << ": ";
				v.at(i)->paint();
			}
			break;
		}
		case 4:
			return 0;

		default:
			cout << "�߸��� ����Դϴ�." << endl;
			break;

		}
	}
}