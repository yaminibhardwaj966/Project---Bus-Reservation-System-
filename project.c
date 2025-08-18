#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function declarations
int isvalidUsername(const char *username);
int isValidPassword(const char *password);
int menu(int signedUp);
void SignUp();
void Sign_in(int signedUp);
void user_menu();
void available_buses();
void show_bus_details();
void ticket_booking();
void cancel_ticket();

#define USERNAME_LEN 20
#define PASSWORD_LEN 9 // 8 chars + 1 for null terminator

struct User
{
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
};
struct User registereduser;

// Global variables for bus details
int BusNumber = 0;
int bookedSeats = 0;
int cancelledSeats = 0;

int isvalidUsername(const char *username)
{
    int hasCharacter = 0, hasDigits = 0;
    int len = strlen(username);

    if (len == 0)
    {
        printf("Username cannot be empty!\n");
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (isalpha(username[i]))
            hasCharacter = 1;
        else if (isdigit(username[i]))
            hasDigits = 1;
        else
        {
            printf("Username can only contain alphanumeric characters.\n");
            return 0;
        }
    }

    if (!hasCharacter || !hasDigits)
    {
        printf("Username must contain both characters and digits.\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (isdigit(username[i]))
        {
            for (int j = i + 1; j < len; j++)
            {
                if (username[i] == username[j])
                {
                    printf("Username cannot have repeating digits.\n");
                    return 0;
                }
            }
        }
    }

    return 1;
}

int isValidPassword(const char *password)
{
    int len = strlen(password);
    int hasChar = 0, hasDigit = 0;

    if (len != 8)
    {
        printf("Password must be exactly 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (isalpha(password[i]))
            hasChar = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
    }

    if (!hasChar || !hasDigit)
    {
        printf("Password must contain both letters and digits.\n");
        return 0;
    }

    return 1;
}

int main()
{
    int signedUp = 0;
    printf("\n---------WELCOME TO BUS RESERVATION SYSTEM--------------\n");

    menu(signedUp);
    return 0;
}

void SignUp()
{
    char Username[USERNAME_LEN];
    char Password[PASSWORD_LEN];
    char Password2[PASSWORD_LEN];
    int valid = 0;

    do
    {
        printf("\n=====SIGN UP=====\n");
        printf("\nEnter your username (alphanumeric characters): ");
        scanf(" %[^\n]", Username);
        if (!isvalidUsername(Username))
        {
            continue;
        }

        printf("\nCreate a password (exactly 8 characters): ");
        scanf(" %s", Password);
        if (!isValidPassword(Password))
        {
            continue;
        }

        printf("Re-enter your password: ");
        scanf(" %s", Password2);

        if (strcmp(Password, Password2) == 0)
        {
            strcpy(registereduser.username, Username);
            strcpy(registereduser.password, Password);
            printf("--------Your Account has been created Successfully!---------\n");
            valid = 1;
        }
        else
        {
            printf("Passwords do not match. Please try again.\n");
        }

    } while (!valid);
}

void Sign_in(int signedUp)
{
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    if (strlen(registereduser.username) == 0)
    {
        printf("\nNo user registered yet. Please sign up first.\n");
        return;
    }

    printf("\n=====SIGN IN=====\n");
    printf("Please enter your Username: ");
    scanf(" %s", username);

    if (strcmp(username, registereduser.username) == 0)
    {
        printf("Please enter your Password: ");
        scanf(" %s", password);

        if (strcmp(password, registereduser.password) == 0)
        {
            printf("-----------Sign in Successfully! WELCOME %s------------\n", registereduser.username);
            user_menu();
        }
        else
        {
            printf("Incorrect password!\n");
        }
    }
    else
    {
        printf("Invalid username!\n");
    }
}

int menu(int signedUp)
{
    int choice;

    do
    {
        printf("\nPress 1 for Sign up");
        printf("\nPress 2 for Sign in");
        printf("\nPress 3 for exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            SignUp();
            break;

        case 2:
            Sign_in(signedUp);
            break;

        case 3:
            printf("Exiting program..........  GOODBYE!\n");
            break;

        default:
            printf("Invalid choice! Please enter the correct option!\n");
        }

    } while (choice != 3);

    return 0;
}

void user_menu()
{
    int choice;

    do
    {
        printf("\n------ MENU ------");
        printf("\n1. Available Buses");
        printf("\n2. Book a Ticket");
        printf("\n3. Cancel a Ticket");
        printf("\n4. Check your Ticket Details");
        printf("\n5. Logout");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
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
            show_bus_details();
            break;
        case 5:
            printf("\nLogged out successfully. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please Try again.\n");
        }
    } while (choice != 5);
}

void available_buses()
{
    printf("\n-----------AVAILABLE BUSES-----------");

    printf("\n\n======DESTINATION:- Aligarh to Mathura======\n");
    printf("Bus Number: 101\n");
    printf("Total seats: 60\n");
    printf("Available Seats: %d\n", 60 - bookedSeats + cancelledSeats);
    printf("Fare Per Seat: 300\n");

    printf("\n======DESTINATION:- Delhi to Agra======\n");
    printf("Bus Number: 102\n");
    printf("Total Seats: 50\n");
    printf("Available Seats: %d\n", 50 - bookedSeats + cancelledSeats);
    printf("Fare Per Seat: 500\n");

    printf("\n======DESTINATION:- Gurgaon to Lucknow======\n");
    printf("Bus Number: 103\n");
    printf("Total Seats: 70\n");
    printf("Available Seats: %d\n", 70 - bookedSeats + cancelledSeats);
    printf("Fare Per Seat: 900\n");

    printf("\n======DESTINATION:- Bangalore to Hyderabad======\n");
    printf("Bus Number: 104\n");
    printf("Total Seats: 80\n");
    printf("Available Seats: %d\n", 80 - bookedSeats + cancelledSeats);
    printf("Fare Per Seat: 1000\n");
}

void show_bus_details()
{
    printf("---------Here is your Bus Ticket Details----------\n");


    if (BusNumber == 101)
    {
        printf("Bus Number: 101\nSource: Aligarh\nDestination: Mathura\nTotal Seats: 60\nAvailable Seats: %d\nTotal Fare: %d\n", 60 - bookedSeats + cancelledSeats, bookedSeats * 300);
    }
    else if (BusNumber == 102)
    {
        printf("Bus Number: 102\nSource: Delhi\nDestination: Agra\nTotal Seats: 50\nAvailable Seats: %d\nTotal Fare: %d\n", 50 - bookedSeats + cancelledSeats, bookedSeats * 500);
    }
    else if (BusNumber == 103)
    {
        printf("Bus Number: 103\nSource: Gurgaon\nDestination: Lucknow\nTotal Seats: 70\nAvailable Seats: %d\nTotal Fare: %d\n", 70 - bookedSeats + cancelledSeats, bookedSeats * 900);
    }
    else if (BusNumber == 104)
    {
        printf("Bus Number: 104\nSource: Bangalore\nDestination: Hyderabad\nTotal Seats: 80\nAvailable Seats: %d\nTotal Fare: %d\n", 80 - bookedSeats + cancelledSeats, bookedSeats * 1000);
    }
    else
    {
        printf("Please enter correct bus number!\n");
    }
}

void ticket_booking()
{
    printf("\nEnter your Bus Number: ");
    scanf(" %d", &BusNumber);
    printf("Please enter the no. of seats you want to book: ");
    scanf(" %d", &bookedSeats);

    printf("\nBooking Successfully Completed! %d seats booked on Bus Number %d.\n", bookedSeats, BusNumber);

    printf("\n-----Here is your Reserved Bus Details :---\n");

    show_bus_details();
}

void cancel_ticket()
{
    printf("Enter Bus Number from which you want to cancel ticket: ");
    scanf(" %d", &BusNumber);
    printf("Please enter the no. of seats you want to cancel: ");
    scanf(" %d", &cancelledSeats);

    printf("\nTickets Cancellation Successful! %d Tickets cancelled on Bus Number %d.\n", cancelledSeats, BusNumber);
}
