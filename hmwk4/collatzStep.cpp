// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 2

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Calculate new value based on even or odd
//1. Take input from function
//2. Test if number is even or odd
//3. if even, return number divided by 2
//4. If odd, return 3 times the number minus 1
//5. If number is less than 0, return 0



int collatzStep(int num){
    if (num % 2 == 0){ // test if number is even
        return num / 2; 
        }
    else 
        if(num % 2 == 1){ // test if number is odd
            return (3*num) + 1; // return 3 times the number plus 1
        }
    else 
        if(num < 0){ // test if number is less than 0
            return 0;
    }
}

int main(){
    
    //test case 1
    //expected output: 0
    cout << collatzStep(-15)<< endl;
    
    //test case 2
    //expected output: 13
    cout << collatzStep(26) << endl;
}