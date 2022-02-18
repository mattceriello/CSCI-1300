// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 7

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Check  if inputed year is a lear year
//1. Take inputs from function
//2. First test if year is before 1582
//3. then test if funtion is divisible by 4 or 400
//4. If divisible by 400 or 4, return true
//5. If not, return false 

bool checkLeapYear(int year){
    if (year > 1582){ // check if year is greater than 1582
    
        if (year % 400 == 0){ // test if number is divisible by 400
            return true;
        }
        if (year % 4 == 0 && year % 100 != 0){ // test if number is divisible by 4 and year is not divisible by 100
            return true;
        }
    
    
        if (year % 400 > 0){ // test if year isn't divisible by 400
            return false;
        }
    
    }
    if (year < 1582){ // test if year is less than 1582
        if (year % 4 == 0){ // test if year is divisible by 4
            return true;
        }
        if (year % 4 > 0){ // test is year is not divisble by 4
            return false;
        }
    }
    
    
    
}

int main(){
    
    // test case 1
    // expected output: 0
    cout << checkLeapYear(1700)<< endl;
    
    // test case 2
    // expected output: 0
    cout<< checkLeapYear(1957) << endl;
    
}