#include <iostream>
#include <cstring>

using namespace std;

int blankIndex(string str);

class Node {
public:
    double arr;
    Node *nextWord;
    Node *prev;
};

class List {
public:
    List() { head = NULL; }

    ~List();

    bool IsEmpty() { return head == NULL; }

    Node *InsertNode(int index, double x);

    void FindNode(double x);

    int DeleteNode(double x, int dIDX);

    void DisplayList();

private:
    Node *head;
};

Node *List::InsertNode(int index, double x) {
    if (index < 0) return NULL;

    int currIndex = 1;
    Node *currNode = head;
    while (currNode && index > currIndex) {
        currNode = currNode->nextWord;
        currIndex++;
    }

    if (index > 0 && currNode == NULL) return NULL;
    Node *newNode = new Node;
    newNode->arr = x;

    if (index == 0) {
        newNode->nextWord = head;
        head = newNode;
    } else {
        newNode->nextWord = currNode->nextWord;
        currNode->nextWord = newNode;
    }
    return newNode;
}

void List::FindNode(double x) {
    Node *currNode = head;
    int currIndex = 1;
    while (currNode) {
        if (currNode->arr == x) {
            cout << "Found Index : " << currIndex << endl;
            currNode = currNode->nextWord;
            currIndex++;
        } else {
            currNode = currNode->nextWord;
            currIndex++;
        }

    }
}

int List::DeleteNode(double x, int dIDX) {
    Node *prevNode = NULL;
    Node *currNode = head;
    while (currNode && currNode->arr != x) {
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

void List::DisplayList() {
    int num = 0;
    Node *currNode = head;
    while (currNode != NULL) {
        cout << currNode->arr << endl;
        currNode = currNode->nextWord;
        num++;
    }
    cout << "Number of nodes in the list : " << num << endl;
}

List::~List() {
    Node *currNode = head, *nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->nextWord;
        delete currNode;
        currNode = nextNode;
    }
}

int main() {
    List list;
    char *command = new char;
    char *cmd = new char;
    char *number = new char;
    int idx = 0, blank = 0;
    int findIndex = 1;
    int deleteIndex = 1;
    double num = 0;
    do {
        cout << "Please Enter Command(1: insert, 2: find, 3: delete, 4: print, 5: quit) : ";
        cin.getline(cmd, 100);
        blank = blankIndex(cmd);
        for (int i = 0; i < blank; i++) {
            command[i] = cmd[i];
        }
        command[blank] = '\0';
        int k = 0;
        for (int i = blank + 1; cmd[i] != '\0'; i++) {
            number[k] = cmd[i];
            k++;
        }
        number[k] = '\0';
        num = stod(number);
        if (strcmp(command, "insert") == 0) {
            list.InsertNode(idx, num);
            idx++;
        }
        if (strcmp(command, "find") == 0) {
            list.FindNode(num);
        }
        if (strcmp(command, "delete") == 0) {
            deleteIndex = list.DeleteNode(num, deleteIndex);
            while (deleteIndex > 0)
                deleteIndex = list.DeleteNode(num, deleteIndex);
            deleteIndex = 1;
        }
        if (strcmp(command, "print") == 0) {
            list.DisplayList();
        }
    } while (strcmp(command, "quit") != 0);
    return 0;
}

int blankIndex(string str) {
    int idx = 0;
    while (str[idx] != NULL) {
        if (str[idx] == ' ') {
            break;
        }
        idx++;
    }
    return idx;
}