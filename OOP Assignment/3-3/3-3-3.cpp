#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static int totalTime = 1;

using namespace std;

struct Node {
    char *food = new char;
    int time;
    Node *next;
};

class Queue {
public:
    Node *front, *rear;
    int len = 0;

    Queue() {
        front = rear = nullptr;
    }

    int size() { return len; }

    bool isEmpty() { return len == 0; }

    void push(char *food, int time) {
        Node *node = new Node;
        strcpy(node->food, food);
        node->time = time;
        node->next = NULL;
        if (isEmpty()) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = rear->next;
        }
        len++;
    }

    void pop() {
//        if (isEmpty()) { cout << "Q is Empty!" << endl; }
        Node *delNode = front;
        cout << "Done!(" << delNode->food << ")" << "\t";
        front = delNode->next;
        free(delNode);
        len--;
    }

    void cooking(unsigned int t) {
        Node* cookNode = front;
        cout << "Cooking(" << cookNode->food <<" "<< t << "/" << cookNode->time << ")";
    }
};

int main() {
    Queue Jack;
    Queue Bob;
    Queue John;

    string str;
    string strJack[7];
    string strBob[7];
    string strJohn[9];
    int i = 0, j=0, k=0, l = 0;

    ifstream file1;
    file1.open("Assignment3-3-3-1.txt");
    if (file1.is_open()) {
        while (!file1.eof()) {
            if (i < 7) {
                getline(file1, str);
                strJack[l] = str;
                l++;
            } else if (i >= 7 && i < 14) {
                getline(file1, str);
                strBob[j] = str;
                j++;
            } else if (i >= 14 && i < 23){
                getline(file1, str);
                strJohn[k] = str;
                k++;
            }
            i++;
        }
    }

    char * food = new char;
    string chef;
    string arr;
    string time;
    int status = 0;

    ifstream file2;
    file2.open("Assignment3-3-3-2.txt");
    if (file2.is_open()) {
        while (!file2.eof()) {
            file2 >> str;
            cout << "New order : " << str << endl;
            do {
                cout << "Pick Cooker : ";
                cin >> chef;
                if (chef == "Jack") {
                    for (int m = 0; m < 7; m++) {
                        istringstream ss(strJack[m]);
                        ss >> arr >> food >> time;
                        if (food == str) {
                            Jack.push(food, stoi(time));
                            status = -1;
                            break;
                        }
                    }
                } else if (chef == "Bob") {
                    for (int m = 0; m < 7; m++) {
                        istringstream ss(strBob[m]);
                        ss >> arr >> food >> time;
                        if (food == str) {
                            Bob.push(food, stoi(time));
                            status = -1;
                            break;
                        }
                    }
                } else if (chef == "John") {
                    for (int m = 0; m < 9; m++) {
                        istringstream ss(strJohn[m]);
                        ss >> arr >> food >> time;
                        if (food == str) {
                            John.push(food, stoi(time));
                            status = -1;
                            break;
                        }
                    }
                }
            } while (status != -1);
        }
    }

    unsigned int jackTime = Jack.front->time -1;
    unsigned int johnTime= John.front->time -1;
    unsigned int bobTime = Bob.front->time -1;

//    cout << "jackTime = " << jackTime;
    cout << "\t\t\t\t" << "Jack" << "\t\t\t\t\t" << "John" << "\t\t\t\t\t\t" << "Bob" << endl;

    while (!Jack.isEmpty() || !John.isEmpty() || !Bob.isEmpty()) {
        cout << "\t\t";
        if (!Jack.isEmpty()) {
            if (jackTime == 0) {
                cout << "\t";
                Jack.pop();
                if (!Jack.isEmpty()) {
                    jackTime = Jack.front->time - 1;
                }
            } else {
                Jack.cooking(jackTime);
                jackTime--;
            }
        }
        cout << "\t\t";
        if (!John.isEmpty()) {
            if (johnTime == 0) {
                John.pop();
                if (!John.isEmpty()) {
                    johnTime = John.front->time - 1;
                }
            } else {
                John.cooking(johnTime);
                johnTime--;
            }
        }
        cout << "\t\t";
        if (!Bob.isEmpty()) {
            if (bobTime == 0) {
                cout << "\t";
                Bob.pop();
                if (!Bob.isEmpty()) {
                    bobTime = Bob.front->time -1;
                }
            } else {
                Bob.cooking(bobTime);
                bobTime--;
            }
        }
        if (Jack.isEmpty() && John.isEmpty() && Bob.isEmpty()) {
            cout << endl << endl;
            cout << "Total Time is : " << totalTime;
            break;
        }
        cout << endl;
        totalTime++;
    }

    delete food;

    file1.close();
    file2.close();
    return 0;
}