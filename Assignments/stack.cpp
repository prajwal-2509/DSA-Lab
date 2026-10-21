#include <iostream>
#include <vector>

using namespace std;

class Stack{

    vector <int> a;
    int top;
    public:

    Stack(){}

    void push(int x){
        a.push_back(x);
        cout<<x <<"->  Pushed on Stack\n";

    }

    bool isEmpty(){
        return a.empty();
    }

    int peek(){
        if(a.empty()){
            cout<<"Stack is empty ! ";
            return -1;
        }

        return a.back();
    }

    int pop(){
        if(a.empty()){
            cout<<"Stack Underflow .";
            return -1;
        }

        int ele=a.back();
        a.pop_back();
        return ele;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(90);

    cout<<"\nPeak Element -> " <<s.peek();

    cout<<"\nStack elements are : ";

    while(!s.isEmpty()){
        cout << s.pop() <<" ";
    }
    cout<<endl;
    return 0;
}