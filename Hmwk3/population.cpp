// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 8

#include <iostream>
#include <math.h>
using namespace std;

//Algorithm: Calculate new pooulation 
//1. take input of function
//2. Calulate births per year
//3. Calculate new immigrants per year
//4. Calculate deaths per year
//5. Calculate new population: Add births and immigrants and subtract deaths all from initial pop

int population(int initial_population){
    
    int seconds_in_year = 31536000; // seconds in year
    
    int births = seconds_in_year/8; // births per year
    
    int deaths = seconds_in_year /12; //deaths per year
    
    int immigrant = seconds_in_year/27; // immigrants per year
    
    return (initial_population + births + immigrant) - deaths; // calculate new population
    
}

int main(){
    
    //test case 1
    //expected output: 3842000
    cout<< population(1360000) << endl;
    
    //test case 2
    //expected output: 4482000
    cout<< population(2000000) << endl;
    
}