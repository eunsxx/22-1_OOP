#include <iostream>
using namespace std;

void Squared(int num, int * squaredSum) {
    * squaredSum = num * num;
}

void Cubic (int num, int * cubicSum) {
    * cubicSum = num * num * num;
}

int main() {
    int num, squaredSum, cubicSum;
    cout << "Number :";
    cin >> num;
    int *squarePtr = &squaredSum;
    int *cubicPtr = &cubicSum;
    Squared(num, squarePtr);
    Cubic(num, cubicPtr);
    cout << "Number^2 : " << squaredSum << endl;
    cout << "Number^3 : " << cubicSum << endl;
    return 0;
}

