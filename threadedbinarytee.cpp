#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

class ThreadedBinaryTree {
    Node *root;

    Node* createNode(int data) {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->lthread = newNode->rthread = true;
        return newNode;
    }

public:
    ThreadedBinaryTree() {
        root = NULL;
    }

    void insert(int key) {
        if (root == NULL) {
            root = createNode(key);
            return;
        }

        Node* parent = NULL;
        Node* current = root;

        while (current) {
            parent = current;

            if (key < current->data) {
                if (current->lthread == false)
                    current = current->left;
                else
                    break;
            } else if (key > current->data) {
                if (current->rthread == false)
                    current = current->right;
                else
                    break;
            } else {
                cout << "Duplicate keys are not allowed\n";
                return;
            }
        }

        Node* newNode = createNode(key);

        if (key < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rthread = false;
            parent->right = newNode;
        }
    }

    void inOrderTraversal() {
        Node* current = root;

        // Go to the leftmost node
        while (current && !current->lthread)
            current = current->left;

        while (current) {
            // Print the current node
            cout << current->data << " ";

            // If right is a thread, follow it
            if (current->rthread)
                current = current->right;
            else {
                // Otherwise, go to the leftmost node in the right subtree
                current = current->right;
                while (current && !current->lthread)
                    current = current->left;
            }
        }
    }

    void preOrderTraversal() {
        Node* current = root;

        while (current) {
            // Print the current node
            cout << current->data << " ";

            // If left is not a thread, move to left child
            if (!current->lthread)
                current = current->left;
            else
                current = current->right;  // Otherwise, follow the right thread
        }
    }
};

int main() {
    ThreadedBinaryTree tbt;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tbt.insert(value);
                break;

            case 2:
                cout << "In-order Traversal:\n";
                tbt.inOrderTraversal();
                break;

            case 3:
                cout << "Pre-order Traversal:\n";
                tbt.preOrderTraversal();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
