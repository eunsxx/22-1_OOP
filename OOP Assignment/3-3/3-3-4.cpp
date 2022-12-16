#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Path {
public:
    char * arr = new char;
    Path * next;

    Path (char * _arr) {
        strcpy(arr, _arr);
    }

    void Save (char * _arr) {
        Path * temp = next;
        if (next == NULL) next = new Path(_arr);
        else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new Path(_arr);
        }
    }
};

struct wordNode {
    char name[100];
    wordNode *left;
    wordNode *right;

    wordNode(char *_name) {
        left = nullptr;
        right = nullptr;
        setName(_name);
    }

    char *getName() { return name; }

    wordNode *getLeftName() const { return left; }

    wordNode *getRightName() const { return right; }

    void setName(char *_name) { strcpy(name, _name); }

    void setLeftName(wordNode *left) { this->left = left; }

    void setRightName(wordNode *right) { this->right = right; }
};

class bstList {
public:
    wordNode *root;

    wordNode *getRoot() { return root; } // 단어 리스트의 IDhead
    void inOrder(char *_major, int _id, wordNode *currName) {
        if (currName != nullptr) {
            if (currName->left != nullptr) inOrder(_major, _id, currName->left);
            cout << _major << " " << _id << " " << currName->name << endl;
            if (currName->right != nullptr) inOrder(_major, _id, currName->right);
        }
    }

    bool search(wordNode *root, char *_name, bool print) {
        if (root == NULL) return false;
        if (strcmp(root->name, _name) == 0) {
            if (print) cout << root->name << endl;
            return true;
        }
        if (print) {
            cout << root->name << "->";
        }
        if (strcmp(root->name, _name) > 0) {
//            cout << "left" << endl;
            return search(root->left, _name, print);
        } else if (strcmp(root->name, _name) < 0) {
//            cout << "right " << endl;
            return search(root->right, _name, print);
        }
    }

    wordNode *findMax(wordNode *n) {
        if (n == NULL) return NULL;
        while (n->right != NULL) {
            n = n->right;
        }
        return n;
    }

    wordNode *findMin(wordNode *n) {
        if (n == NULL) return NULL;
        while (n->left != NULL) {
            n = n->left;
        }
        return n;
    }

    wordNode *removeNode(wordNode ** _root, wordNode *root, char *_name) {
        if (root == NULL) return root;
        if (strcmp(_name, root->name) < 0)
        {
            root->left = removeNode(_root, root->left, _name);
        }
        else if (strcmp(_name, root->name) > 0)
        {
            root->right = removeNode(_root, root->right, _name);
        }
        else {
            wordNode *temp;
            if (root->left == NULL) {
                if (root->right == NULL) {
                    temp = root;
                    cout << "Delete_Name : " << root->name << endl;
                    free(root);
                    return NULL;
                } else {
                    temp = root->right;
                    cout << "Delete_Name : " << root->name << endl;
                    free(root);
                    return temp;
                }
            } else if (root->right == NULL) {
                temp = root->left;
                cout << "Delete_Name : " << root->name << endl;
                free(root);
                return temp;
            }

            temp = findMin(root->right);
            strcpy(root->name, temp->name);
            root->right = removeNode(_root, root->right, temp->name);
        }
//        if (*(_root) == curr && curr->left == NULL && curr->right == NULL) {
//            *(_root) = NULL;
//        }
        return root;
    }

    bstList() { root = nullptr; }

    ~bstList() {};

    void print(char *_major, int _id) {
        inOrder(_major, _id, root);
    }

    bool Find(char *_name, bool print) {
        return search(root, _name, print);
    }

    void FindNoPrint(char *_name) {
        search(root, _name, true);
    }

    bool Remove(char *_name) {
        wordNode * temp = removeNode(&root, root, _name);
        if (temp == NULL) {
            root = NULL;
            return false;
        } else {
            root = temp;
        }
        return true;
    }

    void insertName(char *_name);
};

