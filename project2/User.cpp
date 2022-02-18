#include "User.h"
#include <iostream>
#include <cmath>
using namespace std;

//Algorithm: Default constructor
//1. sets username to null
//2. sets numRatings to 0
//3. sets size to 50
//4. sets ratings array elemts to 0
User::User(){
    
    username = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < size; i++){
        ratings[i] = 0;
    }
    
}

//Algorithm: Parameterized constructor
//1. sets username to inputed username
//2. sets numRatings to inputed numRatings
//3. sets ratings array elemts to inputed array
User::User(string _username, int newarr[50], int _numRatings){
    username = _username;
    numRatings = _numRatings;
    
    for (int i = 0; i < 50; i++){
        if(i < numRatings){
            ratings[i] = newarr[i];
        }
        else{
            ratings[i] = 0;
        }
    }
        
    
}


//Algorithm: Get Username 
//1. return username

string User::getUsername(){
    return username;
}

//Algorithm: set username
//1. set username to inputed string
//input: string a
void User::setUsername(string a){
    username = a;
}

//Algorithm: Get rating at specific index
//1. return rating at inputed index
//input: int index
int User::getRatingAt(int i){
    if (i < 50){
        return ratings[i];
    }
    else{
        return -1;
    }
    
    
}


//Algorithm: set rating at specific index
//1. test if index is in array and value is between 0-5
//2. if so, set new element
//3. return true or false
//input: int index, int value
//return: true or false
bool User::setRatingAt(int index, int value){
    if ((index >= 0 && index < size) && (value >= 0 && value <= 5)){ //test if index is in bounds and value between 1-5
        ratings[index] = value;
        return true;
    }
    else {
        return false;
    }
    
}

//Algorithm: get number of ratings
//1. return numRatings
int User::getNumRatings(){
    return numRatings;
}

//Algorithm: set number of ratings
//1. set numRatings to _numrating
void User::setNumRatings(int _numrating){
    numRatings = _numrating;
}

//Algorithm: get size
//1. return size
int User::getSize(){
    return size;
}

