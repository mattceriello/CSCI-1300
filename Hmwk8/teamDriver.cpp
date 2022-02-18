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

int main(){
    //test case 1
    //expected ouput: Lakers
    Team lakers("Lakers");
    cout << lakers.getTeamName() << endl;
    
    
    //test case 2
    //expected output: 5
    Team giants("Giants");
    giants.readRoster("roster1.txt");
    int total = giants.getNumPlayers();
    cout << total << endl;
}