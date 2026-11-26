
#include <iostream>
#include <algorithm>
using namespace std;

class Searching {
    int a[100], n;
    int hashTable[20];
    int size = 20;

public:
    Searching() {
        for(int i = 0; i < size; i++) {
            hashTable[i] = -1;
        }
    }

    void input() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void display() {
        cout << "\nElements: ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int linearSearch(int key) {
        for(int i = 0; i < n; i++) {
            if(a[i] == key)
                return i;
        }
        return -1;
    }

    int sentinelSearch(int key) {
        if(n == 0)
            return -1;

        int last = a[n - 1];
        a[n - 1] = key;

        int i = 0;

        while(a[i] != key)
            i++;

        a[n - 1] = last;

        if(i == n - 1 && last != key)
            return -1;

        return i;
    }

   void sortArray() {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

    int binarySearch(int key) {
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(a[mid] == key)
                return mid;

            if(a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int fibonacciSearch(int key) {
    int fibA = 0, fibB = 1, fibC = fibA + fibB;
    int offset = -1;

    while(fibC < n) {
        fibA = fibB;
        fibB = fibC;
        fibC = fibA + fibB;
    }

    while(fibC > 1) {
        int i = min(offset + fibA, n - 1);

        if(a[i] < key) {
            fibC = fibB;
            fibB = fibA;
            fibA = fibC - fibB;
            offset = i;
        }
        else if(a[i] > key) {
            fibC = fibA;
            fibB = fibB - fibA;
            fibA = fibC - fibB;
        }
        else {
            return i;
        }
    }

    if(fibB && offset + 1 < n && a[offset + 1] == key)
        return offset + 1;

    return -1;
}

    int hashFunction(int key) {
        return key % size;
    }

    void insertHash() {
        for(int i = 0; i < n; i++) {
            int index = hashFunction(a[i]);
            int start = index;

            while(hashTable[index] != -1) {
                index = (index + 1) % size;

                if(index == start) {
                    cout << "Hash table is full\n";
                    return;
                }
            }

            hashTable[index] = a[i];
        }
    }

    void hashSearch(int key) {
        int index = hashFunction(key);
        int start = index;

        while(hashTable[index] != -1) {
            if(hashTable[index] == key) {
                cout << "Element found at index: " << index << endl;
                return;
            }

            index = (index + 1) % size;

            if(index == start)
                break;
        }

        cout << "Element not found\n";
    }

    void displayHash() {
        cout << "\nHash Table:\n";

        for(int i = 0; i < size; i++) {
            cout << i << " --> " << hashTable[i] << endl;
        }
    }

    void searchMenu() {
        int key, choice;

        while(true) {
            cout << "\n1. Linear Search";
            cout << "\n2. Sentinel Search";
            cout << "\n3. Binary Search";
            cout << "\n4. Fibonacci Search";
            cout << "\n5. Hashing with Linear Probing";
            cout << "\n6. Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            if(choice == 6)
                break;

            cout << "Enter element to search: ";
            cin >> key;

            int result = -1;

            switch(choice) {
                case 1:
                    result = linearSearch(key);
                    break;

                case 2:
                    result = sentinelSearch(key);
                    break;

                case 3:
                    sortArray();
                    result = binarySearch(key);
                    break;

                case 4:
                    sortArray();
                    result = fibonacciSearch(key);
                    break;

                case 5:
                    hashSearch(key);
                    continue;

                default:
                    cout << "Invalid choice\n";
                    continue;
            }

            if(result == -1)
                cout << "Element not found\n";
            else
                cout << "Element found at index: " << result << endl;
        }
    }
};

int main() {
    Searching s;

    s.input();
    s.display();

    s.insertHash();
    s.displayHash();

    s.searchMenu();

    return 0;
}