void bstList::insertName(char *_name) {
    wordNode *newName = new wordNode(_name);
    wordNode *nameListCurr = root;
    if (root == nullptr) {
        root = newName;
    } else {
        while (true) {
            if (strcmp(nameListCurr->name, newName->name) == 0) return;
            if (strcmp(nameListCurr->name, newName->name) > 0) {
                if (nameListCurr->getLeftName() == nullptr) {
                    nameListCurr->setLeftName(newName);
                    return;
                } else {
                    nameListCurr = nameListCurr->left;
                }
            } else if (strcmp(nameListCurr->name, newName->name) < 0) {
                if (nameListCurr->getRightName() == nullptr) {
                    nameListCurr->setRightName(newName);
                    return;
                } else {
                    nameListCurr = nameListCurr->right;
                }
            } else return;
        }
    }
}

class IDNode {
public:
    int id;
    IDNode *nextID; // 다음 학번
    bstList bl;

    IDNode(int _id, char *_name) {
        nextID = nullptr;
        setID(_id);
        bl.insertName(_name);
    }

    void findName(char * _name) {
        bl.Find(_name, true);
    }


    int getID() { return id; } // node의 단어 return
    IDNode *getNextID() { return nextID; } // node의 다음 단어 return
//    wordNode* getNextName() { return nextName; }

    void setID(int id) { this->id = id; } // node의 단어 설정
    void setNextID(IDNode *next) { this->nextID = next; } // node의 다음 단어 설정

    void setNextName(char *_name) {
//        this->nextName = nextName;
//        if (nextName == NULL) {
//            nextName = new wordNode(_name);
//            return;
//        }
        bl.insertName(_name);
    }

//
    void print(char *_major) {
//        cout << _major << " " << id << " "; // TODO Problem Occurred
//        cout << "success" << endl;
        bl.print(_major, id);
    };

    bool namePath(char *_name, bool print) {
        return bl.Find(_name, print);
    }

    void namePathNoPrint(char *_name, bool print) {
        bl.Find(_name, print);
    }

//    void findName(char *_major, int _id, char* _name) {
//
//        IDNode *currID = IDHead;
//        while (currID != NULL) {
//            if (currID->id == _id) currID->print(_major);
//            currID = currID->nextID;
//        }
////        if (currID != NULL) currID->print(_major); // TODO Problem Occurred
//    }
};

class IDList { // 단어 리스트
private:
    IDNode *IDHead;
//    bstList bl;
public:
    IDList(int _id, char *_name) {
        IDHead = new IDNode(_id, _name);
    }

    IDNode *getIDHead() { return IDHead; } // 단어 리스트의 IDhead

    void removeID(IDNode **head, int _id) { // IDNode 없애는 것
        IDNode *temp = *head;
        IDNode *id;
        if (temp->nextID == NULL) {
            cout << "Delete_Year : " << temp->id << endl;
            delete temp;
            *head = NULL;
            return;
        }
        while (temp != NULL) {
            if (temp == *head && temp->id == _id) {
                cout << "Delete_Year : " << temp->id << endl;
                *head = temp->nextID;
                delete temp;
                break;
            }
            if (temp->nextID != NULL && temp->nextID->id == _id) {
                if (temp->nextID->nextID != NULL) {
                    cout << "Delete_Year : " << temp->nextID->id << endl;
                    id = temp->nextID->nextID;
                    delete temp->nextID;
                    temp->nextID = id;
                    break;
                } else {
                    cout << "Delete_Year : " << temp->nextID->id << endl;
                    id = temp->nextID->nextID;
                    delete temp->nextID;
                    temp->nextID = id;
                    break;
                }
            }
            temp = temp->nextID;
        }
    }

