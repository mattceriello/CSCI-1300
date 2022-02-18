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

//default constructor
Player::Player(){
    name = "";
    points = 0.0;
}

//parameterized constructor
Player::Player(string newname, double newpoints){
    name = newname;
    points = newpoints;
}

//returns name of player
string Player::getName(){
    return name;
}

//returns points of player
double Player::getPoints(){
    return points;
}

//sets name to inputed name
void Player::setName(string newname1){
    name = newname1;
}
 
//sets points to inputed points
void Player::setPoints(double newpoints1){
    points = newpoints1;
}