#include <iostream>
using namespace std;

int main() {
    double A, B;
    cout << "Enter Two Number :";
    cin >> A >> B;
    if (A > B)
        cout << A << " > " << B << endl;
    else if (A < B)
        cout << A << " < " << B << endl;
    else
        cout << A << " = " << B << endl;
    return 0;
}