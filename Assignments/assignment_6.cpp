
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    string name;
    Node *left, *right;

    Node(string n) {
        name = n;
        left = right = nullptr;
    }
};

class BST {
    Node *root;

    Node* insert(Node *r, string name) {
        if (r == nullptr)
            return new Node(name);

        if (name < r->name)
            r->left = insert(r->left, name);
        else if (name > r->name)
            r->right = insert(r->right, name);
        else
            cout << "File or folder already exists.\n";

        return r;
    }

       

    Node* search(Node *r, string name) {
        if (r == nullptr || r->name == name)
            return r;

        if (name < r->name)
            return search(r->left, name);

        return search(r->right, name);
    }

    void preorder(Node *r) {
        if (r == nullptr) return;
        cout << r->name << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node *r) {
        if (r == nullptr) return;
        inorder(r->left);
        cout << r->name << " ";
        inorder(r->right);
    }

    void postorder(Node *r) {
        if (r == nullptr) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->name << " ";
    }

    int depth(Node *r) {
        if (r == nullptr) return 0;
        return 1 + max(depth(r->left), depth(r->right));
    }

    void leafNodes(Node *r) {
        if (r == nullptr) return;

        if (r->left == nullptr && r->right == nullptr)
            cout << r->name << " ";

        leafNodes(r->left);
        leafNodes(r->right);
    }

    void mirror(Node *r) {
        if (r == nullptr) return;

        swap(r->left, r->right);
        mirror(r->left);
        mirror(r->right);
    }

    Node* minimum(Node *r) {
        while (r != nullptr && r->left != nullptr)
            r = r->left;
        return r;
    }

