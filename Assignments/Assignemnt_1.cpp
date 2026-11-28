
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Product
{
public:
    int code;
    string name;
    double price;

    Product()
    {
        code = 0;
        name = "";
        price = 0;
    }

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

    Product hashTable[20];
    bool occupied[20] = {false};
    int size = 20;

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
        for (int i = 0; i < products.size() - 1; i++)
        {
            for (int j = 0; j < products.size() - i - 1; j++)
            {
                if (products[j].code > products[j + 1].code)
                {
                    Product temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
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

        if (n == 0)
            return -1;

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

    int hashFunction(int key)
    {
        return (key % size + size) % size;
    }

    void insertHash()
    {
        for (int i = 0; i < products.size(); i++)
        {
            int index = hashFunction(products[i].code);
            int start = index;

            while (occupied[index])
            {
                index = (index + 1) % size;

                if (index == start)
                {
                    cout << "Hash table is full\n";
                    return;
                }
            }

            hashTable[index] = products[i];
            occupied[index] = true;
        }
    }

    void hashSearch(int key)
    {
        int index = hashFunction(key);
        int start = index;

        while (occupied[index])
        {
            if (hashTable[index].code == key)
            {
                cout << "\nHashing with Linear Probing\n";
                cout << "Product Code: " << hashTable[index].code << endl;
                cout << "Product: " << hashTable[index].name << endl;
                cout << "Price: Rs. " << hashTable[index].price << endl;
                return;
            }

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << "Product not found\n";
    }

    void displayHash()
    {
        cout << "\n--- HASH TABLE ---\n";
        cout << "Index\tCode\tProduct\tPrice\n";

        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";

            if (occupied[i])
            {
                cout << hashTable[i].code << "\t"
                     << hashTable[i].name << "\t"
                     << hashTable[i].price;
            }
            else
            {
                cout << "Empty";
            }

            cout << endl;
        }
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

    void searchProduct()
    {
        int choice;
        int key;
        int x = -1;

        while (true)
        {
            cout << "\n--- PRODUCT SEARCH MENU ---\n";
            cout << "1. Linear Search";
            cout << "\n2. Sentinel Search";
            cout << "\n3. Binary Search";
            cout << "\n4. Fibonacci Search";
            cout << "\n5. Hashing with Linear Probing";
            cout << "\n6. Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            if (choice == 6)
                break;

            if (choice < 1 || choice > 5)
            {
                cout << "Invalid choice\n";
                continue;
            }

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
        }
    }
};

int main()
{
    GroceryStore store;

    store.inputProducts();

    store.insertHash();
    store.displayHash();

    store.sortProducts();
    store.displayBill();

    store.searchProduct();

    return 0;
}
