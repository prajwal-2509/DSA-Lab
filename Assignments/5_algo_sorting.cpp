#include<iostream>
#include<algorithm>
using namespace std;

class Sorting{
    public:

        void bubblesort(int a[],int n){
            int temp[n];

            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(temp[j]>temp[j+1]){
                        swap(temp[j],temp[j+1]);
                    }
                }
            }

            cout<<"\nSorted Array: \n";
            for(int i=0;i<n;i++){
                cout<<temp[i]<<" ";
            }
            cout<<"\n";
        }


        void selectionsort(int a[],int n){
            int temp[n];

            for(int i=0;i<n;i++){
                temp[i]=a[i];
            }

            for(int i=0;i<n-1;i++){
                int smallest=i;

                for(int j=i+1;j<n;j++){
                    if(temp[j]<temp[smallest]){
                        smallest=j;
                    }
                }

                swap(temp[i],temp[smallest]);
            }

            cout<<"\nSorted Array: \n";
            for(int i=0;i<n;i++){
                cout<<temp[i]<<" ";
            }
            cout<<"\n";
        }


        void insertionSort(int arr[],int n){
            int temp[n];

            for(int i=0;i<n;i++){
                temp[i]=arr[i];
            }

            for(int i=1;i<n;i++){
                int key=temp[i];
                int j=i-1;

                while(j>=0 && temp[j]>key){
                    temp[j+1]=temp[j];
                    j--;
                }

                temp[j+1]=key;
            }

            cout<<"\nSorted Array: \n";
            for(int i=0;i<n;i++){
                cout<<temp[i]<<" ";
            }
            cout<<"\n";
        }


        void quickswap(int *a,int *b){
            int t=*a;
            *a=*b;
            *b=t;
        }


        int partition(int a[],int low,int high){
            int pivot=a[high];
            int i=low-1;

            for(int j=low;j<=high-1;j++){
                if(a[j]<pivot){
                    i++;
                    quickswap(&a[i],&a[j]);
                }
            }

            quickswap(&a[i+1],&a[high]);

            return i+1;
        }


        void quickSort(int a[],int low,int high){
            if(low<high){
                int pi=partition(a,low,high);

                quickSort(a,low,pi-1);
                quickSort(a,pi+1,high);
            }
        }


        // Merge function
        void merge(int A[],int low,int mid,int high){
            int i=low;
            int j=mid+1;
            int k=low;

            int temp[100];

            while(i<=mid && j<=high){
                if(A[i]<A[j]){
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


        // Merge Sort function
        void mergeSort(int A[],int low,int high){
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

    cout<<"Enter No of elements : \t";
    cin>>n;

    int a[n];
    int a_quick[n];
    int a_merge[n];

    cout<<"Enter the elements : \t";

    for(int i=0;i<n;i++){
        cin>>a[i];

        a_quick[i]=a[i];
        a_merge[i]=a[i];
    }


    cout<<"\nUsing Bubble Sort -> ";
    s.bubblesort(a,n);


    cout<<"\nUsing Selection Sort -> ";
    s.selectionsort(a,n);


    cout<<"\nUsing Insertion Sort -> ";
    s.insertionSort(a,n);


    cout<<"\nUsing Quick Sort -> ";
    s.quickSort(a_quick,0,n-1);

    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<<a_quick[i]<<" ";
    }
    cout<<"\n";


    cout<<"\nUsing Merge Sort -> ";
    s.mergeSort(a_merge,0,n-1);

    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<<a_merge[i]<<" ";
    }
    cout<<"\n";


    return 0;
}