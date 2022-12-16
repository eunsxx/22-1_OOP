#include <iostream>

using namespace std;

int main() {
    unsigned int N;
    cout << "Please enter the length of matrix: ";
    cin >> N;
    // 이차원 배열 동적 할당
    unsigned int **matrix = new unsigned int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new unsigned int[N];
    }
    unsigned int num = 1;
    int i = 0, j = 0;
    // 0으로 초기화
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            matrix[k][l] = -1;
        }
    }
    matrix[0][0] = 0;
    while (num < N*N) {
        // right
        while ((j + 1 < N) && (matrix[i][j + 1] == -1)) {
            j++;
            matrix[i][j] = num;
            num++;
        }

        // down
        while ((i + 1 < N) && (matrix[i + 1][j] == -1)) {
            i++;
            matrix[i][j] = num;
            num++;
        }

        // left
        while ((j - 1 >= 0) && (matrix[i][j - 1] == -1)) {
            j--;
            matrix[i][j] = num;
            num++;
        }

        // up
        while ((i - 1 >= 0) && (matrix[i - 1][j] == -1)) {
            i--;
            matrix[i][j] = num;
            num++;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            cout << matrix[k][l] << '\t';
        }
        cout << endl;
    }

    // 이차원 배열 동적 할당 해제
    for (int k = 0; k < N; k++) {
        delete[] matrix[k];
    }
    delete[] matrix;
    return 0;
}