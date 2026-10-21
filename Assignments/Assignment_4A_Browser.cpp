
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
#include <ctime>
using namespace std;

struct Page
{
    int id;
    time_t time;
    Page* next;
    Page* prev;
};

Page* head = NULL;
Page* current = NULL;

void addPage(int id)
{
    Page* p = new Page;
    p->id = id;
    p->time = time(0);
    p->next = NULL;
    p->prev = NULL;

    if (head == NULL)
    {
        head = current = p;
    }
    else
    {
        Page* temp = current->next;

        while (temp != NULL)
        {
            Page* del = temp;
            temp = temp->next;
            delete del;
        }

        current->next = p;
        p->prev = current;
        current = p;
    }

    cout << "Page added successfully\n";
}

void visitPage(int id)
{
    Page* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            current = temp;
            current->time = time(0);
            cout << "Page visited: " << id << "\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Page not found\n";
}

void backward()
{
    if (current != NULL && current->prev != NULL)
    {
        current = current->prev;
        cout << "Previous page: " << current->id << "\n";
    }
    else
        cout << "No previous page\n";
}

void forward()
{
    if (current != NULL && current->next != NULL)
    {
        current = current->next;
        cout << "Next page: " << current->id << "\n";
    }
    else
        cout << "No next page\n";
}

void deletePage(int id)
{
    Page* temp = head;

    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Page not found\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    delete temp;
    cout << "Page deleted successfully\n";
}

void display()
{
    Page* temp = head;

    if (temp == NULL)
    {
        cout << "History is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "Page ID: " << temp->id
             << " Time: " << ctime(&temp->time);

        if (temp == current)
            cout << "Current page\n";

        temp = temp->next;
    }
}

int main()
{
    int ch, id;

    do
    {
        cout << "\n1. Add page\n";
        cout << "2. Visit page\n";
        cout << "3. Backward\n";
        cout << "4. Forward\n";
        cout << "5. Delete page\n";
        cout << "6. Display history\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter page ID: ";
            cin >> id;
            addPage(id);
            break;

        case 2:
            cout << "Enter page ID: ";
            cin >> id;
            visitPage(id);
            break;

        case 3:
            backward();
            break;

        case 4:
            forward();
            break;

        case 5:
            cout << "Enter page ID to delete: ";
            cin >> id;
            deletePage(id);
            break;

        case 6:
            display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (ch != 0);

    return 0;
}
