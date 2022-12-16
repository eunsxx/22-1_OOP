#include <iostream>

using namespace std;

int main() {
    int arr[3][3] = {0,};
    char command = 'c'; // 초기화를 위해 q를 제외한 문자로 초기화
    int x = 0, y = 0; // Node의 위치
    while (command != 'q') { // 명령어가 q인 경우 while문 중지
        for (int i = 0; i < 3; i++) { // 보드 출력
            for (int j = 0; j < 3; j++) {
                if (i == y and j == x)
                    cout << 'x' << '\t' << '\t';
                else
                    cout << arr[i][j] << '\t' << '\t';
            }
            printf("\n");
        }
        cout << "Enter Move Command(a : Left, d : Right, w : Up, s : Down, q : finish) :";
        cin >> command; // 명령어 입력
        switch (command) { // 명령어에 따라 노드의 위치 변경
            case 'a' :
                if (x != 0) {
                    x -= 1;
                    break;
                } else // 만약 현재 node의 x 위치가 0이라면 보드의 범위를 넘어가므로 입력 무시
                    break;
            case 'd' :
                if (x != 2) {
                    x += 1;
                    break;
                } else // 현재 node x 위치가 2라면 1을 더할 경우 보드의 범위를 넘어가므로 입력 무시
                    break;
            case 'w' :
                if (y != 0) {
                    y -= 1;
                    break;
                } else // 현재 node y 위치가 0이면 1을 뺄 경우 보드의 범위를 넘어가므로 입력 무시
                    break;
            case 's' :
                if (y != 2) {
                    y += 1;
                    break;
                } else // 현재 node ㅛ 위치가 2라면 1을 더할 경우 보드의 범위를 넘어가므로 입력 무시
                    break;
            case 'q' :
                break;
            default:
                cout << "존재하지 않는 명령어입니다." << endl;
        }
    }
    return 0;
}