// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 0123 – yourTAname
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Project1 

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
using namespace std; 



int split(string input, char delimiter){
    int count = 0;
    int temp = 0;
    
    if (input[0] = delimiter){
        for (int i = 0; i < input.length(); i++){
            if (input[i] == delimiter){
                count++;
                if (i != 0){
                    cout << input.substr(temp + 1, i);
                    cout<<" "<< endl;
                }
               
                temp = i;
            }
        }
    }
    
    
    bool first = true;
        
    for (int i = 0; i < input.length(); i++){
        while (first == true){
            if (input[i] == delimiter){
                cout << input.substr(0,i - 1);
            }
        }   
    }
        
    
    
    
    //for (int i = 0; i < input.length(); i++){
        //if (input[i] = delimiter){
            
        //}
    //}
    return count;
}

int main(){
    int x = split(" one small step ", ' ');
}