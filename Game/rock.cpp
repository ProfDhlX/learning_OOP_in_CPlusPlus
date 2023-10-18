#include <iostream>
#include <ctime>
#include <cstdlib>

class Game {
public:
    Game() {
        srand(static_cast<unsigned>(time(0)));
    }

    void start() {
        std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
        std::cout << "Get ready...." << std::endl;
        std::cout << "1.... ";
        std::cout.flush();
        sleep(1);
        std::cout << "2.... ";
        std::cout.flush();
        sleep(1);
        std::cout << "3.... ";
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

    int determineWinner(int userChoice, int computerChoice)  {
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

int main() {
    Game game;
    game.start();
    return 0;
}
