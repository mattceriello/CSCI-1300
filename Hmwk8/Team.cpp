#include "Player.cpp"
#include "Team.h"
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

//split already commented
int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[k] = word;
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}

//default constructor
//sets name to null and adds player vector full of default player objects
Team::Team(){
    teamName = "";
    for(int i = 0; i < players.size(); i++){
        players[i] = Player();
    }
}

//parameterized constructor
////sets name to input and adds player vector full of default player objects
Team::Team(string newteamname){
    teamName = newteamname;
    for(int i = 0; i < players.size(); i++){
        players[i] = Player();
    }
}

//sets team name to input
void Team::setTeamName(string newteamname1){
    teamName = newteamname1;
}

//Algorithm: take a file of team roster and save each player as a player object
void Team::readRoster(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[2];
        string name = "";
        double points = 0.0;
        while(getline(file,line)){ //loop through file line by line
            if(line.length() == 0) continue;
            split(line, ',' , linearr, 2);
            name = linearr[0]; //save name as first thing on each line
            points = stod(linearr[1]); //save points as second thing on each line
            players.push_back(Player(name,points)); //create player object and save to vector off players
        }
        file.close();
    }
}

//return player name at specfic index
string Team::getPlayerName(int i){
    if(i > players.size() - 1){
        return "ERROR";
    }
    return players[i].getName();
}

//return player's points at specific index
double Team::getPlayerPoints(int i){
    if(i > players.size() - 1){
        return -1;
    }
    return players[i].getPoints();
}

//return number of players in player vector
int Team::getNumPlayers(){
    return players.size();
}

//return team name
string Team::getTeamName(){
    return teamName;
}