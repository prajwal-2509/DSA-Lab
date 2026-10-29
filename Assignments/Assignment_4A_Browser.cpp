
/*
A browser maintains a history, which refers to a list of recently visited websites or web pages in
a data structure. Write a C++ menu-driven program to store the browser history or navigation
information dynamically as page_id and recent time-stamp. Write functions to
1. Visit a specific web page.
2. Navigate forward and backward.
3. Add new web pages.
4. Deleting web pages from existing lists.
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Page {
public:
    string url;
    time_t timestamp;
    Page *next, *prev;

    Page(string u) {
        url = u;
        timestamp = time(0);
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
    Page *head, *current;

public:
    BrowserHistory() {
        head = NULL;
        current = NULL;
    }

    void addPage(string url) {
        Page *p = new Page(url);

        if (head == NULL) {
            head = current = p;
        } else {
            Page *temp = current->next;

            while (temp != NULL) {
                Page *del = temp;
                temp = temp->next;
                delete del;
            }

            current->next = p;
            p->prev = current;
            current = p;
        }

        cout << "Visited: " << url << endl;
    }

    void visitPage(string url) {
        addPage(url);
    }

    void backward() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "Current page: " << current->url << endl;
        } else {
            cout << "No previous page.\n";
        }
    }

    void forward() {
        if (current != NULL && current->next != NULL) {
            current = current->next;
            cout << "Current page: " << current->url << endl;
        } else {
            cout << "No next page.\n";
        }
    }

    void deletePage(string url) {
        Page *temp = head;

        while (temp != NULL && temp->url != url) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Page not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (current == temp) {
            if (temp->next != NULL)
                current = temp->next;
            else
                current = temp->prev;
        }

        delete temp;
        cout << "Page deleted successfully.\n";
    }

    void display() {
        Page *temp = head;

        if (temp == NULL) {
            cout << "History is empty.\n";
            return;
        }

        while (temp != NULL) {
            cout << "Website: " << temp->url;
            cout << "\nTimestamp: " << ctime(&temp->timestamp);

            if (temp == current)
                cout << "<-- Current page\n";

            temp = temp->next;
        }
    }

    ~BrowserHistory() {
        while (head != NULL) {
            Page *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BrowserHistory b;
    int choice;
    string url;

    do {
        cout << "\n--- Browser History ---\n";
        cout << "1. Visit a web page\n";
        cout << "2. Navigate backward\n";
        cout << "3. Navigate forward\n";
        cout << "4. Add a new web page\n";
        cout << "5. Delete a web page\n";
        cout << "6. Display browser history\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter website URL: ";
            cin >> url;
            b.visitPage(url);
            break;

        case 2:
            b.backward();
            break;

        case 3:
            b.forward();
            break;

        case 4:
            cout << "Enter website URL: ";
            cin >> url;
            b.addPage(url);
            break;

        case 5:
            cout << "Enter website URL to delete: ";
            cin >> url;
            b.deletePage(url);
            break;

        case 6:
            b.display();
            break;

        case 0:
            cout << "Exiting browser history.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}