// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 1

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Check if number is negative or positive
//1. Take input
//2. Check if number is less than or greater than zero
//3. If less than, print negative
//4. If greater than, print positive
//5. If 0, print zero

void numberSign(int num){
    if (num < 0){   // test if less than 0
        cout << "negative" << endl;
        }
    else 
        if(num > 0){ // test if greater than 0
            cout << "positive" << endl;
        }
    else
        if (num == 0){ // test if number is 0
            cout << "zero" << endl;
        }
    
}

int main(){
    
    //test case 1
    //expected output: positive
    numberSign(7);
    
    //test case 2
    //expected output: negative
    numberSign(-45);
}