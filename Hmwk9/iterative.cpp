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


//Algorith: Input an integer and calculate its binary value using binary rules
//1.save the loop through the integers and save either 0 or 1 to an array
//2.save number as number / 2 
//3. save array of numbers to string and return the string
//input: int - number
//return: string str
string decimalToBinaryIterative(int number){
    if(number == 0){
        return to_string(number);
    }
    int a[10], i;    
    string str = "";
    for(i=0; number>0; i++){  // loop through each integer and add either 0 or 1 to the array  
        a[i]=number%2;    
        number = number/2;  
    }    
    
    for(i=i-1 ;i>=0 ;i--){    
        str +=  to_string(a[i]); //add all elements from the array to a singular string     
    }
   
    return str;

}

int main(){
    
    //test case 1
    //expected output: 1111101
    cout << decimalToBinaryIterative(125) << endl;
    
    //test case 2
    //expected output: 100010
    cout << decimalToBinaryIterative(34);
}