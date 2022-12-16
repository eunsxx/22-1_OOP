#include <iostream>

using namespace std;

int main() {
    int past_x[5] = {0,};
    int past_y[5] = {0,};
    char command = 'c'; // 초기화를 위해 q를 제외한 문자로 초기화
    int x = 0, y = 0; // Node의 위치
    int index = 1;
    while (command != 'q') { // 명령어가 q인 경우 while문 중지
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == y and j == x)
                    cout << 'H';
                else if (i == past_y[0] and j == past_x[0])
                    cout << 'x';
                else if (i == past_y[1] and j == past_x[1])
                    cout << 'x';
                else if (i == past_y[2] and j == past_x[2])
                    cout << 'x';
                else if (i == past_y[3] and j == past_x[3])
                    cout << 'x';
                else if (i == past_y[4] and j == past_x[4])
                    cout << 'x';
                else
                    cout << '0';
            }
            printf("\n");
        }
        cin >> command; // 명령어 입력
        switch (command) { // 명령어에 따라 노드의 위치 변경
            case 'a' :
                if (x != 0) {
                    x -= 1;
                    break;
                } else { // 만약 현재 node의 x 위치가 0이라면 보드의 범위를 넘어가므로 입력 무시
                    index--;
                    break;
                }
            case 'd' :
                if (x != 4) {
                    x += 1;
                    break;
                } else { // 현재 node x 위치가 2라면 1을 더할 경우 보드의 범위를 넘어가므로 입력 무시
                    index--;
                    break;
                }
            case 'w' :
                if (y != 0) {
                    y -= 1;
                    break;
                } else { // 현재 node y 위치가 0이면 1을 뺄 경우 보드의 범위를 넘어가므로 입력 무시
                    index--;
                    break;
                }
            case 's' :
                if (y != 4) {
                    y += 1;
                    break;
                } else { // 현재 node y 위치가 2라면 1을 더할 경우 보드의 범위를 넘어가므로 입력 무시
                    index--;
                    break;
                }
            case 'q' :
                break;
            default:
                cout << "존재하지 않는 명령어입니다." << endl;
        }
        past_x[index % 5] = x;
        past_y[index % 5] = y;
        index++;
    }
    return 0;
}