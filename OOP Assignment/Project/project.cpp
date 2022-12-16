#include <iostream>
#include <fstream>

using namespace std;

struct wordNode {
private:
    char word[100];
    wordNode *left;
    wordNode *right;
public:
    wordNode(char *_word) {
        left = nullptr;
        right = nullptr;
        setWord(_word);
    }

    char *getWord() { return word; }
    void setWord(char *_word) { strcpy(word, _word); }
    wordNode *getLeft() const { return left; }
    wordNode *getRight() const { return right; }
    void setLeft(wordNode *left) { this->left = left; }
    void setRight(wordNode *right) { this->right = right; }
};

class wordList {
public:
    wordNode *root;
    int data;

    wordList() { root = nullptr; data = 0;}
    ~wordList();

    void insertWord(char *_word) {
        wordNode *newWord = new wordNode(_word);
        wordNode *curr = root;
        if (root == nullptr) {
            root = newWord;
            data = 1;
        } else {
            while (true) {
                if (strcmp(curr->getWord(), _word) == 0) break;
                else if (strcmp(curr->getWord(), _word) > 0) {
                    if (curr->getLeft() == nullptr) {
                        curr->setLeft(newWord);
                        data++;
                        return;
                    }
                    curr = curr->getLeft();
                } else if (strcmp(curr->getWord(), _word) < 0) {
                    if (curr->getRight() == nullptr) {
                        curr->setRight(newWord);
                        data++;
                        return;
                    }
                    curr = curr->getRight();
                } else return;
            }
        }
    }
    wordNode *findMin(wordNode *n) {
        if (n == NULL) return NULL;
        while (n->getLeft() != NULL) {
            n = n->getLeft();
        }
        return n;
    }

    void Delete(char * _word) {
        if (deleteWord(root, _word)) data--;
    }
    wordNode *deleteWord(wordNode *curr, char *_word) {
        if (curr == NULL) return curr;
        if (strcmp(_word, curr->getWord()) < 0)
        {
            curr->setLeft(deleteWord(curr->getLeft(), _word));
        }
        else if (strcmp(_word, curr->getWord()) > 0)
        {
            curr->setRight(deleteWord(curr->getRight(), _word));
        }
        else {
            wordNode *temp;
            if (curr->getLeft() == NULL) {
                if (curr->getRight() == NULL) {
                    temp = curr;
                    free(curr);
                    return NULL;
                } else {
                    temp = curr->getRight();
                    free(curr);
                    return temp;
                }
            } else if (curr->getRight() == NULL) {
                temp = curr->getLeft();
                free(curr);
                return temp;
            }

            temp = findMin(curr->getRight());
            curr->setWord(temp->getWord());
            curr->setRight(deleteWord(curr->getRight(), temp->getWord()));
        }
        return curr;
    }

    wordNode* Find(char * _word) {
        return find(root,_word);
    }

    wordNode* find(wordNode* curr, char * _word) {
        if (curr == NULL) return curr;
        if (strcmp(curr->getWord(), _word) == 0) {
//            cout << curr->getWord() << endl;
            return curr;
        }
//        cout << curr->name << "->";
        if (strcmp(curr->getWord(), _word) > 0) {
//            cout << "left" << endl;
            return find(curr->getLeft(), _word);
        } else if (strcmp(curr->getWord(), _word) < 0) {
//            cout << "right " << endl;
            return find(curr->getRight(), _word);
        }
    }
    int getData() { return data; }

    void Inorder() { inorder(root); }
    void inorder(wordNode *curr) {
        if (curr != nullptr) {
            if (curr->getLeft() != nullptr) inorder(curr->getLeft());
            cout << curr->getWord() << " ";
            if (curr->getRight() != nullptr) inorder(curr->getRight());
        }
    }

    void Preorder() { preorder(root); }
    void preorder(wordNode *curr) {
        if (curr != nullptr) {
            cout << curr->getWord() << " ";
            if (curr->getLeft() != nullptr) preorder(curr->getLeft());
            if (curr->getRight() != nullptr) preorder(curr->getRight());
        }
    }

    void Postorder() { postorder(root); }
    void postorder(wordNode *curr) {
        if (curr != nullptr) {
            if (curr->getLeft() != nullptr) postorder(curr->getLeft());
            if (curr->getRight() != nullptr) postorder(curr->getRight());
            cout << curr->getWord() << " ";
        }
    }
};

class node {
private:
    wordList *pWord;
    int x_data = 0;
    int y_data = 0;
    int z_data = 0;

public:
    node *next;
    node *prev;
    node *up;
    node *down;
    node *forward;
    node *backward;

    node() {
        next = prev = up = down = forward = backward = nullptr;
    }
    node(int z, int y, int x) {
        x_data = x;
        y_data = y;
        z_data = z;
        pWord = new wordList();
        next = prev = up = down = forward = backward = nullptr;
    }

