#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_TICKETS = 100;
const int MAX_SEATS = 50;

class Train
{
public:
    int trainNo;
    string trainName;
    string source;
    string destination;

    void display()
    {
        cout << "\n+------------------------------------------------+";
        cout << "\n| Train No    : " << trainNo;
        cout << "\n| Train Name  : " << trainName;
        cout << "\n| From        : " << source;
        cout << "\n| To          : " << destination;
        cout << "\n+------------------------------------------------+";
    }
};

class Ticket
{
public:
    int pnr;
    string passengerName;
    int age;

    int trainNo;
    string trainName;

    string source;
    string destination;

    string journeyDate;
    string travelClass;

    int seatNo;
    double fare;

    string status;

    void displayTicket()
    {
        cout << "\n\n+==============================================+";
        cout << "\n|              RAILWAY E-TICKET                |";
        cout << "\n+==============================================+";

        cout << "\n| PNR           : " << pnr;
        cout << "\n| Passenger     : " << passengerName;
        cout << "\n| Age           : " << age;

        cout << "\n|----------------------------------------------|";

        cout << "\n| Train No      : " << trainNo;
        cout << "\n| Train Name    : " << trainName;
        cout << "\n| From          : " << source;
        cout << "\n| To            : " << destination;
        cout << "\n| Journey Date  : " << journeyDate;

        cout << "\n|----------------------------------------------|";

        cout << "\n| Class         : " << travelClass;
        cout << "\n| Seat No       : " << seatNo;
        cout << "\n| Fare          : Rs. " << fare;
        cout << "\n| Status        : " << status;

        cout << "\n+==============================================+\n";
    }
};

Train trains[5] =
{
    {12001, "Rajdhani Express", "Dibrugarh", "New Delhi"},
    {12505, "North East Express", "Guwahati", "Anand Vihar"},
    {15909, "Avadh Assam Express", "Dibrugarh", "Lalgarh"},
    {15685, "Brahmaputra Mail", "Kamakhya",  "Delhi"},
    {15617, "Dibrugarh Express", "Dibrugarh","Tinsukia"}
};

Ticket tickets[MAX_TICKETS];

int ticketCount = 0;

/* -----------------------------------------
   FIND TRAIN
----------------------------------------- */

int findTrain(int trainNo)
{
    for(int i = 0; i < 5; i++)
    {
        if(trains[i].trainNo == trainNo)
            return i;
    }

    return -1;
}

/* -----------------------------------------
   CHECK SEAT
----------------------------------------- */

bool isSeatBooked(int seat)
{
    for(int i = 0; i < ticketCount; i++)
    {
        if(tickets[i].seatNo == seat &&
           tickets[i].status == "Confirmed")
        {
            return true;
        }
    }

    return false;
}

/* -----------------------------------------
   AUTOMATIC SEAT ALLOCATION
----------------------------------------- */

int getAvailableSeat()
{
    for(int seat = 1; seat <= MAX_SEATS; seat++)
    {
        if(!isSeatBooked(seat))
            return seat;
    }

    return -1;
}

/* -----------------------------------------
   SHOW SEAT MAP
----------------------------------------- */

void showSeatMap()
{
    cout << "\n\n+--------------------------------------+";
    cout << "\n|             SEAT MAP                 |";
    cout << "\n+--------------------------------------+";

    for(int seat = 1; seat <= MAX_SEATS; seat++)
    {
        if(isSeatBooked(seat))
            cout << "[XX] ";
        else
            cout << "[" << seat << "] ";

        if(seat % 5 == 0)
            cout << endl;
    }

    cout << "\nXX = Booked Seat";
    cout << "\n----------------------------------------";
}

/* -----------------------------------------
   SHOW TRAINS
----------------------------------------- */

void showTrains()
{
    cout << "\n\n==========================================";
    cout << "\n           AVAILABLE TRAINS";
    cout << "\n==========================================";

    for(int i = 0; i < 5; i++)
    {
        trains[i].display();
    }
}

/* -----------------------------------------
   CALCULATE FARE
----------------------------------------- */

double calculateFare(string travelClass)
{
    if(travelClass == "General")
        return 150;

    if(travelClass == "Sleeper")
        return 300;

    if(travelClass == "AC")
        return 600;

    return 0;
}

/* -----------------------------------------
   BOOK TICKET
----------------------------------------- */

