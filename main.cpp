#include <iostream>
#include <vector>
using namespace std;
int p = 1;    // Global variable to keep track of number of elements in Vectors
bool found;   // only used in RemovePlayer Function in order to remove from Vector

void MainMenu(){
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
}

void StartingPlayers(vector<int>& playerJersey, vector<int>& playerRating){
        cout << "Enter player " << p << "'s jersey number: ";
        cin >> playerJersey.at(p);
        cout << endl;
        cout << "Enter player  " << p << "'s rating: ";
        cin >> playerRating.at(p);
        ++p;
        cout << endl;
        cout << endl;
}

void AddPlayer(vector<int>& playerJersey, vector<int>& playerRating){
    cout << "Enter another player's jersey number: ";
    cin >> playerJersey.at(p);
    cout << endl;
    cout << "Enter another player  " << "'s rating: ";
    cin >> playerRating.at(p);
    ++p;
    cout << endl;
    cout << endl;
}

void RemovePlayer(vector<int>& playerJersey, vector<int>& playerRating) {
    int playerRemoved;
    unsigned int i = 1;
    cout << "Which player would you like to remove?" << endl;
    cin >> playerRemoved;
    while (!found && (i < playerJersey.size())) {
        if (playerJersey.at(i) == playerRemoved) {
            playerJersey.erase(playerJersey.begin() + i);
            playerRating.erase(playerRating.begin() + i);
            found = true;
        }
        ++i;
    }
    --p;
}

void UpdatePlayerRating(vector<int>& playerJersey, vector<int>& playerRating){
    int updatedNumber;
    int updatePlayer;
    cout << "Which player's rating would you like to update?" << endl;
    cin  >> updatePlayer;
    cout << "What would you like their rating to be? " << endl;
    cin  >> updatedNumber;
    for (int i = 0; i < p; ++i){
        if (playerJersey.at(i) == updatePlayer){
            playerRating.at(i) = updatedNumber;
        }
    }
}

void OutputPlayersAboveRating(vector<int> playerJersey, vector<int> playerRating){
    int minRating;
    cout << "What is the minimum rating you would like to see?" << endl;
    cin  >> minRating;
    cout << "ABOVE" << minRating << endl;
    for (int i = 1; i < p; ++i) {
        if (playerRating.at(i) > minRating) {
            cout << "Player " << i << " -- Jersey number: " << playerJersey.at(i) << ", Rating: " << playerRating.at(i);
        }
        cout << endl;
    }

}

void OutputRoster(vector<int> playerJersey, vector<int> playerRating){
    cout << "ROSTER" << endl;
    for (int i = 1; i < p; ++i){
        cout << "Player " << i << " -- Jersey number: " << playerJersey.at(i) << ", Rating: " << playerRating.at(i) << endl;
    }
    cout << endl;
}

int main() {
    int NUM_PLAYERS = 'p';                 // variable used without to keep track of Number of Vector Elements
    vector<int> playerJersey(NUM_PLAYERS); // Player Numbers
    vector<int> playerRating(NUM_PLAYERS); // Ratings
    char userInput = 'a';                  // Users Input for the Main Menu

    // 5 Starting Players
    for (int i = 0; i < 5; ++i){
        StartingPlayers(playerJersey,playerRating);
    }
    cout << endl;

    // Updated Roster
    OutputRoster(playerJersey, playerRating);

    // Main Menu Loop
    while (userInput != 'q') {
        MainMenu();
        cin >> userInput;
        if (userInput == 'a') {
            AddPlayer(playerJersey, playerRating);
        }
        if (userInput == 'o') {
            OutputRoster(playerJersey, playerRating);
        }
        if (userInput == 'd') {
            RemovePlayer(playerJersey, playerRating);
        }
        if (userInput == 'u') {
            UpdatePlayerRating(playerJersey, playerRating);
        }
        if (userInput == 'r') {
            OutputPlayersAboveRating(playerJersey, playerRating);
        }
    }

    return 0;
}