    int getX() { return x_data; }
    int getY() { return y_data; }
    int getZ() { return z_data; }
    wordList *getPWord() { return pWord; }
    void setX(int data) { x_data = data; }
    void setY(int data) { y_data = data; }
    void setZ(int data) { z_data = data; }
    void setPWord(char *_word) { pWord->insertWord(_word); }
    void deletePWord(char* _word) { pWord->Delete(_word); }
};

class x_chart {
public:
    node *blockHead;
    x_chart *nextChart;

    x_chart(int z, int y) {
        blockHead = new node(z, y, 0);
        blockHead->next = new node(z, y, 1);
        blockHead->next->prev = blockHead;
        blockHead->next->next = new node(z, y, 2);
        blockHead->next->next->prev = blockHead->next;
        nextChart = nullptr;
    }

};

class z_chart {
public:
    x_chart *zHead;
    z_chart *nextFloat;

    z_chart(int y) {
        zHead = new x_chart(0, y);
        zHead->nextChart = new x_chart(1, y);
        connected(zHead, zHead->nextChart);
        zHead->nextChart->nextChart = new x_chart(2, y);
        connected(zHead->nextChart, zHead->nextChart->nextChart);
    }

    void connected(x_chart *Z, x_chart *nextZ) {
        connect_UD(Z->blockHead, nextZ->blockHead);
        connect_UD(Z->blockHead->next, nextZ->blockHead->next);
        connect_UD(Z->blockHead->next->next, nextZ->blockHead->next->next);
    }

    void connect_UD(node *X, node *nextX) {
        X->down = nextX;
        nextX->up = X;
    }

};

class y_cube {
private:
    z_chart *yHead;
public:
    y_cube() {
        yHead = new z_chart(0);
        yHead->nextFloat = new z_chart(1);
        connected(yHead, yHead->nextFloat);
        yHead->nextFloat->nextFloat = new z_chart(2);
        connected(yHead->nextFloat, yHead->nextFloat->nextFloat);
    }

    void connected(z_chart *Y, z_chart *nextY) {
        connect_FBNP(Y->zHead, nextY->zHead);
        connect_FBNP(Y->zHead->nextChart, nextY->zHead->nextChart);
        connect_FBNP(Y->zHead->nextChart->nextChart, nextY->zHead->nextChart->nextChart);
    }
    void connect_FBNP(x_chart *Z, x_chart *nextZ) {
        connect_FB(Z->blockHead, nextZ->blockHead);
        connect_FB(Z->blockHead->next, nextZ->blockHead->next);
        connect_FB(Z->blockHead->next->next, nextZ->blockHead->next->next);

    }
    void connect_FB(node *X, node *nextX) {
        X->backward = nextX;
        nextX->forward = X;
    }

    void insertNode(int z, int y, int x, char *_word) {
        node *pNode = findNode(z, y, x);
        pNode->setPWord(_word);
    }

    void findWord(char* _word) {
        z_chart *pZChart = yHead;
        node *curr;
        int x, y, z;
        while (pZChart != NULL) {
            x_chart *pXChart = pZChart->zHead;
            while (pXChart != NULL) {
                node *pNode = pXChart->blockHead;
                while (pNode != NULL) {
                    z = pNode->getZ();
                    y = pNode->getY();
                    x = pNode->getX();
                    curr = findNode(z, y, x);
                    if (curr->getPWord()->Find(_word) != NULL) {
                        cout << z << " " << y << " " << x << endl;
                    }
                    pNode = pNode->next;
                }
                pXChart = pXChart->nextChart;
            }
            pZChart = pZChart->nextFloat;
        }
    }
    node* findNode(int z, int y, int x) {
        z_chart *pZChart = yHead;
        while (pZChart != NULL) {
            node *pNode = pZChart->zHead->blockHead;
            if (pNode->getY() == y) {
                x_chart *pXChart = pZChart->zHead;
                while (pXChart != NULL) {
                    pNode = pXChart->blockHead;
                    if (pNode->getZ() == z) {
                        while (pNode != NULL) {
                            if (pNode->getX() == x) {
                                return pNode;
                            }
                            pNode = pNode->next;
                        }
                    }
                    pXChart = pXChart->nextChart;
                }
            }
            pZChart = pZChart->nextFloat;
        }
    }

    void removeNode(int z, int y, int x, char* _word) {
        node * pNode = findNode(z, y, x);
        pNode->deletePWord(_word);
    }

