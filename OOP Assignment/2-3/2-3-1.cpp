#include <iostream>
using namespace std;

class A{
private:
    int num;
public:
    A(); // ������
    ~A(); // �Ҹ���
};

A::A() {
    cout << "Enter Any Number :";
    cin >> num;
    cout << "Class A is Created with " << num << endl;
}

A::~A() {
    cout << "Class A is Destroyed with " << num << endl;
}

int main() {
    A A; // ��ü
    return 0;
}