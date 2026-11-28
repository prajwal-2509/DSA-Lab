
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int prn;
    string name;
    Node *next;

    Node(int p, string n)
    {
        prn = p;
        name = n;
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

    // a) Add member
    void addMember(int prn, string name)
    {
        Node *newnode = new Node(prn, name);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }

        cout << "Member added successfully!\n";
    }

    // b) Show members
    void showMembers()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "No members in the club.\n";
            return;
        }

        cout << "\n===== TECHNO-FUN' CLUB MEMBERS =====\n";

        if (head->next == NULL)
        {
            cout << "President: " << head->name
                 << " (PRN: " << head->prn << ")\n";

            cout << "Secretary: Not assigned\n";
            return;
        }

        // First node is President
        cout << "\nPresident: " << head->name
             << " (PRN: " << head->prn << ")\n";

        temp = head->next;

        // Middle nodes are students
        while (temp->next != NULL)
        {
            cout << "Student: " << temp->name
                 << " (PRN: " << temp->prn << ")\n";

            temp = temp->next;
        }

        // Last node is Secretary
        cout << "\nSecretary: " << temp->name
             << " (PRN: " << temp->prn << ")\n";
    }

    // c) Delete member
    void deleteMember(int prn)
    {
        Node *temp = head;
        Node *prev = NULL;

        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        // President cannot be deleted
        if (head->prn == prn)
        {
            cout << "President cannot be deleted.\n";
            return;
        }

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

        prev->next = temp->next;
        delete temp;

        cout << "Member deleted successfully!\n";
    }

    // d) Count members
    int countMembers()
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

    // e) Concatenate two lists
    void concatenate(Club &c)
    {
        if (head == NULL)
        {
            head = c.head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = c.head;
        }

        c.head = NULL;

        cout << "Lists concatenated successfully!\n";
    }
};

// Main function
int main()
{
    Club c1, c2;

    int choice, prn, division;
    string name;

    do
    {
        cout << "\n===== TECHNO-FUN' CLUB =====\n";
        cout << "1. Add Member\n";
        cout << "2. Show Members\n";
        cout << "3. Delete Member\n";
        cout << "4. Count Members\n";
        cout << "5. Concatenate Two Divisions\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter division (1 or 2): ";
                cin >> division;

                cout << "Enter PRN: ";
                cin >> prn;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);

                if (division == 1)
                    c1.addMember(prn, name);
                else if (division == 2)
                    c2.addMember(prn, name);
                else
                    cout << "Invalid division!\n";

                break;

            case 2:
                cout << "Enter division (1 or 2): ";
                cin >> division;

                if (division == 1)
                    c1.showMembers();
                else if (division == 2)
                    c2.showMembers();
                else
                    cout << "Invalid division!\n";

                break;

            case 3:
                cout << "Enter division (1 or 2): ";
                cin >> division;

                cout << "Enter PRN to delete: ";
                cin >> prn;

                if (division == 1)
                    c1.deleteMember(prn);
                else if (division == 2)
                    c2.deleteMember(prn);
                else
                    cout << "Invalid division!\n";

                break;

            case 4:
                cout << "Division 1 Members: "
                     << c1.countMembers() << endl;

                cout << "Division 2 Members: "
                     << c2.countMembers() << endl;

                cout << "Total Members: "
                     << c1.countMembers() +
                        c2.countMembers() << endl;

                break;

            case 5:
                c1.concatenate(c2);
                cout << "\nCombined List:\n";
                c1.showMembers();

                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
