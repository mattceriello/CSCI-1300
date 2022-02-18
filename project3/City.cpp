#include "City.h"
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



City::City(){
    letter = "";
    name = "";
    money = 0;
    armysize = 0;
    points = 0;
}


City::City(string newletter, string newname, int newmoney, int newarmysize, int newpoints){
    letter = newletter;
    name = newname;
    money = newmoney;
    armysize = newarmysize;
    points = newpoints;
}


string City::getname(){
    return name;
}

int City::getmoney(){
    return money;
}

void City::setmoney(int newmoney){
    money = newmoney;
}

int City::getarmysize(){
    return armysize;
}

void City::setarmysize(int newarmysize){
    armysize = newarmysize;
}

int City::getpoints(){
    return points;
}

void City::setpoints(int newpoints){
    points = newpoints;
}

string City::getletter(){
    return letter;
}