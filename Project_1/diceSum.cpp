// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 0123 – yourTAname
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// Project1 

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

//Algorithm: get random number 1-6
//1. use random function to get number between 1-6
//2. return number
//input - none
//return - random number

int rollDie()
{
     return random() % 6 + 1; // random function
}

//Algorithm: Roll dice until the desired sum is reached
//1. check if sum is between 2-12
//2. if so loop 2 dice rolls until the sum of the 2 
//   is equal to the desired sum
// input - int sum - desired sum
// return- none


void diceSum(int sum){
    int dice1 = 0;
    int dice2 = 0;
    
    if (sum >= 2 && sum <= 12){ // check if sum is between 2-12
        
    
    bool equal = false; // create checker variable
    int count = 0;
    
    while(equal == false){ // loop while the sum isnt equal
    
        count++;
        dice1 = rollDie();// roll dice
        dice2 = rollDie();
        
        cout << "You rolled a " <<  dice1 << " and a " << dice2 << endl;
        
        if (dice1 + dice2 ==  sum){ // check if 2 values equal the desired sum
            cout << "Got a " <<  sum << " in " << count << " rolls!" << endl;
            equal = true;
        }
        
    
        
    }
    
        
    }
    else{
        cout << "The desired sum should be between 2 and 12" << endl;
    }
    
    
}


int main(){
    srand (time(NULL));
    
    //test case 1
    //expected output:
    //You rolled a 4 and a 2
    //You rolled a 6 and a 4
    //You rolled a 4 and a 1
    //You rolled a 1 and a 3
    //You rolled a 3 and a 3
    //You rolled a 2 and a 1
    //You rolled a 4 and a 2
    //You rolled a 2 and a 6
    //Got a 8 in 8 rolls!
    diceSum(8);
    
    //test case 2
    //expected output: The desired sum should be between 2 and 12
    diceSum(13);
}