void bookTicket()
{
	int numberOfTicket;
    if(ticketCount >= MAX_TICKETS)
    {
        cout << "\nNo more booking space available!";
        return;
    }

    showTrains();

    int trainNo;

    cout << "\n\nEnter Train Number: ";
    cin >> trainNo;

    int index = findTrain(trainNo);

    if(index == -1)
    {
        cout << "\nInvalid Train Number!";
        return;
    }

    int seat = getAvailableSeat();

    if(seat == -1)
    {
        cout << "\nSorry! All seats are booked.";
        return;
    }

    Ticket &t = tickets[ticketCount];

    t.trainNo = trains[index].trainNo;
    t.trainName = trains[index].trainName;
    t.source = trains[index].source;
    t.destination = trains[index].destination;
    
    
    cout<<"\nHow many ticket you want? ";
    cin>>numberOfTicket;
    
    if(numberOfTicket<=0 || numberOfTicket>=10)
    {
    	cout<<"\nYou can book 1 to 10 ticket at a time.";
    	return;
	}
	if(ticketCount+numberOfTicket>MAX_TICKETS)
	{
		cout<<"\nNot enough booking space!";
		return;
	}

    cout << "\nEnter Passenger Name: ";
    cin.ignore();
    getline(cin,t.passengerName);

    cout << "Enter Age: ";
    cin >> t.age;

    cout << "Enter Journey Date (DD-MM-YYYY): ";
    cin >> t.journeyDate;

    int classChoice;

    cout << "\nSelect Travel Class";
    cout << "\n1. General - Rs.150";
    cout << "\n2. Sleeper - Rs.300";
    cout << "\n3. AC      - Rs.600";

    cout << "\nEnter Choice: ";
    cin >> classChoice;

    if(classChoice == 1)
        t.travelClass = "General";

    else if(classChoice == 2)
        t.travelClass = "Sleeper";

    else if(classChoice == 3)
        t.travelClass = "AC";

    else
    {
        cout << "\nInvalid Class!";
        return;
    }

    t.fare = calculateFare(t.travelClass);

    t.seatNo = seat;

    t.pnr = 100000 + rand() % 900000;

    t.status = "Confirmed";

    ticketCount++;

    cout << "\n\n**** TICKET BOOKED SUCCESSFULLY ****";

    t.displayTicket();

    ofstream file("tickets.txt", ios::app);

    file << t.pnr << " "
         << t.passengerName << " "
         << t.age << " "
         << t.trainNo << " "
         << t.trainName << " "
         << t.source << " "
         << t.destination << " "
         << t.journeyDate << " "
         << t.travelClass << " "
         << t.seatNo << " "
         << t.fare << " "
         << t.status << endl;

    file.close();
}

/* -----------------------------------------
   SEARCH TICKET
----------------------------------------- */

void searchTicket()
{
    int pnr;

    cout << "\nEnter PNR Number: ";
    cin >> pnr;

    bool found = false;

    for(int i = 0; i < ticketCount; i++)
    {
        if(tickets[i].pnr == pnr)
        {
            tickets[i].displayTicket();

            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nTicket not found!";
}

/* -----------------------------------------
   CANCEL TICKET
----------------------------------------- */

void cancelTicket()
{
    int pnr;

    cout << "\nEnter PNR Number: ";
    cin >> pnr;

    bool found = false;

    for(int i = 0; i < ticketCount; i++)
    {
        if(tickets[i].pnr == pnr &&
           tickets[i].status == "Confirmed")
        {
            tickets[i].status = "Cancelled";

            cout << "\n+--------------------------------------+";
            cout << "\n|       TICKET CANCELLED SUCCESSFULLY  |";
            cout << "\n+--------------------------------------+";

            cout << "\nPNR      : " << tickets[i].pnr;
            cout << "\nSeat No  : " << tickets[i].seatNo;

            cout << "\n\nSeat " << tickets[i].seatNo
                 << " is now available for reuse.";

            found = true;
            break;
        }
    }

    if(!found)
        cout << "\nActive ticket not found!";
}

/* -----------------------------------------
   ADMIN LOGIN
----------------------------------------- */

void adminLogin()
{
    string username;
    string password;

    cout << "\n\n+================================+";
    cout << "\n|          ADMIN LOGIN           |";
    cout << "\n+================================+";

    cout << "\nUsername: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if(username != "admin" || password != "1234")
    {
        cout << "\nInvalid username or password!";
        return;
    }

    int confirmed = 0;
    int cancelled = 0;

    double revenue = 0;

    for(int i = 0; i < ticketCount; i++)
    {
        if(tickets[i].status == "Confirmed")
        {
            confirmed++;
            revenue += tickets[i].fare;
        }

        if(tickets[i].status == "Cancelled")
            cancelled++;
    }

    cout << "\n\n+======================================+";
    cout << "\n|           ADMIN DASHBOARD            |";
    cout << "\n+======================================+";

    cout << "\n| Total Bookings     : " << ticketCount;
    cout << "\n| Confirmed Tickets  : " << confirmed;
    cout << "\n| Cancelled Tickets  : " << cancelled;
    cout << "\n| Available Seats    : "
         << MAX_SEATS - confirmed;
    cout << "\n| Total Revenue      : Rs. " << revenue;

    cout << "\n+======================================+";
}

/* -----------------------------------------
   MAIN
----------------------------------------- */

int main()
{
    srand(time(0));

    int choice;

    do
    {
        cout << "\n\n";
        cout << "+==========================================+";
        cout << "\n|       RAILWAY RESERVATION SYSTEM         |";
        cout << "\n+==========================================+";
        cout << "\n| 1. Show Available Trains                 |";
        cout << "\n| 2. Show Seat Map                         |";
        cout << "\n| 3. Book Ticket                           |";
        cout << "\n| 4. Search Ticket by PNR                  |";
        cout << "\n| 5. Cancel Ticket                         |";
        cout << "\n| 6. Admin Dashboard                       |";
        cout << "\n| 7. Exit                                  |";
        cout << "\n+==========================================+";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                showTrains();
                break;

            case 2:
                showSeatMap();
                break;

            case 3:
                bookTicket();
                break;

            case 4:
                searchTicket();
                break;

            case 5:
                cancelTicket();
                break;

            case 6:
                adminLogin();
                break;

            case 7:
                cout << "\nThank you for using Railway Reservation System!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 7);

    return 0;
}
