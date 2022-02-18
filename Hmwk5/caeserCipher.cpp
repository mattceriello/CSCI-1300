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

//Algorithm: Decipher a string based on the constant shift given
//1. Check if the key is out of range
//2. decide whether we are encrypting or decrypting the string
//3. take the ascii value of the index of the string and the key ascii and 
//   add to a new string
//4. return the word
//input: message - string to manipulate, key - how much to shift the alphabet, 
//       flag -  whether to encrypt or decrypt the messagr


string caesarCipher(string message, int key, bool flag){
    if(key < 0 || key > 25){ // test if key is in range
        return "ERROR";
    }
    if (flag == true){ // test if encrypting
        string newWord;
        for (int i = 0; i < message.length(); i++){
            if(int(message[i]) + key > 90){ // check if ascii value of string + key is in the alphabet
                newWord += char(int(message[i]) + key - 26); // add the new character to the new string
            }
            else if (int(message[i]) == 32){ // check of index is a space
                newWord += message[i]; 
            }
            else{
                newWord += char(int(message[i]) + key); //  add character to new string
            }
        }
        return newWord;    
    }
    
    if (flag == false){ // test if decrypting
        string newWord;
        for (int i = 0; i < message.length(); i++){
            if(int(message[i]) == 32){ // test if space
                newWord += message[i];
            }
            else if(int(message[i]) - key < 65){ // test if ascii value is out of aplhabet
                newWord += char(int(message[i]) - key + 26); // add 26 to brinf ascii value to alphabet
            }
            
            else {
                newWord += char(int(message[i]) - key); // add character to string
            }
        }
        return newWord;
    }
}


int main(){
    
    // test case 1
    //expected ouput: GRKD EZ MYWZ CMS
    cout << caesarCipher("WHAT UP COMP SCI", 10, true)<< endl;
    
    // test case 2
    // expected output: ITAZIV IZIT
    cout << caesarCipher("SDKJSF SJSD", 10, false)<< endl;
}    