    void removeNameNode(IDList **Listhead, int _id, char *_name) { // name 없애는 것
        IDNode *temp = IDHead;

        while (temp != NULL) {
            if (temp->id == _id) {
                bool status = temp->bl.Remove(_name);
                if (!status) {
                    removeID(&IDHead, _id);
                }
                if (IDHead == NULL) { // IDNode 하나도 없을 때
                    IDList *temp1 = *Listhead;
                    delete temp1;
                    *Listhead = NULL;
                    break;
                } else break;
            }
            temp = temp->nextID;
        }
    }

    void print(char *_major) {
        IDNode *currID;
        currID = IDHead;
        while (currID != NULL) {
            currID->print(_major);
            currID = currID->nextID;
        }
    }

    void findNameNode (char * _name) {

    }

    void findID(char *_major, int _id) {
        IDNode *currID = IDHead;
        while (currID != NULL) {
            if (currID->id == _id) currID->print(_major);
            currID = currID->nextID;
        }
    }



    void insertID(int _id, char *_name) {
        IDNode *newIDNode = nullptr;
        IDNode *currID;
        if (IDHead == nullptr) { // head에 아무것도 없으면
            newIDNode = new IDNode(_id, _name); // 새로운 노드를 만든 후, 그것을 IDHead 지정
            IDHead = newIDNode;
        } else {
            currID = IDHead;
            while (true) {
                if (currID->nextID == nullptr) break; // 다음 ID 없으면, 바로 break;
                else if ((currID->id <= _id && currID->nextID->id > _id) ||
                         (currID == IDHead && currID->id > _id))
                    break;
                currID = currID->nextID;
            }
            if (currID == IDHead && currID->id > _id) {
                IDNode *temp;
                temp = currID;
                IDHead = new IDNode(_id, _name);
                IDHead->nextID = temp;
                cout << "curr = " << IDHead->id;
                cout << "next = " << IDHead->nextID->id << endl;
            } else {
                if (currID->id != _id) {
                    newIDNode = new IDNode(_id, _name); // 일단 공간 생성하고
                    IDNode *temp;
                    temp = currID->nextID; // curr의 다음을 temp로 설정한 다음
                    currID->nextID = newIDNode; // 지금 노드의 다음을 새로운 노드와 연결한 다음에
                    newIDNode->nextID = temp; // 새로운 노드의 다음을 temp와
                } else {
//                    cout << currID->id<<" is already exist"<<endl;
                    currID->setNextName(_name);
                }
            }
//            cout << "success" << endl;
//            newIDNode = new IDNode(_id1, _name);
//            currID->nextID = newIDNode;
        }
    }

    void IDPath(Path * path, int _id, char *_name) {
        IDNode *idNode = IDHead;
        while (idNode != NULL) {
            cout << idNode->id << "->";
            if (idNode->id == _id) {
                if (path != NULL) {
                    char num_char[10];
                    sprintf(num_char, "%d", _id);
                    path->Save(num_char);
                }
                break;
            }
            idNode = idNode->nextID;
        }
        if (idNode != NULL) {
            bool print;
            print = idNode->namePath(_name, false);
            if (print) {
                Path * temp = path;
                while(temp != NULL) {
                    cout << temp->arr << "->";
                    temp = temp->next;
                }
                idNode->namePath(_name, true);
            }
        }
    }

    void IDPathNoPrint(Path * path, int _id, char *_name) {
        IDNode *idNode = IDHead;
        while (idNode != NULL) {
//            cout << idNode->id << "->";
            if (idNode->id == _id) {
                if (path != NULL) {
                    char num_char[10];
                    sprintf(num_char, "%d", _id);
                    path->Save(num_char);
                }
                break;
            }
            idNode = idNode->nextID;
        }
        if (idNode != NULL) {
            bool print;
            print = idNode->namePath(_name, false);
            if (print) {
                Path * temp = path;
                while(temp != NULL) {
                    cout << temp->arr << "->";
                    temp = temp->next;
                }
                idNode->namePath(_name, true);
            }
        }
    }

};

class majorNode {
public:
    char major[100];
    IDList *stuIDList; // 학번 리스트
    majorNode *nextMajor; // 다음 전공

