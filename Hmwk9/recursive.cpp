#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
using namespace std;


//Algorith: Input an integer and calculate its binary value using binary rules and recursion
//1. Use recursion to loop through number until binary is returned in 0 or 1
//input: int - number
//return: string str
string decimalToBinaryRecursive(int number){
    int binary = 0;
    if (number == 0){
        binary = 0;
    }
    else{
        binary = number % 2 + 10 * stoi((decimalToBinaryRecursive(number/ 2))); // do calculations and re-call the function
    }
    return to_string(binary);
}




int main(){
    
    //test case 1
    //expected output: 1000110110
    cout << decimalToBinaryRecursive(566) << endl;
    
    //test case 2
    //expected output: 10111
    cout << decimalToBinaryRecursive(23);
}