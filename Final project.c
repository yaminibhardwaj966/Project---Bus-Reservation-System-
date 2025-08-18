#include <stdio.h>
#include <string.h>

// global variables for registration
char name[20], username[20];
char password[20], password2[20], Password[20];

// global variables for ticket booking
int busNumber, bookedSeats1, bookedSeats2, bookedSeats3, bookedSeats4;
int totalseats1 = 60, totalseats2 = 50, totalseats3 = 70, totalseats4 = 80;
int totalfare1 = 300, totalfare2 = 500, totalfare3 = 900, totalfare4 = 1000;
int BusNumber, cancelledseats1, cancelledseats2, cancelledseats3, cancelledseats4;

// Functions declaration
int user_menu();
void registration();
void signIn();
void busmenu();
void available_buses();
void ticket_booking();
void busnum101();
void busnum102();
void busnum103();
void busnum104();
void showbus101();
void showbus102();
void showbus103();
void showbus104();
void cancel_ticket();
void cancelbus101();
void cancelbus102();
void cancelbus103();
void cancelbus104();
void bus_details();

int main()
{
    printf("\n\t---------WELCOME TO BUS RESERVATION SYSYTEM------------\n");
    user_menu();
    return 0;
}

int user_menu()
{
    while (1)
    {
        int choice;
        printf("\nPress 1 for Registration");
        printf("\nPress 2 for sign in");
        printf("\nPress 3 for exit");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            registration();
            continue;
        }
        else if (choice == 2)
        {
            signIn();
            continue;
        }
        else
        {
            printf("\nExiting program..........  GOODBYE!\n");
            break;
        }
    }
    return 0;
}
void registration()
{
    while (1)
    {

        printf("\n\t====REGISTRATION====\n");
        printf("\nPlease enter your username: ");
        scanf(" %[^\n]", &name);
        printf("\nCreate your password: ");
        scanf(" %[^\n]", &password);
        printf("\nPlease re-enter your password: ");
        scanf(" %[^\n]", &password2);
        if (strcmp(password, password2) == 0)
        {
            printf("\n\tRegistration successfull! You can now sign in.\n");

            break;
        }
        else
        {
            printf("\ninvalid input! Please try again.\n");
            break;
        }
    }
}
void signIn()
{
    while (1)
    {
        printf("\n\t====SIGN IN====\n");
        printf("\nPlease enter your username: ");
        scanf(" %[^\n]", &username);
        if (strcmp(username, name) == 0)
        {
            printf("\nPlease enter your Password: ");
            scanf(" %[^\n]", &Password);
            if (strcmp(Password, password) == 0)

            {
                printf("\nLogin Successfully! Welcome %s!\n", username);
                busmenu();
                break;
            }
            else
            {
                printf("\nincorrect password! Please try again.\n");
                break;
            }
        }
        else
        {
            printf("\nInvalid username! Please enter the correct username.\n");
            break;
        }
    }
}
void busmenu()
{
    int option;

    printf("\n\t------Welcome to the Bus Reservation System---------\n");

    do
    {
        printf("\n==== MENU ====\n");
        printf("\n1. Available Buses");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Check your Ticket Details");
        printf("\n5. Check bus details");
        printf("\n6. Logout");
        printf("\nPlease enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            available_buses();
            break;
        case 2:
            ticket_booking();
            break;
        case 3:
            cancel_ticket();
            break;
        case 4:
        {
            if (busNumber == 101)
                showbus101();
            else if (busNumber == 102)
                showbus102();
            else if (busNumber == 103)
                showbus103();
            else if (busNumber == 104)
                showbus104();
            break;
        }

        case 5:
        {
            bus_details();
        }
        case 6:
            printf("\nLogged out successfully. Thank you for using bus reservation system.\n");
            break;
        default:
            printf("Invalid choice. Please Try again.\n");
        }
    } while (option != 6);
}
void available_buses()
{
    printf("\n-----------AVAILABLE BUSES-----------\n");

    printf("\n\n======DESTINATION:- Aligarh to Mathura======\n");
    printf("Bus Number: 101\n");
    printf("Total seats: 60\n");
    printf("Available Seats: %d\n", totalseats1);
    printf("Fare Per Seat: 300\n");

    printf("\n======DESTINATION:- Delhi to Agra======\n");
    printf("Bus Number: 102\n");
    printf("Total Seats: 50\n");
    printf("Available Seats: %d\n", totalseats2);
    printf("Fare Per Seat: 500\n");

    printf("\n======DESTINATION:- Gurgaon to Lucknow======\n");
    printf("Bus Number: 103\n");
    printf("Total Seats: 70\n");
    printf("Available Seats: %d\n", totalseats3);
    printf("Fare Per Seat: 900\n");

    printf("\n======DESTINATION:- Bangalore to Hyderabad======\n");
    printf("Bus Number: 104\n");
    printf("Total Seats: 80\n");
    printf("Available Seats: %d\n", totalseats4);
    printf("Fare Per Seat: 1000\n");
}
void ticket_booking()
{
    while (1)
    {
        printf("\nEnter your Bus Number: ");
        scanf(" %d", &busNumber);
        if (busNumber == 101)
        {
            busnum101();
            break;
        }
        else if (busNumber == 102)
        {
            busnum102();
            break;
        }
        else if (busNumber == 103)
        {
            busnum103();
            break;
        }
        else if (busNumber == 104)
        {
            busnum104();
            break;
        }
        else
        {
            printf("Incorrect busnumber! Please enter the correct bus number.\n");
            break;
        }
    }
}

