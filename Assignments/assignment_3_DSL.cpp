#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Node {
    public:
    int id;
    string name;
    float duration ;
    Node *next;
    Node ( int id , string name , float duration )
    {
        this->id = id ;
        this->name = name;
        this->duration = duration;
        this->next = NULL;
    }
};
class SingleLL {
    Node *head;

public:

    SingleLL()
    {
        head = NULL;
    }

    bool isduplicate(int id)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
                return true;

            temp = temp->next;
        }

        return false;
    }

    void insert_at_any_pos(int pos)
    {
               if (pos <= 0)
        {
            cout << "Invalid position!";
            return;
        }

        int pid;

        cout << "Enter the Song ID: ";
        cin >> pid;
 
        if (isduplicate(pid))
        {
            cout << "The Song already exists! "
                 << "No need to enter same ID.";
            return;
        }
        string name;
        float duration;

        cout << "Enter Song Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Duration: ";
        cin >> duration;

        Node *newnode = new Node(pid, name, duration);

        if(pos==1){
            newnode->next = head;
            head = newnode;
            cout << "The song " << newnode->name << " Inserted at Position 1 . ";
            return;
        }

        Node *temp = head;

        for ( int i =1; i < pos -1 && temp!=nullptr ; i++){
            temp = temp->next ;
        }

        if(temp==nullptr){
            cout<<"The song "<< newnode->name << " is out of bounds !!";
            delete newnode; return ;
        }else{
            newnode->next = temp->next ;
            temp ->next = newnode;
            cout << "\nInserted \"" << newnode->name << "\" at position " << pos << ".\n";

        }

    }

    void displayll(){
        if (head == nullptr)
{
    cout << "Playlist is empty!";
    return;
}
        Node *temp = head;
        int pos = 1;
        while (temp!=nullptr){
            cout << "\n Position " << pos << " \n Name : " <<temp->name << "\n ID : " << temp->id << "\n Duration : " << temp->duration;
            temp=temp->next ;
            pos++;
        }
    }

    void delete_at_pos(int pos)
{
    if (head == nullptr)
    {
        cout << "There are no songs to delete!";
        return;
    }

    if (pos <= 0)
    {
        cout << "Invalid position!";
        return;
    }

    Node *temp = head;

    // Delete first node
    if (pos == 1)
    {
        head = head->next;

        cout << "\nDeleted song \"" << temp->name
             << "\" from position 1.\n";

        delete temp;
        return;
    }

    Node *prev = nullptr;

    // Move temp to the node at the required position
    for (int i = 1; i < pos && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // Position doesn't exist
    if (temp == nullptr)
    {
        cout << "\nPosition " << pos << " is out of bounds!\n";
        return;
    }

    // Remove node
    prev->next = temp->next;

    cout << "\nDeleted song \"" << temp->name
         << "\" from position " << pos << ".\n";

    delete temp;
}

        // Sort Playlist by Song ID
void sortByID()
{
    if (head == nullptr)
    {
        cout << "Playlist is empty!";
        return;
    }

    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->id > temp->next->id)
            {
                swap(temp->id, temp->next->id);
                swap(temp->name, temp->next->name);
                swap(temp->duration, temp->next->duration);

                swapped = true;
            }

            temp = temp->next;
        }
    }

    cout << "\nPlaylist sorted by ID!\n";
}


// Sort Playlist by Song Title
void sortByTitle()
{
    if (head == nullptr)
    {
        cout << "Playlist is empty!";
        return;
    }

    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->name > temp->next->name)
            {
                swap(temp->id, temp->next->id);
                swap(temp->name, temp->next->name);
                swap(temp->duration, temp->next->duration);

                swapped = true;
            }

            temp = temp->next;
        }
    }

    cout << "\nPlaylist sorted by Title!\n";
}


// Sort Playlist by Duration
void sortByDuration()
{
    if (head == nullptr)
    {
        cout << "Playlist is empty!";
        return;
    }

    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->duration > temp->next->duration)
            {
                swap(temp->id, temp->next->id);
                swap(temp->name, temp->next->name);
                swap(temp->duration, temp->next->duration);

                swapped = true;
            }

            temp = temp->next;
        }
    }

    cout << "\nPlaylist sorted by Duration!\n";
}

     void playLoop()
{
    if (head == nullptr)
    {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    Node *temp = head;
    char choice;

    do
    {
        cout << "\nPlaying: " << temp->name
             << " | ID: " << temp->id
             << " | Duration: " << temp->duration
             << " seconds\n";

        usleep((int)(temp->duration * 1000000));

        temp = temp->next;

        if (temp == nullptr)
        {
            cout << "\n--- Playlist Restarted ---\n";
            temp = head;
        }

        cout << "\nContinue playing? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}
};

int main()
{
    SingleLL list;

    int choice;

    do
    {
        cout << "\n\n========== PLAYLIST MENU ==========";
        cout << "\n1. Insert Song";
        cout << "\n2. Display Playlist";
        cout << "\n3. Delete Song by Position";
        cout << "\n4. Sort by Song ID";
        cout << "\n5. Sort by Song Title";
        cout << "\n6. Sort by Duration";
        cout << "\n7. Play Playlist in Loop";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int pos;

                cout << "\nEnter position to insert: ";
                cin >> pos;

                list.insert_at_any_pos(pos);
                break;
            }

            case 2:
                list.displayll();
                break;

            case 3:
            {
                int pos;

                cout << "\nEnter position to delete: ";
                cin >> pos;

                list.delete_at_pos(pos);
                break;
            }

            case 4:
                list.sortByID();
                list.displayll();
                break;

            case 5:
                list.sortByTitle();
                list.displayll();
                break;

            case 6:
                list.sortByDuration();
                list.displayll();
                break;

            case 7:
                list.playLoop();
                break;

            case 8:
                cout << "\nExiting Playlist...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 8);

    return 0;
}

