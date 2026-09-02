#include <iostream>
using namespace std;

struct product {
    int id;
    string name;
    string manufacturer;
    float price;
    float rating;
};

void bubbleSortById(product a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].id > a[j + 1].id)
                swap(a[j], a[j + 1]);
}

void selectionSortByPrice(product a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j].price < a[min].price)
                min = j;
        swap(a[i], a[min]);
    }
}

void insertionSortByRatingDesc(product a[], int n) {
    for (int i = 1; i < n; i++) {
        product key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].rating < key.rating) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void display(product a[], int n) {
    cout << "\nID\tName\tManufacturer\tPrice\tRating\n";
    cout << "----------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].id << "\t" << a[i].name << "\t" << a[i].manufacturer
             << "\t\t" << a[i].price << "\t" << a[i].rating << "\n";
    }
    cout << "----------------------------------------------\n";
}

int main() {
    product a[100], b[100], c[100];
    int k;
    cout << "\nEnter No of Products: ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << "\nEnter ID: ";
        cin >> a[i].id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, a[i].name);
        cout << "Enter Manufacturer: ";
        getline(cin, a[i].manufacturer);
        cout << "Enter Price: ";
        cin >> a[i].price;
        cout << "Enter Rating: ";
        cin >> a[i].rating;

        b[i] = a[i];
        c[i] = a[i];
    }

    bubbleSortById(a, k);
    cout << "\nIncreasing Order of ID:\n";
    display(a, k);

    selectionSortByPrice(b, k);
    cout << "\nIncreasing Order of Price:\n";
    display(b, k);

    insertionSortByRatingDesc(c, k);
    cout << "\nDecreasing Order of Rating:\n";
    display(c, k);

    return 0;
}