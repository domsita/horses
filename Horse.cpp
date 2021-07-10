#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>
#include "Horse.h"

using namespace std;

Horse::Horse(string n, string r) {
    name = n;
    rider = r;
    distanceTraveled = 0;
    racesWon = 0;
    unsigned seed = time(0);
    srand(seed);
    maxRunningDistPerSecond = getRandomRunSpeed();
}

string Horse::getName() {
    return name;    
}

void Horse::setName(string n) {
    name = n;
}

string Horse::getRider() {
    return rider;
}

void Horse::setRider(string r) {
    rider = r;
}

int Horse::getMaxRunningDistPerSecond() {
    return maxRunningDistPerSecond;
}

void Horse::setMaxRunningDistPerSecond(int d) {
    maxRunningDistPerSecond = d;
}

int Horse::getDistanceTraveled() {
    return distanceTraveled;
}

void Horse::setDistanceTraveled(int d) {
    distanceTraveled = d;
}

int Horse::getRacesWon() {
    return racesWon;
}

void Horse::setRacesWon(int w) {
    racesWon += w;
}

int Horse::getRandomRunSpeed() {
    const int MIN_SPEED = 1;
    const int MAX_SPEED = 100;
    return ((rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED);
}

void Horse::runASecond() {
    int distanceThisSecond = getMaxRunningDistPerSecond();
    setDistanceTraveled(distanceTraveled + distanceThisSecond);
    // I'm setting run speed after every run to make the program more dynamic.
    // Initially I had the same running speed every turn but whichever horse was in
    // first at the beginning won the race. This make it more interesting.
    setMaxRunningDistPerSecond(getRandomRunSpeed());
}

void Horse::sendToGate() {
    distanceTraveled = 0;    
}

// takes in a goal length and outputs a portion of the string in proportion to 
// the track length.
void Horse::displayHorse(int goalLength) {
    string track = "|-------------------------------------------------->|";
    int currentLocation = getDistanceTraveled();
    double trackRatio = (static_cast<double>(currentLocation) / goalLength) * 50;
    int trackIndex = static_cast<int>(trackRatio) + 1;
    cout << left << setw(60) << track.substr(0, trackIndex); 
    cout << name << " ridden by " << rider << endl;
}