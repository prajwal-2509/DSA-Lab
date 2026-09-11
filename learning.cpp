#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void addAtEnd(Node *&head, int data)
{
    Node* temp = head;

    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    

    temp->next = new Node(data);
    
}

void traverse(Node *head)
{
    if(head==NULL)
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    while(head!=NULL)
    {
        cout<<head->data<<"-> ";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

void insertAfter(Node *&head, int data, int key)
{
    Node *temp = head;

    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->next==NULL && head->data == key)
    {
        Node *newNode = new Node(data);
        head->next = newNode;
        return;
    }

    while(temp->next!= NULL && temp->data!=key)
    {
        temp = temp->next;
    }

    if(temp->next==NULL)
    {
        addAtEnd(head, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

}

void insertAtFirst(Node *&head, int data)
{
    if(head==NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;

}

void insertBefore(Node *&head, int data, int key)
{
    if(head==NULL)
    {
        insertAtFirst(head, data);
        return;
    }

    if((head->next==NULL) && (head->data==key || head->data!=key))
    {
        insertAtFirst(head, data);
        return;
    }

    Node *temp1 = head;
    Node *temp2 = head->next;;
    

    while()
}

int main()
{
    Node* head = new Node(5);

    addAtEnd(head, 10);
    addAtEnd(head, 15);
    addAtEnd(head, 20);

    traverse(head);
    
    insertAtFirst(head, 1);
    traverse(head);

    insertAfter(head, 100, 5);
    traverse(head);
    return 0;
}