    majorNode(char *_major, int _id, char *_name) {
        nextMajor = nullptr;
        setMajor(_major);
        setNextID(_id, _name);
    }

    void removeMajor(majorNode **majorHead, char *_major, int _id, char *_name) {
        majorNode *temp = *majorHead;
        while (temp != NULL) {
            if (strcmp(temp->major, _major) == 0) {
                temp->stuIDList->removeNameNode(&temp->stuIDList, _id, _name);
                if (temp->stuIDList == NULL) {
                    majorNode *temp1 = *majorHead; // TODO temp1 = majorHead
                    majorNode *temp2 = *majorHead; // TODO 삭제할 prev major 탐색 ex) 2018
                    majorNode *temp3; // TODO 삭제할 major 중간에 있는 경우 next major를 저장 ex) 2020
                    while (temp2->nextMajor != NULL) { // 2019 != NULL
                        if (temp2 == *majorHead && strcmp(temp2->major, _major) == 0) {
                            cout << "Delete_Major : " << temp2->major << endl;
                            temp3 = temp2->nextMajor;
                            delete temp2;
                            *majorHead = temp3;
                            break;
                        }
                        if (temp2->nextMajor->nextMajor != NULL && strcmp(temp2->nextMajor->major, _major) == 0) { // 2020 != NULL && 2019 == 2019
                            cout << "Delete_Major : " << temp2->nextMajor->major << endl;
                            temp3 = temp2->nextMajor->nextMajor; // temp3 == 2020
                            delete temp2->nextMajor; // temp2(2019) delete
                            temp2->nextMajor = temp3; // 2018->next == temp3(2020); (now, temp2 = 2018)
                            break;
                        }
                        else if (temp2->nextMajor == temp ){ // 삭제할 major =  마지막 노드일 때
                            cout << "Delete_Major : " << temp2->nextMajor->major << endl;
                            delete temp2->nextMajor;
                            temp2->nextMajor = NULL;
                            break;
                        }
                        temp2 = temp2->nextMajor; // temp2 == 2019;
                    }
                    if ( temp2 == *majorHead && temp2->nextMajor == NULL) { // major가 하나만 있는 경우
                        cout << "Delete_Major : " << temp1->major << endl;
                        delete temp1; // yHead 지움
                        *majorHead = NULL;
                        break;
                    }
                }
            }
            temp = temp->nextMajor;
        }
    }

    char *getMajor() { return major; }

    majorNode *getNextMajor() { return nextMajor; }

    IDList *getNextID() { return stuIDList; }

    void setMajor(char *_major) { strcpy(major, _major); }

    void setNextMajor(majorNode *nextMajor) { this->nextMajor = nextMajor; }

    void setNextID(int _id, char *_name) {
        if (stuIDList == NULL) {
            stuIDList = new IDList(_id, _name);
            return;
        }
        this->stuIDList->insertID(_id, _name);
    }

    void print() {
        stuIDList->print(major);
    };

//    void findName(char *_name) {
//        stuIDList->
//    }

    void findPrint(majorNode *major, int _id) {
        stuIDList->findID(major->major, _id);
    }
};

class majorList { // Major 리스트
private:
    majorNode *majorHead; // Major 리스트의 IDhead
public:
    majorList() { majorHead = nullptr; }

    majorNode *getMajorHead() { return majorHead; }

    void insertMajor(char *_major, int _id, char *_name);

    void removeMajorList(char *_major, int _id, char *_name) {
        majorHead->removeMajor(&majorHead, _major, _id, _name);
    }

    void print() {
        majorNode *currMajor;
        currMajor = majorHead;
        while (currMajor != nullptr) {
            currMajor->print();
            currMajor = currMajor->nextMajor;
        }
    }

    void findMajor(char *_major) {
        majorNode *majorNode = majorHead;
        while (majorNode != NULL) {
            if (strcmp(majorNode->major, _major) == 0) break;
            majorNode = majorNode->nextMajor;
        }
        if (majorNode != NULL) {
            majorNode->print();
        }
    }

