#include "Game.h"
#include "Tile.cpp"
#include "Hero.cpp"
#include "City.cpp"
#include "Warrior.cpp"
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

int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[k] = word;
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}


Game::Game(){
    turns = 0;
    gameover = false;
}


//load map text file into 2d array of tile objects
void Game::readmap(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        int row = 0;
        string letter;
        //Map m1();
        string linearr[16]; 
        while(getline(file,line)){ //loop through eachn line
            if(line.length() == 0) continue; //skip if line is empty
            split(line, ',' , linearr, 16);
            for(int i = 0; i < 16; i++){
                letter = linearr[i];
                map[row][i] =  Tile(letter); 
            }
            row++;
        }
    }
    else{
        cout << "Error";
    }
}

void Game::readwarrior(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        int row = 0;
        bool isfree = false;
        bool hasship = false;
        bool dragonglass = false;
        string linearr[7];
        while(getline(file,line)){ //loop through eachn line
            if(line.length() == 0) continue; //skip if line is empty
            split(line, ',' , linearr, 7);
            if(linearr[4] == "no"){
                isfree = false;
            }
            else if(linearr[4] == "yes"){
                isfree = true;
            }
            if(linearr[5] == "no"){
                hasship = false;
            }
            else if(linearr[5] == "yes"){
                hasship = true;
            }
            if(linearr[6] == "no "){
                dragonglass = false;
            }
            else if(linearr[6] == "yes "){
                dragonglass = true;
            }
            warriors1.push_back(Warrior(linearr[0], stoi(linearr[1]), stoi(linearr[2]), stoi(linearr[3]), isfree, hasship, dragonglass));
        }
        
    }
    else{
        cout << "Error";
    }
}


//read hero text file into vector of hero objects
void Game::readhero(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[11];
        bool hasship = false;
        while(getline(file,line)){//loop through eachn line
            vector<Warrior> warriorsstart;
            if(line.length() == 0) continue; //skip if line is empty
            split(line, ',' , linearr, 11);
            for(int i = 4; i < 8; i++){
                if(linearr[i] != "NULL"){
                    for(int j = 0; j < 14; j++){
                        if(warriors1[j].getname() == linearr[i]){
                            warriorsstart.push_back(warriors1[j]);
                        }
                    }
                }
            }
            if (linearr[10] == "no "){
                hasship = false;
            }
            else if(linearr[10] == "yes "){
                hasship = true;
            }
            heroes.push_back(Hero(linearr[0], stoi(linearr[1]), stoi(linearr[2]), stoi(linearr[3]), warriorsstart, stoi(linearr[8]), stoi(linearr[9]), hasship));
        }
    }
    else{
        cout << "Error";
    }
}

//read text file of cities into array of cities
void Game::readcity(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        int row = 0;
        string letter;
        string linearr[5]; 
        while(getline(file,line)){ //loop through eachn line
            if(line.length() == 0) continue; //skip if line is empty
            split(line, ',' , linearr, 5);
            cities.push_back(City(linearr[0], linearr[1], stoi(linearr[2]), stoi(linearr[3]), stoi(linearr[4])));
        }
    }
    else{
        cout << "Error";
    }
}


