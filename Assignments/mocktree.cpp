#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    string name;
    Node *left, *right;

    Node(string n) {
        name = n;
        left = right = NULL;
    }
};

class BST {
    Node *root;

    Node* insert(Node *r, string name) {
        if (r == NULL)
            return new Node(name);

        if (name < r->name)
            r->left = insert(r->left, name);
        else if (name > r->name)
            r->right = insert(r->right, name);

        return r;
    }

public:
    BST() {
        root = NULL;
    }

    void createTree() {
        int n;
        string name;

        cout << "Enter number of files/folders: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter name: ";
            cin >> name;
            root = insert(root, name);
        }
    }

    void preorder() {
        if (root == NULL)
            return;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();

            cout << temp->name << " ";

            if (temp->right != NULL)
                s.push(temp->right);

            if (temp->left != NULL)
                s.push(temp->left);
        }
        cout << endl;
    }

    void postorderTraversal() {
        if (root == NULL)
            return;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node *temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left != NULL)
                s1.push(temp->left);

            if (temp->right != NULL)
                s1.push(temp->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->name << " ";
            s2.pop();
        }
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice;

    tree.createTree();

    do {
        cout << "\n1. Non-recursive Preorder";
        cout << "\n2. Non-recursive Postorder";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.preorder();
                break;

            case 2:
                tree.postorderTraversal();
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}