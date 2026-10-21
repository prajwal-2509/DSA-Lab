
#include <iostream>
using namespace std;

class Deque {
    int a[100];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == 100;
    }

    void insertFront(int order) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + 100) % 100;

        a[front] = order;
        count++;
        cout << "Order inserted at front\n";
    }

    void insertRear(int order) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % 100;

        a[rear] = order;
        count++;
        cout << "Order inserted at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Order processed: " << a[front] << endl;
        front = (front + 1) % 100;
        count--;

        if (isEmpty()) {
            front = 0;
            rear = -1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Order processed: " << a[rear] << endl;
        rear = (rear - 1 + 100) % 100;
        count--;

        if (isEmpty()) {
            front = 0;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Orders: ";
        for (int i = 0; i < count; i++)
            cout << a[(front + i) % 100] << " ";
        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, order;

    do {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Display Orders";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order number: ";
                cin >> order;
                d.insertFront(order);
                break;

            case 2:
                cout << "Enter order number: ";
                cin >> order;
                d.insertRear(order);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