    Node* deleteNode(Node *r, string name) {
        if (r == nullptr) return nullptr;

        if (name < r->name)
            r->left = deleteNode(r->left, name);
        else if (name > r->name)
            r->right = deleteNode(r->right, name);
        else {
            if (r->left == nullptr) {
                Node *temp = r->right;
                delete r;
                return temp;
            }

            if (r->right == nullptr) {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            Node *temp = minimum(r->right);
            r->name = temp->name;
            r->right = deleteNode(r->right, temp->name);
        }

        return r;
    }

            

    void destroy(Node *r) {
        if (r == nullptr) return;
        destroy(r->left);
        destroy(r->right);
        delete r;
    }

   

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(string name) {
        root = insert(root, name);
    }

         void insertNonRecursive(string name) {
        Node *newNode = new Node(name);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *temp = root;
        Node *parent = nullptr;

        while (temp != nullptr) {
            parent = temp;

            if (name < temp->name)
                temp = temp->left;
            else if (name > temp->name)
                temp = temp->right;
            else {
                cout << "File or folder already exists.\n";
                delete newNode;
                return;
            }
        }

        if (name < parent->name)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

                void deleteNonRecursive(string name) {
            Node *temp = root, *parent = nullptr;

            while (temp != nullptr && temp->name != name) {
                parent = temp;

                if (name < temp->name)
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if (temp == nullptr) {
                cout << "File or folder not found.\n";
                return;
            }

            if (temp->left == nullptr || temp->right == nullptr) {
                Node *child;

                if (temp->left != nullptr)
                    child = temp->left;
                else
                    child = temp->right;

                if (parent == nullptr)
                    root = child;
                else if (parent->left == temp)
                    parent->left = child;
                else
                    parent->right = child;

                delete temp;
            }
            else {
                Node *p = temp;
                Node *successor = temp->right;

                while (successor->left != nullptr) {
                    p = successor;
                    successor = successor->left;
                }

                temp->name = successor->name;

                if (p->left == successor)
                    p->left = successor->right;
                else
                    p->right = successor->right;

                delete successor;
            }

            cout << "File or folder deleted.\n";
        }

    void search(string name) {
        if (search(root, name))
            cout << "File or folder found.\n";
        else
            cout << "File or folder not found.\n";
    }

        int countNodes(Node *r) {
            if (r == nullptr)
                return 0;

            return 1 + countNodes(r->left) + countNodes(r->right);
        }

        void displayTotalNodes() {
            cout << "Total nodes: " << countNodes(root) << endl;
        }


        int countLeafNodes(Node *r) {
            if (r == nullptr)
                return 0;

            if (r->left == nullptr && r->right == nullptr)
                return 1;

            return countLeafNodes(r->left) + countLeafNodes(r->right);
        }

        void displayLeafCount() {
            cout << "Total leaf nodes: " << countLeafNodes(root) << endl;
        }


    void deleteFile(string name) {
        if (search(root, name)) {
            root = deleteNode(root, name);
            cout << "File or folder deleted.\n";
        } else {
            cout << "File or folder not found.\n";
        }
    }

    void recursivePreorder() {
        preorder(root);
        cout << endl;
    }

    void recursiveInorder() {
        inorder(root);
        cout << endl;
    }

    void recursivePostorder() {
        postorder(root);
        cout << endl;
    }

    void nonRecursivePreorder() {
        if (root == nullptr) return;
        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node *r = s.top();
            s.pop();
            cout << r->name << " ";

            if (r->right) s.push(r->right);
            if (r->left) s.push(r->left);
        }
        cout << endl;
    }

    void nonRecursiveInorder() {
        stack<Node*> s;
        Node *r = root;

        while (r != nullptr || !s.empty()) {
            while (r != nullptr) {
                s.push(r);
                r = r->left;
            }

            r = s.top();
            s.pop();
            cout << r->name << " ";
            r = r->right;
        }
        cout << endl;
    }

    void nonRecursivePostorder() {
        if (root == nullptr) return;
        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node *r = s1.top();
            s1.pop();
            s2.push(r);

            if (r->left) s1.push(r->left);
            if (r->right) s1.push(r->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->name << " ";
            s2.pop();
        }
        cout << endl;
    }

    
        int maxDepthNonRecursive() {
        if (root == nullptr) return 0;

        queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int count = q.size();
            depth++;

            for (int i = 0; i < count; i++) {
                Node *r = q.front();
                q.pop();

                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
        }

        return depth;
    }

    void displayDepth() {
        cout << "Maximum depth: " << depth(root) << endl;
    }
    

    void displayLeafNodes() {
        cout << "Files/folders without children: ";
        leafNodes(root);
        cout << endl;
    }

    void createMirror() {
        mirror(root);
        cout << "Mirror image created.\n";
    }

    void displayLevelOrder() {
        if (root == nullptr) {
            cout << "Hierarchy is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node *r = q.front();
            q.pop();
            cout << r->name << " ";

            if (r->left) q.push(r->left);
            if (r->right) q.push(r->right);
        }
        cout << endl;
    }   


        void findMaximum() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        Node *temp = root;

        while (temp->right != nullptr)
            temp = temp->right;

        cout << "Maximum value: " << temp->name << endl;
    }
};

int main() {
    BST tree;
    int choice, type;
    string name;

    do {
        cout << "\n--- File and Folder Hierarchy ---\n";
        cout << "1. Insert file/folder (Recursive)\n";
        cout << "2. Recursive traversals\n";
        cout << "3. Non-recursive traversals\n";
        cout << "4. Maximum depth (Recursive)\n";
        cout << "5. Display files/folders without children\n";
        cout << "6. Create mirror image\n";
        cout << "7. Search file/folder\n";
        cout << "8. Delete file/folder (Recursive)\n";
        cout << "9. Display level order\n";
        cout << "10. Non-recursive insertion\n";
        cout << "11. Non-recursive deletion\n";
        cout << "12. Count total nodes\n";
        cout << "13. Count leaf nodes\n";
        cout << "14. Find maximum value\n";
        cout << "15. Exit\n";
        cout << "16. Maximum depth (Non-Recursive)\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter file/folder name: ";
                cin >> ws;
                getline(cin, name);
                tree.insert(name);
                break;

            case 2:
                cout << "1. Preorder  2. Inorder  3. Postorder: ";
                cin >> type;

                if (type == 1) tree.recursivePreorder();
                else if (type == 2) tree.recursiveInorder();
                else if (type == 3) tree.recursivePostorder();
                else cout << "Invalid traversal choice.\n";
                break;

            case 3:
                cout << "1. Preorder  2. Inorder  3. Postorder: ";
                cin >> type;

                if (type == 1) tree.nonRecursivePreorder();
                else if (type == 2) tree.nonRecursiveInorder();
                else if (type == 3) tree.nonRecursivePostorder();
                else cout << "Invalid traversal choice.\n";
                break;

            case 4:
                tree.displayDepth();
                break;

            case 5:
                tree.displayLeafNodes();
                break;

            case 6:
                tree.createMirror();
                break;

            case 7:
                cout << "Enter file/folder name to search: ";
                cin >> ws;
                getline(cin, name);
                tree.search(name);
                break;

            case 8:
                cout << "Enter file/folder name to delete: ";
                cin >> ws;
                getline(cin, name);
                tree.deleteFile(name);
                break;

            case 9:
                tree.displayLevelOrder();
                break;

            case 10:
                cout << "Enter file/folder name: ";
                cin >> ws;
                getline(cin, name);
                tree.insertNonRecursive(name);
                break;

            case 11:
                cout << "Enter file/folder name to delete: ";
                cin >> ws;
                getline(cin, name);
                tree.deleteNonRecursive(name);
                break;

            case 12:
                tree.displayTotalNodes();
                break;

            case 13:
                tree.displayLeafCount();
                break;

            case 14:
                tree.findMaximum();
                break;

            case 15:
                cout << "Exiting...\n";
                break;

            case 16:
                cout << "Maximum depth (Non-Recursive): "
                     << tree.maxDepthNonRecursive() << endl;
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 15);

    return 0;
}