//prompt user to choose a character or create their own
void Game::intro(){
    cout << "Welcome to the G A M E of T H R O N E S!" << endl;
    string name = "";
    cout << "State your name, Your Grace:" << endl;
    cin >> name;
    string answer = "";
    cout << "Would you like to choose a hero " << name << ", Your Grace?(Y/N):";
    cin >> answer;
    if(answer == "Y" || answer == "y"){
        cout<< "Please choose from the following heroes(Answer with #):" << endl;
        int num = 0;
        cout<< "\t1. Cersei Lannister\n\t2. Stannis Baratheon\n\t3. Jon Snow\n\t4. Sansa Stark\n\t5. Euron Greyjoy\n\t6. Daenerys Targaryen" << endl;
        cin >> num;
        vector<Warrior> userwarriors;
        for(int i = 0; i < heroes[num - 1].getvectorsize(); i++){
            userwarriors.push_back(heroes[num - 1].getwarrior(i));
        }
        //Hero user(heroes[num - 1].getname(), heroes[num - 1].getmoney(), heroes[num - 1].getinfluence(), heroes[num - 1].getarmysize(), userwarriors, heroes[num - 1].getrow(), heroes[num - 1].getcol(), heroes[num - 1].getship());
        user.setname(heroes[num - 1].getname());
        user.setmoney(heroes[num - 1].getmoney());
        user.setinfluence(heroes[num - 1].getinfluence());
        user.setarmysize(heroes[num - 1].getarmysize());
        user.fillvector(userwarriors);
        user.setrow(heroes[num - 1].getrow());
        user.setcol(heroes[num - 1].getcol());
        user.setship(heroes[num - 1].getship());
        for(int i = 0; i < user.getvectorsize(); i++){
            if(user.getwarrior(i).getship() == true){
                user.setship(true);
            }
        }
        
        
        if(map[user.getrow()][user.getcol()].isCity() == true){
            for(int j = 0; j < cities.size(); j++){
                if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                    user.addpoints(cities[j].getpoints());
                }
            }
        }
        else if((map[user.getrow()][user.getcol()].isWater()) == true){
            user.addpoints(1);
        }
        else if((map[user.getrow()][user.getcol()].isLand()) == true){
            user.addpoints(2);
        }
        
    }
    else if(answer == "N" || answer == "n"){
        cout << "Your Grace " << name << ", you have chosen to go on this journey alone.\nPlease provide starting values for your adventure." <<endl;
        int money = 0;
        int influence = 0;
        int armysize = 0;
        int row = 0;
        int col = 0;
        bool ship = false;
        cout << "Please choose a value for money(0-10000):" << endl;
        cin >> money;
        cout << "Please choose a value for influence(0-10000):" << endl;
        cin >> influence;
        cout << "Please choose a value for army size(0-10000):" << endl;
        cin >> armysize;
        cout << "Please choose a row value(0-24):" << endl;
        cin >> row;
        cout << "Please choose a column value(0-15):" << endl;
        cin >> col;
        if(map[row][col].getLetter() == "w"){
            ship = true;
        }
        vector<Warrior> warriorsempty;
        //Hero user(name, money, influence, armysize, warriorsempty, row, col, ship);
        user.setname(name);
        user.setmoney(money);
        user.setinfluence(influence);
        user.setarmysize(armysize);
        user.setrow(row);
        user.setcol(col);
        if(map[user.getrow()][user.getcol()].getLetter() == "w"){
            user.setship(true);
        }
        if(map[user.getrow()][user.getcol()].isCity() == true){
            for(int j = 0; j < cities.size(); j++){
                if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                    user.addpoints(cities[j].getpoints());
                }
            }
        }
        else if((map[user.getrow()][user.getcol()].isWater()) == true){
            user.addpoints(1);
        }
        else if((map[user.getrow()][user.getcol()].isLand()) == true){
            user.addpoints(2);
        }
    }
}

//prints 7x7 mini map based on where the player is located currently
void Game::printminimap(){
    bool flag = false;
    int minirow = 0;
    int minicol = 0;
    int row = user.getrow();
    int col = user.getcol();
    int startrow = row - 3; //13
    int startcol = col - 3; //4
    for(int i = startrow; i < startrow + 7; i++){
        minicol = 0;
        for(int j = startcol; j < startcol + 7; j++){
            flag = false;
            if((i < 0 || i > 24) || (j < 0 || j > 15)){
                minimap[minirow][minicol] = '#';
                flag = true;
            }
            else if(map[i][j].getLetter() == "w"){
                minimap[minirow][minicol] = '~';
                flag = true;
            }
            else if(map[i][j].getLetter() == "p"){
                minimap[minirow][minicol] = '*';
                flag = true;
            }
            else if((i >= 0 && i <= 24) && (j >= 0 && j <= 15)){
                char letter[1] = {};
                string str = map[i][j].getLetter();
                letter[0] = str[0];
                if((int(letter[0]) > 64 || int(letter[0]) < 91) && flag == false){
                    minimap[minirow][minicol] = letter[0];
                }
            }
            minicol++;
        }
        minirow++;
    }
    
    for(int a = 0; a < 7; a++){
        for(int b = 0; b < 7; b++){
            cout << minimap[a][b];
            cout << " ";
        }
        cout << endl;
    }
    
}

//ask user what they want to do for their turn
void Game::promptturn(){
    cout << "What would you like to do for your turn?(Answer with #):" << endl;
    int answer = 0;
    cout << "\t1. Travel\n\t2. Rest\n\t3. Contsult with the gods" << endl;
    cin >> answer;
    if(answer == 1){
        travel();
    }
    else if(answer == 2){
        rest();
    }
    else if(answer == 3){
        consult();
    }
}

