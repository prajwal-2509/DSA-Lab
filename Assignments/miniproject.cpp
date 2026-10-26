
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class Node {
public:
    char data;
    Node *left, *right;

    Node(char ch) {
        data = ch;
        left = right = nullptr;
    }
};

class ExpressionTree {
    Node *root;
    string postfix;

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' ||
               ch == '*' || ch == '/' || ch == '^';
    }

    void preorder(Node *r) {
        if (r == nullptr) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node *r) {
        if (r == nullptr) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void postorder(Node *r) {
        if (r == nullptr) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }

    double evaluate(Node *r, bool &valid) {
        if (isdigit(r->data))
            return r->data - '0';

        double a = evaluate(r->left, valid);
        double b = evaluate(r->right, valid);

        if (!valid) return 0;

        switch (r->data) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) {
                    valid = false;
                    return 0;
                }
                return a / b;
            case '^': return pow(a, b);
        }

        valid = false;
        return 0;
    }

    void clear(Node *r) {
        if (r == nullptr) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

public:
    ExpressionTree() {
        root = nullptr;
    }

    ~ExpressionTree() {
        clear(root);
    }

    void input() {
        cout << "Enter postfix expression: ";
        cin >> postfix;
    }

    bool build() {
        stack<Node*> s;

        for (char ch : postfix) {
            if (isalnum(ch)) {
                s.push(new Node(ch));
            }
            else if (isOperator(ch)) {
                if (s.size() < 2) {
                    while (!s.empty()) {
                        clear(s.top());
                        s.pop();
                    }
                    return false;
                }

                Node *r = new Node(ch);
                r->right = s.top();
                s.pop();
                r->left = s.top();
                s.pop();
                s.push(r);
            }
            else {
                while (!s.empty()) {
                    clear(s.top());
                    s.pop();
                }
                return false;
            }
        }

        if (s.size() != 1) {
            while (!s.empty()) {
                clear(s.top());
                s.pop();
            }
            return false;
        }

        Node *newRoot = s.top();
        s.pop();

        clear(root);
        root = newRoot;
        return true;
    }

    void display() {
        if (root == nullptr) {
            cout << "Build the tree first.\n";
            return;
        }

        cout << "Preorder: ";
        preorder(root);

        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPostorder: ";
        postorder(root);

        cout << endl;
    }

    void evaluateExpression() {
        if (root == nullptr) {
            cout << "Build the tree first.\n";
            return;
        }

        bool valid = true;
        double result = evaluate(root, valid);

        if (valid)
            cout << "Result: " << result << endl;
        else
            cout << "Invalid evaluation or division by zero.\n";
    }
};

int main() {
    ExpressionTree obj;
    int choice;

    do {
        cout << "\n1. Input Postfix Expression";
        cout << "\n2. Build Expression Tree";
        cout << "\n3. Display Traversals";
        cout << "\n4. Evaluate Expression";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.input();
                break;

            case 2:
                if (obj.build())
                    cout << "Expression tree created.\n";
                else
                    cout << "Invalid postfix expression.\n";
                break;

            case 3:
                obj.display();
                break;

            case 4:
                obj.evaluateExpression();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
