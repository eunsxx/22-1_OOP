#include <iostream>
using namespace std;
int blankIndex(char *string);
char *wordInput(int blank, const char *string);
int strCmp(char *s1, char *s2);

class My_string {
private:
    char *str = new char;
public:
    My_string();
    int my_strlen();
    void my_strcpy(char *cmd);
    void my_strcat(char *cmd);
    void print();
    ~My_string();
};

My_string::My_string() {
    cout << "First String : ";
    cin >> str;
    cin.ignore();
}

int My_string::my_strlen() {
    int num = 0;
    while (str[num] != '\0')
        num++;
    return num;
}

void My_string::my_strcpy(char * cmd) {
    int num = 0;
    while (cmd[num] != '\0') {
        str[num] = cmd[num];
        num++;
    }
    str[num] = '\0';
    cout << "strcpy is done" << endl;
}

void My_string::my_strcat(char *cmd) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        i++;
    }
    while (cmd[j] != '\0') {
        str[i] = cmd[j];
        i++;
        j++;
    }
    str[i] = '\0';
    cout << "strcat is done" << endl;
}

void My_string::print() {
    cout << "Current String : " << str << endl;
}

My_string::~My_string() {
    delete str;
}

int main() {
    My_string MyStr;
    char command[100];
    int blank;
    int len;
    char cmd1[] = "strlen";
    char cmd2[] = "strcpy";
    char cmd3[] = "strcat";
    char cmd4[] = "print";
    char cmd5[] = "quit";

    do {
        cout << "Please Enter Command(strlen, strcpy, strcat, print, quit) :";
        cin.getline(command, 100);
        if (strCmp(command, cmd1) == 0) {
            len = MyStr.my_strlen();
            cout << "String Length :" << len << endl;
        }
        if (strCmp(command, cmd2) == 0) {
            blank = blankIndex(command);
            MyStr.my_strcpy(wordInput(blank, command));
        }
        if (strCmp(command, cmd3) == 0) {
            blank = blankIndex(command);
            MyStr.my_strcat(wordInput(blank, command));
        }
        if (strCmp(command, cmd4) == 0) {
            MyStr.print();
        }
    } while (strCmp(command, cmd5) != 0);

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

int strCmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }
    return 0;
}
