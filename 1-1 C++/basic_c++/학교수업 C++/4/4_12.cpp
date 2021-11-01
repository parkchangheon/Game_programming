#include<iostream>
#include<string>
using namespace std;


class Circle {
    int radius;
    string name;

public:
    void setCircle(string name, int radius) { this->name = name; this->radius = radius; };
    double getArea();
    string getName() { return name; };
};


class CircleManager {
    Circle* p; 
    int size;
    int r;
    string s;
public:
    CircleManager(int size);
    ~CircleManager();
    void searchByName();
    void searchByArea(); 
};



double Circle::getArea() {
    return radius * radius * 3.14;
}

CircleManager::CircleManager(int size) {
    p = new Circle[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
        cout << "�� " << i + 1 << " �� �̸��� ������ >>";
        cin >> s >> r;
        p[i].setCircle(s, r);
    }
}

CircleManager::~CircleManager() {
    delete[]p;
}
void CircleManager::searchByName() {
    cout << "�˻��ϰ��� �ϴ� ���� �̸�>>";
    cin >> s;
    for (int i = 0; i < size; i++) {
        if (s == p[i].getName()) {
            cout << s << "�� ������ " << p[i].getArea() << endl;
        }
    }
}
void CircleManager::searchByArea() {
    cout << "�ּ� ������ ������ �Է��ϼ���>>";
    cin >> r;
    for (int i = 0; i < size; i++) {
        if (r < p[i].getArea()) {
            cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
        }
    }
}




int main() {
    int size;
    cout << "���� ���� >> ";
    cin >> size;
    CircleManager C(size);
    C.searchByName();
    C.searchByArea();
    


}