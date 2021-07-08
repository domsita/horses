// Specification for the Horse class
#ifndef HORSE_H
#define HORSE_H
#include <string>

using namespace std;

class Horse {
    private:
        string name;
        string rider;
        int maxRunningDistPerSecond;
        int distanceTraveled;
        int racesWon;
    public:
        Horse(string n, string r);
        string getName();
        void setName(string n);
        string getRider();
        void setRider(string r);
        int getMaxRunningDistPerSecond();
        void setMaxRunningDistPerSecond(int d);
        int getDistanceTraveled();
        void setDistanceTraveled(int d);
        int getRacesWon();
        void setRacesWon(int w);
        int initMaxRunSpeed();
        void runASecond();
        void sendToGate();
        void displayHorse(int goalLength);
};

#endif