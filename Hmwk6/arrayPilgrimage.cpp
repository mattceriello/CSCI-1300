// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: <304> – <Shudong Hao>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std; 

int main(){
    double temp[10]; 
    string colors[5];
    int sequence[100];
    char letters[52];
    for(int i = 0; i < 10; i++){// fill temp array with -459.67 10 times
        temp[i] = -459.67;
        cout << temp[i]<< endl;
    }
    
    cout << " " << endl;
    
    for(int j = 0; j < 5; j++){ // fill color array with 5 different colors
        if(j == 0){
            colors[j] = "Red";
        }
        else if(j == 1){
            colors[j] = "Blue";
        }
        else if(j == 2){
            colors[j] = "Green";
        }
        else if(j == 3){
            colors[j] = "Cyan";
        }
        else if(j == 4){
            colors[j] = "Magenta";
        }
        cout << colors[j] << endl;
    }
    
    cout << " " << endl;
    
    for(int k = 1; k <= 100; k++){ // fill sequence array with 100 numbers
        sequence[k] = k;
        cout << sequence[k] << endl;
    }
    
    cout << " " << endl;
    
    int ascii = 65;
    for(int l = 0; l <= 52 ; l+=2){ // fill letter array with upper and lowercase of each letter from ascii value
        letters[l] = char(ascii);
        ascii += 32;
        letters[l + 1] = char(ascii);
        ascii -= 31;
        
    }
    
    for(int l = 0; l < 52 ; l+=2){ // print letter array
       cout << letters[l] << " " << letters[l+ 1] << endl;
        
    }
   
}


