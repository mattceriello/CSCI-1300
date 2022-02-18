// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 0123 – yourTAname
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Project1 - Problem 1



#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

//Algorithm:
//1. Use a for loop to loop through numbers 0 to the input
//2. calculate if number is odd
//3. If so, print that number
//input- int max -  maximum number to loop through
//returns - none

void printOddNums(int max){
    for (int i = 0; i <= max; i++){// for loop for numbers 0 to the input
        if(i % 2 == 1){// calculate if odd
            cout << i << endl;
        } 
    }
}



int main(){
    
    //test case 1
    // expected output:1,3,5,7,9,11,13
    printOddNums(13);
    
    //test case 2
    //expected output: 1,3,5
    printOddNums(6);
}