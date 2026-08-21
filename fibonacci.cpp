#include<iostream>
using namespace std;

class Fibonacci{

    public:

    int minimum(int f, int b){

        if(f < b){
            return f;
        }

        return b;
    }
};

int main(){

    Fibonacci f;

    int an;

    cout << "Enter size of array: ";
    cin >> an;

    int a[an];

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < an; i++){
        cin >> a[i];
    }

    int key;

    cout << "Enter element to search: ";
    cin >> key;


    // Generate Fibonacci numbers
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while(fib < an){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }


    int offset = -1;
    int itr = 1;
    int flag = 0;


    // Fibonacci Search
    while(fib > 1){

        int j = f.minimum(offset + fib2, an - 1);

        if(a[j] == key){

            cout << "Element Found\n";
            cout << "Index : " << j << "\n";
            cout << "Iterations -> " << itr << "\n";

            flag = 1;
            break;
        }

        if(a[j] < key){

            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;

            offset = j;
            itr++;
        }

        else{

            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;

            itr++;
        }
    }


    // Check remaining element
    if(flag == 0 && offset + 1 < an && a[offset + 1] == key){

        cout << "Element Found\n";
        cout << "Index : " << offset + 1 << "\n";
        cout << "Iterations -> " << itr << "\n";

        flag = 1;
    }


    if(flag == 0){

        cout << "Element not found";
    }

    return 0;
}