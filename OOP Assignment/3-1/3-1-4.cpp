#include <iostream>
#include <cstring>

using namespace std;

class Node {
    int strIDData;
    char * strNameData = new char;
    Node *nextWord, *prev;

    Node() {
        nextWord = prev = NULL;
        strIDData = 0;
    }

    Node(int id, char *name, Node *ptr) { //ptr 뒤에 추가한다.
        strIDData = id;
        strcpy(strNameData, name);
        prev = ptr;
        nextWord = ptr->nextWord;
        nextWord->prev = prev->nextWord = this;
    }

    void selvDelete() {
        prev->nextWord = nextWord;
        nextWord->prev = prev;
        delete this;
    }

    friend class DLinkedList;
};

class DLinkedList {
private:
    Node *head;
    Node *tail;
public:
    int count;

    DLinkedList() { //생성자
        count = 0;
        head = new Node(); //더미를 선언해서 가지고 있게한다.
        tail = new Node(); //더미를 선언해서 가지고 있게한다.
        head->nextWord = tail; //서로연결한다.
        tail->prev = head;
    }
    ~DLinkedList() { // 소멸자
        while (head->nextWord != tail)
            head->nextWord->selvDelete();
        delete head;
        delete tail;
    }

    void firstInsert(int id, char *name) { //IDhead 다음에 추가한다.
        new Node(id, name, head);
    }

    void endInsert(int id, char *name) { //IDtail 앞에 추가한다.
        new Node(id, name, tail->prev);
    }

    void sortByName() {
        Node *p = head;
        Node *temp = NULL;

        int tempID = 0;
        char tempName[10] = {0,};

        if (head == NULL) {
            return;
        }
        for (p = head; p->nextWord != NULL; p = p->nextWord) {
            for (temp = p->nextWord; temp != NULL; temp = temp->nextWord) {
                if (p->strIDData == 0) {
                    break;
                }
                if (strcmp(p->strNameData, temp->strNameData) < 0) {
                    tempID = p->strIDData;
                    p->strIDData = temp->strIDData;
                    temp->strIDData = tempID;

                    strcpy(tempName, p->strNameData);
                    strcpy(p->strNameData, temp->strNameData);
                    strcpy(temp->strNameData, tempName);
                }
            }
        }
    }

    void sortByID() {
        Node *p = head;
        Node *temp = NULL;

        int tempID = 0;
        char tempName[10];
        if (head == NULL) {
            return;
        }
        for (p = head; p->nextWord != NULL; p = p->nextWord) {

            for (temp = p->nextWord; temp != NULL; temp = temp->nextWord) {
                if (p->strIDData == 0) {
                    break;
                }
                if (p->strIDData < temp->strIDData) {
                    tempID = p->strIDData;
                    p->strIDData = temp->strIDData;
                    temp->strIDData = tempID;

                    strcpy(tempName, p->strNameData);
                    strcpy(p->strNameData, temp->strNameData);
                    strcpy(temp->strNameData, tempName);
                }
            }
        }
    }

    void TraverseBackward();
    void TraverseForward();
    int deleteNode(int id, int dIDX) {
        Node *prevNode = NULL;
        Node *currNode = head;
        while (currNode && currNode->strIDData != id) {
            prevNode = currNode;
            currNode = currNode->nextWord;
            dIDX++;
        }
        if (currNode) {
            if (prevNode) {
                prevNode->nextWord = currNode->nextWord;
                delete currNode;
            } else {
                head = currNode->nextWord;
                delete currNode;
            }
            return dIDX;
        }
        return 0;
    }
};

void DLinkedList::TraverseBackward() {
    Node *v = tail->prev;
    while (v->prev != NULL) {
        cout << v->strIDData << " ";
        cout << v->strNameData << " ";
        cout << endl;
        v = v->prev;
    }
}

void DLinkedList::TraverseForward() {
    Node *v = head->nextWord;
    while (v->nextWord != NULL) {
        cout << v->strIDData << " ";
        cout << v->strNameData << " ";
        cout << endl;
        v = v->nextWord;
    }
}

int main() {
    DLinkedList *list = new DLinkedList();
    char *command = new char;
    int ID;
    char name[100];
    string str;
    do {
        cout << "Please Enter command(1: insert, 2: print, 3: print_reverse, 4: sortByName, 5: sort_by_ID, 6: delete, 7: exit) : ";
        cin >> command;
        cin.ignore();
        if (command[0] == '1') {
            cin >> ID;
            cin.ignore();
            cin >> name;
            cin.ignore();
            list->firstInsert(ID, name);
            list->sortByID();
        }
        if (command[0] == '2') {
            list->TraverseBackward();
            cout << endl;
        }
        if (command[0] == '3') {
            list->TraverseForward();
            cout << endl;
        }
        if (command[0] == '4') {
            list->sortByName();
            list->TraverseBackward();
        }
        if (command[0] == '5') {
            list->sortByID();
            list->TraverseBackward();
        }
        if (command[0] == '6') { // delete
            cin >> ID;
            cin.ignore();
            int deleteIndex = 1;
            list->deleteNode(ID, deleteIndex);
        }
    } while (command[0] != '7');
    delete list;
}
