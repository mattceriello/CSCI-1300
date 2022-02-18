#include "Tile.h"
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


Tile::Tile(){
    letter = "";
    points = 0;
}

Tile::Tile(string newletter){
    letter = newletter;
    if(newletter == "w"){
        points = 1;
    }
    else if(newletter == "p"){
        points = 2;
    }
}

string Tile::getLetter(){
    return letter;
}

void Tile::setpoints(int newpoints){
    points = newpoints;
}

int Tile::getpoints(){
    return points;
}

bool Tile::isWater(){
    if (letter == "w"){
        return true;
    }
    else{
        return false;
    }
}



bool Tile::isCity(){
    //return true if tile is city
    char arr[1];
    string str = letter;
    arr[0] = letter[0];
    if(int(arr[0]) > 64 && int(arr[0]) < 91){
     return true;
    }
    else{
        return false;
    }
}

bool Tile::isFree(){
    //return true if tile is free

}

bool Tile::isLand(){
    //return true if tile is land
    if (letter == "p"){
        return true;
    }
    else{
        return false;
    }    
        
}

void Tile::setdragonglass(bool hasglass){ //set glass on map
    dragonglass = hasglass;
}