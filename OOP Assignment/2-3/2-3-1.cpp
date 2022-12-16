#include <iostream>
using namespace std;

class A{
private:
    int num;
public:
    A(); // 持失切
    ~A(); // 社瑚切
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
    A A; // 梓端
    return 0;
}