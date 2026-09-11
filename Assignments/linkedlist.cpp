#include<iostream>

using namespace std;

struct Node{

    public:
    int data;
    Node *Next;
    Node(int val)
    {
        data = val;
        Next = NULL;
    }   

};

void insertatend(Node *&head,int data ){

    if (head==NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }

    Node *temp=head;
    while (temp->Next!=NULL){
        
        temp=temp->Next;
    }

    temp->Next = new Node (data );

}

void traverse(Node *head){

    if (head==NULL)
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    while (head!=NULL)
    {
        cout<<head->data<<"-> ";
        head=head->Next;
    }
    cout<<"NULL";
    cout<<endl;
    
}

void insertatstart(Node *&head,int data){

    if (head==NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }

    Node *newNode = new Node (data);
    newNode -> Next =head;
    head = newNode;

}

void addafter(Node *&head, int data, int key)
{
    if(head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = head;

    // Search for key
    while(temp != NULL && temp->data != key)
    {
        temp = temp->Next;
    }

    // Key found
    if(temp != NULL)
    {
        Node *newNode = new Node(data);
        newNode->Next = temp->Next;
        temp->Next = newNode;
        return;
    }

    // Key not found → add at end
    insertatend(head, data);
}
void addbefore(Node *&head, int data, int key)
{
    if(head == NULL)
    {
        return;
    }

    if(head->data == key)
    {
        insertatstart(head, data);
        return;
    }

    Node *temp = head;

    while(temp->Next != NULL && temp->Next->data != key)
    {
        temp = temp->Next;
    }

    if(temp->Next != NULL)
    {
        Node *newNode = new Node(data);
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

int main(){

    Node* head = new Node(5);
    insertatend(head, 10);
    insertatend(head, 15);
    traverse(head);

    insertatstart(head, 1);
    traverse(head);

    addafter(head, 12, 10);
    traverse(head);

    addbefore(head, 8, 10);
    traverse(head);
    return 0;
}