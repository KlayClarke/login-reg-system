#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() 
{
    string entered_username, entered_password, correct_username, correct_password;

    correct_username = "correct_username";
    correct_password = "correct_password";

    cout << "Username: ";
    cin >> entered_username;
    cout << "Password: ";
    cin >> entered_password;

    if (entered_username == correct_username && entered_password == correct_password)
    {
        cout << "Access Granted";
        return true;
    }
    
}

int main()
{
    IsLoggedIn();
    // Initialize variables for username and password - as username and password strings

    // Take user input for username

    // Take user input for password

    // If user input for username and password is equal to username and password strings, print "Access Granted"

    // Else, print "Access Denied"
    return 0;
}
