#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void length(string word[], int wordNum, int num);
int len(string word);

int main() {
    string word[101];
    ifstream file("Assignment.txt", ios_base::in);  // �Է� ����
    int i = 0;
    if (file.is_open()) {
        while (!file.eof()) { //������ ���� ���� ������ �ݺ�
            if (file.eof()) { //������ ������ �ߺ� üũ
                break;
            }
            file >> word[i];
            i++;
        }
    } else
        cout << "������ �ҷ����µ� �����߽��ϴ�." << endl;

    for (int j = 1; j < 21; j++) {
        length(word, i, j);
    }
    return 0;
}

void length(string word[], int wordNum, int num) {
    int status = 0;
    for (int i = 0; i < wordNum; i++) {
        if (len(word[i]) == num){
            status = 1;
        }
    }
    switch (status) {
        case 1:
            cout << "Length " << num << " : ";
            break;
        case 0:
            return;
    }
    for (int i = 0; i < wordNum; i++) {
        if (len(word[i]) == num){
            cout << word[i] << " ";
        }
    }

    printf("\n");
}

int len(string word) {
    int i = 0;
    while (word[i] != '\0')
        i++;
    return i;
}
