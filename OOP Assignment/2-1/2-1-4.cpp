#include <iostream>
#include <ctime>

using namespace std;
int ** rowSort(int ** matrix);
int ** sumSort(int ** matrix);
void printMatrix(int ** matrix);
void printMatrixSum(int ** matrix);

int main() {
    // ���� �Ҵ�
    int ** matrix;
    matrix = new int*[10];
    for (int i = 0; i < 10; i++)
        matrix[i] = new int[11];

    // �� ����
    int random;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            random = rand()%100;
            matrix[i][j] = random;
        }
    }

    // matrix ���
    cout << "Original Matrix" << endl;
    printMatrix(matrix);

    // row sort
    cout << endl;
    cout << "Sort by row" << endl;
    matrix = rowSort(matrix);

    // �� row�� sum ���ϱ�
    for (int i = 0; i < 10; i++) {
        matrix[i][10] = 0;
        for (int j = 0; j < 10; j++) {
            matrix[i][10] += matrix[i][j];
        }
    }

    // sum�� ������ row sort matrix ���
    printMatrixSum(matrix);

    // Sort by sum
    cout << endl;
    cout << "Sort by sum" << endl;
    matrix = sumSort(matrix);

    // sum�� ������ sum sort matrix ���
    printMatrixSum(matrix);

    for (int i = 0; i < 10; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

int ** rowSort(int ** matrix) {
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 9; k++) {
            for (int j = k + 1; j < 10; j++) {
                if (matrix[i][j] < matrix[i][k]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][j];
                    matrix[i][j] = temp;
                }
            }
        }
    }
    return matrix;
}

int ** sumSort(int ** matrix) {
    int * temp;
    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (matrix[i][10] > matrix[j][10]) {
                    temp = matrix[i];
                    matrix[i] = matrix[j];
                    matrix[j] = temp;
                }
            }
        }
    }
    return matrix;
}

void printMatrix(int ** matrix) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << '\t' << '\t';
        }
        cout << endl;
    }
}

void printMatrixSum(int ** matrix) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << '\t' << '\t';
        }
        cout << "Sum is " << matrix[i][10] << "(" << &matrix[i][10] << ")" << endl;
    }
}

