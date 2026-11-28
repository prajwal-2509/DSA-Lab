#include <iostream>
#include <algorithm>
#include <string>
#include<vector>
using namespace std;
class Prod{
    public:
    int code ;
    string name;
    double price;
    Prod(){
        code=0;
        name="";
        price=0;
    }

    Prod(int c,string n,double p){
        code=c; name=n;price=p;
    }
};

class Grocery{
    int size=20;
    vector<Prod> products;
    Prod hashTable[20];
    bool occupy[20]={false};

    public:

        void input(){
            int c,no;
            string n;
            double d;

            cout<<"Enter the no of elements :";
            cin>>no;

            for(int i=0;i<no;i++){
                cout<<"Enter the code : ";
                cin>>c;

                cout<<"Enter name : ";
                cin.ignore();
                getline(cin,n);

                cout<<"Enter Price : ";
                cin>>d;

                Prod p(c,n,d);
                products.push_back(p);
            }
        }

        void display(){
            cout<<"\nGROCERY BILL\n";
            cout<<"--------------------------------\n";
            cout<<"Code\tProduct\tPrice\n";
            cout<<"--------------------------------\n";

            for(int i=0;i<products.size();i++){
                cout<<products[i].code<<"\t"
                    <<products[i].name<<"\t"
                    <<products[i].price<<endl;
            }

            cout<<"--------------------------------\n";
        }

        int linearSearch(int key){
            for(int i=0;i<products.size();i++){
                if(products[i].code==key)
                    return i;
            }
            return -1;
        }

        int sentinelsearch(int key){
            if(products.empty()){ return -1;}

            int last = products.back().code;
            products.back().code=key;

            int i=0;
            while(products[i].code!=key){
                i++;
            }

            products.back().code=last;
            if(i==products.size()-1 && last!=key)
                return -1;

            return i;
        }

        void sortproducts (){
            for(int i=0;i<products.size()-1;i++){
                for(int j=0;j<products.size()-i-1;j++){
                    if(products[j].code>products[j+1].code){
                        swap(products[j],products[j+1]);
                    }
                }
            }
        }

        int binarysearch(int key){
            int low=0;
            int high=products.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(products[mid].code==key)
                    return mid;

                if(products[mid].code<key)
                    low=mid+1;
                else
                    high=mid-1;
            }
            return -1;
        }

        int fibonaccisearch(int key){
            int n=products.size();
            if(n==0) return -1;

            int a=0;
            int b=1;
            int c=a+b;
            int offset=-1;

            while(c<n){
                a=b;
                b=c;
                c=a+b;
            }

            while(c>1){
                int i=min(offset+a,n-1);

                if(products[i].code<key){
                    c=b;
                    b=a;
                    a=c-b;
                    offset=i;
                }
                else if(products[i].code>key){
                    c=a;
                    b=b-a;
                    a=c-b;
                }
                else{
                    return i;
                }
            }

            if(b && offset+1<n && products[offset+1].code==key)
                return offset+1;

            return -1;
        }

        int hashfunction(int key){
    return (key % size + size) % size;
}

        void inserthash(){

            for(int i=0;i<products.size();i++){

            int index=hashfunction(products[i].code);
            int start = index;
            while (occupy[index]){
                index=(index+1)%size;
                if(index==start){
                    cout<<"Hash table is full\n";
                    return;
                }
            }
            hashTable[index]=products[i];
            occupy[index]=true;
        }}

        void hashsearch(int key){
            int index=hashfunction(key);
            int start=index;

            while (occupy[index]){
                if(hashTable[index].code==key){
                    cout<<"Product found\n";
                    cout<<"Code: "<<hashTable[index].code<<endl;
                    cout<<"Name: "<<hashTable[index].name<<endl;
                    cout<<"Price: "<<hashTable[index].price<<endl;
                    return;
                }

                index=(index+1)%size;
                if(index==start) break;
            }
        }

        void hashdisplay(){
            cout<<"\nHASH TABLE\n";
            cout<<"Index\tCode\tProduct\tPrice\n";
            for(int i=0;i<size;i++){
                cout<<i<<"\t";
                if(occupy[i]){
                    cout<<hashTable[i].code<<"\t"
                        <<hashTable[i].name<<"\t"
                        <<hashTable[i].price;
                }
                else{
                    cout<<"Empty";
                }
                cout<<endl;
            }
        }

        
};

int main()
{
    Grocery g;

    // Input products from user
    g.input();

    // Display original products
    cout << "\n========== ORIGINAL PRODUCTS ==========\n";
    g.display();

    int key;
    cout << "\nEnter product code to search: ";
    cin >> key;
    
    // 1. Linear Search
    cout << "\n========== LINEAR SEARCH ==========\n";
    int result = g.linearSearch(key);

    if(result != -1)
        cout << "Product found at index: " << result << endl;
    else
        cout << "Product not found\n";

    // 2. Sentinel Search
    cout << "\n========== SENTINEL SEARCH ==========\n";
    result = g.sentinelsearch(key);

    if(result != -1)
        cout << "Product found at index: " << result << endl;
    else
        cout << "Product not found\n";

    // 3. Bubble Sort
    cout << "\n========== BUBBLE SORT ==========\n";
    g.sortproducts();
    g.display();

    // 4. Binary Search
    cout << "\n========== BINARY SEARCH ==========\n";
    result = g.binarysearch(key);

    if(result != -1)
        cout << "Product found at index: " << result << endl;
    else
        cout << "Product not found\n";

    // 5. Fibonacci Search
    cout << "\n========== FIBONACCI SEARCH ==========\n";
    result = g.fibonaccisearch(key);

    if(result != -1)
        cout << "Product found at index: " << result << endl;
    else
        cout << "Product not found\n";

    // 6. Hashing
    cout << "\n========== HASH TABLE ==========\n";
    g.inserthash();
    g.hashdisplay();

    // 7. Hash Search
    cout << "\n========== HASH SEARCH ==========\n";
    g.hashsearch(key);

    return 0;
}