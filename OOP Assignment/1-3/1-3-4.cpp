#include <iostream>

using namespace std;

int main() {
    int past_x[5] = {0,};
    int past_y[5] = {0,};
    char command = 'c'; // �ʱ�ȭ�� ���� q�� ������ ���ڷ� �ʱ�ȭ
    int x = 0, y = 0; // Node�� ��ġ
    int index = 1;
    while (command != 'q') { // ��ɾ q�� ��� while�� ����
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
        cin >> command; // ��ɾ� �Է�
        switch (command) { // ��ɾ ���� ����� ��ġ ����
            case 'a' :
                if (x != 0) {
                    x -= 1;
                    break;
                } else { // ���� ���� node�� x ��ġ�� 0�̶�� ������ ������ �Ѿ�Ƿ� �Է� ����
                    index--;
                    break;
                }
            case 'd' :
                if (x != 4) {
                    x += 1;
                    break;
                } else { // ���� node x ��ġ�� 2��� 1�� ���� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    index--;
                    break;
                }
            case 'w' :
                if (y != 0) {
                    y -= 1;
                    break;
                } else { // ���� node y ��ġ�� 0�̸� 1�� �� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    index--;
                    break;
                }
            case 's' :
                if (y != 4) {
                    y += 1;
                    break;
                } else { // ���� node y ��ġ�� 2��� 1�� ���� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    index--;
                    break;
                }
            case 'q' :
                break;
            default:
                cout << "�������� �ʴ� ��ɾ��Դϴ�." << endl;
        }
        past_x[index % 5] = x;
        past_y[index % 5] = y;
        index++;
    }
    return 0;
}