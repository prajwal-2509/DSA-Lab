#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
};

class GroceryStore {
    Product products[100];
    int n;

public:

    void inputProducts() {
        cout << "Enter number of products: ";
        cin >> n;

        for(int i = 0; i < n; i++) {
            cout << "Enter product and price: ";
            cin >> products[i].name >> products[i].price;
        }
    }

    void displayBill() {
        double total = 0;

        cout << "\nGROCERY BILL\n";
        cout << "-----------------------------\n";
        cout << "No.\tProduct\tPrice\n";

        for(int i = 0; i < n; i++) {
            cout << i + 1 << "\t"
                 << products[i].name << "\t"
                 << products[i].price << endl;

            total = total + products[i].price;
        }

        cout << "-----------------------------\n";
        cout << "Grand Total: Rs. " << total << endl;
    }

    // Linear Search
    int linearSearch(string key) {
        for(int i = 0; i < n; i++) {
            if(products[i].name == key)
                return i;
        }

        return -1;
    }

    // Sentinel Search
    int sentinelSearch(string key) {

        if(n == 0)
            return -1;

        string last = products[n - 1].name;

        products[n - 1].name = key;

        int i = 0;

        while(products[i].name != key) {
            i++;
        }

        products[n - 1].name = last;

        if(i == n - 1 && last != key)
            return -1;

        return i;
    }

    // Simple Bubble Sort
    void sortProducts() {

        for(int i = 0; i < n - 1; i++) {

            for(int j = 0; j < n - i - 1; j++) {

                if(products[j].name > products[j + 1].name) {

                    Product temp = products[j];

                    products[j] = products[j + 1];

                    products[j + 1] = temp;
                }
            }
        }
    }

    // Binary Search
    int binarySearch(string key) {

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(products[mid].name == key)
                return mid;

            if(products[mid].name < key)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    // Fibonacci Search
    int fibonacciSearch(string key) {

        int a = 0;
        int b = 1;
        int c = 1;

        int offset = -1;

        while(c < n) {
            a = b;
            b = c;
            c = a + b;
        }

        while(c > 1) {

            int i = offset + a;

            if(i >= n)
                i = n - 1;

            if(products[i].name < key) {

                c = b;
                b = a;
                a = c - b;

                offset = i;
            }

            else if(products[i].name > key) {

                c = a;
                b = b - a;
                a = c - b;
            }

            else {
                return i;
            }
        }

        if(b != 0 && offset + 1 < n &&
           products[offset + 1].name == key) {

            return offset + 1;
        }

        return -1;
    }

    void result(string type, int i) {

        cout << "\n" << type << endl;

        if(i == -1) {
            cout << "Product not found\n";
            return;
        }

        cout << "Product: " << products[i].name << endl;
        cout << "Price: Rs. " << products[i].price << endl;
    }

    void searchProduct() {

        int choice;
        string key;

        while(true) {

            cout << "\nEnter product: ";
            cin >> key;

            cout << "\n1. Linear Search";
            cout << "\n2. Sentinel Search";
            cout << "\n3. Binary Search";
            cout << "\n4. Fibonacci Search";
            cout << "\n5. Exit";

            cout << "\nEnter choice: ";
            cin >> choice;

            int x = -1;

            if(choice == 1) {

                x = linearSearch(key);

                result("Linear Search", x);
            }

            else if(choice == 2) {

                x = sentinelSearch(key);

                result("Sentinel Search", x);
            }

            else if(choice == 3) {

                sortProducts();

                x = binarySearch(key);

                result("Binary Search", x);
            }

            else if(choice == 4) {

                sortProducts();

                x = fibonacciSearch(key);

                result("Fibonacci Search", x);
            }

            else if(choice == 5) {

                break;
            }

            else {

                cout << "Invalid choice\n";
            }
        }
    }
};

int main() {

    GroceryStore store;

    store.inputProducts();

    store.displayBill();

    store.searchProduct();

    return 0;
}