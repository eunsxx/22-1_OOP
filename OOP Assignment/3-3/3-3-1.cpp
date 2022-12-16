#include <iostream>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;
};

class bstList {
private:
    Node *root;

    void inOrder(Node *current) {
        if (current != nullptr) {
            if (current->left != nullptr) inOrder(current->left);
            cout << current->data << " -> ";
            if (current->right != nullptr) inOrder(current->right);
        }
    }

    Node *search(Node *root, int num) {
        if (root == NULL || root->data == num) {
            cout << root->data << endl;
            return root;
        }
        cout << root->data << "->";
        if (root->data > num) {
            return search(root->left, num);
        }
        if (root->data < num) {
            return search(root->right, num);
        }
    }

    Node *findMax(Node *n) {
        if (n == NULL) return NULL;
        while (n->right != NULL) {
            n = n->right;
        }
        return n;
    }

    Node *findMin(Node *n) {
        if (n == NULL) return NULL;
        while (n->left != NULL) {
            n = n->left;
        }
        return n;
    }

    Node* removeNode (Node* root, int num) {
        if (root == NULL) return root;
        if (num < root->data)
            root->left = removeNode(root->left, num);
        else if (num > root->data)
            root->right = removeNode(root->right, num);
        else {
            Node* temp;
            if (root->left == NULL) {
                temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                temp = root->left;
                free(root);
                return temp;
            }

            temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right, temp->data);
        }
        return root;
    }

public:
    bstList() : root(nullptr) {};
    ~bstList() {};
    void insertNode(int num);
    void print(){
        inOrder(root);
    };
    void Find(int num) {
        search(root, num);
    }
    void Remove(int num) {
        removeNode(root, num);
    }
};

void bstList::insertNode(int num) {
    Node *node = new Node();
    Node *temp = nullptr;

    node->data = num;
    if (root == nullptr) root = node;
    else {
        Node *ptr = root;
        while (ptr != nullptr) {
            temp = ptr;
            if (node->data < ptr->data) ptr = ptr->left;
            else ptr = ptr->right;
        }
        if (node->data < temp->data) temp->left = node;
        else temp->right = node;
    }
}

int main() {
    bstList *BST = new bstList();

    int command = 0, num = 0;
    do {
        cout << "Enter Any Command (1: Insert, 2: Delete, 3: Find, 4: Exit): ";
        cin >> command;
        if (command == 1) {
            cin >> num;
            BST->insertNode(num);
        } else if (command == 2) {
            cin >> num;
            BST->Remove(num);
        } else if (command == 3) {
            cin >> num;
            BST->Find(num);
        } else if (command == 4) break;
        else
            cout << "잘못 입력하셨습니다." << endl;
    } while (command != 4);

    return 0;
}