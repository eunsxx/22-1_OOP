#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter any Number :";
    cin >> N;
    for (int i = 1; i < 21; i++) {
        cout << i << '\t' << '\t';
        if (i % N == 0)
            printf("\n");
    }
    return 0;
}