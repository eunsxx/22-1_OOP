#include <iostream>
using namespace std;

int main() {
    string name, major;
    int ID;
    cout << "이름 : " ;
    cin >> name;
    cout << "학번 : " ;
    cin >> ID;
    cout << "전공 : " ;
    cin >> major;

    cout << major << " " << ID << " " << name << endl;

    return 0;
}