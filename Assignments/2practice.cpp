#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Product{
    public:
        int id;
        string name;
        string manu;
        double price;
        double rating;
};

class Sorting{
    public:
        int pass=0;

        void display(Product a[],int n){
            cout<<"\nID\tName\tManufacturer\tPrice\tRating\n";

            for(int i=0;i<n;i++){
                cout<<"\n"<<a[i].id<<"\t"
                    <<a[i].name<<"\t"
                    <<a[i].manu<<"\t\t"
                    <<a[i].price<<"\t"
                    <<a[i].rating<<"\t";
            }
        }

        void bubblesort(Product a[],int n)
        {
            Product temp[n];
            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=0;i<n-1;i++){
                bool swapped= false;
                for(int j=0;j<n-i-1;j++){
                    if(temp[j].id> temp[j+1].id){
                        swap(temp[j],temp[j+1]);
                        swapped=true;
                    }
                }

                cout<<"\nPass "<<i+1 <<":\n";
                display(temp,n);

                if(!swapped){
                    break;
                }
            }

            cout<<"\nSorted by Product ID ( Increasing) :\n";
            display(temp,n);
        }
};
int main() 
{
    Sorting s;
    int n;
    cout<<"Enter the no of Products :";
    cin>>n;

    Product a[n];
    Product quick_n[n];
    Product merge_n[n];

    for(int i=0;i<n;i++){
        cout<<"\nProduct " << i+1<<endl ;

        cout<<"Enter ID ";
        cin>>a[i].id;

        cout<<"Enter Name ";
        cin>>a[i].name;

        cout<<"Enter Manufacturer ";
        cin>>a[i].manu;

        cout<<"Enter Price ";
        cin>>a[i].price;

        cout<<"Enter Rating ";
        cin>>a[i].rating;

        quick_n[i]=a[i];
        merge_n[i]=a[i];

    }

    cout<<"\nUsing Bubble sort : ";
    s.bubblesort(a,n);

        
}