void busnum101()
{
    while (1)
    {
        printf("Please enter the no. of seats you want to book: ");
        scanf(" %d", &bookedSeats1);

        if (bookedSeats1 <= totalseats1)
        {
            totalseats1 -= bookedSeats1;
            printf("\nBooking Successfully Completed! %d seats booked on Bus Number %d.\n", bookedSeats1, busNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct integer!\n");
            break;
        }
    }
}
void busnum102()
{

    while (1)
    {
        printf("\nPlease enter the no. of seats you want to book: ");
        scanf(" %d", &bookedSeats2);

        if (bookedSeats2 <= totalseats2)
        {
            totalseats2 -= bookedSeats2;
            printf("\nBooking Successfully Completed! %d seats booked on Bus Number %d.\n", bookedSeats2, busNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct integer!\n");
            break;
        }
    }
}
void busnum103()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to book: ");
        scanf(" %d", &bookedSeats3);

        if (bookedSeats3 <= totalseats3)
        {
            totalseats3 -= bookedSeats3;
            printf("\nBooking Successfully Completed! %d seats booked on Bus Number %d.\n", bookedSeats3, busNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct integer!\n");
            break;
        }
    }
}
void busnum104()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to book: ");
        scanf(" %d", &bookedSeats4);

        if (bookedSeats4 <= totalseats4)
        {
            totalseats4 -= bookedSeats4;
            printf("\nBooking Successfully Completed! %d seats booked on Bus Number %d.\n", bookedSeats4, busNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct integer!");
            break;
        }
    }
}
void showbus101()
{
    printf("\n\t------------Here is your Reserved bus details---------\n");
    printf("\nYour Booked Bus Number: %d", busNumber);
    printf("\nDestination: Aligarh to Mathura");
    printf("\nYour Booked seats: %d", bookedSeats1);
    printf("\nAvailable Seats: %d", totalseats1);
    printf("\nTotal Fare: %d", totalfare1 * bookedSeats1);
}
void showbus102()
{
    printf("\n\t------------Here is your Reserved bus details---------\n");
    printf("\nYour Booked Bus Number: %d", busNumber);
    printf("\nDestination: Delhi to Agra");
    printf("\nYour Booked seats: %d", bookedSeats2);
    printf("\nAvailable Seats: %d", totalseats2 );
    printf("\nTotal Fare: %d", totalfare2 * bookedSeats2);
}
void showbus103()
{
    printf("\n\t------------Here is your Reserved bus details---------\n");

    printf("\nYour Booked Bus Number: %d", busNumber);
    printf("\nDestination: Gurgaon to Lucknow");
    printf("\nYour Booked seats: %d", bookedSeats3);
    printf("\nAvailable Seats: %d", totalseats3 );
    printf("\nTotal Fare: %d", totalfare3 * bookedSeats3);
}
void showbus104()

