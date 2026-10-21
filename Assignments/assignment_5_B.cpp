/*C++ Program
A Deque (Double-Ended Queue) is the appropriate data structure because orders can be added and deleted from both the front and rear ends.
*/


#include <iostream>
using namespace std;

class Deque
{
    int a[100];
    int front, rear;

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == 99) ||
               (front == rear + 1);
    }

    void insertFront(int order)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = 99;
        else
            front--;

        a[front] = order;
        cout << "Order added at front.\n";
    }

    void insertRear(int order)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else if (rear == 99)
            rear = 0;
        else
            rear++;

        a[rear] = order;
        cout << "Order added at rear.\n";
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Processed order: " << a[front] << endl;

        if (front == rear)
            front = rear = -1;
        else if (front == 99)
            front = 0;
        else
            front++;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Removed order: " << a[rear] << endl;

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = 99;
        else
            rear--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No orders in queue.\n";
            return;
        }

        cout << "Orders: ";
        int i = front;

        while (true)
        {
            cout << a[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % 100;
        }

        cout << endl;
    }
};

int main()
{
    Deque q;
    int choice, order;

    do
    {
        cout << "\n--- Pizza Parlour ---\n";
        cout << "1. Add Order at Front\n";
        cout << "2. Add Order at Rear\n";
        cout << "3. Process Order from Front\n";
        cout << "4. Remove Order from Rear\n";
        cout << "5. Display Orders\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter order ID: ";
            cin >> order;
            q.insertFront(order);
            break;

        case 2:
            cout << "Enter order ID: ";
            cin >> order;
            q.insertRear(order);
            break;

        case 3:
            q.deleteFront();
            break;

        case 4:
            q.deleteRear();
            break;

        case 5:
            q.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}

