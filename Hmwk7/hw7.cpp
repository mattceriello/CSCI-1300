// CSCI1300 Spring 2019
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 

#include "User.h"
#include "User.cpp"
#include "Book.h"
#include "Book.cpp"
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



class User{
    
    public:
        User();
        User(string, int [], int);
        string getUsername();
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int,int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
        
        
    private:
        string username;
        int ratings[50];
        int numRatings;
        int size;
    
};



User::User(){
    
    username = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < size; i++){
        ratings[i] = 0;
    }
    
}



User::User(string _username, int newarr[50], int _numRatings){
    username = _username;
    numRatings = _numRatings;
    if (numRatings <= 50){
        for (int i = 0; i < 50; i++){
            ratings[i] = newarr[i];
        }
        
    }
}


string User::getUsername(){
    return username;
}

void User::setUsername(string a){
    username = a;
}

int User::getRatingAt(int index){
    if (index >= 50){
        return -1;
    }
    
    
    else if (index < size){
        //cout << ratings[index];
        return ratings[index];
    }
    
    
    
    
}

bool User::setRatingAt(int index, int value){
    if ((index > 0 && index < size) && (value >= 0 && value <= 5)){ 
        ratings[index] = value;
        return true;
    }
    else {
        return false;
    }
    
}

int User::getNumRatings(){
    return numRatings;
}

void User::setNumRatings(int _numrating){
    numRatings = _numrating;
}

int User::getSize(){
    return size;
}

class Book{
    
    public:
        Book();
        Book(string, string);
        string getTitle();
        void setTitle(string);
        string getAuthor();
        void setAuthor(string);
        
    private:
        string title;
        string author;
        
    
    
};

Book::Book(){
    
    title = "";
    author = "";
}

Book::Book(string _title, string _author){
    title = _title;
    author = _author;
}

string Book::getTitle(){
    return title;
}

void Book::setTitle(string newtitle){
    title = newtitle;
}

string Book::getAuthor(){
    return author;
}

void Book::setAuthor(string newauthor){
    author = newauthor;
}


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


int readBooks(string filename, Book books[], int numBooksStored, int size){
    if (numBooksStored == size){ // if array already full
        return -2;
    }
    
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[2]; // create array for each line
        int i = numBooksStored;
        while(getline(file,line)){ 
            if(line.length() == 0) continue;
            split(line, ',' , linearr, 2); //split line array at comma
            if (i == size ){
                break;
            }
            books[i] = Book(linearr[1], linearr[0]);
            i++;
        }
        
        return i;
        
    }
    else{
        return -1;
    }
    file.close();
    
}


int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol){
    if(numUsersStored == usersArrSize){
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        
        string line = "";
        string linearr[maxCol + 1];
        string username;
        while(getline(file,line)){
            int ratings[50];
            if(line.length() == 0) continue;
            split(line, ',', linearr, maxCol + 1);
            if(numUsersStored == usersArrSize){
                break;
            }
            username = linearr[0];
            
            for(int col = 1; col <= 50; col++){
                if (linearr[col] != ""){
               
                    string rate = linearr[col];
                    ratings[col - 1] = stoi(rate);
                    //cout << numUsersStored<< " - " << col - 1 << " : "<< linearr[col] << endl;    
                
                }
                
            }
            users[numUsersStored] = User(username,ratings, 50);
           
            numUsersStored++;
        }
       
        file.close();
        
        return numUsersStored;
    }
    else{
        return -1;
    }
    
}

void printAllBooks(Book books[], int num){
    if(num <= 0){ //test if no books are stored
        cout<< "No books are stored" << endl;
    }
    int i = 0;
    if (num > 0){ // print heading
        cout << "Here is a list of books" << endl;
    }
    while(i < num){ //print title and author at index
        cout << books[i].getTitle() << " by "; 
        cout << books[i].getAuthor << endl;
        i++;
    }
}

int getRating(string username, string title, User users[], Book books[], int usersnum, int booksnum){
    bool userflag = false;
    bool titleflag = false;
    int titleindex = 0;
    int userindex = 0;
    string lowerusername = "";
    string lowertitle = "";
    for(int i = 0; i < username.length(); i++){ //loop through target username and make lowercase
        lowerusername += tolower(username[i]);
    }
    for(int i = 0; i < title.length(); i++){//loop through target title and make lowercase
        lowertitle += tolower(title[i]);
    }
    
    
    for(int i = 0; i < usersnum; i++){ //array of usernames
        string usernew = "";
        string word = users[i].getUsername();
        for(int i = 0; i < word.length(); i++){ //make current username lowercase
            usernew += tolower(word[i]);
        }
        if (usernew == lowerusername){// test if username = target name
            userflag = true;
            userindex = i;
            
        }
    }
    for (int j = 0; j < booksnum; j++){ // array of titles
        string titlenew = "";
        string word = books[i].getTitle();
        for(int i = 0; i < word.length(); i++){//make current title lowercase
            titlenew += tolower(word[i]);
        } 
        cout << titlenew << endl;
        cout << lowertitle << endl;
        if (titlenew == lowertitle){ // test if title = target title
            titleflag = true;
            titleindex = j;
        }
    }
    if (userflag == true && titleflag == true){ // if title and user exist, return rating 
        return users[userindex].getRatingAt(titleindex);
        
    }
    else if(userflag == false || titleflag == false){ //if one or both dont exist, return -3
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
    int maxCol = 50;
    
    
    string titles[50];
    string authors[50];
    string users[100];
    int ratings[100][50];
    int numofBooks = 0;
    int numofUsers = 0;
    int rating = 0;
    int numUsersStored = 0;
    int numBooksStored = 0;
    Books books[];
    User Users[];

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

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                
                numofBooks = readBooks(bookFileName, books, numBooksStored, bookArrSize);
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

                
                
                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                
                numofUsers = readRatings(userFileName, users, numUsersStored, userArrSize, maxCol);
                
                if(numofUsers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if(numofUsers == -2){
                    cout << "Database is already full. No users were added." << endl; 
                }
                else if(numofUsers == userArrSize){
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
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                printAllBooks(books, numBooks);

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

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                
                rating = getRating(userName, bookTitle, users, books, numUsers, numBooks);
                
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