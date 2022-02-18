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


void vigenereCipher(string message, string key, bool flag){
    if(flag == true){
        if (message[0] < key[0]){
            string newWord;
            int shift = 0; 
            for (int i = 0; i < message.length(); i++){
                if(message[i] == 'Z')
                {
                    message[i]='A';
                }
                
                shift = int(key[i]) - int('A');
                newWord += char(int(message[i]) + shift);
                
            }
            cout<<newWord<< endl;
        }
        else if (message[0] > key[0]){
            string newWord;
            int shift = 0;
            for (int i = 0; i < message.length(); i++){
                
            }
        }
        
        
    }
    
    if(flag == false){
        
    }
    
    
}


int main(){
   vigenereCipher("BATMAN", "TIGER", true);
}