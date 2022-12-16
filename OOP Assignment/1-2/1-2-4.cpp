#include <iostream>
using namespace std;

int tree(int result, int N) {
    if (N == 0)
        return 0;
    else {
        for (int i = 0; i < N; i++) { // n^i�� ����ϴ� ����
            result *= 2;
        }
        result = N * result; // i * (n^i)�� ����ϴ� ����
        result += tree(1, N-1); // n�� ���� ������ ���ϴ� ����
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