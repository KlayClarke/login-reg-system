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
    else
    {
        if (entered_username == correct_username && entered_password != correct_password)
        {
            cout << "Incorrect password";
        }

        else if (entered_username != correct_username && entered_password == correct_password)
        {
            cout << "Incorrect username";
        }

        else 
        {
            cout << "Access Denied";
        }

        return false;
    }

}

int main()
{
    IsLoggedIn();

    return 0;
}
