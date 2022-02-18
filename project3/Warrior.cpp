#include "Warrior.h"
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



Warrior::Warrior(){
    name = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    isfree = false;
    ship = false;
    dragonGlass = false;
}

Warrior::Warrior(string newname, int newstrength, int newloyalty, int newmorale, bool newisfree, bool newship, bool newhasdragonglass){
    name = newname;
    strength = newstrength;
    loyalty = newloyalty;
    morale = newmorale;
    isfree = newisfree;
    ship = newship;
    dragonGlass = newhasdragonglass;
}


string Warrior::getname(){
    return name;
}

int Warrior::getstrength(){
    return strength;
}

void Warrior::setstrength(int newstrength){
    strength = newstrength;
}

int Warrior::getloyalty(){
    return loyalty;
}

void Warrior::setloyalty(int newloyalty){
    loyalty =  newloyalty;
}

int Warrior::getmorale(){
    return morale;
}

void Warrior::setmorale(int newmorale){
    morale = newmorale;    
}

bool Warrior::getisfree(){
    return isfree;
}

void Warrior::setlocation(int r, int c){
    row = r;
    col = c;
}

bool Warrior::getship(){
    return ship;
}

bool Warrior::getdragonglass(){
    return dragonGlass;
}

void Warrior::addstrength(int num){
    strength += num;
}

void Warrior::addmorale(int number){
    morale += number; 
}

int Warrior::getrow(){
    return row;
}

int Warrior::getcol(){
    return col;
}

void Warrior::addloyalty(int num){
    loyalty += num;
}

void Warrior::setisfree(bool input){
    isfree = input;
}