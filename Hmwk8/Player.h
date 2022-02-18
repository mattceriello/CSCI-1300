#ifndef Player_h
#define Player_h
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

class Player{
    
    private:
        string name;
        double points;
    
    public:
        Player();
        Player(string, double);
        string getName();
        double getPoints();
        void setName(string);
        void setPoints(double);

};
#endif