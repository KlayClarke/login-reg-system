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
        cout << "Access Granted\n";
        return true;
    }
    else
    {
        if (entered_username == correct_username && entered_password != correct_password)
        {
            cout << "Incorrect password\n\n";
        }

        else if (entered_username != correct_username && entered_password == correct_password)
        {
            cout << "Incorrect username\n\n";
        }

        else 
        {
            cout << "Incorrect username and password\n\n";
        }

        return false;
    }

}

int main()
{
    while (!IsLoggedIn())
    {
        IsLoggedIn();
        cin.clear();
        cin.ignore();
    }

    return 0;
}
