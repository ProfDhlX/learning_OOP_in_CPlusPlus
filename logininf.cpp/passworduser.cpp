// a simple cpp program which get the username and password from user and store them in a file
// and implement the file element in login phase which help user to make an good password login interface with .txt database
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void RegisterUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
    ofstream file("password.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }

    // Write the username and password to the file
    file << username << ' ' << password << endl;

    cout << "Registration successful! You can now log in." << endl;
    file.close();
}

// Function to check if a username and password match for the same person
bool AuthenticateUser(const string& username, const string& password) {
    string storedUsername, storedPassword;
    ifstream file("password.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return false;
    }

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            file.close();
            return true; // User found
        }
    }

    file.close();
    return false; // User not found
}

int main() {
    int choice;
    string username, password;

    cout << "Welcome to the Login System!" << endl;
    do {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                RegisterUser();
                break;
            case 2:
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                if (AuthenticateUser(username, password)) {
                    cout << "Authentication successful! Access granted." << endl;

                } else {
                    cout << "Authentication failed. Please try again." << endl;
                }
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
