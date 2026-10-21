#include<iostream>
#include<vector>
#include <string>

using namespace std;

class Stack{
    private:
        vector<char> stack;

    public:
        void push(char s){
            stack.push_back(s);
        }

        void pop(){
            if(stack.empty()){
                cout<<"Stack Underflow !";
                return ;
            }

            stack.pop_back();
        }

        char peek(){
            if(stack.empty()){
                cout<<"Stack Underflow !";
                return '\0';
            }

           return stack.back();
        }

        bool isEmpty(){
            return stack.empty();
        }


        bool checkExpression(string exp){
            Stack s;
            bool balance=true;

            for(int i=0;i<exp.length();i++){

                char ch= exp[i];

                if( ch=='(' || ch=='{' || ch=='['){
                    s.push(ch);
                }

                else if (ch==')' || ch=='}' || ch==']'){
                    if(s.isEmpty()){
                        balance=false;
                        break;

                    }

                char top = s.peek();

                if (ch == ')' && top == '(') {
                        s.pop();
                }
                else if (ch =='}' && top=='{')
                        s.pop();
                
                else if ( ch ==']' && top == '[')
                {       s.pop(); }

                else {
                    balance=false;
                    break;
                }
            }}

            if(!s.isEmpty()){
                balance=false;
            }
            return balance;

        }
};

int main(){
    Stack check;
    string exp1;
    cout<<"Enter the expression : ";
    getline(cin,exp1);

    cout<< exp1 << " Is " << (check.checkExpression(exp1) ? " Balanced " : " Not Balanced ")<<endl;
   
    return 0;
}