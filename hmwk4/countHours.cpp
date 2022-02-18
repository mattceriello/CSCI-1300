// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 6

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Calculate hours in a selected month 
//1. Take inputs from function
//2. Muliply 24 hours by the amount of days in eavch month
//3. return total hours 

int countHours(int month){
    switch (month){ // test which month was inputed
        case 1: // tests for january
            return 31 * 24; // multuplies 31 days by 24 hours
            break;
        
        case 2: //tests for february 
            return 28 * 24; // mulitplies 28 days by 24 hours
            break;
       
        case 3: // tests for march
            return 31 * 24; //  multiplies 31 days by 24 hours
            break;
        
        case 4: //  tests for april
            return 30 * 24; // multiplies 30 days by 24 hours 
            break;
        
        case 5: // tests for may 
            return 31 * 24; // multiplies 31 days by 24 hours
            break;
        
        case 6: // tests for june   
            return 30 * 24; // multiplies 30 days by 24 hours 
            break;
        
        case 7: //tests for july 
            return 31 * 24; // multiplies 31 days by 24 hours 
            break;
        
        case 8: // tests for august 
            return 31 * 24; // multiplies 31 days by 24 hours
            break;
        
        case 9: //tests for september
            return 30 * 24; // multiplies 30 days by 24 hours
            break; 
        
        case 10:// tests for october
            return 31 * 24; // multiplies 31 days by 24 hours
            break;
        
        case 11: //tests for november 
            return 30 * 24; // multiplies 30 days by 24 hours
        
        case 12: // tests for december 
            return 31 * 24; // multiplies 31 days by 24 hours
            break;
            
    }
}

int main(){
    
    //test case 1
    //expected output: 672
    cout << countHours(2)<< endl;
    
    // test case 2
    // expected output: 744
    cout << countHours(5);
}