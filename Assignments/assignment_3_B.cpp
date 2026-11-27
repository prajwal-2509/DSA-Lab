#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int prn;
    string name;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

class Club
{
    Node *head;

public:

    Club()
    {
        head = NULL;
    }

    void addMember()
    {
        int prn;
        string name;

        cout << "Enter PRN: ";
        cin >> prn;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        Node *newNode = new Node;

        newNode->prn = prn;
        newNode->name = name;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }

        cout << "Member added.\n";
    }

    void showMembers()
    {
        if (head == NULL)
        {
            cout << "No members.\n";
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp != NULL)
        {
            if (count == 1)
                cout << "President: ";
            else if (temp->next == NULL)
                cout << "Secretary: ";
            else
                cout << "Member: ";

            cout << temp->prn << " " << temp->name << endl;

            temp = temp->next;
            count++;
        }
    }

    void deleteMember()
    {
        int prn;

        cout << "Enter PRN to delete: ";
        cin >> prn;

        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL && temp->prn != prn)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Member not found.\n";
            return;
        }

        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        delete temp;

        cout << "Member deleted.\n";
    }

    int totalMembers()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

        void concatenate(Club &second)
        {
            if (head == NULL)
            {
                head = second.head;
                second.head = NULL;
                return;
            }

            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = second.head;
            second.head = NULL;

            cout << "Lists concatenated successfully!";
        }
};

int main()
{
    Club division1, division2;

    int choice, division;

    do
    {
        cout << "\n--- Techno-Fun Club ---\n";
        cout << "1. Add Member\n";
        cout << "2. Show Members\n";
        cout << "3. Delete Member\n";
        cout << "4. Total Members\n";
        cout << "5. Concatenate Two Divisions\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Division (1/2): ";
            cin >> division;

            if (division == 1)
                division1.addMember();
            else
                division2.addMember();

            break;

        case 2:
            cout << "\nDivision 1:\n";
            division1.showMembers();

            cout << "\nDivision 2:\n";
            division2.showMembers();

            break;

        case 3:
            cout << "Enter Division (1/2): ";
            cin >> division;

            if (division == 1)
                division1.deleteMember();
            else
                division2.deleteMember();

            break;

        case 4:
            cout << "Division 1 Members: "
                 << division1.totalMembers() << endl;

            cout << "Division 2 Members: "
                 << division2.totalMembers() << endl;

            break;

        case 5:
            division1.concatenate(division2);

            cout << "\nAfter Concatenation:\n";
            division1.showMembers();

            break;

        case 6:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
