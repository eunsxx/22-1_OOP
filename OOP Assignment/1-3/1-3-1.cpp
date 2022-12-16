#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream fout;        // 파일 출력 객체 생성
    fout.open("Assignment.txt");   // a.txt라는 파일 열기
    fout << "7 41 4 21 9 8 65 32 14 55 24 32 66 54 3 1 74 37 99 93";   // cout처럼 출력하기 ( a.txt에 출력 )
    fout << endl;
    fout.close();

    ifstream fin("Assignment.txt", ios_base::in);  // 입력 파일

    int num[21]; // 파일의 내용을 입력받을 변수
    for (int i = 0; i < 20; i++) {
        fin >> num[i];   // a.txt의 내용을 str이 입력 받습니다.
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
    fin.close(); // 파일을 닫습니다.
}