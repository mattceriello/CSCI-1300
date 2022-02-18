#include "User.h"
#include "User.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


//split already commented
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
    return j;
}

//Algorithm: loop through file and store users and ratings in respective arrays
//1. use file i/o to access file
//2. use split to split up each line by commas
//3. store first index in user array
//4. store res of line in ratings array
//input: filename, user array, rating array, num of users, max rows, max columns
int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol){
    if(numUsersStored == usersArrSize){
        return -2;
    }
    int ratings[50];
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        //int row = numUsers;
        string username = "";
        string line = "";
        
        string linearr[maxCol + 1]; // create line array
        
        while(getline(file,line)){
            if(line.length() == 0) continue;
            split(line, ',', linearr, maxCol + 1); //split line
            if(usersArrSize == numUsersStored){
                break;
            }
            username = linearr[0];
            
            
            for (int j = 0; j < 50; j++){
                string rate = linearr[j + 1];
                //cout << rate;
                
                ratings[j] = stoi(rate);
            }
            cout << endl;
            //users[numUsersStored] = User(username,ratings, 100); // store username in array
            numUsersStored++; // count amount of users
        }
        
        
          
        file.close();
        return numUsersStored;
    }
    else{
        return -1;
    }
    
}

int main(){
    
    User users[10];
    
    int numUsersStored = 0;
    int usersArrSize = 10;
    cout << readRatings("ratings.txt", users, numUsersStored, usersArrSize, 50);
}