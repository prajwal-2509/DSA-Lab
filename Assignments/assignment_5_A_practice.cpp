#include <iostream>
#include <vector>

using namespace std;

class Stack{
    vector <char> arr;
    public:

    void push(string s){
    for(int i = 0; i < s.length(); i++){
        arr.push_back(s.at(i));
    }
    cout << "String pushed on Stack !";
}

    void display(){
        if(arr.empty()){
            cout<<"The stack is empty! ";
            return;
        }

        for(int i=arr.size()-1;i>=0;i--){
            cout<<arr.at(i)<<" ";

        }
    }

    char pop() {
    if (arr.empty()) {
        cout << "Stack Underflow! ";
        return '\0'; 
    }
    char popped_val = arr.back(); 
    arr.pop_back();               
    return popped_val;
}

    // int pop(){

    // }
};


int main(){

    Stack s;
    string str;
    cout<<"Enter the expression : ";
    getline(cin,str);

    s.push(str);
    s.display();

    cout << "\nPopped element: " << s.pop() << "\n";
    cout<<"Other elements on stack : \n";
    s.display();

    return 0;
}