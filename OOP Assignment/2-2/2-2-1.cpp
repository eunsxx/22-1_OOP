#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void push(double *num, string command, int size);
void pop(double *num, int size);
void stack(double * num, int size);

int main() {
    int size = 0;
    double *num = new double[size];
    string command;
    while (1) {
        cout << "Please Enter Command(push, pop) :";
        getline(cin, command);
        if (command[1] == 'u') {
            size++;
            push(num, command, size);
            stack(num, size);
        } else if (command[1] == 'o') {
            size--;
            pop(num, size);
            stack(num, size);
        } else if (command == "q" or command == "Q") {
            cout << "����Ǿ����ϴ�." << endl;
            break;
        } else {
            cout << "�߸��� �Է��Դϴ�" << endl;
        }
    }

    delete[] num;
    return 0;
}

void push(double *num, string command, int size) {
    int numSize = 0;
    for (int i = 5; command[i] != '\0'; i++)
        numSize++;

    // ���ڸ� ���� ���� 48 ���ϱ�
    double number = 0;
    for (int i = 5; i < 5 + numSize; i++)
        number += (command[i] - 48) * pow(10, i - 5);

    num[size - 1] = number;
}

void pop(double *num, int size) {
    num[size] = -1;
}

void stack(double * num, int size) {
    for (int i = 0; i < size; i++)
        cout << num[i] << endl;
}