// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 3

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Check if 3 numbers are all equal to eachother
//1. Take inputs from function
//2. test if number 1 is equal to number 2 and number 1 is equal to number 3
//3. If all equal print all same
//3. if number 1 doesnt equal number 2 and 
//   number 1 doesnt equal number 3 and number 2 doesnt equal number 3, print all different
//4. else print neither

void checkEqual(int num1, int num2, int num3){
    if (num1 == num2 && num1 == num3){ // test if numbers are all the same 
        cout << "All same " << endl;
    }
    else 
        if (num1 != num2 && num1 != num3 && num2 != num3){ // test if numbers are all different
            
            cout << "All different" << endl;
            
        }
   
    else{ // if neither of the above tests are valid 
        cout << "Neither" << endl;
    }
}

int main(){
    
    //test case 1
    //expected output: all differnt
    checkEqual(1,2,3);
    
    //test case 2
    //expected output: neither
    checkEqual(3,4,4);
}