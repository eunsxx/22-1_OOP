#include <iostream>

using namespace std;
static int num = 0;

int blankIndex(char *string);
char *wordInput(int blank, const char *string);
int stringCompare(char *s1, char *s2);
int size(char s1[]);
//int findNum(char ** wordList, char * find);


int main() {
    char **word = new char *[100]; // ������ �ܾ� ���
    char *string = new char; // �Է�
    char *command = new char; // �Է� �� ��ɾ ����
    char * findWord = new char;
    char s1[] = "INSERT";
    char s2[] = "FIND";
    char s3[] = "END";

    while (true) {
        cin.getline(string, 100); // �������� �Է�
        int blank = blankIndex(string); // ������ ��ġ�� �ε��� ã��
//        cout << "blank = " << blank << endl;
        for (int i = 0; i < blank; i++) { // ���� �������� ���ڸ� ��ɾ ����
            command[i] = string[i];
        }
        command[blank] = '\0';
//        cout << "string = " << string << endl;
//        cout << "command = " << command << endl;

        if (stringCompare(command, s3) == 0) { // END
            break;
        }
        if (stringCompare(command, s1) == 0) { // INSERT
//            cout << "string Compare Success" << endl;
            // �Է�
            word[num] = wordInput(blank, string); // word�� �ܾ� ����

            // ����
            if (num > 0) {
                for (int i = 0; i < num; i++) {
                    for (int j = i+1; j < num + 1; j++) {
                        if (stringCompare(word[i], word[j]) == 0) {
                            int len1 = size(word[i]);
                            int len2 = size(word[j]);
                            if (len1 > len2) {
                                char *temp = word[i];
                                word[i] = word[j];
                                word[j] = temp;
                            } else if (len1 == len2) {
                                if (stringCompare(word[i], word[j]) == 0) {
                                    num--;
                                }
                            }
                        }
                        else if (stringCompare(word[i], word[j]) == 1) {
                            char * temp = word[i];
                            word[i] = word[j];
                            word[j] = temp;
                        }
                    }
                }
            }
            // ���
            for (int i = 0; i <= num; i++) {
                cout << i << "." << word[i] << endl;
            }
            num++;
        }

        if (stringCompare(command, s2) == 0) { // FIND
            findWord = wordInput(blank, string);
            int status = 0;
            for (int i = 0; i < num; i++) {
                int findSize = size(findWord);
                int wordSize = size(word[i]);
                if (findSize == wordSize){
                    int idx = stringCompare(findWord, word[i]);
                    if (idx == 0){
                        status = i;
                        break;
                    }
                    else {
                        status = -1;
                    }
                }
                else {
                    status = -1;
                }
            }
            if (status != -1) {
                cout << status << "." << word[status] << endl;
            } else {
                cout << "Not Found" << endl;
            }
        }
    }

    delete findWord;
    delete[] word;
    delete string;
    delete command;
    return 0;
}

int blankIndex(char *string) {
    int idx = 0;
    while (string[idx] != NULL) {
        if (string[idx] == ' ') {
            break;
        }
        idx++;
    }
    return idx;
}

char *wordInput(int blank, const char *string) {
    char *arr = new char;
    int i = 0;
    for (int k = blank + 1; string[k] != '\0'; k++) {
        arr[i] = string[k];
        i++;
    }
    return arr;
}

int stringCompare(char s1[], char s2[]) {
    int i = 0, j = 0, k=0;
    char * si1 = new char;
    char * si2 = new char;
//    cout << "s1 = " << s1 << endl;
//    cout << "s2 = " << s2 << endl;
    while (s1[j] != '\0') {
        if (s1[j] >= 'A' && s1[j] <= 'Z') {
            si1[j] = (char)(s1[j] +32);
        }
        else {
            si1[j] = s1[j];
        }
        j++;
    }
    while (s2[k] != '\0') {
        if (s2[k] >= 'A' && s2[k] <= 'Z') {
            si2[k] = (char)(s2[k] +32);
        }
        else {
            si2[k] = s2[k];
        }
        k++;
    }
//    cout << "si1 = " << si1 << endl;
//    cout << "si2 = " << si2 << endl;
    while (si1[i] != '\0' && si2[i] != '\0') {
        if (si1[i] > si2[i]) {
            return 1;
        } else if (si1[i] < si2[i]) {
            return -1;
        }
        i++;
    }
    delete si1;
    delete si2;
    return 0;
}

int size(char s1[]) {
    int i = 0;
    while(s1[i] != '\0') {
        i++;
    }
    return i;
}