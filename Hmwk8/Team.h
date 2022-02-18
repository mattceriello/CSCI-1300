#ifndef Team_h
#define Team_h
#include "Player.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;

class Team{
    
    private:
        string teamName;
        vector<Player> players;
    
    public:
        Team();
        Team(string);
        void setTeamName(string);
        void readRoster(string);
        string getPlayerName(int);
        double getPlayerPoints(int);
        int getNumPlayers();
        string getTeamName();
        
};
#endif