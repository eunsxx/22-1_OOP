#include<iostream>
#include <cstring>

using namespace std;

class Node {
public:
    char *arr = new char;
    Node *nextWord;
};

class List {
private:
    Node *head, *tail;

public:
    List() {
        head = tail = NULL;
    }

    ~List() {
        DeleteWord();
    }

    void InsertWord(char *word) {
        if (NULL != head) {
            tail->nextWord = new Node;
            tail = tail->nextWord;
        } else {
            head = new Node;
            tail = head;
        }
        strcpy(tail->arr, word);
        tail->nextWord = NULL;
    }

    void DisplayWord() {
        Node *currNode = head;

        while (NULL != currNode) {
            cout << currNode->arr << "-> ";
            currNode = currNode->nextWord;
        }
        cout << endl;
    }

    void DeleteWord() {
        if (head != NULL) {
            Node *p = head, *prevNode;

            while (NULL != p) {
                prevNode = p->nextWord;
                delete p;
                p = prevNode;
            }
            head = tail = NULL;
        }
    }

    int SearchWord(char *word) {
        Node *w = head;
        char carr[100];
        char cword[100];
        while (NULL != w) {
            int i = 0, j = 0;
            while (w->arr[i] != '\0') {
                if (w->arr[i] >= 'A' and w->arr[i] <= 'Z') {
                    carr[i] = w->arr[i] + 32;
                } else {
                    carr[i] = w->arr[i];
                }
                i++;
            }
            carr[i] = '\0';

            while (word[j] != '\0') {
                if (word[j] >= 'A' and word[j] <= 'Z') {
                    cword[j] = word[j] + 32;
                } else {
                    cword[j] = word[j];
                }
                j++;
            }
            cword[j] = '\0';

            if (strcmp(carr, cword) == 0) {
                cout << "Already Exists" << endl;
                while (NULL != w) {
                    w = w->nextWord;
                }
                return 1;
            }
            else {
                w = w->nextWord;
            }
        }
        return 0;
    }

    void CheckWord(char *word) {
        if (strcmp(word, "exit") == 0) {
            DeleteWord();
            exit(0);
        }
    }
};

int main() {
    List list;
    char word[100];
    char prev_word[100]{};
    for (int index = 0; ; index++) {
        cout << "CMD(Word/exit)>> ";
        cin >> word;
        int result = 0;
        list.CheckWord(word);
        result = list.SearchWord(word);
        if (word[0] == prev_word[strlen(prev_word) - 1] || word[0] == prev_word[strlen(prev_word) - 1] - 32 ||
            word[0] == prev_word[strlen(prev_word) - 1] + 32 || index == 0) {
            if (result != 1){
                list.InsertWord(word);
                list.DisplayWord();
                strcpy(prev_word, word);
            } else if (result == 1) {
                list.DisplayWord();
            }
        } else {
            cout << "Not Chained" << endl;
            list.DisplayWord();
        }
    }
    return 0;
}