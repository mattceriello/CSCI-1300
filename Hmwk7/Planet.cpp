// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk7
#include "Planet.h"
#include <iostream>
#include <cmath>
using namespace std;

//Algorithm: Default constructor
//1. set name to null
//2. set radius to 0.0
Planet::Planet(){
    planetName = "";
    planetRadius = 0.0;
}

//Algorithm: Parameterized constructor
//1. set name to new name
//2. set radius to new radius
Planet::Planet(string _planetName, double _planetRadius){
    planetName = _planetName;
    planetRadius = _planetRadius;
}

//Algorithm: get name
//1. return name

string Planet::getName(){
    return planetName;
}

//Algorithm: set name
//1. set name
//input: string- new name
void Planet::setName(string a){
    planetName = a;
}
      
//Algorithm: Get radius
//1. return planet radius
double Planet::getRadius(){
    return planetRadius;
}


//Algorithm: Set Radius
//1. set radius to input
//input: double- new radius
void Planet::setRadius(double num){
    planetRadius = num;
}

//Algorithm: get volume of planet
//1. calculate volume using radius
//2. return volume

double Planet::getVolume(){
    double volume = (4*3.14159265359*getRadius()*getRadius()*getRadius())/3;
    return volume;
}