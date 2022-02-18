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


int rollDie()
{
     return random() % 6 + 1;
}




void diceSum(int sum){
    int dice1 = 0;
    int dice2 = 0;
    
    if (sum >= 2 && sum <= 12){
        
    
    bool equal = false;
    int count = 0;
    
    while(equal == false){
    
        count++;
        dice1 = rollDie();
        dice2 = rollDie();
        
        cout << "You rolled a " <<  dice1 << " and a " << dice2 << endl;
        
        if (dice1 + dice2 ==  sum){
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
    diceSum(8);
}