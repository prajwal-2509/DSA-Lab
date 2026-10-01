#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) {
        name = n;
        price = p;
    }
};

class GroceryStore {
    vector<Product> products;
    unordered_map<string, Product> hashTable;

public:
    void inputProducts() {
        int n;

        cout << "Enter number of products: ";
        cin >> n;

        for(int i = 0; i < n; i++) {
            string name;
            double price;

            cout << "Enter product and price: ";
            cin >> name >> price;

            Product p(name, price);
            products.push_back(p);
            hashTable.insert({name, p});
        }
    }

    void displayBill() {
        double total = 0;

        cout << "\nGROCERY BILL\n";
        cout << "--------------------------------\n";
        cout << "No.\tProduct\tPrice\n";

        for(int i = 0; i < products.size(); i++) {
            cout << i + 1 << "\t"
                 << products[i].name << "\t"
                 << products[i].price << endl;

            total += products[i].price;
        }

        cout << "--------------------------------\n";
        cout << "Grand Total: Rs. " << total << endl;
    }

    int linearSearch(string key) {
        for(int i = 0; i < products.size(); i++) {
            if(products[i].name == key)
                return i;
        }

        return -1;
    }

    int sentinelSearch(string key) {
        if(products.empty())
            return -1;

        string last = products.back().name;
        products.back().name = key;

        int i = 0;

        while(products[i].name != key)
            i++;

        products.back().name = last;

        if(i == products.size() - 1 && last != key)
            return -1;

        return i;
    }

    // void sortProducts() {
    //     sort(products.begin(), products.end(),
    //         [](Product a, Product b) {
    //             return a.name < b.name;
    //         });
    // }
    void sortProducts() {
    for(int i = 0; i < products.size() - 1; i++) {
        for(int j = i + 1; j < products.size(); j++) {
            if(products[i].name > products[j].name) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

    int binarySearch(string key) {
        int low = 0;
        int high = products.size() - 1;

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

    int fibonacciSearch(string key) {
        int n = products.size();
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
            int i = min(offset + a, n - 1);

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

        if(b && offset + 1 < n && products[offset + 1].name == key)
            return offset + 1;

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

    void hashSearch(string key) {
        auto x = hashTable.find(key);

        cout << "\nHashing\n";

        if(x == hashTable.end()) {
            cout << "Product not found\n";
            return;
        }

        cout << "Product: " << x->second.name << endl;
        cout << "Price: Rs. " << x->second.price << endl;
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
            cout << "\n5. Hashing";
            cout << "\n6. Exit";
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
                hashSearch(key);
            }
            else if(choice == 6) {
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