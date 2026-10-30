#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Stack{

    vector<char> stack;
    public:

        void push(char ch){
            stack.push_back(ch);

        }

        void pop(){
            if(stack.empty()){
                cout<<"underflow ";
                return;
            }

            stack.pop_back();
        }

        char peek(){
            if(stack.empty()){
                cout<<"underflow ";
                return '\0';
            }

            return stack.back();
        }

        bool isEmpty(){
            return stack.empty();
        }

        bool chechexp(string exp){
            bool balance=true;
            Stack s;

            for(int i=0;i<exp.length();i++){
                char ch=exp[i];
                if(ch == '(' || ch=='{' || ch=='['){
                    s.push(ch);
                }
                else if(ch==')' || ch=='}' || ch==']') {
                        if(s.isEmpty()){
                            balance=false;
                            break;

                        }

                        char top= s.peek();

                        if (ch=='}' && top=='{' || ch==']' && top=='['  || ch==')' && top=='('  ){
                            s.pop();
                        }

                        else{
                            balance=false;
                            break;

                        }
                }
            }

            if(!s.isEmpty()){
                balance=false;
            }

            return balance;
        }
};
int main() 
    {

        Stack check;
        string exp="({a+b})";

        cout<< exp << (check.chechexp(exp) ? "Balanced ": "not balance")<<endl;
    return 0;
}