#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// bool IsLoggedIn() 
// {
//     string entered_username, entered_password, correct_username, correct_password;

//     cout << "Username: ";
//     cin >> entered_username;
//     cout << "Password: ";
//     cin >> entered_password;

//     ifstream read(entered_username + '.txt');
//     getline(read, correct_username);
//     getline(read, correct_password);

//     if (entered_username == correct_username && entered_password == correct_password)
//     {
//         cout << "Access Granted\n";
//         return true;
//     }
//     else
//     {
//         if (entered_username == correct_username && entered_password != correct_password)
//         {
//             cout << "Incorrect password\n\n";
//         }

//         else if (entered_username != correct_username && entered_password == correct_password)
//         {
//             cout << "Incorrect username\n\n";
//         }

//         else 
//         {
//             cout << "Incorrect username and password\n\n";
//         }

//         return false;
//     }

// }

int main()
{
    int choice;

    cout << "Press 1 to register, 2 to login: ";
    cin >> choice;

    if (choice == 1) // if user chooses to register
    {
        string username, password;

        cout << "\nenter a username: ";
        cin >> username;
        cout << "\nenter a password: ";
        cin >> password;

        ofstream file (username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }

    else if (choice == 2) // if user chooses to login
    {
        // bool status = IsLoggedIn();

        // if (!status)
        // {
        //     cout << "Login attempt unsuccessful!";
        // }

        // else 
        // {
        //     cout << "Login attempt successful!";
        // }

        cout << "Loading...";
    }
    
    return 0;

}
