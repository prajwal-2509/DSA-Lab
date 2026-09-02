#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Product
{
public:
    int code;
    string name;
    double price;

    Product(int c, string n, double p)
    {
        code = c;
        name = n;
        price = p;
    }
};

class GroceryStore
{
    vector<Product> products;
    unordered_map<int, Product> hashTable;

public:
    void inputProducts()
    {
        int n;

        cout << "Enter number of products: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int code;
            string name;
            double price;

            cout << "\nEnter product code: ";
            cin >> code;

            cout << "Enter product name: ";
            cin >> name;

            cout << "Enter product price: ";
            cin >> price;

            Product p(code, name, price);

            products.push_back(p);
            hashTable.insert({code, p});
        }
    }

    void displayBill()
    {
        double total = 0;

        cout << "\nGROCERY BILL\n";
        cout << "--------------------------------\n";
        cout << "Code\tProduct\tPrice\n";
        cout << "--------------------------------\n";

        for (int i = 0; i < products.size(); i++)
        {
            cout << products[i].code << "\t"
                 << products[i].name << "\t"
                 << products[i].price << endl;

            total += products[i].price;
        }

        cout << "--------------------------------\n";
        cout << "Grand Total: Rs. " << total << endl;
    }

    int linearSearch(int key)
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].code == key)
                return i;
        }

        return -1;
    }

    int sentinelSearch(int key)
    {
        if (products.empty())
            return -1;

        int last = products.back().code;
        products.back().code = key;

        int i = 0;

        while (products[i].code != key)
            i++;

        products.back().code = last;

        if (i == products.size() - 1 && last != key)
            return -1;

        return i;
    }

    void sortProducts()
    {
        sort(products.begin(), products.end(),
             [](Product a, Product b)
             {
                 return a.code < b.code;
             });
    }

    int binarySearch(int key)
    {
        int low = 0;
        int high = products.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (products[mid].code == key)
                return mid;

            if (products[mid].code < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int fibonacciSearch(int key)
    {
        int n = products.size();

        int a = 0;
        int b = 1;
        int c = 1;
        int offset = -1;

        while (c < n)
        {
            a = b;
            b = c;
            c = a + b;
        }

        while (c > 1)
        {
            int i = min(offset + a, n - 1);

            if (products[i].code < key)
            {
                c = b;
                b = a;
                a = c - b;
                offset = i;
            }
            else if (products[i].code > key)
            {
                c = a;
                b = b - a;
                a = c - b;
            }
            else
            {
                return i;
            }
        }

        if (b && offset + 1 < n &&
            products[offset + 1].code == key)
            return offset + 1;

        return -1;
    }

    void result(string type, int i)
    {
        cout << "\n" << type << endl;

        if (i == -1)
        {
            cout << "Product not found\n";
            return;
        }

        cout << "Product Code: " << products[i].code << endl;
        cout << "Product: " << products[i].name << endl;
        cout << "Price: Rs. " << products[i].price << endl;
    }

    void hashSearch(int key)
    {
        auto x = hashTable.find(key);

        cout << "\nHashing\n";

        if (x == hashTable.end())
        {
            cout << "Product not found\n";
            return;
        }

        cout << "Product Code: " << x->second.code << endl;
        cout << "Product: " << x->second.name << endl;
        cout << "Price: Rs. " << x->second.price << endl;
    }

    void searchProduct()
    {
        int choice;
        int key;
        int x = -1;

        while (true)
        {
            cout << "\n1. Linear Search";
            cout << "\n2. Sentinel Search";
            cout << "\n3. Binary Search";
            cout << "\n4. Fibonacci Search";
            cout << "\n5. Hashing";
            cout << "\n6. Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            if (choice == 6)
                break;

            cout << "\nEnter product code: ";
            cin >> key;

            if (choice == 1)
            {
                x = linearSearch(key);
                result("Linear Search", x);
            }
            else if (choice == 2)
            {
                x = sentinelSearch(key);
                result("Sentinel Search", x);
            }
            else if (choice == 3)
            {
                sortProducts();
                x = binarySearch(key);
                result("Binary Search", x);
            }
            else if (choice == 4)
            {
                sortProducts();
                x = fibonacciSearch(key);
                result("Fibonacci Search", x);
            }
            else if (choice == 5)
            {
                hashSearch(key);
            }
            else
            {
                cout << "Invalid choice\n";
            }
        }
    }
};

int main()
{
    GroceryStore store;

    store.inputProducts();
    store.sortProducts();
    store.displayBill();
    store.searchProduct();

    return 0;
}