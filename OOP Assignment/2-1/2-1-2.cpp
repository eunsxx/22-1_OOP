#include <iostream>

using namespace std;

int size(char * str) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

void copy(char * str1, char * str2, char * ptr, int len1, int len2, int len) {
    int status;
    for (int i = 0; i <= len1; i++) {
        ptr[i] = str1[i];
        status = i;
    }
    for (int j = 0; j <= len2; j++) {
        ptr[status+j] = str2[j];
    }
    ptr[len+1] = '\0';
    cout << ptr << endl;
}

int main() {
    char * str1 = new char[100];
    char * str2 = new char[100];

    cout << "String 1: ";
    cin.getline(str1, 100);
    cout << "String 2: ";
    cin.getline(str2, 100);

    int len1 = size(str1);
    int len2 = size(str2);
    int len = len1 + len2;

    char * ptr = new char [100];
    cout << "Reuslt: ";
    copy(str1, str2, ptr, len1, len2, len);

    delete[] str1;
    delete[] str2;
    delete[] ptr;

    return 0;
}