#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn() 
{
    string entered_username, entered_password, correct_username, correct_password;
    // prompt user to enter username, password
    cout << "Username: ";
    cin >> entered_username;
    cout << "Password: ";
    cin >> entered_password;
    ifstream file (entered_username + ".txt"); // find and read file with entered_username.txt as filename
    getline(file, correct_username); // initialize correct_username variable as text on first line 
    getline(file, correct_password); // initialize correct_password variable as text on second line
    // if user's entered username and password are found in txt file - means user is a user within db
    if (entered_username == correct_username && entered_password == correct_password)
    {
        cout << "Access Granted\n";
        return true;
    }
    else
    {   // if user's entered username is found but entered password is not - means user may've forgotten password
        if (entered_username == correct_username && entered_password != correct_password)
        {
            cout << "Incorrect password\n\n";
        }
        // if user's entered username is not found but entered password is - means user may've forgotten username
        else if (entered_username != correct_username && entered_password == correct_password)
        {
            cout << "Incorrect username\n\n";
        }
        else // if both entries are not found
        {
            cout << "Incorrect username and password\n\n";
        }
        return false;
    }
}

int main()
{
    int choice;
    cout << "Press 1 to register, 2 to login: "; // prompt user to either register or login - options
    cin >> choice; // take user choosing as choice variable
    if (choice == 1) // if user chose to register
    {
        string username, password;
        // allow user to create account using unique username, and a password
        cout << "\nenter a username: ";
        cin >> username;
        cout << "\nenter a password: ";
        cin >> password;
        ofstream file (username + ".txt"); //create txt file in working directory titled '{username}.txt'
        file << username << endl << password; //write user's username to one line and password to another line in txt file
        file.close(); //close text file

        main();
    }

    else if (choice == 2) // if user chose to login
    {
        bool status = IsLoggedIn(); // IsLoggedIn is returning either true or false - depends on whether user passed correct values through
        if (!status) //if status / IsLoggedIn() is false
        {
            cout << "Login attempt unsuccessful!";
        }
        else  //if status / IsLoggedIn() is true
        {
            cout << "Login attempt successful!";
        }
    }
    return 0;
}

// what about for preexisting usernames????????

// when user attempts to create new account with existing username, preexisting account overridden completely - stop this