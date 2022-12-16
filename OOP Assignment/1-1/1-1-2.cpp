#include <iostream>
using namespace std;
unsigned long long Plus (unsigned long long n1, unsigned long long n2);

int main() {
    unsigned long long num1, num2;
    cout << "Enter Two Numbers :";
    cin >> num1 >> num2;
    cout << Plus(num1, num2);

    return 0;
}

unsigned long long Plus (unsigned long long n1, unsigned long long n2) {
    unsigned long long sum = n1 + n2;
    return sum;
}