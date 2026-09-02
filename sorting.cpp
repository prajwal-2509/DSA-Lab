#include<iostream>
using namespace std;

void bubblesort(int a[],int n){


    for (int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++)
            {

                if (a[j] > a[j+1]){
                    swap(a[j],a[j+1]);

                }
            }
    }
}

void selectionsort(int a[],int n){

    for (int i=0;i<n-1;i++){
        int smallest = i;
         
        for(int j=i+1;j<n;j++){

            if(a[j] < a[smallest]){
                smallest =j;
            }
        }

        swap( a[i],a[smallest]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void inputarray(int a[],int n){

    for (int i=0;i<n;i++){

        cin>> a[i];
    }
}
void display(int a[],int n){
    cout<<"\nSorted Array: \n";
    for (int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    cout<<"\n";
}

int main(){
    
    int n;
    cout<< "Enter No of elements : " << "\t";
    cin>>n;
    int a[n];
    
    cout<< "Enter the elements : "<< "\t";
    inputarray(a,n);

    cout<<"\nUsing Bubble Sort -> ";
    bubblesort(a,n);
    display(a,n);

    cout<<"\n\nUsing Selection Sort -> ";

    selectionsort(a,n);
    display(a,n);

    cout<<"\nUsing Insertion Sort -> ";
    insertionSort(a,n);

    return 0;
}