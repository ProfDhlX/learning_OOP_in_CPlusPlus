//A login system using OOP . Demonstrating how login system works .
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //

using namespace std;

class Game {
public:
    Game() {
        srand(static_cast<unsigned>(time(0)));
    }

    void start() {
        std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
        std::cout << "Get ready..." << std::endl;
        std::cout << "3... ";
        std::cout.flush();
        sleep(1);
        std::cout << "2... ";
        std::cout.flush();
        sleep(1);
        std::cout << "1... ";
        std::cout.flush();
        sleep(1);
        std::cout << "Go!" << std::endl;

        std::cout << "Enter your choice (0 - Rock, 1 - Paper, 2 - Scissors): ";
        int userChoice;
        std::cin >> userChoice;

        if (userChoice < 0 || userChoice > 2) {
            std::cout << "Invalid choice. Please choose 0, 1, or 2." << std::endl;
            return;
        }

        int computerChoice = rand() % 3;

        std::cout << "Computer chose: ";
        printChoice(computerChoice);

        std::cout << "You chose: ";
        printChoice(userChoice);

        determineWinner(userChoice, computerChoice);
    }

private:
    void sleep(int seconds) {
        clock_t endwait;
        endwait = clock() + seconds * CLOCKS_PER_SEC;
        while (clock() < endwait) {}
    }

    void printChoice(int choice) {
        switch (choice) {
            case 0:
                std::cout << "Rock" << std::endl;
                break;
            case 1:
                std::cout << "Paper" << std::endl;
                break;
            case 2:
                std::cout << "Scissors" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    }

    int determineWinner(int userChoice, int computerChoice) {
        if (userChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            std::cout << "You win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        }
    }
};

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

                        Game::game.start();
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
    int choice;

    cout << "Welcome to the Login System!" << endl;
    do {
        cout << "1. Register\n2. Login\n3. Play Game\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                objpwd.RegisterUser();
                break;
            case 2: {
                string username, password;
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                if (objpwd.AuthenticateUser(username, password)) {
                    cout << "Authentication successful! Access granted." << endl;
                } else {
                    cout << "Authentication failed. Please try again." << endl;
                }
                break;
            }
            case 3:
                Game game;
                game.start();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}