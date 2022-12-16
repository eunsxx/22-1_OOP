#include <iostream>
#include <cmath>
using namespace std;
int strCmp(char* s1, char* s2);
char* my_strtok(char* command);
int stoi(char* str);
static int num = 0;
static int idx = 0;
static char* arr = new char[100];

class Student_info {
private:
    char name[10];
    int age = 0;
    char university[100];
    char major[100];
public:
    Student_info() = default;
    Student_info(char* name, int age, char* univ, char* major);
    bool find(char* name);
    void print();
    void change(char* name, int age, char* univ, char* major);
    ~Student_info() = default;
};

Student_info::Student_info(char* name, int age, char* univ, char* major) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        this->name[i] = name[i];
    }
    this->name[i] = '\0';
    this->age = age;
    for (i = 0; univ[i] != '\0'; i++) {
        this->university[i] = univ[i];
    }
    this->university[i] = '\0';
    for (i = 0; major[i] != '\0'; i++) {
        this->major[i] = major[i];
    }
    this->major[i] = '\0';
}

bool Student_info::find(char* name) {
    int status = strcmp(this->name, name);
    if (status == 0)
        return true;
    else
        return false;
}

void Student_info::print() {
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "University : " << university << endl;
    cout << "Major : " << major << endl;
    cout << "---------------" << endl;
}

void Student_info::change(char* name, int age, char* univ, char* major) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        this->name[i] = name[i];
    }
    this->name[i] = '\0';
    this->age = age;
    for (i = 0; univ[i] != '\0'; i++) {
        this->university[i] = univ[i];
    }
    this->university[i] = '\0';
    for (i = 0; major[i] != '\0'; i++) {
        this->major[i] = major[i];
    }
    this->major[i] = '\0';
}

int main() {
    Student_info* student = new Student_info[10];
    char command[100];
    int index = 0;
    char cmd1[] = "insert";
    char cmd2[] = "find";
    char cmd3[] = "change";
    char cmd4[] = "print";
    char cmd5[] = "exit";
    char** string = new char* [10];

    do {
        cout << "Please Enter Command(insert, find, change, print, exit) :";
        cin.getline(command, 100);

        if (strCmp(command, cmd1) == 0) { // insert
            arr = command;
            idx = 0, num = 0;
            string[idx] = my_strtok(arr);
            while (string[idx] != NULL) {
                if (num < 0)
                    break;
                string[++idx] = my_strtok(NULL);
            }
            student[index] = Student_info(string[1], stoi(string[2]), string[3], string[4]);
            index++;
        }
        if (strCmp(command, cmd2) == 0) { // find
            cout << "----------find----------" << endl;
            arr = command;
            idx = 0, num = 0;
            string[idx] = my_strtok(arr);
            while (string[idx] != NULL) {
                if (num < 0)
                    break;
                string[++idx] = my_strtok(NULL);
            }
            int status = 0;
            for (int i = 0; i < index; i++) {
                if (student[i].find(string[1])) {
                    student[i].print();
                    status = 0;
                    break;
                }
                else
                    status = -1;
            }
            if (status == -1)
                cout << "Not Found" << endl;
        }
        if (strCmp(command, cmd3) == 0) { // change
            arr = command;
            idx = 0, num = 0;
            string[idx] = my_strtok(arr);
            while (string[idx] != NULL) {
                if (num < 0)
                    break;
                string[++idx] = my_strtok(NULL);
            }

            int status = 0;
            for (int i = 0; i < index; i++) {
                if (student[i].find(string[1])) {
                    student[i].change(string[2], stoi(string[3]), string[4], string[5]);
                    status = 0;
                    break;
                }
                else
                    status = -1;
            }
            if (status == -1)
                cout << "Not Found" << endl;
        }
        if (strCmp(command, cmd4) == 0) { // print
            cout << "----------print----------" << endl;
            for (int i = 0; i < index; i++) {
                student[i].print();
            }

        }

    } while (strCmp(command, cmd5) != 0);

    delete[] student;
    delete[] string;
    return 0;
}

int strCmp(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1;
        }
        else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    return 0;
}

char* my_strtok(char* command) {
    /*
     * 1. string의 첫 ' '을 NULL로 바꾸고, 처음부터 ' ' 까지를 command[idx]에 저장
     * 2. 다음 ' '를 널로 바꾼 후 이전 출력 이후부터 ' '까지를 command[++idx]에 저장
     */
    if (command == NULL) {
        command = &arr[++num];
        arr = command;
        num = 0;

        if (arr == NULL) {
            return NULL;
        }

        while (arr[num] != NULL) {
            if (arr[num] == ' ') {
                arr[num] = NULL;
                return arr;
            }
            num++;
        }
        num--;
        return arr;

    }
    else {
        while (arr[num] != NULL) {
            if (arr[num] == ' ') {
                arr[num] = NULL;
                return arr;
            }
            num++;
        }
    }
    return arr;
}

int stoi(char* str) {
    int value = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if ('0' <= ch && ch <= '9') {
            value = value * 10 + ch - '0';
            i++;
        }
        else
            break;
    }
    return value;
}