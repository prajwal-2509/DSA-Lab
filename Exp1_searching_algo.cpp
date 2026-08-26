#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int price;
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
        cin.ignore();

        cout << "\nEnter item name: ";
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
                if (a[j].price > a[j + 1].price)
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
            cout << i << ". "
                 << a[i].name
                 << " - Rs." << a[i].price << endl;
        }
    }

    // Linear Search
    void linearSearch(int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i].price == key)
            {
                cout << "Linear Search: Found "
                     << a[i].name
                     << " at index " << i << endl;
                return;
            }
        }

        cout << "Linear Search: Not Found" << endl;
    }

    // Sentinel Search
    void sentinelSearch(int key)
    {
        Item last = a[n - 1];
        a[n - 1].price = key;

        int i = 0;

        while (true)
        {
            if (a[i].price == key)
                break;

            i++;
        }

        a[n - 1] = last;

        if (i < n - 1 || last.price == key)
        {
            cout << "Sentinel Search: Found "
                 << a[i].name
                 << " at index " << i << endl;
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

            if (a[mid].price == key)
            {
                cout << "Binary Search: Found "
                     << a[mid].name
                     << " at index " << mid << endl;
                return;
            }
            else if (a[mid].price < key)
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

            if (a[i].price < key)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }
            else if (a[i].price > key)
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }
            else
            {
                cout << "Fibonacci Search: Found "
                     << a[i].name
                     << " at index " << i << endl;
                return;
            }
        }

        if (fib1 && offset + 1 < n &&
            a[offset + 1].price == key)
        {
            cout << "Fibonacci Search: Found "
                 << a[offset + 1].name
                 << " at index " << offset + 1 << endl;
            return;
        }

        cout << "Fibonacci Search: Not Found" << endl;
    }

    // Hashing
    void hashing(int key)
    {
        Item hashTable[100];

        for (int i = 0; i < 100; i++)
            hashTable[i].price = -1;

        for (int i = 0; i < n; i++)
        {
            int index = a[i].price % 100;

            while (hashTable[index].price != -1)
                index = (index + 1) % 100;

            hashTable[index] = a[i];
        }

        int index = key % 100;

        while (hashTable[index].price != -1)
        {
            if (hashTable[index].price == key)
            {
                cout << "Hashing: Found "
                     << hashTable[index].name
                     << " at hash index " << index << endl;
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

    cout << "\nEnter price to search: ";
    cin >> key;

    cout << "\n--- Search Results ---\n";

    s.linearSearch(key);
    s.sentinelSearch(key);
    s.binarySearch(key);
    s.fibonacciSearch(key);
    s.hashing(key);

    return 0;
}