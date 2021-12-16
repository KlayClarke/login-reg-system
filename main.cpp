#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn() {
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
    if (entered_username == correct_username && entered_password == correct_password) {
        cout << "Access Granted\n";
        return true;
    }
    else {   // if user's entered username is found but entered password is not - means user may've forgotten password
        if (entered_username == correct_username && entered_password != correct_password)
        {
            cout << "Incorrect password\n\n";
        }
        // if user's entered username is not found but entered password is - means user may've forgotten username
        else if (entered_username != correct_username && entered_password == correct_password) {
            cout << "Incorrect username\n\n";
        }
        // if both entries are not found
        else {
            cout << "Incorrect username and password\n\n";
        }
        return false;
    }
}

int main() {
    int choice;
    cout << "Press 1 to register, 2 to login: "; // prompt user to either register or login - options
    cin >> choice; // take user choosing as choice variable
    // if user chose to register
    if (choice == 1) {
        string username, password;
        cout << "\nenter a username: "; // prompt user to enter unique username
        cin >> username;
        ifstream file (username + ".txt"); //check to see if username exists in 'database'
        // if username exists
        if (file) {
            cout << "Account with this username already exists!\n";
        }
        // if not, allow user to continue registration
        else {
            cout << "\nenter a password: "; // prompt user to enter password
            cin >> password;
            ofstream file (username + ".txt"); //create txt file in working directory titled '{username}.txt'
            file << username << endl << password; //write user's username to one line and password to another line in txt file
            file.close(); //close text file
        }
        main();
    }
    // if user chose to login
    else if (choice == 2) {
        bool status = IsLoggedIn(); // run IsLoggedIn and return either true or false - depends on whether user passed correct values through
        //if IsLoggedIn() is false
        if (!status) {
            cout << "Login attempt unsuccessful!";
        }
        //if IsLoggedIn() is true
        else {  
            bool logout = false;
            int choice;
            cout << "Press 1 to access secrets, 2 to logout: ";
            while (!logout) {
                cin >> choice;
                if (choice == 1) {
                    cout << "SECRETS...SECRETS...SECRETS...SECRETS...SECRETS";
                    logout = false;
                }
                else if (choice == 2) {
                    cout << "Have a nice day!";
                    logout = true;
                }
            }
        }
    }
    return 0;
}
// after accessing secrets, allow user to choose between secrets or logout again
// after logout, give user choice to register or login again
// once user logged in, give option to logout - if user chooses to logout, give option to either register or login
// option to change username -- ??? or change password -- ???
