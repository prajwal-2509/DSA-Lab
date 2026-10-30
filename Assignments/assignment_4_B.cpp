
#include <iostream>
using namespace std;

class Seat {
    public:
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

class Theater {
    int M, N;
    Seat** head;

public:
    Theater(int rows, int seats) {
        M = rows;
        N = seats;

        head = new Seat*[M];

        for (int i = 0; i < M; i++) {
            head[i] = nullptr;
            Seat* last = nullptr;

            for (int j = 1; j <= N; j++) {
                Seat* temp = new Seat;

                temp->seatNo = j;
                temp->booked = false;
                temp->next = nullptr;
                temp->prev = last;

                if (head[i] == nullptr)
                    head[i] = temp;
                else
                    last->next = temp;

                last = temp;
            }
        }
    }

    void displayAvailableSeats() {
    cout << "\nSeat Status (true = booked, false = free):\n";

    for (int i = 0; i < M; i++) {
        cout << "Row " << i + 1 << ": ";

        Seat* temp = head[i];

        while (temp != nullptr) {
            cout << temp->seatNo << "-"
                 << (temp->booked ? "true" : "false") << " ";

            temp = temp->next;
        }

        cout << endl;
    }
}

    void bookSeat(int row, int seatNo) {
        if (row < 1 || row > M ||
            seatNo < 1 || seatNo > N) {
            cout << "Invalid row or seat number!\n";
            return;
        }

        Seat* temp = head[row - 1];

        while (temp != nullptr && temp->seatNo != seatNo)
            temp = temp->next;

        if (temp->booked)
            cout << "Seat already booked!\n";
        else {
            temp->booked = true;
            cout << "Seat booked successfully!\n";
        }
    }

    void cancelBooking(int row, int seatNo) {
        if (row < 1 || row > M ||
            seatNo < 1 || seatNo > N) {
            cout << "Invalid row or seat number!\n";
            return;
        }

        Seat* temp = head[row - 1];

        while (temp != nullptr && temp->seatNo != seatNo)
            temp = temp->next;

        if (!temp->booked)
            cout << "Seat is not booked!\n";
        else {
            temp->booked = false;
            cout << "Booking cancelled successfully!\n";
        }
    }
};

int main() {
    int M, N, choice, row, seatNo;

    cout << "Enter number of rows: ";
    cin >> M;

    cout << "Enter seats per row: ";
    cin >> N;

    if (M <= 0 || N <= 0) {
        cout << "Invalid dimensions!\n";
        return 0;
    }

    Theater t(M, N);

    do {
        cout << "\n1. Display available seats";
        cout << "\n2. Book a seat";
        cout << "\n3. Cancel a booking";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
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

            case 0:
                cout << "Exiting system.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