    void findID(int _id) {
        majorNode *majorNode = majorHead;
        while (majorNode != NULL) {
            majorNode->findPrint(majorNode, _id);
            majorNode = majorNode->nextMajor;
        }
    }

    void findName(char *_name) {
        majorNode *majorNode = majorHead;
        IDNode * idNode = NULL;
        while (majorNode != NULL) {
            idNode = majorNode->stuIDList->getIDHead();
            while (idNode != NULL) {
                majorPathNoPrint(majorNode->major, idNode->id, _name);
//                cout << "major : " << majorNode->major << " ID : " << idNode->id << endl;
                idNode = idNode->nextID;
            }
            majorNode = majorNode->nextMajor;
        }
    }

    void majorPathNoPrint(char *_major, int _id, char *_name) {
        Path * path;
        majorNode *majorNode = majorHead;
        while (majorNode != NULL) {
//            cout << majorNode->major << "->";
            if (strcmp(majorNode->major, _major) == 0) {
                path = new Path(_major);
                break;
            }
            majorNode = majorNode->nextMajor;
        }
        if (majorNode != NULL) majorNode->stuIDList->IDPathNoPrint(path, _id, _name);
    }

    void majorPath(char *_major, int _id, char *_name) {
        Path * path;
        majorNode *majorNode = majorHead;
        while (majorNode != NULL) {
            cout << majorNode->major << "->";
            if (strcmp(majorNode->major, _major) == 0) {
                path = NULL;
                break;
            }
            majorNode = majorNode->nextMajor;
        }
        if (majorNode != NULL) majorNode->stuIDList->IDPath(path, _id, _name);

    }
};

void majorList::insertMajor(char *_major, int _id, char *_name) {
    majorNode *newMajorNode = nullptr;
    majorNode *curr;
    if (majorHead == nullptr) {
        newMajorNode = new majorNode(_major, _id, _name);
        majorHead = newMajorNode;
    } else {
        curr = majorHead;
        while (true) {
            if (curr->getNextMajor() == nullptr) break;
            else if (strcmp(curr->major, _major) == 0 ||
                     ((strcmp(curr->major, _major) < 0) && strcmp(curr->getNextMajor()->major, _major) > 0))
                break;
            curr = curr->getNextMajor();
        }
        if (strcmp(curr->major, _major) != 0) { // 전공 없을 때
            newMajorNode = new majorNode(_major, _id, _name);
            majorNode *temp;
            temp = curr->nextMajor;
            curr->nextMajor = newMajorNode;
            newMajorNode->nextMajor = temp;
        } else { // 전공이 이미 있을 때, 그 전공에다가 학번만 추가
            curr->setNextID(_id, _name);
        }
    }
}


int main() {
    ifstream file;
    char major[100];
    int ID;
    char name[100];
    int command;

    majorList ml;
    file.open("Assignment3-3-4.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            file >> major >> ID >> name;
            ml.insertMajor(major, ID, name);
        }
    }

    do {
        cout << "Enter Any Command(1: Insert, 2: Delete, 3: Print_all, 4: Print_major, 5: Print_id, 6: Print_name, 7: Exit) : ";
        cin >> command;
        if (command == 1) {
            cin >> major >> ID >> name;
            ml.insertMajor(major, ID, name);
            ml.majorPath(major, ID, name);
        } else if (command == 2) {
            cin >> major >> ID >> name;
            ml.removeMajorList(major, ID, name);
        } else if (command == 3) {
            ml.print();
        } else if (command == 4) {
            cin >> major;
            ml.findMajor(major);
        } else if (command == 5) {
            cin >> ID;
            ml.findID(ID);
        }else if (command == 6) { // TODO 해당 이름의 경로 모두 출력
            cin >> name;
            ml.findName(name);
//            ml.majorPath(major, ID, name);
        } else if (command == 7) break;
        else continue;
    } while (command != 7);
    file.close();
    return 0;
}