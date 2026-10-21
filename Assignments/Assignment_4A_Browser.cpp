
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

struct Page
{
    int page_id;
    string timestamp;
    Page* next;
    Page* prev;
};

class BrowserHistory
{
    Page* head;
    Page* current;
    Page* tail;

    string getTime()
    {
        time_t now = time(0);
        string t = ctime(&now);
        if (!t.empty() && t.back() == '\n')
            t.pop_back();
        return t;
    }

public:
    BrowserHistory()
    {
        head = current = tail = nullptr;
    }

    void addPage(int id)
    {
        Page* newPage = new Page;
        newPage->page_id = id;
        newPage->timestamp = getTime();
        newPage->next = nullptr;
        newPage->prev = nullptr;

        if (head == nullptr)
        {
            head = current = tail = newPage;
        }
        else
        {
            if (current != tail)
            {
                Page* temp = current->next;
                while (temp != nullptr)
                {
                    Page* del = temp;
                    temp = temp->next;
                    delete del;
                }
                current->next = nullptr;
                tail = current;
            }

            tail->next = newPage;
            newPage->prev = tail;
            tail = newPage;
            current = newPage;
        }

        cout << "Web page added successfully.\n";
    }

    void visitPage(int id)
    {
        Page* temp = head;

        while (temp != nullptr)
        {
            if (temp->page_id == id)
            {
                current = temp;
                current->timestamp = getTime();
                cout << "Visited page ID: " << current->page_id << "\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Page not found in history.\n";
    }

    void goBackward()
    {
        if (current != nullptr && current->prev != nullptr)
        {
            current = current->prev;
            current->timestamp = getTime();
            cout << "Moved backward to page ID: "
                 << current->page_id << "\n";
        }
        else
        {
            cout << "No previous page available.\n";
        }
    }

    void goForward()
    {
        if (current != nullptr && current->next != nullptr)
        {
            current = current->next;
            current->timestamp = getTime();
            cout << "Moved forward to page ID: "
                 << current->page_id << "\n";
        }
        else
        {
            cout << "No next page available.\n";
        }
    }

    void deletePage(int id)
    {
        Page* temp = head;

        while (temp != nullptr && temp->page_id != id)
            temp = temp->next;

        if (temp == nullptr)
        {
            cout << "Page not found.\n";
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        if (current == temp)
        {
            current = temp->next != nullptr ? temp->next : temp->prev;
        }

        delete temp;

        cout << "Web page deleted successfully.\n";
    }

    void displayHistory()
    {
        if (head == nullptr)
        {
            cout << "Browser history is empty.\n";
            return;
        }

        Page* temp = head;

        cout << "\nBrowser History:\n";

        while (temp != nullptr)
        {
            cout << "Page ID: " << temp->page_id
                 << " | Timestamp: " << temp->timestamp;

            if (temp == current)
                cout << " [Current Page]";

            cout << "\n";
            temp = temp->next;
        }
    }

    ~BrowserHistory()
    {
        Page* temp = head;

        while (temp != nullptr)
        {
            Page* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main()
{
    BrowserHistory browser;
    int choice, id;

    do
    {
        cout << "\n--- Browser History Menu ---\n";
        cout << "1. Visit a specific web page\n";
        cout << "2. Navigate backward\n";
        cout << "3. Navigate forward\n";
        cout << "4. Add a new web page\n";
        cout << "5. Delete a web page\n";
        cout << "6. Display browser history\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter page ID to visit: ";
            cin >> id;
            browser.visitPage(id);
            break;

        case 2:
            browser.goBackward();
            break;

        case 3:
            browser.goForward();
            break;

        case 4:
            cout << "Enter new page ID: ";
            cin >> id;
            browser.addPage(id);
            break;

        case 5:
            cout << "Enter page ID to delete: ";
            cin >> id;
            browser.deletePage(id);
            break;

        case 6:
            browser.displayHistory();
            break;

        case 0:
            cout << "Exiting browser history.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
