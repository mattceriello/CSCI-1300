#include "Player.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
using namespace std;


string Player::getname(){
    return name;
}

int Player::getpoints(){
    return points;

}

void Player::setpoints(int newpoints){
    points = newpoints; 
}