{
    printf("\n\t------------Here is your Reserved bus details---------\n");
    printf("\nYour Booked Bus Number: %d", busNumber);
    printf("\nDestination: Bangloreto Hyderabad");
    printf("\nYour Booked seats: %d", bookedSeats4);
    printf("\nAvailable Seats: %d", totalseats4 );
    printf("\nTotal Fare: %d", totalfare4 * bookedSeats4);
}

void cancel_ticket()
{
    while (1)
    {
        printf("\nEnter Bus Number from which you want to cancel ticket: ");
        scanf(" %d", &BusNumber);
        if (BusNumber == 101)
        {
            cancelbus101();
            break;
        }
        else if (BusNumber == 102)
        {
            cancelbus102();
            break;
        }
        else if (BusNumber == 103)
        {
            cancelbus103();
            break;
        }
        else if (BusNumber == 104)
        {
            cancelbus104();
            break;
        }
        else
        {
            printf("\nPlease enter the correct bus number!\n");
            break;
        }
    }
}
void cancelbus101()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to cancel: ");
        scanf(" %d", &cancelledseats1);
        if (cancelledseats1 <= bookedSeats1)
        {
            bookedSeats1 -= cancelledseats1;
            totalseats1 += cancelledseats1;

            printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledseats1, BusNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct no. of seats!\n");
        }
    }
}
void cancelbus102()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to cancel: ");
        scanf(" %d", &cancelledseats2);
        if (cancelledseats2 <= bookedSeats2)
        {
            bookedSeats2 -= cancelledseats2;
            totalseats2 += cancelledseats2;

            printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledseats2, BusNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct no. of seats!\n");
            break;
        }
    }
}
void cancelbus103()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to cancel: ");
        scanf(" %d", &cancelledseats3);
        if (cancelledseats3 <= bookedSeats3)
        {
            bookedSeats3 -= cancelledseats3;
            totalseats3 += cancelledseats3;

            printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledseats3, BusNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct no. of seats!\n");
            break;
        }
    }
}
void cancelbus104()
{
    while (1)
    {
        printf("\nPlease enter the no. of seats you want to cancel: ");
        scanf(" %d", &cancelledseats4);
        if (cancelledseats4 <= bookedSeats4)
        {
            bookedSeats4 -= cancelledseats4;
            totalseats4 += cancelledseats4;

            printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledseats4, BusNumber);
            break;
        }
        else
        {
            printf("\nPlease enter the correct no. of seats!\n");
            break;
        }
    }
}
void bus_details()
{
    printf("\n\t********* BUS DETAILS ************");

    printf("\n\n======DESTINATION:- Aligarh to Mathura======\n");
    printf("\nBus Number: 101\n");
    printf("\nTotal seats: %d\n", totalseats1 );
    printf("\nAvailable Seats: %d\n", totalseats1 );
    printf("\nFare Per Seat: 300\n");

    printf("\n======DESTINATION:- Delhi to Agra======\n");
    printf("\nBus Number: 102\n");
    printf("\nTotal Seats: %d\n", totalseats2 );
    printf("\nAvailable Seats: %d\n", totalseats2 );
    printf("\nFare Per Seat: 500\n");

    printf("\n======DESTINATION:- Gurgaon to Lucknow======\n");
    printf("\nBus Number: 103\n");
    printf("\nTotal Seats: %d\n", totalseats3 );
    printf("\nAvailable Seats: %d\n", totalseats3 );
    printf("\nFare Per Seat: 900\n");

    printf("\n======DESTINATION:- Bangalore to Hyderabad======\n");
    printf("\nBus Number: 104\n");
    printf("\nTotal Seats: %d\n", totalseats4 );
    printf("\nAvailable Seats: %d\n", totalseats4 );
    printf("\nFare Per Seat: 1000\n");
}