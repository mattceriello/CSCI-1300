#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include "User.h"
#include "User.cpp"
using namespace std;



int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {//test if string length is 0
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;// add delimiter to end
    for (int i = 0; i < str.length(); i++) //loop through string
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            
            words[k] = word;//add part of string to array 
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];// add characters to temp string
        }
    }
    return j;
    
}


//Algorithm: Read in the ratings from a file
//1. read file using file i/o
//2. for each line, add first elememt to username, and all ratings to ratings array
//3. create a user object at each line for each user
//4. return the total number of users
//input: string filename, user object array, int number of users atored, int user array size, int max col
int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol){
    if(numUsersStored == usersArrSize){
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[maxCol + 1];
        string username;
        while(getline(file,line)){
            int ratings[50];
            if(line.length() == 0) continue;
            split(line, ',', linearr, maxCol + 1);
            if(numUsersStored == usersArrSize){
                break;
            }
            username = linearr[0]; // first element in line array is username
            for(int col = 1; col <= 50; col++){ // loop through the rest of the line 
                if (linearr[col] != ""){
                    string rate = linearr[col]; 
                    ratings[col - 1] = stoi(rate); // add rate to ratings array
                }
            }
            users[numUsersStored] = User(username,ratings, 50); // create user object for that line
            numUsersStored++;
        }
        file.close();
        return numUsersStored;
    }
    else{
        return -1;
    }
}

int main(){
    
    //test case 1
    //expected output: Cynthia
    
    User users[10] = {};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    numUsers = readRatings("ratings.txt", users,numUsers, maxRows, maxColumns);
    cout << users[0].getUsername()<<endl;


    //test case 2
    //expected output: 4
    cout << users[0].getRatingAt(0);
}