// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 9

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Calculate Fahrenheit from Celcius
//1. Take inout from function
//2. Plug into formula for celcius
//3. Output new temperature in Fahrenheit




void celsiusToFahrenheit(int celcius){
    
    double fahrenheit = (1.8 * celcius) + 32;//calculate fahrenheit
    
    cout << "The temperature of " << celcius << " in Fahrenheit is " << fixed << setprecision(2) << fahrenheit << endl; //output 
    
}


int main(){
    
    //test case 1
    //expected output: The temperature of 40 in Fahrenheit is 104.00
    celsiusToFahrenheit(40);
    
    //test case 2 
    //expected output: The temperature of 50 in Fahrenheit is 122.00
    celsiusToFahrenheit(50);
}