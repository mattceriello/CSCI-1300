// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong 

// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Project1 

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
using namespace std; 

//Algorithm: Tally up the amount of words in a given string
//1. Start by testing if the string is null
//2. test if the index of the string is a space
//3. return the amount of words

int getWordCount(string word){
    if (word == ""){ // test if the string is null
        return 0;
    }
    int count = 0;
    for(int i = 0; i < word.length(); i++){
        if (word[i] == ' '){ // test if the index is a space
            count++;
        }
    }
    return count + 1; 
}

int main(){
    
    //test case 1
    //expected output: 2
    cout << getWordCount("I like Basketball")<< endl;
    
    //test case 2
    //expected output: 3
    cout << getWordCount("I like Basketball")<< endl;
}