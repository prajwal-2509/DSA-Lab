
#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char a[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        if (top == 99)
            return;

        a[++top] = ch;
    }

    char pop()
    {
        if (top == -1)
            return '\0';

        return a[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool checkExpression(string exp)
    {
        for (int i = 0; i < exp.length(); i++)
        {
            char ch = exp[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (isEmpty())
                    return false;

                char open = pop();

                if ((ch == ')' && open != '(') ||
                    (ch == '}' && open != '{') ||
                    (ch == ']' && open != '['))
                    return false;
            }
        }

        return isEmpty();
    }
};

int main()
{
    Stack s;
    string exp;

    cout << "Enter an expression: ";
    getline(cin, exp);

    if (s.checkExpression(exp))
        cout << "Expression is well-parenthesized.\n";
    else
        cout << "Expression is not well-parenthesized.\n";

    return 0;
}
