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
//1.
//2.
//3. 
//input: int - number
//return: string str
string decimalToBinaryRecursive(int number){
    int binary = 0;
    if (number == 0){
        binary = 0;
    }
    else{
        binary = number % 2 + 10 * stoi((decimalToBinaryRecursive(number/ 2)));
   }
    return to_string(binary);
}




int main(){
    cout << decimalToBinaryRecursive(8);
}