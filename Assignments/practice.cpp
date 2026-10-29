
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
    vector<char> stack;

public:
    void push(char s) {
        stack.push_back(s);
    }

    void pop() {
        if (stack.empty()) {
            cout << "Underflow";
            return;
        }

        stack.pop_back();
    }

    char peek() {
        if (stack.empty()) {
            cout << "Underflow";
            return '\0';
        }

        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool checkexp(string exp) {
        Stack s;
        bool balance = true;

        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];

            // Step 1: Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            }

            // Step 2: Check closing brackets
            else if (ch == ')' || ch == '}' || ch == ']') {

                if (s.isEmpty()) {
                    balance = false;
                    break;
                }

                char top = s.peek();

                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    s.pop();
                }
                else {
                    balance = false;
                    break;
                }
            }
        }

        // Step 3: Check for unmatched opening brackets
        if (!s.isEmpty()) {
            balance = false;
        }

        return balance;
    }
};

int main() {
    Stack b;
    string exp = "[{(a+b))}";

    cout << exp << " IS "
         << (b.checkexp(exp) ? "Balanced" : "Not balanced");

    return 0;
}
