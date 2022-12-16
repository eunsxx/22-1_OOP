#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout << "Enter Two Numbers :";
    cin >> A >> B;
    cout << A << " + " << B << ": " << A+B << endl;
    cout << A << " - " << B << ": " << A-B << endl;
    cout << A << " * " << B << ": " << A*B << endl;
    cout << A << " / " << B << ": " << (double)A/(double)B << endl;
    cout << A << " % " << B << ": " << A%B << endl;
    return 0;
}