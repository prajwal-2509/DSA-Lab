
/*
The ticket booking system of the theater has to be implemented using C++ program. There are
M rows and N seats in each row. Keep track of free seats at rows. Assume some random booking
to start with. Use an array to store pointers (Head pointer) to each row. On demand:
1. The list of available seats is to be displayed.
2. The seats are to be booked.
3. The booking can be cancelled.

Note: Use Doubly Linked List to store data.
*/

#include <iostream>
using namespace std;

struct Seat
{
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

class Theater
{
    int M, N;
    Seat** head;

public:
    Theater(int rows, int seats)
    {
        M = rows;
        N = seats;

        head = new Seat*[M];

        for (int i = 0; i < M; i++)
        {
            head[i] = nullptr;
            Seat* last = nullptr;

            for (int j = 1; j <= N; j++)
            {
                Seat* newSeat = new Seat;
                newSeat->seatNo = j;
                newSeat->booked = false;
                newSeat->next = nullptr;
                newSeat->prev = last;

                if (head[i] == nullptr)
                    head[i] = newSeat;
                else
                    last->next = newSeat;

                last = newSeat;
            }
        }

        head[0]->booked = true;
        if (N >= 3)
            head[0]->next->next->booked = true;
        if (M >= 2)
            head[1]->next->booked = true;
    }

    void displayAvailableSeats()
    {
        cout << "\nAvailable Seats:\n";

        for (int i = 0; i < M; i++)
        {
            cout << "Row " << i + 1 << ": ";

            Seat* temp = head[i];
            bool found = false;

            while (temp != nullptr)
            {
                if (!temp->booked)
                {
                    cout << temp->seatNo << " ";
                    found = true;
                }
                temp = temp->next;
            }

            if (!found)
                cout << "No seats available";

            cout << "\n";
        }
    }

    void bookSeat(int row, int seatNo)
    {
        if (row < 1 || row > M ||
            seatNo < 1 || seatNo > N)
        {
            cout << "Invalid row or seat number.\n";
            return;
        }

        Seat* temp = head[row - 1];

        while (temp != nullptr && temp->seatNo != seatNo)
            temp = temp->next;

        if (temp->booked)
            cout << "Seat is already booked.\n";
        else
        {
            temp->booked = true;
            cout << "Seat booked successfully.\n";
        }
    }

    void cancelBooking(int row, int seatNo)
    {
        if (row < 1 || row > M ||
            seatNo < 1 || seatNo > N)
        {
            cout << "Invalid row or seat number.\n";
            return;
        }

        Seat* temp = head[row - 1];

        while (temp != nullptr && temp->seatNo != seatNo)
            temp = temp->next;

        if (!temp->booked)
            cout << "Seat is not booked.\n";
        else
        {
            temp->booked = false;
            cout << "Booking cancelled successfully.\n";
        }
    }

    void displayAllSeats()
    {
        cout << "\nSeat Status (B = Booked, F = Free):\n";

        for (int i = 0; i < M; i++)
        {
            cout << "Row " << i + 1 << ": ";

            Seat* temp = head[i];

            while (temp != nullptr)
            {
                cout << temp->seatNo << "-"
                     << (temp->booked ? "B " : "F ");
                temp = temp->next;
            }

            cout << "\n";
        }
    }

    ~Theater()
    {
        for (int i = 0; i < M; i++)
        {
            Seat* temp = head[i];

            while (temp != nullptr)
            {
                Seat* del = temp;
                temp = temp->next;
                delete del;
            }
        }

        delete[] head;
    }
};

int main()
{
    int M, N, choice, row, seatNo;

    cout << "Enter number of rows: ";
    cin >> M;

    cout << "Enter seats per row: ";
    cin >> N;

    if (M <= 0 || N <= 0)
    {
        cout << "Invalid theater dimensions.\n";
        return 0;
    }

    Theater t(M, N);

    do
    {
        cout << "\n--- Theater Ticket Booking System ---\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Display all seat statuses\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.displayAvailableSeats();
            break;

        case 2:
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter seat number: ";
            cin >> seatNo;
            t.bookSeat(row, seatNo);
            break;

        case 3:
            cout << "Enter row number: ";
            cin >> row;
            cout << "Enter seat number: ";
            cin >> seatNo;
            t.cancelBooking(row, seatNo);
            break;

        case 4:
            t.displayAllSeats();
            break;

        case 0:
            cout << "Exiting system.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
