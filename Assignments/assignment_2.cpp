#include<iostream>
// #include<algorithm>
// #include<string>
using namespace std;

class Product{
    public:
        int id;
        string name;
        string manufacturer;
        double price;
        double rating;
};

class Sorting{
    public:

        void display(Product a[], int n){
            cout<<"ID\tName\tManufacturer\tPrice\tRating\n";

            for(int i=0;i<n;i++){
                cout<<a[i].id<<"\t"
                    <<a[i].name<<"\t"
                    <<a[i].manufacturer<<"\t\t"
                    <<a[i].price<<"\t"
                    <<a[i].rating<<"\n";
            }
        }

        // Bubble Sort - Increasing Product ID
        void bubblesort(Product a[], int n){
            Product temp[n];

            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(temp[j].id > temp[j+1].id){
                        swap(temp[j],temp[j+1]);
                    }
                }
            }

            cout<<"\nSorted by Product ID (Increasing):\n";
            display(temp,n);
        }

        // Selection Sort - Increasing Product Price
        void selectionsort(Product a[], int n){
            Product temp[n];

            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=0;i<n-1;i++){
                int smallest=i;

                for(int j=i+1;j<n;j++){
                    if(temp[j].price < temp[smallest].price){
                        smallest=j;
                    }
                }

                swap(temp[i],temp[smallest]);
            }

            cout<<"\nSorted by Price (Increasing):\n";
            display(temp,n);
        }

        // Insertion Sort - Decreasing Quality Rating
        void insertionSort(Product a[], int n){
            Product temp[n];

            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=1;i<n;i++){
                Product key=temp[i];
                int j=i-1;

                while(j>=0 && temp[j].rating < key.rating){
                    temp[j+1]=temp[j];
                    j--;
                }

                temp[j+1]=key;
            }

            cout<<"\nSorted by Quality Rating (Decreasing):\n";
            display(temp,n);
        }

        // Quick Sort - Decreasing Quality Rating
        void quickswap(Product *a, Product *b){
            Product t=*a;
            *a=*b;
            *b=t;
        }

        int partition(Product a[], int low, int high){
            double pivot=a[high].rating;
            int i=low-1;

            for(int j=low;j<=high-1;j++){
                if(a[j].rating > pivot){
                    i++;
                    quickswap(&a[i],&a[j]);
                }
            }

            quickswap(&a[i+1],&a[high]);

            return i+1;
        }

        void quickSort(Product a[], int low, int high){
            if(low<high){
                int pi=partition(a,low,high);

                quickSort(a,low,pi-1);
                quickSort(a,pi+1,high);
            }
        }

        // Merge function
        void merge(Product A[], int low, int mid, int high){
            int i=low;
            int j=mid+1;
            int k=low;

            Product temp[100];

            while(i<=mid && j<=high){
                if(A[i].name < A[j].name){
                    temp[k]=A[i];
                    i++;
                }
                else{
                    temp[k]=A[j];
                    j++;
                }

                k++;
            }

            while(i<=mid){
                temp[k]=A[i];
                i++;
                k++;
            }

            while(j<=high){
                temp[k]=A[j];
                j++;
                k++;
            }

            for(i=low;i<=high;i++){
                A[i]=temp[i];
            }
        }

        // Merge Sort - Increasing Product Name
        void mergeSort(Product A[], int low, int high){
            if(low<high){
                int mid=(low+high)/2;

                mergeSort(A,low,mid);
                mergeSort(A,mid+1,high);

                merge(A,low,mid,high);
            }
        }
};

int main(){
    Sorting s;
    int n;

    cout<<"Enter No of products: ";
    cin>>n;

    Product a[n];
    Product a_quick[n];
    Product a_merge[n];

    cout<<"Enter Product Details:\n";

    for(int i=0;i<n;i++){
        cout<<"\nProduct "<<i+1<<"\n";

        cout<<"Product ID: ";
        cin>>a[i].id;

        cout<<"Product Name: ";
        cin>>a[i].name;

        cout<<"Manufacturer: ";
        cin>>a[i].manufacturer;

        cout<<"Price: ";
        cin>>a[i].price;

        cout<<"Quality Rating: ";
        cin>>a[i].rating;

        a_quick[i]=a[i];
        a_merge[i]=a[i];
    }

    cout<<"\nUsing Bubble Sort";
    s.bubblesort(a,n);

    cout<<"\nUsing Selection Sort";
    s.selectionsort(a,n);

    cout<<"\nUsing Insertion Sort";
    s.insertionSort(a,n);

    cout<<"\nUsing Quick Sort";
    s.quickSort(a_quick,0,n-1);
    cout<<"\nSorted by Quality Rating (Decreasing):\n";
    s.display(a_quick,n);

    cout<<"\nUsing Merge Sort";
    s.mergeSort(a_merge,0,n-1);
    cout<<"\nSorted by Product Name (Increasing):\n";
    s.display(a_merge,n);

    return 0;
}