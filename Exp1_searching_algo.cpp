#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Item
{
    int code;
    int price;
    string name;
};

struct Searching
{
    Item a[100];
    int n;

    void input()
    {
        cout << "Enter number of items: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter product code: ";
            cin >> a[i].code;

            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, a[i].name);

            cout << "Enter price: ";
            cin >> a[i].price;
        }
    }

    void sortArray()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j].code > a[j + 1].code)
                {
                    Item temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    void display()
    {
        cout << "\nGrocery Items:\n";

        for (int i = 0; i < n; i++)
        {
            cout << "Code: " << a[i].code
                 << " | Name: " << a[i].name
                 << " | Price: Rs." << a[i].price << endl;
        }
    }

    // Linear Search
    void linearSearch(int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i].code == key)
            {
                cout << "Linear Search: Found | "
                     << a[i].name << " | Rs." << a[i].price << endl;
                return;
            }
        }

        cout << "Linear Search: Not Found" << endl;
    }

    // Sentinel Search
    void sentinelSearch(int key)
    {
        Item last = a[n - 1];
        a[n - 1].code = key;

        int i = 0;

        while (true)
        {
            if (a[i].code == key)
                break;

            i++;
        }

        a[n - 1] = last;

        if (i < n - 1 || last.code == key)
        {
            cout << "Sentinel Search: Found | "
                 << a[i].name << " | Rs." << a[i].price << endl;
        }
        else
        {
            cout << "Sentinel Search: Not Found" << endl;
        }
    }

    // Binary Search
    void binarySearch(int key)
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (a[mid].code == key)
            {
                cout << "Binary Search: Found | "
                     << a[mid].name << " | Rs." << a[mid].price << endl;
                return;
            }
            else if (a[mid].code < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << "Binary Search: Not Found" << endl;
    }

    // Fibonacci Search
    void fibonacciSearch(int key)
    {
        int fib2 = 0;
        int fib1 = 1;
        int fib = fib1 + fib2;

        while (fib < n)
        {
            fib2 = fib1;
            fib1 = fib;
            fib = fib1 + fib2;
        }

        int offset = -1;

        while (fib > 1)
        {
            int i = min(offset + fib2, n - 1);

            if (a[i].code < key)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }
            else if (a[i].code > key)
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }
            else
            {
                cout << "Fibonacci Search: Found | "
                     << a[i].name << " | Rs." << a[i].price << endl;
                return;
            }
        }

        if (fib1 && offset + 1 < n &&
            a[offset + 1].code == key)
        {
            cout << "Fibonacci Search: Found | "
                 << a[offset + 1].name
                 << " | Rs." << a[offset + 1].price << endl;
            return;
        }

        cout << "Fibonacci Search: Not Found" << endl;
    }

    // Hashing
    void hashing(int key)
    {
        Item hashTable[100];

        for (int i = 0; i < 100; i++)
            hashTable[i].code = -1;

        for (int i = 0; i < n; i++)
        {
            int index = a[i].code % 100;

            while (hashTable[index].code != -1)
                index = (index + 1) % 100;

            hashTable[index] = a[i];
        }

        int index = key % 100;

        while (hashTable[index].code != -1)
        {
            if (hashTable[index].code == key)
            {
                cout << "Hashing: Found | "
                     << hashTable[index].name
                     << " | Rs." << hashTable[index].price << endl;
                return;
            }

            index = (index + 1) % 100;
        }

        cout << "Hashing: Not Found" << endl;
    }
};

int main()
{
    Searching s;
    int key;

    s.input();

    s.sortArray();

    s.display();

    cout << "\nEnter product code to search: ";
    cin >> key;

    cout << "\n--- Search Results ---\n";

    s.linearSearch(key);
    s.sentinelSearch(key);
    s.binarySearch(key);
    s.fibonacciSearch(key);
    s.hashing(key);

    return 0;
}