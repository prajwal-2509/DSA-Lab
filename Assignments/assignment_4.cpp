#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int page_id;
    string timestamp;
    Node *prev, *next;
};

Node *head = NULL;
Node *current = NULL;

void visitPage()
{
    Node *newNode = new Node;

    cout << "Enter Page ID: ";
    cin >> newNode->page_id;

    cout << "Enter Time Stamp: ";
    cin >> newNode->timestamp;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        current = newNode;
    }
    else
    {
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    cout << "Page visited.\n";
}

void backward()
{
    if (current == NULL || current->prev == NULL)
        cout << "No previous page.\n";
    else
    {
        current = current->prev;
        cout << "Page ID: " << current->page_id << endl;
        cout << "Time: " << current->timestamp << endl;
    }
}

void forward()
{
    if (current == NULL || current->next == NULL)
        cout << "No next page.\n";
    else
    {
        current = current->next;
        cout << "Page ID: " << current->page_id << endl;
        cout << "Time: " << current->timestamp << endl;
    }
}

void addPage()
{
    Node *newNode = new Node;

    cout << "Enter Page ID: ";
    cin >> newNode->page_id;

    cout << "Enter Time Stamp: ";
    cin >> newNode->timestamp;

    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        current = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        current = newNode;
    }

    cout << "Page added.\n";
}

void deletePage()
{
    int id;
    cout << "Enter Page ID to delete: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL && temp->page_id != id)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Page not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (current == temp)
        current = temp->next;

    delete temp;

    cout << "Page deleted.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Backward";
        cout << "\n3. Forward";
        cout << "\n4. Add Page";
        cout << "\n5. Delete Page";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            visitPage();
            break;

        case 2:
            backward();
            break;

        case 3:
            forward();
            break;

        case 4:
            addPage();
            break;

        case 5:
            deletePage();
            break;

        case 6:
            cout << "Exit";
            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 6);

    return 0;
}