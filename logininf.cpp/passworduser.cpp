//very simple C++ program for an project login.
//You can inject this code in your program for login interface. 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system("cls")

using namespace std;

class PasswordManager {
public:
    // Function to clear the display
    void ClearDisplay() {
        system("cls");
    }

    // Function to register a new user
    void RegisterUser() {
        string username, password;
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;

        ifstream file("password.txt");
        string storedUsername;

        while (file >> storedUsername) {
            if (username == storedUsername) {
                file.close();
                cerr << "Error: Username already taken. Please choose a different username." << endl;
                return;
            }
        }

        file.close();

        ofstream outFile("password.txt", ios::app);
        if (!outFile.is_open()) {
            cerr << "Error: Could not open the file." << endl;
            return;
        }

        // Write the username and password to the file
        outFile << username << ' ' << password << endl;

        cout << "Registration successful! You can now log in." << endl;
        outFile.close();
        ClearDisplay();
    }

    // Function to check if a username and password match for the same person
    bool AuthenticateUser(const string &username, const string &password) {
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

    // Main program logic
    void Run() {
        int choice;

        cout << "Welcome to the Login System!" << endl;
        do {
            cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    RegisterUser();
                    break;
                case 2: {
                    string username, password;
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter your password: ";
                    cin >> password;
                    if (AuthenticateUser(username, password)) {
                        cout << "Authentication successful! Access granted." << endl;
                        ClearDisplay();
                    } else {
                        cout << "Authentication failed. Please try again." << endl;
                    }
                    break;
                }
                case 3:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 3);
    }
};

int main() {
    PasswordManager objpwd;
    objpwd.Run();
    return 0;
}