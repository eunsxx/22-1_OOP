#include <iostream>
using namespace std;

class Person {
    friend ostream& operator<< (ostream&, const Person&);
    friend istream& operator>> (istream&, Person&);
private:
    char name[20];
    int age;
    char live[30];
};

istream& operator>> (istream& input, Person& P) {
    input >> P.name >> P.age >> P.live;
    return input;
}
ostream& operator<< (ostream& output, const Person& P) {
    output << "�̸� : " << P.name << endl;
    output << "���� : " << P.age << endl;
    output << "������ : " << P.live << endl;
    return output;
}

int main() {
    Person P;
    cin >> P;
    cout << P;
    return 0;
}