//ask user how they want tp handle an encouter between themselves and another hero
void Game::userencounter(){
    //run intructions for an encounter
    //
    //based on what type of encounter and what the user wants
    //to do, different code will be executed.
    bool flag = false;
    int idx = 0;
    for(int i = 0; i < heroes.size(); i++){
        if(user.getname() == heroes[i].getname()){
            continue;
        }
        else if(abs(user.getcol() - heroes[i].getcol()) < 3 && abs(user.getrow() - heroes[i].getrow()) < 3){
            flag = true;
            idx = i;
        }
    }
    if(flag == true){
        cout << "You are about to have an encounter" << endl;
        cout << "How would you like to deal with this encounter?(Answer with #):" << endl;
        cout << "\t1. Give a speech\n\t2. Buy them outright\n\t3. Battle" << endl;
        int answer;
        cin >> answer;
        if(answer == 1){
            givespeech(idx);
        }
        else if(answer == 2){
            buyout(idx);
        }
        else if(answer == 3){
            battle(idx);
        }
    }
}


//run similar code for encounter in the background to heros that arent he user
void Game::otherecnounter(){
    int idx = 0;
    bool flag = false;
    for(int i = 0; i < heroes.size(); i++){
        for(int j = 0; j < heroes.size(); j++){
            if(heroes[i].getname() != heroes[j].getname()){
            if(abs(heroes[i].getcol() - heroes[j].getcol()) < 3 && abs(heroes[i].getrow() - heroes[j].getrow()) < 3){
                
                if(heroes[i].gethasbattled() == false && heroes[j].gethasbattled() == false){
                    if(heroes[i].getvectorsize() == 0 && heroes[j].getvectorsize() == 0){
                        if(heroes[i].getarmysize() > heroes[j].getarmysize()){
                            cout << heroes[j].getname() << " has retired." << endl;
                            for(int k = 0; k < heroes[j].getvectorsize(); k++){
                                if(heroes[i].getvectorsize() < 4){
                                    heroes[i].addwarrior(heroes[j].getwarrior(k));
                                }
                            }
                            heroes[i].addmoney(heroes[j].getmoney());
                            heroes[i].addinfluence(heroes[j].getinfluence());
                            heroes[i].addmoney(heroes[j].getmoney());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                        else if(heroes[i].getarmysize() < heroes[j].getarmysize()){
                            cout << heroes[i].getname() << " has retired." << endl;
                            for(int x = 0; x < heroes[i].getvectorsize(); x++){
                                if(heroes[j].getvectorsize() < 4){
                                    heroes[j].addwarrior(heroes[i].getwarrior(x));
                                }
                            }
                            heroes[j].addmoney(heroes[i].getmoney());
                            heroes[j].addinfluence(heroes[i].getinfluence());
                            heroes[j].addmoney(heroes[i].getmoney());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                        else if(heroes[i].getarmysize() == heroes[j].getarmysize()){
                            heroes[i].setarmysize(heroes[i].getarmysize() / 2);
                            heroes[j].setarmysize(heroes[j].getarmysize() / 2);
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                        else if((heroes[i].getvectorsize() == 0 && heroes[i].getarmysize() == 0) &&  (heroes[j].getvectorsize() == 0 && heroes[j].getarmysize() == 0)){
                            cout << heroes[i].getname() << " has retired." << endl;
                            cout << heroes[j].getname() << " has retired." << endl;
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                    }
                    else if((heroes[i].getvectorsize() == 0 && heroes[j].getvectorsize() > 0) || (heroes[i].getvectorsize() > 0 && heroes[j].getvectorsize() == 0)){
                        if(heroes[i].getvectorsize() == 0){
                            cout << heroes[i].getname() << " has retired." << endl;
                            for(int a = 0; a < heroes[i].getvectorsize(); a++){
                                if(heroes[j].getvectorsize() < 4){
                                    heroes[j].addwarrior(heroes[i].getwarrior(a));
                                }
                            }
                            heroes[j].addmoney(heroes[i].getmoney());
                            heroes[j].addinfluence(heroes[i].getinfluence());
                            heroes[j].addmoney(heroes[i].getmoney());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                        else if(heroes[j].getvectorsize() == 0){
                            cout << heroes[j].getname() << " has retired." << endl;
                            for(int b = 0; b < heroes[j].getvectorsize();b++){
                                if(heroes[i].getvectorsize() < 4){
                                    heroes[i].addwarrior(heroes[j].getwarrior(b));
                                }
                            }
                            heroes[i].addmoney(heroes[j].getmoney());
                            heroes[i].addinfluence(heroes[j].getinfluence());
                            heroes[i].addmoney(heroes[j].getmoney());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                    }
                    else if(heroes[i].getvectorsize() > 0 && heroes[j].getvectorsize() > 0){
                        int hero1 = heroes[i].getvectorsize();
                        int hero2 = heroes[j].getvectorsize();
                        int hero1idx = 4;
                        int hero2idx = 4;
                        int hero1battle = 0;
                        int hero2battle = 0;
                        while(hero1idx >= hero1){
                            hero1idx = rand() % 4;
                        }
                        while(hero2idx >= hero2){
                            hero2idx = rand() % 4;
                        }
                        hero1battle = (heroes[i].getarmysize() * heroes[i].getwarrior(hero1idx).getstrength());
                        hero2battle = (heroes[j].getarmysize() * heroes[j].getwarrior(hero2idx).getstrength());
                        if(hero1battle > hero2battle){ // user wins
                            cout << heroes[j].getname() << " has retired." << endl;
                            for(int c = 0; c < heroes[j].getvectorsize(); c++){
                                if(user.getvectorsize() < 4){
                                    heroes[i].addwarrior(heroes[j].getwarrior(c));
                                }
                            }
                            heroes[i].addmoney(heroes[j].getmoney());
                            heroes[i].addinfluence(heroes[j].getinfluence());
                            heroes[i].addarmysize(heroes[j].getarmysize());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                        else if(hero1battle < hero2battle){ // user loses
                            cout << heroes[i].getname() << " has retired." << endl;
                            for(int d = 0; d < heroes[j].getvectorsize(); d++){
                                if(heroes[i].getvectorsize() < 4){
                                    heroes[i].addwarrior(heroes[j].getwarrior(d));
                                }
                            }
                            heroes[j].addmoney(heroes[i].getmoney());
                            heroes[j].addinfluence(heroes[i].getinfluence());
                            heroes[j].addarmysize(heroes[i].getarmysize());
                            heroes[i].sethasbattled(true);
                            heroes[j].sethasbattled(true);
                        }
                    }
                }   
            }    
            }
        }
    }
}


//sets new row or column value based on what direction the user chpse to go when traveling
bool Game::travel(){
    //run code for if user deciedes to travel for their turn
    //
    //decide which directiont the user will travel
    string answer = "";
    cout << "Which direction would you like to travel: North, South, East, or West?" << endl;
    cin >> answer;
    if(answer == "North" || answer == "north"){
        int rowup = user.getrow() - 1;
        if(isoutofbounds(rowup, user.getcol()) == false){
            if(map[rowup][user.getcol()].isWater() == true && user.getship() == true){
                user.setrow(rowup);
                user.addpoints(1);
                user.addmoney(10);
            }
            else if(map[rowup][user.getcol()].isWater() == true && user.getship() == false){
                cout << "Cant travel to water without ship." << endl;
            }
            if(map[rowup][user.getcol()].isCity() == true){
                user.setrow(rowup);
                for(int j = 0; j < cities.size(); j++){
                    if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                        user.addpoints(cities[j].getpoints());
                        user.addmoney(cities[j].getmoney());
                        user.addarmysize(cities[j].getarmysize());
                    }
                }
            }
            else if(map[rowup][user.getcol()].isLand() == true){
                user.setrow(rowup);
                user.addpoints(2);
                user.addmoney(20);
                user.addarmysize(10);
            }
        }
        else if(isoutofbounds(rowup, user.getcol()) == true){
            cout << "You fell off the side of the map" << endl;
        }
    }
    else if(answer == "South" || answer == "south"){
        int rowdown = user.getrow() + 1;
        if(isoutofbounds(rowdown, user.getcol()) == false){
            if(map[rowdown][user.getcol()].isWater() == true && user.getship() == true){
                user.setrow(rowdown);
                user.addpoints(1);
                user.addmoney(10);
            }
            else if(map[rowdown][user.getcol()].isWater() == true && user.getship() == false){
                cout << "Cant travel to water without ship." << endl;
            }
            if(map[rowdown][user.getcol()].isCity() == true){
                user.setrow(rowdown);
                for(int j = 0; j < cities.size(); j++){
                    if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                        user.addpoints(cities[j].getpoints());
                        user.addmoney(cities[j].getmoney());
                        user.addarmysize(cities[j].getarmysize());
                    }
                }
            }
            else if(map[rowdown][user.getcol()].isLand() == true){
                user.setrow(rowdown);
                user.addpoints(2);
                user.addmoney(20);
                user.addarmysize(10);
            }
        }
        else if(isoutofbounds(rowdown, user.getcol()) == true){
            cout << "You fell off the side of the map" << endl;
        }
    }
    else if(answer == "East" || answer == "east"){
        int colright = user.getcol() + 1;
        if(isoutofbounds(user.getrow(), colright) == false){
            if(map[user.getrow()][colright].isWater() == true && user.getship() == true){
                user.setcol(colright);
                user.addpoints(1);
                user.addmoney(10);
            }
            else if(map[user.getrow()][colright].isWater() == true && user.getship() == false){
                cout << "Cant travel to water without ship." << endl;
            }
            if(map[user.getrow()][colright].isCity() == true){
                user.setcol(colright);
                for(int j = 0; j < cities.size(); j++){
                    if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                        user.addpoints(cities[j].getpoints());
                        user.addmoney(cities[j].getmoney());
                        user.addarmysize(cities[j].getarmysize());
                    }
                }
            }
            else if(map[user.getrow()][colright].isLand() == true){
                user.setcol(colright);
                user.addpoints(2);
                user.addmoney(20);
                user.addarmysize(10);
            }
        }
        else if(isoutofbounds(user.getrow(), colright) == true){
            cout << "You fell off the side of the map" << endl;
        }
    }
    else if(answer == "West" || answer == "west"){
        int colleft = user.getcol() - 1;
        if(isoutofbounds(user.getrow(), colleft) == false){
            if(map[user.getrow()][colleft].isWater() == true && user.getship() == true){
                user.setcol(colleft);
                user.addpoints(1);
                user.addmoney(10);
            }
            else if(map[user.getrow()][colleft].isWater() == true && user.getship() == false){
                cout << "Cant travel to water without ship." << endl;
            }
            if(map[user.getrow()][colleft].isCity() == true){
                user.setcol(colleft);
                for(int j = 0; j < cities.size(); j++){
                    if(map[user.getrow()][user.getcol()].getLetter() == cities[j].getletter()){
                        user.addpoints(cities[j].getpoints());
                        user.addmoney(cities[j].getmoney());
                        user.addarmysize(cities[j].getarmysize());
                    }
                }
            }
            else if(map[user.getrow()][colleft].isLand() == true){
                user.setcol(colleft);
                user.addpoints(2);
                user.addmoney(20);
                user.addarmysize(10);
            }
        }
        else if(isoutofbounds(user.getrow(), colleft) == true){
            cout << "You fell off the side of the map" << endl;
        }
    }
    findfreewar(user.getrow(), user.getcol());
}


void Game::updateotherheroes(){
    for(int i = 0; i < heroes.size(); i++){
        int num = randommove();
        if(user.getname() == heroes[i].getname()){
            continue;
        }
        else{
            if(num = 1){ // north
                int rowup = heroes[i].getrow() - 1;
                if(isoutofbounds(rowup, heroes[i].getcol()) == false){
                    if(map[rowup][heroes[i].getcol()].isWater() == true && heroes[i].getship() == true){
                        heroes[i].setrow(rowup);
                        heroes[i].addpoints(1);
                        heroes[i].addmoney(10);
                    }
                    else if(map[rowup][heroes[i].getcol()].isWater() == true && heroes[i].getship() == false){
                    }
                    if(map[rowup][heroes[i].getcol()].isCity() == true){
                        heroes[i].setrow(rowup);
                        for(int j = 0; j < cities.size(); j++){
                            if(map[rowup][heroes[i].getcol()].getLetter() == cities[j].getletter()){
                                heroes[i].addpoints(cities[j].getpoints());
                                heroes[i].addmoney(cities[j].getmoney());
                                heroes[i].addarmysize(cities[j].getarmysize());
                            }
                        }
                    }
                    else if(map[rowup][heroes[i].getcol()].isLand() == true){
                        heroes[i].setrow(rowup);
                        heroes[i].addpoints(2);
                        heroes[i].addmoney(20);
                        heroes[i].addarmysize(10);
                    }
                }
            }
            else if(num = 2){ // south
                int rowdown = heroes[i].getrow() + 1;
                if(isoutofbounds(rowdown, heroes[i].getcol()) == false){
                    if(map[rowdown][heroes[i].getcol()].isWater() == true && heroes[i].getship() == true){
                        heroes[i].setrow(rowdown);
                        heroes[i].addpoints(1);
                        heroes[i].addmoney(10);
                    }
                    else if(map[rowdown][heroes[i].getcol()].isWater() == true && heroes[i].getship() == false){
                    }
                    if(map[rowdown][heroes[i].getcol()].isCity() == true){
                        heroes[i].setrow(rowdown);
                        for(int j = 0; j < cities.size(); j++){
                            if(map[heroes[i].getrow()][heroes[i].getcol()].getLetter() == cities[j].getletter()){
                                heroes[i].addpoints(cities[j].getpoints());
                                heroes[i].addmoney(cities[j].getmoney());
                                heroes[i].addarmysize(cities[j].getarmysize());
                            }
                        }
                    }
                    else if(map[rowdown][heroes[i].getcol()].isLand() == true){
                        heroes[i].setrow(rowdown);
                        heroes[i].addpoints(2);
                        heroes[i].addmoney(20);
                        heroes[i].addarmysize(10);
                    }
                }
            }
            else if(num = 3){ // east
                int colright = heroes[i].getcol() + 1;
                if(isoutofbounds(heroes[i].getrow(), colright) == false){
                    if(map[heroes[i].getrow()][colright].isWater() == true && heroes[i].getship() == true){
                        heroes[i].setcol(colright);
                        heroes[i].addpoints(1);
                        heroes[i].addmoney(10);
                    }
                    else if(map[heroes[i].getrow()][colright].isWater() == true && heroes[i].getship() == false){
                        
                    }
                    if(map[heroes[i].getrow()][colright].isCity() == true){
                        heroes[i].setcol(colright);
                        for(int j = 0; j < cities.size(); j++){
                            if(map[heroes[i].getrow()][heroes[i].getcol()].getLetter() == cities[j].getletter()){
                                heroes[i].addpoints(cities[j].getpoints());
                                heroes[i].addmoney(cities[j].getmoney());
                                heroes[i].addarmysize(cities[j].getarmysize());
                            }
                        }
                    }
                    else if(map[heroes[i].getrow()][colright].isLand() == true){
                        heroes[i].setcol(colright);
                        heroes[i].addpoints(2);
                        heroes[i].addmoney(20);
                        heroes[i].addarmysize(10);
                    }
                }
            }
            else if(num = 4){ // west
                int colleft = heroes[i].getcol() - 1;
                if(isoutofbounds(heroes[i].getrow(), colleft) == false){
                    if(map[heroes[i].getrow()][colleft].isWater() == true && heroes[i].getship() == true){
                        heroes[i].setcol(colleft);
                        heroes[i].addpoints(1);
                        heroes[i].addmoney(10);
                    }
                    else if(map[heroes[i].getrow()][colleft].isWater() == true && heroes[i].getship() == false){
                        cout << "Cant travel to water without ship." << endl;
                    }
                    if(map[heroes[i].getrow()][colleft].isCity() == true){
                        heroes[i].setcol(colleft);
                        for(int j = 0; j < cities.size(); j++){
                            if(map[heroes[i].getrow()][heroes[i].getcol()].getLetter() == cities[j].getletter()){
                                heroes[i].addpoints(cities[j].getpoints());
                                heroes[i].addmoney(cities[j].getmoney());
                                heroes[i].addarmysize(cities[j].getarmysize());
                            }
                        }
                    }
                    else if(map[heroes[i].getrow()][colleft].isLand() == true){
                        heroes[i].setcol(colleft);
                        heroes[i].addpoints(2);
                        heroes[i].addmoney(20);
                        heroes[i].addarmysize(10);
                    }
                }
            }
        }
    }
    cout << "All other heroes updated." << endl;
}

bool Game::rest(){
    //run code for when user deciedes to rest for their turn
    //
    //update resources based on this action 
    for(int i = 0; i < user.getvectorsize(); i++){
        user.getwarrior(i).addstrength(1);
    }
}

bool Game::consult(){
    //run code for if user decides
    for(int i = 0; i < user.getvectorsize(); i++){
        user.getwarrior(i).addmorale(1);
    }
}

int Game::randommove(){
    //calculate a random direction for the user to move if they choose travel
    srand (time(NULL));
    int num = rand() % 4 + 1;
    return num;
}

bool Game::givespeech(int num){
    //run code for if the user chooses to to give a speech during an encounter
    double probability = (1.0-(double(heroes[num].getwarrior(0).getmorale())/100.0)* (user.getinfluence()/1600.0));
    probability = probability * 100;
    cout << probability << endl;
    srand (time(NULL));
    int poss = rand() % 99 + 1;
    if(poss < probability || poss == 1){ // user wins
        cout << heroes[num].getname() << " has retired." << endl;
        for(int i = 0; i < heroes[num].getvectorsize(); i++){
            if(user.getvectorsize() < 4){
                user.addwarrior(heroes[num].getwarrior(i));
            }
        }
        user.addmoney(heroes[num].getmoney());
        user.addinfluence(heroes[num].getinfluence());
        user.addarmysize(heroes[num].getarmysize());
    }
    else if(poss > probability || poss == 0){ // user loses
        user.setinfluence(user.getinfluence() / 2);
    }
    
}

bool Game::buyout(int num){
    //run code for if user chooses to buyout in an encounter
    double probability = (1.0-(double(heroes[num].getwarrior(0).getloyalty())/100.0)* (user.getmoney()/17800.0));
    probability = probability * 100;
    cout << probability << endl;
    srand (time(NULL));
    int poss = rand() % 99 + 1;
    if(poss < probability || poss == 1){ // user wins
        cout << heroes[num].getname() << " has retired." << endl;
        for(int i = 0; i < heroes[num].getvectorsize(); i++){
            if(user.getvectorsize() < 4){
                user.addwarrior(heroes[num].getwarrior(i));
            }
        }
        user.addmoney(heroes[num].getmoney());
        user.addinfluence(heroes[num].getinfluence());
        user.addarmysize(heroes[num].getarmysize());
    }
    else if(poss > probability || poss == 0){ // user loses
        user.setmoney(user.getmoney() / 2);
    }
}

bool Game::battle(int num){
    //run code for if user chooses to battle in an encounter
    int cpu = 4;
    srand (time(NULL));
    int userbattlevalue = 0;
    int cpubattlevalue = 0;
    int size = 0;
    if((user.getvectorsize() == 0 && heroes[num].getvectorsize() > 0) || (user.getvectorsize() > 0 && heroes[num].getvectorsize() == 0)){ // one of the heros has no warriors
        if(heroes[num].getvectorsize() == 0){
            cout << heroes[num].getname() << " has retired." << endl;
            for(int i = 0; i < heroes[num].getvectorsize(); i++){
                if(user.getvectorsize() < 4){
                    user.addwarrior(heroes[num].getwarrior(i));
                }
            }
        user.addmoney(heroes[num].getmoney());
        user.addinfluence(heroes[num].getinfluence());
        user.addarmysize(heroes[num].getarmysize());
        }
        else if(user.getvectorsize() == 0){
            cout << "You have died in the battle" << endl;
            setgameover(true);
        }
    }
    else if(user.getvectorsize() > 0 && heroes[num].getvectorsize() > 0){ //both heros have warriors
        cout << "Please choose a warrior to represent you in battle(Answer in #):" << endl;
        for(int i = 1; i <= user.getvectorsize(); i++){
            cout << i << ": " << user.getwarrior(i - 1).getname() << endl;
        }
        int answer;
        cin >> answer;
        size = heroes[num].getvectorsize();
        while(cpu >= size){
            cpu = rand() % 4;
        }
        userbattlevalue = (user.getarmysize() * user.getwarrior(answer - 1).getstrength());
        cpubattlevalue = (heroes[num].getarmysize() * heroes[num].getwarrior(cpu).getstrength());
        if(userbattlevalue > cpubattlevalue){ // user wins
            cout << heroes[num].getname() << " has retired." << endl;
            for(int i = 0; i < heroes[num].getvectorsize(); i++){
                if(user.getvectorsize() < 4){
                    user.addwarrior(heroes[num].getwarrior(i));
                }
            }
            user.addmoney(heroes[num].getmoney());
            user.addinfluence(heroes[num].getinfluence());
            user.addarmysize(heroes[num].getarmysize());
        }
        else if(userbattlevalue < cpubattlevalue){ // user loses
            cout << "You have died in the battle" << endl;
            setgameover(true);
        }
    }
}

bool Game::gainwarrior(){
    //add warrior to vector of warriors for hero
}

bool Game::getgameover(){
    return gameover;
}

void Game::setgameover(bool end){
    gameover = end;
}

void Game::findfreewar(int row, int col){
    bool flag = false;
    int idx = 0;
    for(int i = 0; i < warriors1.size(); i++){
        if(abs(col - warriors1[i].getcol()) < 3 && abs(row - warriors1[i].getrow()) < 3){
            flag = true;
            idx = i;
        }
    }
    if(flag == true){
        if(user.getvectorsize() < 4){
            user.addwarrior(warriors1[idx]);
            cout << "You have added a new warrior, " << warriors1[idx].getname() << endl;
            warriors1[idx].addmorale(10);
        }
    }
    
    
}


int Game::generaterow(){
    srand (time(NULL));
    int num = rand() % 26;
    return num;
    
}

int Game::generatecol(){
    srand (time(NULL));
    int num = rand() % 17;
    return num;
}

void Game::initiatedg(){
    int count = 0;
    while(count < 5){ //place 5 random dragonglass
        int r = generaterow();
        int c = generatecol();
        if(map[r][c].getLetter() != "w"){
            map[r][c].setdragonglass(true);
            count ++;
        }
    }
}


void Game::setwarriors(){
    bool flag;
    for(int i = 0; i < warriors1.size(); i++){
        flag = false;
        while(flag == false){
            int r = generaterow();
            int c = generatecol();
            if(warriors1[i].getisfree() == true && warriors1[i].getship() == true){
                if(map[r][c].getLetter() == "w"){
                    warriors1[i].setlocation(r,c);
                    flag = true;
                }
            }
            else if(warriors1[i].getisfree() == true && warriors1[i].getship() == false){
                if(map[r][c].getLetter() == "p"){
                    warriors1[i].setlocation(r,c);
                    flag = true;
                }
            }
            else if(warriors1[i].getisfree() == false){
                flag = true;
            }
        }
    }
    return;
}

bool Game::isoutofbounds(int row, int col){
    if((row < 1 || row > 25) || (col < 1 || col > 16)){
        return true;  
    }
    else{
        return false;
    }
}

void Game::randomevents(){
    srand (time(NULL));
    int num = rand() % 120;
    if(num >= 0 && num < 30){ //drought
        for(int i = 0; i < user.getvectorsize(); i++){
            user.getwarrior(i).setmorale(user.getwarrior(i).getmorale() - 10);
            user.getwarrior(i).setstrength(user.getwarrior(i).getstrength() - 10);
        }
    }
    else if(num >= 30 && num < 60){ // deserters
        user.setarmysize(user.getarmysize() - 10);
        for(int i = 0; i < user.getvectorsize(); i++){
            user.getwarrior(i).setloyalty(user.getwarrior(i).getloyalty() - 10);
        }
    }
    else if(num >= 60 && num < 90){ // jackpot
        user.setmoney(user.getmoney() * 2);
    }
    else if(num >= 90 && num < 120){ // kindness
        user.addarmysize(10);
        for(int i = 0; i < user.getvectorsize(); i++){
            user.getwarrior(i).addloyalty(10);
        }
    }
    
    
}

void Game::adddragon(){
    for(int i = 0; i < heroes.size(); i++){
        if (heroes[i].getname() == "Daenerys Targaryen"){
            if(heroes[i].getvectorsize() == 4){
                heroes[i].removewarrior();
                heroes[i].addwarrior(Warrior("Dragon", int(180 * 1.10), int(100 *1.10) , int(80 * 1.10), false, false, false));
                
               
            }
            else{
                heroes[i].addwarrior(Warrior("Dragon", 180, 100, 80, false, false, false));
            }
        }
    }
}
       
void Game::stannis(){
    for(int i = 0; i < heroes.size(); i++){
        if (heroes[i].getname() == "Stannis Baratheon"){
            for(int j = 0; j < heroes[i].getvectorsize(); i++){
                heroes[i].getwarrior(j).setisfree(true);
            }
            heroes.erase(heroes.begin() + i);
        }
    }
    cout << "Stannis has retired. Press F to pay respects." << endl;
    string word;
    cin>> word;
    if(word != "F" || word != "f"){
       cout <<  "Have you no respect?! Press F to pay respects." << endl;
    }
    
}
        
void Game::sansa(){
    for(int i = 0; i < heroes.size(); i++){
        if(heroes[i].getname() == "Sansa Stark"){
            heroes[i].addwarrior(Warrior("Arya Stark", 200, 100, 60, true, false, false));
        }
    }
}
        
void Game::cersei(){
    for(int i = 0; i < heroes.size(); i++){
        if(heroes[i].getname() == "Cersei Lannister"){
            heroes[i].erasewarrior("Jaime Lannister");
        }
    }
}
       
void Game::mandatory(){
    adddragon();
    stannis();
    sansa();
    cersei();
}