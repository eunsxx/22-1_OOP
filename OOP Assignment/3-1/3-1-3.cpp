#include <iostream>
#include <cstring>

using namespace std;

class mystring {
private:
    char *string = new char;
public:
    void print() {
        cout << string << endl;
    }
    mystring(char *newStr) {
        strcpy(string, newStr);
    }
    ~mystring() {
        delete string;
    }
    mystring operator+=(char *string2) {
        strcat(string, string2);
        return mystring(string);
    }

    mystring operator-=(char character) {
        int i = 0, c = 0;
        char *newStr = new char;
        for (; i < strlen(string); i++) {
            if (string[i] != character) {         // msg 에서 쌍따옴표 제외하는것이 목적일 경우
                newStr[c] = string[i];
                c++;
            }
        }
        newStr[c] = '\0';
        strcpy(string, newStr);
        return mystring(newStr);
    }

    mystring operator--() {
        int i = 0;
        while (string[i] != '\0') {
            i++;
        }
        string[i - 1] = '\0';

        return mystring(string);
    }

    mystring operator&&(char character) {
        int i = 0;
        while (string[i] != '\0') {
            if (string[i] != character) {
                string[i] = '0';
                i++;
            } else if (string[i] == character) {
                i++;
            }
        }
        return mystring(string);
    }
};

int main() {


    char *command = new char[1000];
    int cmd;
    char *str = new char[1000];

    cout
            << "Please Enter command(1 : add, 2 : delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
    cin.getline(command, 150);
    cmd = stoi(strtok(command, " "));
    str = strtok(NULL, " ");
    // cout << "string : ";
    mystring A(str);

    // A.print();

    while (cmd != 6) {
        cout
                << "Please Enter command(1 : add, 2 : delete_char, 3 : delete_lastchar, 4 : and_operator, 5 : print, 6 : exit) : ";
        cin.getline(command, 150);
        cmd = stoi(strtok(command, " "));
        str = strtok(NULL, " ");

        if (cmd == 1) { //string add +=
            A += str;
        } else if (cmd == 2) { //delete character -=
            A -= *str;
        } else if (cmd == 3) {// delete last character --
            --A;
        } else if (cmd == 4) {//&& 문자열에서 문자 외에 모두 0으로 변환
            A && *str;
        } else if (cmd == 5) { //print
            A.print();
        }

    }

    delete[] command;
    delete[] str;

}