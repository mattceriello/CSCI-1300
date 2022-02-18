#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
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
int readRatings(string filename, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
    if(numUsers == maxRows){
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        int row = numUsers;
        string line = "";
        string linearr[maxColumns + 1]; // create line array
        
        while(getline(file,line)){
            if(line.length() == 0) continue;
            split(line, ',', linearr, maxColumns + 1); //split line
            if(maxRows == row){
                break;
            }
            
            users[row] = linearr[0]; // store username in array
            int irating = 0;
            for(int col = 1; col <= 50; col++){ //loop through rating array and store rating from line array
                if(linearr[col] != ""){
                    string rate = linearr[col];
                    ratings[row][irating] = stoi(rate);// convert to int and store
                    
                    irating++;
                }
            }
            
           
            row++; // count amount of users
        }
        
        
        //printArray2d(ratings,row);   
        file.close();
        return row;
    }
    else{
        return -1;
    }
    
}

int main(){
    
    //test case 1
    //expected ouput: 10
    
    string users[10] = {};
    int ratings[10][50] = {{0}};
    int numUsers = 0;
    int maxRows = 10;
    int maxColumns = 50;
    cout << readRatings("test.txt", users, ratings, numUsers, maxRows, maxColumns) << endl;
}