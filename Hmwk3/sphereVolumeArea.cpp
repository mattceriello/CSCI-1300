// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 4

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl; //take Input
    double radius;
    cin >> radius;//input radius
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3); // calculate volume 
    cout << "volume: " << volume << endl; //ouput volume
    double surface_area; //initialize variable
    surface_area = 4 * 3.14159265359 * pow(radius,2); //do calculations of surface area
    cout << "surface area: " << surface_area << endl; //output surface area
   
}