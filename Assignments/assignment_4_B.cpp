#include <iostream>
using namespace std;

struct Node
{
    int seat;
    Node *prev;
    Node *next;
};

class Theater
{
    Node **head;
    int M, N;

public:

    Theater(int rows, int seats)
    {
        M = rows;
        N = seats;

        head = new Node*[M];

        for (int i = 0; i < M; i++)
            head[i] = NULL;

        for (int i = 0; i < M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                Node *newNode = new Node;
                newNode->seat = j;
                newNode->prev = NULL;
                newNode->next = NULL;

                if (head[i] == NULL)
                {
                    head[i] = newNode;
                }
                else
                {
                    Node *temp = head[i];

                    while (temp->next != NULL)
                        temp = temp->next;

                    temp->next = newNode;
                    newNode->prev = temp;
                }
            }
        }
    }

    void displayAvailableSeats()
    {
        cout << "\nAvailable Seats:\n";

        for (int i = 0; i < M; i++)
        {
            cout << "Row " << i + 1 << ": ";

            Node *temp = head[i];

            if (temp == NULL)
            {
                cout << "No seats available";
            }
            else
            {
                while (temp != NULL)
                {
                    cout << temp->seat << " ";
                    temp = temp->next;
                }
            }

            cout << endl;
        }
    }

    void bookSeat()
    {
        int row, seat;

        cout << "Enter Row: ";
        cin >> row;

        cout << "Enter Seat: ";
        cin >> seat;

        if (row < 1 || row > M || seat < 1 || seat > N)
        {
            cout << "Invalid row or seat.\n";
            return;
        }

        Node *temp = head[row - 1];

        while (temp != NULL && temp->seat != seat)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Seat is already booked.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head[row - 1] = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;

        cout << "Seat booked successfully.\n";
    }

    void cancelBooking()
    {
        int row, seat;

        cout << "Enter Row: ";
        cin >> row;

        cout << "Enter Seat: ";
        cin >> seat;

        if (row < 1 || row > M || seat < 1 || seat > N)
        {
            cout << "Invalid row or seat.\n";
            return;
        }

        Node *newNode = new Node;
        newNode->seat = seat;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head[row - 1] == NULL)
        {
            head[row - 1] = newNode;
        }
        else
        {
            Node *temp = head[row - 1];

            if (seat < temp->seat)
            {
                newNode->next = temp;
                temp->prev = newNode;
                head[row - 1] = newNode;
            }
            else
            {
                while (temp->next != NULL && temp->next->seat < seat)
                    temp = temp->next;

                if (temp->seat == seat ||
                    (temp->next != NULL && temp->next->seat == seat))
                {
                    cout << "Seat is already available.\n";
                    delete newNode;
                    return;
                }

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL)
                    temp->next->prev = newNode;

                temp->next = newNode;
            }
        }

        cout << "Booking cancelled successfully.\n";
    }
};

int main()
{
    int M, N, choice;

    cout << "Enter number of rows: ";
    cin >> M;

    cout << "Enter seats in each row: ";
    cin >> N;

    Theater t(M, N);

    t.bookSeat();
    t.bookSeat();

    do
    {
        cout << "\n--- Theater Ticket Booking ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.displayAvailableSeats();
            break;

        case 2:
            t.bookSeat();
            break;

        case 3:
            t.cancelBooking();
            break;

        case 4:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}