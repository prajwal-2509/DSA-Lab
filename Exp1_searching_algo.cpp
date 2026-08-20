#include <iostream>

using namespace std;

class Searching
{
    int a[100];
    int n;

public:

    // Input
    void input()
    {
        cout << "Enter number of items: ";
        cin >> n;

        cout << "Enter prices: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    // Sort array
    void sortArray()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            }
        }
    }

    // Display array
    void display()
    {
        cout << "Sorted prices: ";

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    // 1. Linear Search
    void linearSearch(int key)
    {
        int comparisons = 0;
        int iterations = 0;

        for (int i = 0; i < n; i++)
        {
            iterations++;
            comparisons++;

            if (a[i] == key)
            {
                cout << "Linear Search: Found"
                     << " | Index: " << i
                     << " | Comparisons: " << comparisons
                     << " | Iterations: " << iterations << endl;
                return;
            }
        }

        cout << "Linear Search: Not Found"
             << " | Comparisons: " << comparisons
             << " | Iterations: " << iterations << endl;
    }

    // 2. Sentinel Search
    void sentinelSearch(int key)
    {
        int comparisons = 0;
        int iterations = 0;

        int last = a[n - 1];
        a[n - 1] = key;

        int i = 0;

        while (true)
        {
            iterations++;
            comparisons++;

            if (a[i] == key)
                break;

            i++;
        }

        a[n - 1] = last;

        if (i < n - 1 || last == key)
        {
            cout << "Sentinel Search: Found"
                 << " | Index: " << i
                 << " | Comparisons: " << comparisons
                 << " | Iterations: " << iterations << endl;
        }
        else
        {
            cout << "Sentinel Search: Not Found"
                 << " | Comparisons: " << comparisons
                 << " | Iterations: " << iterations << endl;
        }
    }

    // 3. Binary Search
    void binarySearch(int key)
    {
        int low = 0;
        int high = n - 1;

        int comparisons = 0;
        int iterations = 0;

        while (low <= high)
        {
            iterations++;

            int mid = (low + high) / 2;

            comparisons++;

            if (a[mid] == key)
            {
                cout << "Binary Search: Found"
                     << " | Index: " << mid
                     << " | Comparisons: " << comparisons
                     << " | Iterations: " << iterations << endl;
                return;
            }
            else if (a[mid] < key)
            {
                comparisons++;
                low = mid + 1;
            }
            else
            {
                comparisons++;
                high = mid - 1;
            }
        }

        cout << "Binary Search: Not Found"
             << " | Comparisons: " << comparisons
             << " | Iterations: " << iterations << endl;
    }
};

int main()
{
    Searching s;
    int key;

    s.input();

    s.sortArray();

    s.display();

    cout << "Enter price to search: ";
    cin >> key;

    cout << "\n--- Search Results ---\n";

    s.linearSearch(key);
    s.sentinelSearch(key);
    s.binarySearch(key);

    return 0;
}