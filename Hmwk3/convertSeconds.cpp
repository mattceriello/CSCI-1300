// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 7

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: Convert secinds into hours, minutes, ansd seconds
//1. take input of function
//2. calculate hours
//3. subract amount of hours in seconds from initial
//4. calculate minutes with whats left
//5. subtracts minutes in seconds from whats left
//6. seconds are whats left from initial seconds
//7. Output in formaat: hours, minutes, seconds

void convertSeconds(int seconds_input){
    
    int hours = seconds_input / 3600;//calculate hours
    
    seconds_input -= hours*3600;//subtract hours in seconds
    
    int minutes = seconds_input/60;//calculate seconds 
    
    seconds_input -= minutes*60;//subtracts minutes in seconds from whats left
    
    int seconds = seconds_input; //seconds are whats left from input
    
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s) "<< endl;//output
}



int main(){
    
    //test case 1
    //expected output: 1 hour(s) 6 minute(s) 41 second(s) 
    convertSeconds(4001);
    
    //test case 2
    //expected output: 1 hour(s) 23 minute(s) 45 second(s) 
    convertSeconds(5025);
    
}