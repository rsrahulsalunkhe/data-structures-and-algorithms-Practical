#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        }
        else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    Node* searchRecursive(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return searchRecursive(root->left, value);
        }
        else {
            return searchRecursive(root->right, value);
        }
    }

    void inorderTraversalRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }

        inorderTraversalRecursive(root->left);
        cout << root->data << " ";
        inorderTraversalRecursive(root->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        Node* result = searchRecursive(root, value);
        return result != nullptr;
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }
};

int main() {
    BST bst;

    cout << "Enter numbers to build the BST (-1 to stop):" << endl;

    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        bst.insert(value);
    }

    cout << "Inorder Traversal of BST: ";
    bst.inorderTraversal();
    cout << endl;

    cout << "Enter a value to search in the BST: ";
    cin >> value;
    if (bst.search(value)) {
        cout << value << " is present in the BST." << endl;
    }
    else {
        cout << value << " is not present in the BST." << endl;
    }

    return 0;
}
