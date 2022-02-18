// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Homework 5- Question 1 

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
using namespace std; 

//Algorithm: get amount of digits in a string
//1. test if the index contains a number
//2. Add to counter every time they find a digit
//input: string word - the string to analyze
//return: count- amount of digits in the string

int getDigitCount(string word){
    int count = 0;
    
    for (int i = 0; i < word.length(); i++){
        if (isdigit(word[i])){ //  test if the index of the string is a digit
            count++;
        }
    }
    return count; //return total number of 
}

int main(){
   
   //test case 1
   //expected output: 2
   cout<< getDigitCount("sdf23")<< endl;
   
   //test case 2
   //expected output: 3
   cout<< getDigitCount("dsfg343j")<< endl;
}