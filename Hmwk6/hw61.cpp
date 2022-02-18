// CSCI1300 Spring 2019
// Author: <Your name>
// Recitation: <123> – <Your TA name>
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
#include <locale>
#include <sstream>
#include <iomanip>
using namespace std;



//////////////////////////////////////////////////////////////////////////
// other helper functions... split 
//////////////////////////////////////////////////////////////////////////
int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[k] = word;
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}


int readBooks(string filename, string titles[], string authors[], int numBooksStored, int size){
    if (numBooksStored == size){
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[2];
        int i = numBooksStored;
        while(getline(file,line)){
            if(line.length() == 0) continue;
            split(line, ',' , linearr, 2);
            if (i == size ){
                break;
            }
            authors[i] = linearr[0];
            titles[i] = linearr[1];
            i++;
        }
        return i;
    }
    else{
        return -1;
    }
    file.close();
}


int readRatings(string filename, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
    if(numUsers == maxRows){
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        int row = numUsers;
        string line = "";
        string linearr[maxColumns + 1];
        while(getline(file,line)){
            if(line.length() == 0) continue;
            split(line, ',', linearr, maxColumns + 1);
            if(maxRows == row){
                break;
            }
            users[row] = linearr[0];
            int irating = 0;
            for(int col = 1; col <= 50; col++){
                if(linearr[col] != ""){
                    string rate = linearr[col];
                    ratings[row][irating] = stoi(rate);
                    irating++;
                }
            }
            row++;
        }
        file.close();
        return row;
    }
    else{
        return -1;
    }
    
}

void printAllBooks(string titles[], string authors[], int num){
    if(num <= 0){
        cout<< "No books are stored" << endl;
    }
    int i = 0;
    if (num > 0){
        cout << "Here is a list of books" << endl;
    }
    while(i < num){
        cout << titles[i] << " by " << authors[i] << endl;
        i++;
    }
}

int getRating(string username, string title, string users[], string titles[], int ratings[][50], int usersnum, int books){
    bool userflag = false;
    bool titleflag = false;
    int titleindex = 0;
    int userindex = 0;
    string lowerusername = "";
    string lowertitle = "";
    for(int i = 0; i < username.length(); i++){
        lowerusername += tolower(username[i]);
    }
    for(int i = 0; i < title.length(); i++){
        lowertitle += tolower(title[i]);
    }
    for(int i = 0; i < usersnum; i++){ //array of usernames
        string usernew = "";
        string word = users[i];
        for(int i = 0; i < word.length(); i++){
            usernew += tolower(word[i]);
        }
        if (usernew == lowerusername){
            userflag = true;
            userindex = i;
        }
    }
    for (int j = 0; j < books; j++){
        string titlenew = "";
        string word = titles[j];
        for(int i = 0; i < word.length(); i++){
            titlenew += tolower(word[i]);
        } 
        if (titlenew == lowertitle){
            titleflag = true;
            titleindex = j;
        }
    }
    if (userflag == true && titleflag == true){
        cout << "yes" << endl; 
        return ratings[userindex][titleindex];
    }
    else if(userflag == false || titleflag == false){
        return -3;
    }
}




/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Get rating" << endl;
  cout << "5. Quit" << endl;
}


int main(int argc, char const *argv[]) {

    // taking menu choice 
    string choice;

    // number of books and users stored in the arrays
    int numBooks = 0;
    int numUsers = 0;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;
    
    int maxRows = 100;
    int maxColumns = 50;
    
    string titles[50];
    string authors[50];
    string users[100];
    int ratings[100][50];
    int numofBooks = 0;
    int numofUsers = 0;
    int rating = 0;


    // variables to store user inputs 
    string bookFileName;
    string userFileName;
    string userName, bookTitle;    

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                numofBooks = readBooks(bookFileName, titles, authors, numBooks, bookArrSize);
                if (numofBooks == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if(numofBooks == -2){
                    cout << "Database is already full. No books were added." << endl; 
                }
                
                else if(numofBooks == bookArrSize){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numofBooks << endl;
                }

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No books saved to the database." << endl;
                // cout << "Database is already full. No books were added." << endl;     
                // cout << "Database is full. Some books may have not been added." << endl;     
                // cout << "Total books in the database: " << numBooks << endl;
                
                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                numofUsers = readRatings(userFileName, users, ratings, numUsers, maxRows, maxColumns);
                
                if(numofUsers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if(numofUsers == -2){
                    cout << "Database is already full. No users were added." << endl; 
                }
                else if(numofUsers == maxRows){
                    cout << "Database is full. Some users may have not been added." << endl; 
                }
                else{
                    cout << "Total users in the database: " << numofUsers << endl;
                }

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << "No users saved to the database." << endl;
                // cout << "Database is already full. No users were added." << endl; 
                // cout << "Database is full. Some users may have not been added." << endl; 
                // cout << "Total users in the database: " << numUsers << endl;

                cout << endl;
                break;

            case 3:
                // print the list of the books
                
                printAllBooks(titles, authors, numBooks);

                cout << endl;
                break;

            case 4:
                // get user's rating 
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title 
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                rating = getRating(userName, bookTitle, users, titles, ratings, numUsers, numBooks);
                
                if (rating == 0){
                    cout << userName << " has not rated " << bookTitle << endl;
                }
                else if(rating == -3){
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
                }
                else{
                    cout << userName << " rated " << bookTitle << " with " << rating << endl;
                }

                // Use the below messages and match them to the return code. Update variables as needed.
                // cout << userName << " has not rated " << bookTitle << endl; 
                // cout << userName << " or " << bookTitle << " does not exist" << endl; 
                // cout << userName << " rated " << bookTitle << " with " << rate << endl; 


                cout << endl;
                break;
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}