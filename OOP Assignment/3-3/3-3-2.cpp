#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    char * data = new char;
    Node * next, * prev;
    Node() {
        next = prev = NULL;
    }
    Node(char * arr, Node* tail){
        strcpy(data, arr);
        prev = tail;
        next = tail->next;
        next->prev = prev->next = this;
    }

    void deleteNode() {
        prev->next= next;
        next->prev = prev;
        delete this;
    }
};

class DLinkedList {
public:
    Node *head;
    Node *tail;
    DLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    ~DLinkedList() {
        while (head->next != tail)
            head->next->deleteNode();
        delete head;
        delete tail;
    }

    int findSubway(char * start) {
        Node * temp = head->next;
        while (temp != tail) {
            if (strcmp(temp->data, start) == 0) return 1;
            temp = temp->next;
        } return 0;
    }

    Node* findStation(char * start) {
        Node * temp = head->next;
        while (temp != head->prev) {
            if (strcmp(temp->data, start) == 0) return temp;
            temp = temp->next;
        } return NULL;
    }

    int find(char * start, char * end) {
        Node* startStation = findStation(start);
        Node* endStation = findStation(end);

        while (startStation != tail) {
            if (startStation == endStation) {
                startStation = findStation(start);
                while (startStation != endStation) {
                    cout << startStation->data << "->";
                    startStation = startStation->next;
                } if (startStation == endStation) {
                    cout << startStation->data;
                    break;
                }
            } else
                startStation = startStation->next;
        }
        startStation = findStation(start);
        while (startStation != head) {
            if (startStation == endStation) {
                startStation = findStation(start);
                while (startStation != endStation) {
                    cout << startStation->data << "->";
                    startStation = startStation->prev;
                } if (startStation == endStation) {
                    cout << startStation->data;
                    break;
                }
            } else
                startStation = startStation->prev;
        }
    }

    void insert(char * arr) {
        new Node(arr, tail->prev);
    }
};

class CircuitDLinkedList {
public:
    Node *head;
    CircuitDLinkedList() {
        head = new Node();
        head->prev = head->next = head;
    }
    ~CircuitDLinkedList() {
        while (head->next != head)
            head->next->deleteNode();
        delete head;
    }

    void insert(char * arr) {
        new Node(arr, head->prev);
    }

    int findSubway(char * start) {
        Node * temp = head->next;
        while (temp != head->prev) {
            if (strcmp(temp->data, start) == 0) return 2;
            temp = temp->next;
        } return 0;
    }

    Node* findStation(char * start) {
        Node * temp = head->next;
        while (temp != head->prev) {
            if (strcmp(temp->data, start) == 0) return temp;
            temp = temp->next;
        } return NULL;
    }

    void find(char * start, char * end) {
        int fcount = 0, bcount = 0;
        Node* forw = findStation(start);
        for (int i = 0; i < 50; i++) {
            if (strcmp(forw->data, end) == 0) {
                break;
            }
            forw = forw->next;
            fcount++;
        }
        Node* back = findStation(start);

        for (int i = 0; i < 50; i++) {
            if (strcmp(back->data, end) == 0) {
                break;
            }
            back = back->prev;
            bcount++;
        }

        if (fcount <= bcount) {
            Node* startST = findStation(start);
            if (strcmp(start, "시청") == 0) {
                startST = startST->next;
            }
            Node* endST = findStation(end);
            if (strcmp(end, "시청") == 0) {
                endST = endST->prev;
            }
            for (int i = 0; i < 50; i++) {
                if (startST != head->prev) {
                    cout << startST->data << "->";
                    startST = startST->next;
                    if (startST == endST) {
                        cout << startST->data;
                        break;
                    }
                } if (startST == head->prev) {
                    cout << startST->data << "->";
                    startST = startST->next;
                    startST = startST->next;
                }
            }
        } else if (fcount > bcount){
            Node* startST = findStation(start);
            if (strcmp(start, "시청") == 0) {
                startST = startST->prev;
            }
            Node* endST = findStation(end);
            if (strcmp(end, "시청") == 0) {
                endST = endST->next;
            }
            for (int i = 0; i < 50; i++) {
                cout << startST->data << "->";
                startST = startST->prev;
                if (startST == endST) {
                    cout << startST->data;
                    break;
                }
            }
        }
    }
};

int main() {
    DLinkedList * list = new DLinkedList();
    CircuitDLinkedList * Clist = new CircuitDLinkedList();

    char * arr = new char;
    char * start = new char;
    char * end = new char;

    ifstream file;
    file.open("Assignment3-3-2-1.txt");
    if (file.is_open()){
        while (!file.eof()) {
            file >> arr;
            list->insert(arr);
        }
    }

    ifstream fin;
    fin.open("Assignment3-3-2-2.txt");
    if (fin.is_open()) {
        while(!fin.eof()) {
            fin >> arr;
            Clist->insert(arr);
        }
    }

    cout << "출발역: ";
    cin >> start;
    cin.clear();
    cout << "도착역: ";
    cin >> end;
    cin.clear();

    int sub1 = list->findSubway(start);
    if (sub1 == 0) sub1 = Clist->findSubway(start);
    if (sub1 == 0) {
        cout << "출발역이 존재하지 않습니다." << endl;
        return 0;
    }

    int sub2 = list->findSubway(end);
    if (sub2 == 0) sub2 = Clist->findSubway(end);
    if (sub2 == 0) {
        cout << "도착역이 존재하지 않습니다." << endl;
        return 0;
    }

    if (strcmp(start, "시청") == 0) {
        if (sub2 == 2) sub1 = 2;
    } else if (strcmp(end, "시청") == 0) {
        if (sub1 == 2) sub2 = 2;
    }


    if (sub1 == 1 && sub2 == 1) {
        list->find(start, end);
    } else if (sub1 == 2 && sub2 == 2) {
        if(strcmp(start, "시청") == 0) cout << "시청->";
        Clist->find(start, end);
        if(strcmp(end, "시청") == 0) cout << "->시청";
    } else if (sub1 == 1 && sub2 == 2) {
        list->find(start, "시청");
        cout << "->";
        Clist->find("시청", end);
    } else if (sub1 == 2 && sub2 == 1) {
        Clist->find(start, "시청");
        cout << "->";
        list->find("시청", end);
    }

    file.close();
    fin.close();

    delete list;
    delete arr;
    delete start;
    delete end;
    return 0;
}
