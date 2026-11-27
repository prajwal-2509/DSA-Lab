
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Node {
public:
    int id;
    string name;
    float duration;
    Node *next;

    Node(int id, string name, float duration) {
        this->id = id;
        this->name = name;
        this->duration = duration;
        this->next = NULL;
    }
};

class CircularSLL {
    Node *head;

public:

    CircularSLL() {
        head = NULL;
    }

    // Count total nodes
    int length() {
        if (head == NULL)
            return 0;

        int count = 0;
        Node *temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    // Check duplicate Song ID
    bool isduplicate(int id) {
        if (head == NULL)
            return false;

        Node *temp = head;

        do {
            if (temp->id == id)
                return true;

            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Insert at any position
    void insert_at_any_pos(int pos) {

        if (pos <= 0 || pos > length() + 1) {
            cout << "Invalid position!";
            return;
        }

        int pid;

        cout << "Enter the Song ID: ";
        cin >> pid;

        if (isduplicate(pid)) {
            cout << "The Song already exists! "
                 << "No need to enter same ID.";
            return;
        }

        string name;
        float duration;

        cout << "Enter Song Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter Duration: ";
        cin >> duration;

        Node *newnode = new Node(pid, name, duration);

        // First node
        if (head == NULL) {
            head = newnode;
            newnode->next = head;

            cout << "Inserted \"" << name
                 << "\" at position 1.";
            return;
        }

        // Insert at first position
        if (pos == 1) {
            Node *last = head;

            while (last->next != head) {
                last = last->next;
            }

            newnode->next = head;
            last->next = newnode;
            head = newnode;

            cout << "Inserted \"" << name
                 << "\" at position 1.";
            return;
        }

        // Insert at other positions
        Node *temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;

        cout << "\nInserted \"" << name
             << "\" at position " << pos << ".\n";
    }

    // Display playlist
    void displayll() {

        if (head == NULL) {
            cout << "Playlist is empty!";
            return;
        }

        Node *temp = head;
        int pos = 1;

        do {
            cout << "\nPosition " << pos
                 << "\nName : " << temp->name
                 << "\nID : " << temp->id
                 << "\nDuration : " << temp->duration;

            temp = temp->next;
            pos++;

        } while (temp != head);
    }

    // Delete at any position
    void delete_at_pos(int pos) {

        if (head == NULL) {
            cout << "There are no songs to delete!";
            return;
        }

        if (pos <= 0 || pos > length()) {
            cout << "Invalid position!";
            return;
        }

        Node *temp = head;

        // Delete first node
        if (pos == 1) {

            // Only one node
            if (head->next == head) {
                cout << "\nDeleted song \"" << head->name << "\".";
                delete head;
                head = NULL;
                return;
            }

            Node *last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            cout << "\nDeleted song \"" << temp->name
                 << "\" from position 1.\n";

            delete temp;
            return;
        }

        // Delete other positions
        Node *prev = NULL;

        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;

        cout << "\nDeleted song \"" << temp->name
             << "\" from position " << pos << ".\n";

        delete temp;
    }

    // Sort by Song ID
    void sortByID() {

        int n = length();

        if (n == 0) {
            cout << "Playlist is empty!";
            return;
        }

        for (int i = 0; i < n - 1; i++) {

            Node *temp = head;

            for (int j = 0; j < n - i - 1; j++) {

                if (temp->id > temp->next->id) {
                    swap(temp->id, temp->next->id);
                    swap(temp->name, temp->next->name);
                    swap(temp->duration, temp->next->duration);
                }

                temp = temp->next;
            }
        }

        cout << "\nPlaylist sorted by ID!\n";
    }

    // Sort by Song Title
    void sortByTitle() {

        int n = length();

        if (n == 0) {
            cout << "Playlist is empty!";
            return;
        }

        for (int i = 0; i < n - 1; i++) {

            Node *temp = head;

            for (int j = 0; j < n - i - 1; j++) {

                if (temp->name > temp->next->name) {
                    swap(temp->id, temp->next->id);
                    swap(temp->name, temp->next->name);
                    swap(temp->duration, temp->next->duration);
                }

                temp = temp->next;
            }
        }

        cout << "\nPlaylist sorted by Title!\n";
    }

    // Sort by Duration
    void sortByDuration() {

        int n = length();

        if (n == 0) {
            cout << "Playlist is empty!";
            return;
        }

        for (int i = 0; i < n - 1; i++) {

            Node *temp = head;

            for (int j = 0; j < n - i - 1; j++) {

                if (temp->duration > temp->next->duration) {
                    swap(temp->id, temp->next->id);
                    swap(temp->name, temp->next->name);
                    swap(temp->duration, temp->next->duration);
                }

                temp = temp->next;
            }
        }

        cout << "\nPlaylist sorted by Duration!\n";
    }

    // Play playlist in circular loop
    void playLoop() {

        if (head == NULL) {
            cout << "\nPlaylist is empty!\n";
            return;
        }

        Node *temp = head;
        char choice;

        do {

            cout << "\nPlaying: " << temp->name
                 << " | ID: " << temp->id
                 << " | Duration: " << temp->duration
                 << " seconds\n";

            usleep((int)(temp->duration * 1000000));

            // Automatically moves to next node.
            // Last node automatically points to head.
            temp = temp->next;

            cout << "\nContinue playing? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    // Free allocated memory
    ~CircularSLL() {

        if (head == NULL)
            return;

        Node *temp = head->next;

        while (temp != head) {
            Node *nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }

        delete head;
        head = NULL;
    }
};

int main() {

    CircularSLL list;

    int choice;

    do {

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

        switch (choice) {

            case 1: {
                int pos;

                cout << "\nEnter position to insert: ";
                cin >> pos;

                list.insert_at_any_pos(pos);
                break;
            }

            case 2:
                list.displayll();
                break;

            case 3: {
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
