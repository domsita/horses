#include <string>
#include <iostream>
#include <memory>
#include "Horse.h"

using namespace std;

int getNumHorses();
string getHorseName();
string getRiderName();
int getGoalLength();

int main() {
    bool raceIsActive = false;
    char startAgain = 'n';
    int winningHorse = -1;
    char continueRace = 'y';
    int numHorses = getNumHorses();
    Horse * horses[numHorses];
    cin.ignore();

    // Initializes the array of Horse objects with a name and rider
    for (int i = 0; i < numHorses; i++) {
        string hName = getHorseName();
        string rName = getRiderName();
        horses[i] = new Horse(hName, rName);
    }

    int goalLength = getGoalLength();
    raceIsActive = true;

    // loop to handle whether or not to continue the race. if a user 
    // selects no, the program exits. if they select yes, we run another second
    while (raceIsActive) {
        for (int i = 0; i < numHorses; i++) {
            horses[i]->runASecond();
            horses[i]->displayHorse(goalLength);
        }
        
        for (int i = 0; i < numHorses; i++) {
            if (horses[i]->getDistanceTraveled() > goalLength) {
                raceIsActive = false;
                if (winningHorse < 0) {
                    winningHorse = i;
                } else {
                    if (horses[i]->getDistanceTraveled() > horses[winningHorse]->getDistanceTraveled()) {
                        winningHorse = i;
                    }
                }
            }
        }

        if (!raceIsActive) {
            horses[winningHorse]->setRacesWon(1);
            cout << horses[winningHorse]->getName() << " ridden by " << horses[winningHorse]->getRider() << " is the winner!" << endl;
            if (horses[winningHorse]->getRacesWon() == 1) {
                cout << horses[winningHorse]->getName() << " has won 1 race so far. " << endl;
            } else {
                cout << horses[winningHorse]->getName() << " has won " << horses[winningHorse]->getRacesWon() << " races." << endl;
            }
        }

        if (raceIsActive) {
            cout << "Continue race? (y or n) ";
            cin >> continueRace;
            if (continueRace == 'n' || continueRace == 'N') {
                raceIsActive = false;
            }
        } else {
            cout << "Start a new race? (y or n)? ";
            cin >> startAgain;
            if (startAgain == 'y' || startAgain == 'Y') {
                goalLength = getGoalLength();
                winningHorse = -1;
                raceIsActive = true;
                for (int i = 0; i < numHorses; i++) {
                    horses[i]->sendToGate();
                }
            }
        }
    }

    for (int i = 0; i < numHorses; i++) {
        delete horses[i];
    }
    *horses = nullptr;

    return 0;
}

// Asks the users to input the number of horses in the race.
// The number of horses in the race has to be between 1 and 20.
// 20 is an arbitrarily chosen number but any more would be hard to display.
int getNumHorses() {
    int numHorses = 0;
    while (numHorses < 1 || numHorses > 20) {
        cout << "How many horses are in the race? ";
        cin >> numHorses;
    }
    return numHorses;
}

// Asks user for the name of a horse and returns the value.
string getHorseName() {
    string horseName = "";
    do {
        cout << "Please enter the name of a horse: ";
        getline(cin, horseName);
    } while (horseName.empty());

    return horseName;
}

// Asks users for the name of the rider and returns the value.
string getRiderName() {
    string riderName = "";
    do {
        cout << "Please enter the rider's name: ";
        getline(cin, riderName);
    } while (riderName.empty());
    
    return riderName;
}

// gets the length of the race from the user
int getGoalLength() {
    int goal = 0;
    while (goal < 100 || goal > 1000) {
        cout << "How long should the race be? ";
        cin >> goal;
    }
    return goal;
}
