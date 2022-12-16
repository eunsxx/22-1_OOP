#include <iostream>

using namespace std;
static int idx = 0;
static int num = 0;
static char *arr = new char[100];

char *my_strtok(char *string) {
    /*
     * 1. string의 첫 /을 NULL로 바꾸고, 처음부터 / 까지를 string[idx]에 저장
     * 2. 다음 /를 널로 바꾼 후 이전 출력 이후부터 /까지를 string[++idx]에 저장
     */
    if (string == NULL) {
        string = &arr[++num];
        arr = string;
        num = 0;

        if (arr == NULL) {
            return NULL;
        }

        while (arr[num] != NULL) {
            if (arr[num] == '/') {
                arr[num] = NULL;
                return arr;
            }
            num++;
        }
        num--;
        return arr;

    } else {
        while (arr[num] != NULL) {
            if (arr[num] == '/') {
                arr[num] = NULL;
                return arr;
            }
            num++;
        }
    }
    return arr;
}

int main() {
    char **string = new char *[10];

    cout << "Please Enter Any String :";
    cin >> arr;
    string[idx] = my_strtok(arr);
    while (string[idx] != NULL) {
        if (num < 0)
            break;
        string[++idx] = my_strtok(NULL);
    }
    for (int i = 0; i < idx; i++)
        cout << string[i] << endl;

    delete[] string;
    return 0;
}