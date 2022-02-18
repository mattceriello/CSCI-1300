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

void greeting(){
	cout<< "Welcome to Jeopardy Dice!";
	cout << " " << endl;
}


bool initialRoll(){
	cout << "Do you want to roll a dice (Y/N)?: " << endl;
	
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
	cout << "Do you want to roll again (Y/N)?: " << endl;
	
	char rollAgain;
	
	cin >> rollAgain;
	
	if (rollAgain == 'Y' || rollAgain == 'y'){
		return true;
	}
	else if (rollAgain == 'N' || rollAgain == 'n'){
		return false;
	}
	
}

int computerTurn(int userTotal, int computerTotal1){
	
	int turnTotal = 0;
	while (turnTotal < 10){
		int roll = rollDie();
		if (roll == 2 || roll == 5){
			turnTotal = 0;
			computerTotal1 += turnTotal;
			cout << "Computer rolled a "<< roll<< endl;
			cout << "Computer turn total is " << turnTotal << endl;
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			return computerTotal1;
		}
	
		else if (roll == 4){
			turnTotal = 15;
			computerTotal1 += turnTotal;
			cout << "Computer rolled a "<< roll<< endl;
			cout << "Computer turn total is " << turnTotal << endl;
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			return computerTotal1;
		}
	
		else if (roll == 1 || roll == 3 || roll == 6){
			turnTotal += roll;
		}
	
		
		cout << "Computer rolled a "<< roll<< endl;
		cout << "Computer turn total is " << turnTotal << endl;
		
	}
	computerTotal1 += turnTotal;
	cout << "computer: " <<  computerTotal1<<endl;
	cout << "human: " << userTotal << endl;
	return computerTotal1;
	
}


int userTurn(int userTotal, int computerTotal1){

	bool start = initialRoll();
	int turnTotal = 0;
	if (start == false){
		turnTotal = 0;
		cout << "computer: " <<  computerTotal1<<endl;
		cout << "human: " << userTotal << endl;
		userTotal += turnTotal;
		return userTotal;
	}
		while (start == true){
			

			int roll = rollDie();
			
			if (roll == 2 || roll == 5){
				turnTotal = 0;
				userTotal += turnTotal;
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
		
			}
	
			else if (roll == 4){
				turnTotal = 15;
				userTotal += turnTotal;
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
			}
	
			else if (roll == 1 || roll == 3 || roll == 6){
				turnTotal += roll;
			}
	
			
			cout << "You rolled a "<< roll<< endl;
			cout << "Your turn total is " << turnTotal << endl;
			start = false;
			
		}
		
	
		
		bool again = turnAgain();
		
		
		
		while (again == true){ // roll again
			

			int roll = rollDie();
			
			if (roll == 2 || roll == 5){
				turnTotal = 0;
				userTotal += turnTotal;
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
		
			}
	
			else if (roll == 4){
				turnTotal = 15;
				userTotal += turnTotal;
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
			}
	
			else if (roll == 1 || roll == 3 || roll == 6){
				turnTotal += roll;
			}
	
			
			cout << "You rolled a "<< roll<< endl;
			cout << "Your turn total is " << turnTotal << endl;
			
			again = turnAgain();
		}
		
		if (again == false){
			
			userTotal += turnTotal;
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			
			return userTotal;
		}
	
}



void game(){
	
	int x = 0;
	int computerTotal1 = 0;
	int humanTotal = 0;
	greeting();
	while (computerTotal1 < 80 && humanTotal < 80 ){
		
		cout << " " << endl;
		cout << "It is now human's turn" << endl;
		cout << " " << endl;
		
		humanTotal = userTurn(humanTotal, computerTotal1);
		
		if (humanTotal >= 80){
			cout<< " " << endl;
			cout << "Congratulations! human won this round of Jeopardy Dice!"<< endl;
			break;
		}
		
		
		cout << " " << endl;
		cout << "It is now computer's turn" << endl;
		cout << " " << endl;
		
		computerTotal1 = computerTurn(humanTotal,computerTotal1);
		
		
		if (computerTotal1 >= 80){
			cout<< " " << endl;
			cout << "Congratulations! computer won this round of Jeopardy Dice!"<< endl;
			break;
		}
		
		
		
		
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