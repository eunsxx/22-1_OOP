#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream fout;        // ���� ��� ��ü ����
    fout.open("Assignment.txt");   // a.txt��� ���� ����
    fout << "7 41 4 21 9 8 65 32 14 55 24 32 66 54 3 1 74 37 99 93";   // coutó�� ����ϱ� ( a.txt�� ��� )
    fout << endl;
    fout.close();

    ifstream fin("Assignment.txt", ios_base::in);  // �Է� ����

    int num[21]; // ������ ������ �Է¹��� ����
    for (int i = 0; i < 20; i++) {
        fin >> num[i];   // a.txt�� ������ str�� �Է� �޽��ϴ�.
    }
    cout << "input array : ";
    for (int j = 0; j < 20; j++) {
        cout << num[j] << ' ';
    }
    printf("\n");
    int temp;
    for (int i = 19; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }

        }
    }
    cout << "sorted array : ";
    for (int j = 0; j < 20; j++) {
        cout << num[j] << ' ';
    }
    fin.close(); // ������ �ݽ��ϴ�.
}