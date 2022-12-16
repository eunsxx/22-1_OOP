#include <iostream>
#include <ctime>

using namespace std;
int ** makeMatrix (int row, int column, int ** matrix);
void printfMatrix (int row, int column, int ** matrix);
int ** matrixMultiplication(int row1, int row2, int column2, int ** A, int ** B);

int main() {
    int row1, row2, column1, column2;
    int **matrixA;
    int **matrixB;
    int **matrixAB;

    // Matrix 만들기
    cout << "Matrix A :";
    cin >> row1 >> column1;
    matrixA = makeMatrix(row1, column1, matrixA);
    cout << "Matrix B :";
    cin >> row2 >> column2;
    matrixB = makeMatrix(row2, column2, matrixB);

    // Matrix 출력
    cout << "A Matrix :" << endl;
    printfMatrix(row1, column1, matrixA);
    printf("\n");
    cout << "B Matrix :" << endl;
    printfMatrix(row2, column2, matrixB);
    printf("\n");

    if (column1 == row2) {
        // Matrix Multiplication
        matrixAB = matrixMultiplication(row1, row2, column2, matrixA, matrixB);
        // Matrix 연산 결과 출력
        cout << "A*B Result :" << endl;
        printfMatrix(row1,column2, matrixAB);
    } else {
        printf("\n");
        cout << "Can't Operate Matrix Multiplication(" << row2 << "!=" << column1 <<")" << endl;
    }

    for (int i = 0; i < row1; ++i) {
        delete[] matrixA[i];
    }
    delete[] matrixA;

    for (int i = 0; i < row2; ++i) {
        delete[] matrixB[i];
    }
    delete[] matrixB;
//
//    for (int i = 0; i < row1; ++i) {
//        delete[] matrixAB[i];
//    }
//    delete[] matrixAB;

    return 0;
}

int ** makeMatrix (int row, int column, int ** matrix) {
    // 동적 할당
    matrix = new int*[row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    // 랜덤한 값 입력
    int random;
    srand(time(NULL));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            random = rand() % 10;
            matrix[i][j] = random;
        }
    }
    return matrix;
}

void printfMatrix (int row, int column, int ** matrix) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << matrix[i][j] << '\t' << '\t';
        printf("\n");
    }
}

int ** matrixMultiplication(int row1, int row2, int column2, int ** A, int ** B) {
    // (4,3) x (3,4) = (4,4)
    // row2 = column1이고, 계산한 행렬의 행, 열은 각각 row1, column2와 같음
    // 동적 할당
    int ** C;
    C = new int*[row1];
    for (int i = 0; i < row1; i++)
        C[i] = new int[column2];

    // 행렬 연산
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column2; j++) {
            for (int k = 0; k < row2; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return C;
}