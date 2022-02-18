#include "Game.cpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>    
#include <time.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
using namespace std;




int main(){
    int turns = 0;
    cout << "hello"<< endl;
    Game g1;
    g1.readmap("mapGOT.txt");
    g1.readwarrior("warriorsGOT.txt");
    g1.readhero("heroesGOT.txt");
    g1.readcity("citiesGOT.txt");
    g1.initiatedg();
    g1.setwarriors();
    g1.intro();
    cout << endl;
    while(g1.getgameover() == false){
        g1.printminimap();
        cout << endl;
        g1.promptturn();
        cout << endl;
        g1.updateotherheroes();
        cout << endl;
        g1.userencounter();
        cout << endl;
        g1.otherecnounter();
        cout << endl;
        g1.randomevents();
        cout << endl;
        if(turns == 10){
            g1.mandatory();
        }
        turns++;
    }
}