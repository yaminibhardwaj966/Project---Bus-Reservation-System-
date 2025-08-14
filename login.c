#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define USERNAME_LEN 20
#define PASSWORD_LEN 9 //

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