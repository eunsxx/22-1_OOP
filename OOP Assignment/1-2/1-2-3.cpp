#include <iostream>

using namespace std;

int main() {
    int arr[3][3] = {0,};
    char command = 'c'; // �ʱ�ȭ�� ���� q�� ������ ���ڷ� �ʱ�ȭ
    int x = 0, y = 0; // Node�� ��ġ
    while (command != 'q') { // ��ɾ q�� ��� while�� ����
        for (int i = 0; i < 3; i++) { // ���� ���
            for (int j = 0; j < 3; j++) {
                if (i == y and j == x)
                    cout << 'x' << '\t' << '\t';
                else
                    cout << arr[i][j] << '\t' << '\t';
            }
            printf("\n");
        }
        cout << "Enter Move Command(a : Left, d : Right, w : Up, s : Down, q : finish) :";
        cin >> command; // ��ɾ� �Է�
        switch (command) { // ��ɾ ���� ����� ��ġ ����
            case 'a' :
                if (x != 0) {
                    x -= 1;
                    break;
                } else // ���� ���� node�� x ��ġ�� 0�̶�� ������ ������ �Ѿ�Ƿ� �Է� ����
                    break;
            case 'd' :
                if (x != 2) {
                    x += 1;
                    break;
                } else // ���� node x ��ġ�� 2��� 1�� ���� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    break;
            case 'w' :
                if (y != 0) {
                    y -= 1;
                    break;
                } else // ���� node y ��ġ�� 0�̸� 1�� �� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    break;
            case 's' :
                if (y != 2) {
                    y += 1;
                    break;
                } else // ���� node �� ��ġ�� 2��� 1�� ���� ��� ������ ������ �Ѿ�Ƿ� �Է� ����
                    break;
            case 'q' :
                break;
            default:
                cout << "�������� �ʴ� ��ɾ��Դϴ�." << endl;
        }
    }
    return 0;
}