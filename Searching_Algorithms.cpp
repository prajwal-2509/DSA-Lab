#include <iostream>
using namespace std;

class Search
{
    int a[50], n, key;

public:

    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Enter key to search: ";
        cin >> key;
    }

    // Linear Search
    void linear()
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == key)
            {
                cout << "Linear Search: Found at position "
                     << i + 1 << endl;
                return;
            }
        }

        cout << "Linear Search: Not Found" << endl;
    }

    // Sentinel Search
    void sentinel()
    {
        int last = a[n - 1];
        a[n - 1] = key;

        int i = 0;

        while (a[i] != key)
            i++;

        a[n - 1] = last;

        if (i < n - 1 || last == key)
            cout << "Sentinel Search: Found at position "
                 << i + 1 << endl;
        else
            cout << "Sentinel Search: Not Found" << endl;
    }

    // Sorting
    void sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    // Binary Search
    void binary()
    {
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (a[mid] == key)
            {
                cout << "Binary Search: Found at position "
                     << mid + 1 << endl;
                return;
            }
            else if (a[mid] < key)
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
};

int main()
{
    Search s;

    s.input();

    cout << "\n--- Searching Results ---\n";

    s.linear();

    s.sentinel();

    s.sort();

    cout << "\nAfter Sorting: ";
    
    // Binary Search requires sorted data
    s.binary();

    return 0;
}