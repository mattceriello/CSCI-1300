// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 5

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: Calculates volume of a sphere
//1. Take input from function
//2. Plug into volume equation
//3. Print volume
//Parameters: radius double
//Output: Volume
//returns: Nothing

void sphereVolume(double radius){
    
   
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    
    cout<< "volume: " << volume<<endl;
    
    
}


int main(){
    
    //test case 1: 
    //expected output: volume: 904.779
    sphereVolume(6);
   
   //test case 2
   //expected output: volume: 7238.23
   sphereVolume(12);
   
}