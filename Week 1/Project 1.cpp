#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void displayIntro();
bool askPlayAgain();

int main() {
    srand(time(0)); // Seed for random number generator
    int rounds, numPlayers, playerPick;
    
    // Loops the game so it can repeat
    do { 
        displayIntro();
        
        // Input rounds
        do {
            cout << "How many rounds would you like to play (1-6)? ";
            cin >> rounds;
        } while (rounds < 1 || rounds > 6);
        
        // Input number of players
        do {
            cout << "How many players are playing (2-6)? ";
            cin >> numPlayers;
        } while (numPlayers < 2 || numPlayers > 6);
        
        // Set array for player status
        string playerNames[numPlayers]; // Allows string for names
        bool isAlive[numPlayers];   // Allows players dead or alive
        
        // Get player names
        for (int i = 0; i < numPlayers; i++) {
            cout << "Enter name for Player " << (i + 1) << ": ";
            cin >> playerNames[i];
        }
        
        // Set all players to alive
        for (int i = 0; i < numPlayers; i++) {
            isAlive[i] = true;
        }

        int totalShots = 0; // Track the amount of shots fired 
        bool gameEnded = false; // Game didn't end

        // Game rounds
        for (int round = 1; round <= rounds && !gameEnded; round++) {
            cout << "\n=== ROUND " << round << " ===" << endl;
            
            for (int i = 0; i < numPlayers; i++) {
                if (!isAlive[i]) continue; // If the player is dead, skip them
                
                int chamber = rand() % 6 + 1; // Randomized 1-6
                
                do {
                    cout << playerNames[i] << "'s turn. Pick a chamber (1-6): ";
                    cin >> playerPick;
                } while (playerPick < 1 || playerPick > 6);
                totalShots++;
                
                // Player choose the wrong chamber
                if (playerPick == chamber) {
                    cout << "💥 BANG! " << playerNames[i] << " has been eliminated." << endl;
                    isAlive[i] = false;

                    // Check remaining players
                    int survivors = 0;
                    for (int i = 0; i < numPlayers; i++) {
                        if (isAlive[i]) survivors++;
                    }
                    
                    // Game ends if no one alive
                    if (survivors < 1) {
                        gameEnded = true;
                        break;
                    }
                } else {
                    cout << "😌 Click. " << playerNames[i] << " is safe." << endl;
                }
                
            }
        }

        // Final results
        cout << "\n=== GAME OVER ===" << endl;
        cout << "Total shots fired: " << totalShots << endl;
        cout << "Survivors: ";
        bool survivorsExist = false;
        for (int i = 0; i < numPlayers; i++) {
            if (isAlive[i]) {
                cout << playerNames[i] << " ";
                survivorsExist = true;
            }
        }
        if (!survivorsExist) cout << "None"; // If no player survived
        cout << endl;

    } while (askPlayAgain());

    cout << "Thanks for playing Russian Roulette. Happy Living!" << endl;
    return 0;
}

// Display game introduction
void displayIntro() 
{
    cout << "\n===========================================" << endl;
    cout << "             RUSSIAN ROULETTE              " << endl;
    cout << "            Multiplayer Edition            " << endl;
    cout << "===========================================" << endl;
}

// Ask to play again
bool askPlayAgain() 
{
    char choice;
    while (true) {
        cout << "\nWould you like to play again? (y/n): ";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'y') 
            return true;
        else if (choice == 'n') 
            return false;
        else 
            cout << "Invalid input. Please enter 'y' or 'n'.";
    }
}