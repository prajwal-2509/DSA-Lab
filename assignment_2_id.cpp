#include <iostream>
using namespace std;

struct product {
    int id;
    int price;
    string name;
};

class bubblesort {
public:
    product a[100];
    void display(int n) {
        cout << "\n\nFinal Sorted List \n";
        for (int i = 0; i < n; i++) {
            cout << "\nID: " << a[i].id << " | Name: " << a[i].name << " | Price: " << a[i].price;
        }
        cout << endl;
    }

    void sort(int n) {
        int pass1 = 0;
        int pass2 = 0;

        for (int i = 0; i < n - 1; i++) {
            pass1++;
            cout << "\nOuter Pass " << pass1 << " (i = " << i << ") ---" << endl;
            
            for (int j = 0; j < n - i - 1; j++) {
                pass2++;
                cout << "  Inner Pass " << pass2 << ": Comparing Index " << j << " (ID: " << a[j].id << ") and " << j + 1 << " (ID: " << a[j + 1].id << ")";
                
                if (a[j].id > a[j + 1].id) {
                    cout << " -> SWAPPED" << endl;
                    swap(a[j], a[j + 1]);
                } else {
                    cout << " -> NO SWAP" << endl;
                }
            }
        }

        cout << "\nOuter Loop executions: " << pass1 << " | Inner Loop comparisons: " << pass2 << "\n";
    }
};

class selectionsort{

    public:
    product a[100];

    void display(int n) {
        cout << "\nFinal Sorted List \n";
        for (int i = 0; i < n; i++) {
            cout << "\nID: " << a[i].id << " | Name: " << a[i].name << " | Price: " << a[i].price;
        }
        cout << endl;
    }

    void sort(int n) {
        int smallest = 0;
        int pass2 = 0;

        for (int i = 0; i < n - 1; i++) {
            smallest = i;
            cout << "\nOuter Pass " << smallest << " (i = " << i << ") ---" << endl;
            
            for (int j = i + 1; j < n; j++) {
                pass2++;
                cout << "  Inner Pass " << pass2 << ": Comparing Index " << smallest << " (ID: " << a[smallest].id << ") and " << j << " (ID: " << a[j].id << ")";
                
                if (a[j].id < a[smallest].id) {
                    cout << " -> NEW SMALLEST FOUND";
                    smallest = j;
                }
                cout << endl;
            }
            
            if (smallest != i) {
                cout << "  -> SWAPED \n";
                swap(a[i], a[smallest]);
            } else {
                cout << " No Swapping Happened ! \n";
            }
        }

        cout << "\nOuter Loop executions: " << n - 1 << " | Inner Loop comparisons: " << pass2 << "\n";
    }

};

int main() {
    selectionsort s;
    bubblesort b;
    int k;
    cout << "Enter No of Products: ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        product temp;
        cout << "\nEnter ID: ";
        cin >> temp.id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, temp.name);

        cout << "Enter Manufacturer Price: ";
        cin >> temp.price;

        b.a[i] = temp;
        s.a[i] = temp;
    }

    b.sort(k);
    cout << "Using Bubble Sort -> \n";
    b.display(k);

    s.sort(k);
    cout << "Using Selection Sort -> \n";
    s.display(k);

    return 0;
}
