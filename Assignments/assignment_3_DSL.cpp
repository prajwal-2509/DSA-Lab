#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

struct Node{
    int id;
    string name;
    float duration;
    Node *next=nullptr;
};

class Singlelinkedllist{
    public:
    Node *head;

    Singlelinkedllist(){
        head=nullptr;
    }

    bool isDuplicate(int pid) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == pid) return true;
            temp = temp->next;
        }
        return false;
    }

    void insert_in_playlist(int pos){
        int pid;
        cout << "\nEnter Song ID: ";
        cin >> pid;

        if (isDuplicate(pid)) {
            cout << "Error: Song with ID " << pid << " already exists in the playlist!\n";
            return;
        }

        Node *newnode = new Node();
        newnode->id = pid;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, newnode->name);
        cout << "Enter Song Duration (seconds): ";
        cin >> newnode->duration;

        if (pos == 1){
            newnode->next = head;
            head = newnode;
            cout << "\nInserted \"" << newnode->name << "\" at position 1.\n";
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++){
            temp = temp->next;
        }

        if(temp == nullptr){
            cout << "\nSong Position " << pos << " is out of bounds!\n";
            delete newnode;
        }else{
            newnode->next = temp->next;
            temp->next = newnode;
            cout << "\nInserted \"" << newnode->name << "\" at position " << pos << ".\n";
        }
    }

    void displaysongs(){
        if (head == nullptr){
            cout << "\nThe list is empty !!\n";
            return ;
        }

        Node *temp = head;
        int pos = 1;
        cout << "\n--- Current Playlist ---\n";
        while (temp != nullptr){
            cout << pos << ". ID: " << temp->id 
             << " | Name: " << temp->name 
             << " | Duration: " << temp->duration << " seconds\n";
            temp = temp->next;
            pos++;
        }
    }

    void deleteanyposition(int pid){
        if (head == nullptr){
            cout << " No songs are there to Delete  !!";
            return;
        }
        Node *temp =head;
        Node *prev = nullptr;

        if ( temp != nullptr && temp->id==pid){
            head=temp->next ;
            cout << " The song with ID " << temp ->id << " Deleted  !!";
            delete temp;
            return;
        }
        while (temp != nullptr && temp->id != pid) {
            prev = temp;
            temp = temp->next;
        }

        if ( temp == nullptr ){
            cout << " No song found with given ID !";
            return;
        }
            prev->next = temp->next ;
            cout << "\nDeleted song \"" << temp->name << "\" with ID " << pid << ".\n";
             delete temp;
    }

    void sortByID() {
    if (head == nullptr) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->id > temp->next->id) {
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

        void sortByTitle() {
    if (head == nullptr) return;

    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->name > temp->next->name) {
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

    void sortByDuration() {
        if (head == nullptr) return;

        bool swapped = true;
        while (swapped) {
            swapped = false;
            Node* temp = head;

            while (temp != nullptr && temp->next != nullptr) {
                if (temp->duration > temp->next->duration) {
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
    
    void playLoop() {

    if (head == nullptr) {
        cout << "\nPlaylist is empty!\n";
        return;
    }

    Node* temp = head;

    while (true) {

        cout << "\nPlaying: " << temp->name
             << " | ID: " << temp->id
             << " | Duration: " << temp->duration
             << " seconds\n";

        // Wait for the given duration
        Sleep((int)(temp->duration * 1000));

        temp = temp->next;

        if (temp == nullptr) {
            cout << "\n--- Playlist Restarted ---\n";
            temp = head;
        }
    }
}
};

int main(){
    Singlelinkedllist s;
    int choice, pos, id;

    while(true){
        cout << "\n1. Insert Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Delete Song\n";
        cout << "4. Sort by ID\n";
        cout << "5. Sort by Title\n";
        cout << "6. Sort by Duration\n";
        cout << "7. Play Playlist in Loop\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter target position to insert: ";
            cin >> pos;
            s.insert_in_playlist(pos);
        }
        else if(choice == 2){
            s.displaysongs();
        }
        else if(choice == 3){
            cout << "Enter Song ID to delete: ";
            cin >> id;
            s.deleteanyposition(id);
        }
        else if(choice == 4){
            s.sortByID();
        }
        else if(choice == 5){
            s.sortByTitle();
        }
        else if(choice == 6){
            s.sortByDuration();
        }
        else if(choice == 7){
            s.playLoop();
        }
        else if(choice == 8){
            break;
        }
        else{
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}