    void exchangeNode(int z, int y, int x, int z0, int y0, int x0) {
        // 000 블록과 001 블록 바꾸기
        node* node1 = findNode(0,0,0);
        node* node2 = findNode(0,0,1);
        cout << node1 << endl;
        cout << node2 << endl;

        node* temp = node1; // 기존 node1 정보를 보관해두고 있음.
        /*
         * 1. node2 자리에 node1 넣기
         * 2. temp 자리에 node2 넣기
         * 3. temp 삭제하기
         */

        /*
        if (node2->next) {
            node1->next = node2->next;
            node1->next->prev = node1;
        } else { node1->next = nullptr; }
        if (node2->prev) {
            node1->prev = node2->prev;
            node1->prev->next = node1;
        } else { node1->prev = nullptr; }
        if (node2->down) {
            node1->down = node2->down;
            node1->down->up = node1;
        } else { node1->down = nullptr; }
        if (node2->up) {
            node1->up = node2->up;
            node1->up->down = node1;
        } else { node1->up = nullptr; }
        if (node2->forward) {
            node1->forward = node2->forward;
            node1->forward->backward = node1;
        }  else { node1->forward = nullptr; }
        if (node2->backward) {
            node1->backward = node2->backward;
            node1->backward->forward = node1;
        } else { node1->backward = nullptr; }


        if (temp->next) {
            node2->next = temp->next;
            node2->next->prev = node2;
        } else { node2->next = nullptr; }
        if (temp->prev) {
            node2->prev = temp->prev;
            node2->prev->next = node2;
        } else { node2->prev = nullptr; }
        if (temp->down) {
            node2->down = temp->down;
            node2->down->up = node2;
        } else { node2->down = nullptr; }
        if (temp->up) {
            node2->up = temp->up;
            node2->up->down = node2;
        } else { node2->up = nullptr; }
        if (temp->forward) {
            node2->forward = temp->forward;
            node2->forward->backward = node2;
        }  else { node2->forward = nullptr; }
        if (temp->backward) {
            node2->backward = temp->backward;
            node2->backward->forward = node2;
        } else { node2->backward = nullptr; }
         */

        node1 = node2;
        node2 = temp;
        cout << node1 << " " << node2 << endl;

        delete temp;
    }

    void printPoint(node* pNode) {
        cout << "next = " << pNode->next->getX() << endl;
        cout << "prev = " << pNode->prev->getX() << endl;
        cout << "down= " << pNode->down->getZ() << endl;
        cout << "up= " << pNode->up->getZ() << endl;
//        cout << "forward = " << pNode->forward->getX() << endl;
//        cout << "backward = " << pNode->backward->getX() << endl;
    }
    void printWord(int z, int y, int x) {
        node * pNode = findNode(z, y, x);
        cout << "Preorder: ";
        pNode->getPWord()->Preorder();
        cout << endl << "Postorder: ";
        pNode->getPWord()->Postorder();
        cout << endl << "Inorder: ";
        pNode->getPWord()->Inorder();
        cout << endl;
    }
    void print() {
        z_chart *pZChart = yHead;
        while (pZChart != NULL) {
            x_chart *pXChart = pZChart->zHead;
            while (pXChart != NULL) {
                node *pNode = pXChart->blockHead;
                while (pNode != NULL) {
//                    cout << pNode->getZ() << " ";
//                    cout << pNode->getY() << " ";
//                    cout << pNode->getX() << " ";
                    cout << pNode->getPWord()->getData() << "\t\t";
                    pNode = pNode->next;
                }
                cout << endl;
                pXChart = pXChart->nextChart;
            }
            cout << endl;
            pZChart = pZChart->nextFloat;
        }
    }
};

int main() {
    y_cube cube;
    ifstream file;
    int x, y, z;
    int x1, y1, z1;
    char word[100];
    int cmd;
    file.open("WordBook.txt");
    if (!file.is_open()) {
        cout << "file is not open" << endl;
    } else {
        while (!file.eof()) {
            file >> z >> y >> x >> word;
            cube.insertNode(z, y, x, word);
        }
    }

    do {
        cout << "Enter Any Command(1: Insert, 2: Delete, 3:Find, 4:Print, 5: Print_All, 6: Turn, 7: Exchange, 8: Exit) :";
        cin >> cmd;
        if (cmd == 1) { // TODO 해당 좌표에 단어 삽입. 1번 완성
            cin >> z >> y >> x >> word;
            cube.insertNode(z, y, x, word);
        } else if (cmd == 2) { // TODO 해당 좌표의 단어를 삭제. 2번 완성
            cin >> z >> y >> x >> word;
            cube.removeNode(z, y, x, word);
        } else if (cmd == 3) { // TODO 해당 단어가 있는 좌표 모두 출력. 3번 완성
            cin >> word;
            cube.findWord(word);
        } else if (cmd == 4) { // TODO 해당 좌표의 단어 모두 출력. 4번 완성
            cin >> z >> y >> x;
            cube.printWord(z,y,x);
        } else if (cmd == 5) { // TODO 모든 좌표에 저장된 단어 개수 각각 출력. 5번 완성
            cube.print();
        } else if (cmd == 6) { // TODO Turn 기능 수행
            cin >> z >> y >> x; // z : 0(전면), 1(윗면), 2(측면), y: 0(시계), 1(반시계), x: 0(y), 1(z), 2(x)
        } else if (cmd == 7) { // TODO 블럭 교환.
            cin >> z >> y >> x >> z1 >> y1 >> x1;
            cube.exchangeNode(z,y,x,z1,y1,x1);
        } else if (cmd == 8) break;
        else {
            cout << "잘못 입력하셨습니다." << endl;
            break;
        }
    } while (cmd != 8);

//    cube.print();
    return 0;
}