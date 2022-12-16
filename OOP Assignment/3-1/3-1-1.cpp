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
    output << "이름 : " << P.name << endl;
    output << "나이 : " << P.age << endl;
    output << "거주지 : " << P.live << endl;
    return output;
}

int main() {
    Person P;
    cin >> P;
    cout << P;
    return 0;
}