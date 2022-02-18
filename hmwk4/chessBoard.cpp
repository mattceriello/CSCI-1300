// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 4 - Problem 4

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Algorithm: Check if a square on a chess board is dark or light
//1. Take inputs from function
//2. Test if dark or light by the character and number combination
//3. Print white or black based on tests

void chessBoard(char letter, int num){
    if (letter == 'a'){ // test if character is a
        if (num % 2 == 1){ // test if number is odd
            cout << "black" << endl;
        }
        else 
            if (num % 2 == 0){ //  test if number is even
                cout << "white" << endl;
            }
        }
    
    else 
        if(letter == 'b'){ // test if character is b
            if (num % 2 == 1){ // test if number is odd
                cout << "white" << endl;
            }
            else 
                if (num %2 == 0){ //  test if number is even
                    cout << "black" << endl;
                }
        }
    
    else
        if(letter == 'c'){  // test if character is c
            if (num % 2 == 1){ // test if number is odd
                cout << "black" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "white" << endl;
                }
        }
    
    else
        if(letter == 'd'){   // test if character is d
            if (num % 2 == 1){  // test if number is odd
                cout << "white" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "black" << endl;
                }
        }
    
    else
        if(letter == 'e'){   // test if character is e
            if (num % 2 == 1){  // test if number is odd
                cout << "black" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "white" << endl;
                }
        }    
    
    
    else
        if(letter == 'f'){ // test if character is f
            if (num % 2 == 1){  // test if number is odd
                cout << "white" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "black" << endl;
                }
        }
    
    else
        if(letter == 'g'){ // test if character is g
            if (num % 2 == 1){  // test if number is odd
                cout << "black" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "white" << endl;
                }
        }

    else
        if(letter == 'h'){ // test if character is h
            if (num % 2 == 1){  // test if number is odd
                cout << "white" << endl;
            }
            else
                if (num % 2 == 0){ //  test if number is even
                    cout << "black" << endl;
                }
        }
    
    else{ // if character isnt a-h and number isnt 1-8
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8 "<< endl;
    }
    
    
}


int main(){
    
    //test case 1
    //expected output: white
    chessBoard('c',6);
    
    //test case 2
    //expected output: black
    chessBoard('d',4);
}