// CSCI1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Project1 - Jeopardy Dice

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

//function described in diceSum.cpp

int rollDie()
{
	return random() % 6 + 1; 
}

// your 3 + functions go in here

//Algorithm: Greets user
//1. print greeting
//input- none
//return - none

void greeting(){
	cout<< "Welcome to Jeopardy Dice!";
	cout << " " << endl;
}

//Algorithm: Ask user if they want to roll a dice
//1. take input from user if they want to roll a dice
//input - none
//return- bool - true or false (yes/no)

bool initialRoll(){
	cout << "Do you want to roll a dice (Y/N)?: " << endl;
	
	char roll;
	
	cin >> roll;// take input
	
	if (roll == 'Y' || roll == 'y'){ //check if yes
		return true;
	}
	else if (roll == 'N'|| roll == 'n'){ // check if no
		return false;
	}
}

//Algorithm: Ask user if they want to roll again
//1. take input from user if they want to roll again
//input - none
//return- bool - true or false (yes/no)


bool turnAgain(){
	cout << "Do you want to roll again (Y/N)?: " << endl;
	
	char rollAgain;
	
	cin >> rollAgain;
	
	if (rollAgain == 'Y' || rollAgain == 'y'){//check if yes
		return true;
	}
	else if (rollAgain == 'N' || rollAgain == 'n'){ // check if no
		return false;
	}
	
}

//Algorithm: Run a turn for the computer using rollDice() function
//1. Input current user and computer totals
//2. loop while the computer total is less than 10
//3. when the turn total is greater than 10, the number should be returned to game()
//input - int usertotal- current total of user - int computertotal - current total of computer
//return - computer total - updates score of computer


int computerTurn(int userTotal, int computerTotal1){
	
	int turnTotal = 0;
	while (turnTotal < 10){// loop while turn total is less than 10
		int roll = rollDie(); // get random number
		if (roll == 2 || roll == 5){ // test if roll is 2 or 5
			turnTotal = 0;// automatically make turn total to 0 and end turn
			computerTotal1 += turnTotal; // add 0 to total
			cout << "Computer rolled a "<< roll<< endl;
			cout << "Computer turn total is " << turnTotal << endl;
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			return computerTotal1;
		}
	
		else if (roll == 4){// test if roll is = 4
			turnTotal = 15; // make total 15 and end turn
			computerTotal1 += turnTotal; // add 15 to current total
			cout << "Computer rolled a "<< roll<< endl;
			cout << "Computer turn total is " << turnTotal << endl;
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			return computerTotal1;
		}
	
		else if (roll == 1 || roll == 3 || roll == 6){ // test if roll is 1 or 3 or 6
			turnTotal += roll; //add that number to turn total
		}
	
		
		cout << "Computer rolled a "<< roll<< endl;
		cout << "Computer turn total is " << turnTotal << endl;
		
	}
	computerTotal1 += turnTotal; // add turn total to computer total
	cout << "computer: " <<  computerTotal1<<endl;
	cout << "human: " << userTotal << endl;
	return computerTotal1;
	
}

//Algorithm: run a turn for the user 
//1. Ask user if they want to roll a dice using initialRoll()
//2. If yes, roll dice
//3. if no skip turn
//4. Ask if they want to roll again
//5. if yes roll dice again
//6. if no end turn
//input- int usertotal - current total of user - int computertotal - current total of computer
//return - user total - updates score of computer



int userTurn(int userTotal, int computerTotal1){

	bool start = initialRoll(); // ask for intial roll
	int turnTotal = 0;
	if (start == false){ //test if intial roll is false
		turnTotal = 0; 
		cout << "computer: " <<  computerTotal1<<endl;
		cout << "human: " << userTotal << endl;
		userTotal += turnTotal; // add 0 to user total
		return userTotal;
	}
		while (start == true){ // loop while inital roll is true
			

			int roll = rollDie();// roll dice
			
			if (roll == 2 || roll == 5){// test if roll is 2 or 5
				turnTotal = 0;
				userTotal += turnTotal; // add 0 to user total and end turn
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
		
			}
	
			else if (roll == 4){// test if roll is 4
				turnTotal = 15;
				userTotal += turnTotal;// add 15 to user total and end turn
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
			}
	
			else if (roll == 1 || roll == 3 || roll == 6){// test if roll is 1 or 3 or 6
				turnTotal += roll;// add that number to turn total
			}
	
			
			cout << "You rolled a "<< roll<< endl;
			cout << "Your turn total is " << turnTotal << endl;
			start = false; // end intial turn
			
		}
		
		bool again = turnAgain(); // ask if they want to roll again
		while (again == true){ // test if they want to roll again
			

			int roll = rollDie(); // roll
			
			if (roll == 2 || roll == 5){ //test if roll is 2 or 5
				turnTotal = 0;
				userTotal += turnTotal;// add 0 to user total and end turn
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
		
			}
	
			else if (roll == 4){// test if roll is 4
				turnTotal = 15;
				userTotal += turnTotal;// add 15 to user total and end turn
				cout << "You rolled a "<< roll<< endl;
				cout << "Your turn total is " << turnTotal << endl;
				cout << "computer: " <<  computerTotal1<<endl;
				cout << "human: " << userTotal << endl;
				return userTotal;
			}
	
			else if (roll == 1 || roll == 3 || roll == 6){// test if roll is 1 or 3 or 6
				turnTotal += roll;// add that number to turn total
			}
	
			
			cout << "You rolled a "<< roll<< endl;
			cout << "Your turn total is " << turnTotal << endl;
			
			again = turnAgain();// ask if they want to roll again
		}
		
		if (again == false){// test if they dont want to roll again
			
			userTotal += turnTotal; // add turn total to user total
			cout << "computer: " <<  computerTotal1<<endl;
			cout << "human: " << userTotal << endl;
			
			return userTotal;
		}
	
}

//Algorithm: Loop through a user turn and computer turn while their scores are less than 80
//1. initiate totals for user and computer
//2. loop while scores are less than 80
//3. test if scores are less than 80 after each turn

void game(){
	
	int x = 0;
	int computerTotal1 = 0;
	int humanTotal = 0;
	greeting();// greeting
	while (computerTotal1 < 80 && humanTotal < 80 ){// loop while scores are less than 80
		
		cout << " " << endl;
		cout << "It is now human's turn" << endl;
		cout << " " << endl;
		
		humanTotal = userTurn(humanTotal, computerTotal1); // run a user turn and return total to human total
		
		if (humanTotal >= 80){// test if user has 80 or more points
			cout<< " " << endl;
			cout << "Congratulations! human won this round of Jeopardy Dice!"<< endl;
			break;// break out of loop
		}
		
		
		cout << " " << endl;
		cout << "It is now computer's turn" << endl;
		cout << " " << endl;
		
		computerTotal1 = computerTurn(humanTotal,computerTotal1);// run a turn for computer and return that total to computer total
		
		
		if (computerTotal1 >= 80){// test if comuputer total is more than 80
			cout<< " " << endl;
			cout << "Congratulations! computer won this round of Jeopardy Dice!"<< endl;
			break;// break out of loop
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