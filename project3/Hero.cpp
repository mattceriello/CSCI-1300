#include "Hero.h"
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



Hero::Hero(){
    name = "";
    money = 0;
    influence = 0;
    armysize = 0;
    herorow = 0;
    herocol = 0;
    ship = false;
    points = 0;
    hasbattled = false;
}


Hero::Hero(string newname, int newmoney, int newinfluence, int newarmysize, vector<Warrior> newwarriors, int newrow, int newcol, bool newship){
    name = newname;
    money = newmoney;
    influence = newinfluence;
    armysize = newarmysize;
    for(int i = 0; i < newwarriors.size(); i++){
        warriors.push_back(newwarriors[i]);
    }
    herorow = newrow - 1;
    herocol = newcol - 1;
    ship = newship;
    points = 0;
    hasbattled = false;
}

string Hero::getname(){
    return name;
}

void Hero::setname(string newname){
    name = newname;
}

int Hero::getmoney(){
    return money;
}

void Hero::setmoney(int newmoney){
    money = newmoney;
}

int Hero::getinfluence(){
    return influence;
}

void Hero::setinfluence(int newinfluence){
    influence = newinfluence;
}

int Hero::getarmysize(){
    return armysize;
}

void Hero::setarmysize(int newarmysize){
    armysize = newarmysize;
}

bool Hero::crossWater(){
    //if hero has ship return true
}

int Hero::getrow(){
    return herorow;
}

void Hero::setrow(int newrow){
    herorow = newrow;
}

int Hero::getcol(){
    return herocol;
}

void Hero::setcol(int newcol){
    herocol = newcol;
}

Warrior Hero::getwarrior(int num){
    return warriors[num];
}

int Hero::getvectorsize(){
    return warriors.size();
}

bool Hero::getship(){
    return ship;
}

void Hero::setship(bool newship){
    ship = newship;
}

void Hero::fillvector(vector<Warrior> newwarriors){
    for(int i = 0; i < newwarriors.size(); i++){
        warriors.push_back(newwarriors[i]);
    }
}

int Hero::getpoints(){
    return points;
}

void Hero::addpoints(int num){
    points += num;
}

void Hero::addwarrior(Warrior warrior){
    warriors.push_back(warrior);
}

void Hero::addmoney(int num){
    money += num;
}

void Hero::addinfluence(int num){
    influence += num;
}

void Hero::addarmysize(int num){
    armysize += num;
}

bool Hero::gethasbattled(){
    return hasbattled;
}

void Hero::sethasbattled(bool battle){
    hasbattled = battle;
}

void Hero::removewarrior(){
    warriors.pop_back();
}
void Hero::erasewarrior(string name){
    for(int i = 0; i < warriors.size(); i++){
        if(warriors[i].getname() == name){
            warriors.erase(warriors.begin() + i);
        }
    }
}