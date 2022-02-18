#include "Team.cpp"
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

//Algorithm: input 2 teams and see who wins
//1. total up points for each team's first 4 players
//2. whichever team has more points wins
//input: team1 Team object - team2 Team object
string game(Team team1, Team team2){
    if(team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4){//test if each team has enough players
        return "forfeit";
    }
    double total1 = 0.0;
    double total2 = 0.0;
    for(int i = 0; i < 4; i++){
        total1 += team1.getPlayerPoints(i);//total up team1 
    }
    
    for(int i = 0; i < 4; i++){
        total2 += team2.getPlayerPoints(i);//total up team 2
    }
    
    if(total1 > total2){
        return team1.getTeamName();//if team1 wins return teamname
    }
    else if(total2 > total1){
         return team2.getTeamName();//if team2 wins return teamname
    }
    else if(total1 == total2){
        return "draw";
    }
    
}

int main(){
    //test case 1
    //expected output: giants
    Team team1("giants");
    team1.readRoster("roster1.txt");
    
    Team team2("patriots");
    team2.readRoster("roster2.txt");
    cout << game(team1,team2);
}