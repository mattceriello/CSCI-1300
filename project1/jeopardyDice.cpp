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



///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining how you are approaching the problem, step by step 
///////////////////////////////////////////////////////////////////////////////////////////////////

/*

Your algorithm goes into here 


*/




///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 



int rollDie()
{
	return random() % 6 + 1; 
}

// your 3 + functions go in here


bool initialRoll(){
	cout << "Do you want to roll a dice(Y/N)?: " << endl;
	
	char roll;
	
	cin >> roll;
	
	if (roll == 'Y' || roll == 'y'){
		return true;
	}
	else if (roll == 'N'|| roll == 'n'){
		return false;
	}
}




bool turnAgain(){
	cout << "Do you want to roll again(Y/N)?: " << endl;
	
	char rollAgain;
	
	cin >> rollAgain;
	
	if (rollAgain == 'Y' || rollAgain == 'y'){
		return true;
	}
	else if (rollAgain == 'N' || rollAgain == 'n'){
		return false;
	}
	
}

int computerTurn(int playerTotal){
	
	int turnTotal;
	while (turnTotal < 10){
		int roll = rollDie();
		if (roll == 2 || roll == 5){
			turnTotal = 0;
		
		}
	
		else if (roll == 4){
			turnTotal = 15;
		}
	
		else if (roll == 1 || roll == 3 || roll == 6){
			turnTotal += roll;
		}
	
		playerTotal += turnTotal;
		cout << "Computer rolled a "<< roll<< endl;
		cout << "Computer turn total is " << turnTotal << endl;
		
	}
	cout<< playerTotal << endl;
	return playerTotal;
	
}


int userTurn(int playerTotal){
	
	int turnTotal;
	
	int roll = rollDie();
	if (roll == 2 || roll == 5){
		turnTotal = 0;
		
	}
	
	else if (roll == 4){
		turnTotal = 15;
	}
	
	else if (roll == 1 || roll == 3 || roll == 6){
		turnTotal += roll;
	}
	
	playerTotal = turnTotal;
	cout << "You rolled a "<< roll<< endl;
	cout << "Your turn total is " << turnTotal << endl;
	return playerTotal;
	
}



void game(){
	
	int computerTotal1 = 0;
	int humanTotal = 0;
	//welcome
	while (computerTotal1 != 80 && humanTotal != 80 ){
		cout << "It is now human's turn" << endl;
		cout << " " << endl;
		bool start = initialRoll();
		while (start == true){
			humanTotal = userTurn(humanTotal);
			start = false;
		}
		bool again = turnAgain();
		while (again == true){
			humanTotal += userTurn(humanTotal);
			again = turnAgain();
		}
		if (again == false){
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << humanTotal << endl;
			
		}
		cout << "it is now computer's turn" << endl;
		
		int computerTotal1 = computerTurn(computerTotal1);
		cout << "computer: " <<  computerTotal1<<endl;
		cout << "human: " << humanTotal << endl;
		
		
		
	}	
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main. 
// Once you finished please paste your code above this line 
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game! 
	game();
	return 0;
}