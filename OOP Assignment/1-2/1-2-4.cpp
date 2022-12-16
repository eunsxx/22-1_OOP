#include <iostream>
using namespace std;

int tree(int result, int N) {
    if (N == 0)
        return 0;
    else {
        for (int i = 0; i < N; i++) { // n^i를 계산하는 과정
            result *= 2;
        }
        result = N * result; // i * (n^i)를 계산하는 과정
        result += tree(1, N-1); // n에 따른 값들을 더하는 과정
    }
    return result;
}

int main() {
    int N, result = 1;
    cout << "Enter Any Positive Number : ";
    cin >> N;
    cout << tree(result, N) << endl;
    return 0;
}