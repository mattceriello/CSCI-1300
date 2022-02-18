// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 6

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: Calculate surface area of a sphere
//1. take input of function
//2. plug into equation of surface area
//3. Print surface area


double sphereSurfaceArea(double radius){
    
    double surface_area; //initialize variable
    surface_area = 4 * 3.14159265359 * pow(radius,2); //do calculations of surface area
    cout << "surface area: " << surface_area << endl; //output surface area
    
    
}



int main(){
    
    
    //test case 1
    //expected output: surface area: 201.062
    sphereSurfaceArea(4);
    
    //test case 2
    //expected output: surface area: 1017.88
    sphereSurfaceArea(9);
    
}