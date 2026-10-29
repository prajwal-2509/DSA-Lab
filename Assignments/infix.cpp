#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Conversion
{
    string infix, postfix, prefix;
    stack<char> s;

    int priority(char ch)
    {
        if (ch == '+' || ch == '-')
            return 1;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '^')
            return 3;
        return 0;
    }

public:
    void input()
    {
        cout << "Enter infix expression: ";
        cin >> infix;
    }

    void convertPostfix()
    {
        postfix = "";

        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];

            if (isalnum(ch))
                postfix += ch;

            else if (ch == '(')
                s.push(ch);

            else if (ch == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    postfix += s.top();
                    s.pop();
                }
                if (!s.empty())
                    s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != '(' &&
                      (priority(s.top()) > priority(ch) ||
                      (priority(s.top()) == priority(ch) && ch != '^')))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }

        while (!s.empty())
        {
            postfix += s.top();
            s.pop();
        }
    }

    void convertPrefix()
    {
        reverse(infix.begin(), infix.end());

        for (int i = 0; i < infix.length(); i++)
        {
            if (infix[i] == '(')
                infix[i] = ')';
            else if (infix[i] == ')')
                infix[i] = '(';
        }

        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i];

            if (isalnum(ch))
                prefix += ch;

            else if (ch == '(')
                s.push(ch);

            else if (ch == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    prefix += s.top();
                    s.pop();
                }
                if (!s.empty())
                    s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != '(' &&
                      (priority(s.top()) > priority(ch) ||
                      (priority(s.top()) == priority(ch) && ch == '^')))
                {
                    prefix += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }

        while (!s.empty())
        {
            prefix += s.top();
            s.pop();
        }

        reverse(prefix.begin(), prefix.end());
    }

    void display()
    {
        cout << "Postfix: " << postfix << endl;
        cout << "Prefix: " << prefix << endl;
    }

    void clearStack()
{
    while (!s.empty())
        s.pop();
}
};

int main()
{
    Conversion obj;

    obj.input();
    obj.convertPostfix();

    obj.clearStack();

    obj.convertPrefix();
    obj.display();

    return 0;
}