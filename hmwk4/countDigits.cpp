// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 5

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Count  the amount of digits in an inputed number
//1. Take inputs from function
//2. Test whether the number is between 1-9, 10,99, or 100-999
//3. return number of digits to main

int countDigits(int num){
    if (num < 0){ // test if number is less than 0
        num *= -1; // multiply to make positive
        if (num >0 && num < 10){ // test if number is between 1-9
            return 1;
        }
        else 
            if(num >= 10 && num < 100){ // test if number is between 10-99
                return 2;
            }
        else 
            if(num < 1000){ // test if number is implied 100 and 999
                return 3;
                }
            }

    if (num > 0){ // test if number is greater than 0
        if (num >0 && num < 10){ // test if number is between 1-9
        return 1;
            }
    else 
        if(num >= 10 && num < 100){ // test if number is between 10-99
            return 2;
            }
    else 
        if(num >= 100 && num < 1000 ){ // test if number is implied 100 and 999
            return 3;
                
            }
        }
        
    else{ // else just return -1(fail)
        return -1;
    }        
        

}


int main(){
    
    // test case 1
    // expected output: 3
    cout<< countDigits(-1453) << endl;
    
    //test case 2:
    // exoected output: 2
    cout<< countDigits(25) << endl;
}