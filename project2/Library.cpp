#include "Library.h"
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;


//slpit already commented
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
    return j ;
}

//default constructor
//set numbooks and numusers to 0
Library::Library(){
    numBooks = 0;
    numUsers = 0;
}

//gets size of books array
//returns int sizeBook
int Library::getSizeBook(){
    return sizeBook;
}

//gets size of user array
//returns int SizeUser
int Library::getSizeUser(){
    return sizeUser;
}

//gets number of books in the system
//returns int numBooks
int Library::getNumBooks(){
    return numBooks;
}

//gets number of users in the system
//returns int numUsers
int Library::getNumUsers(){
    return numUsers;
}


//Algorithm: Read through a file of books and save them to a database
//1. open file using file i/o
//2. create array for each line in file
//3. save the author and title as a new book object
//4. loop and return how many books are stored
//input: string filename
//return: int numBooks
int Library::readBooks(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[2]; 
        while(getline(file,line)){ //loop through eachn line
            if(line.length() == 0) continue; //skip if line is empty
            split(line, ',' , linearr, 2);
            if(numBooks == sizeBook){// when number of books saved equals max allowed, return -2
                return -2;
            }
            books[numBooks] = Book(linearr[1], linearr[0]); //save author and title into book object
            numBooks++;
        }
        return numBooks;
    }
    else if((numBooks == sizeBook) && (file.is_open() == false)){
        return -2;
    }
    else{
        return -1;
    }
}


//loop through book ojbect array and print title and author for each
void Library::printAllBooks(){
    cout << "Here is a list of books" << endl;
    for(int i = 0; i < numBooks; i++){
        cout << books[i].getTitle() << " by ";
        cout << books[i].getAuthor() << endl;
    }
}

//Algorithm: Read through a file of users and their ratings, and save them to a database
//1. open file using file i/o
//2. create array for each line in file
//3. save the username and the subsequent ratings as a new user object
//4. loop and return how many users are stored
//input: string filename
//return: int numUsers
int Library::readRatings(string filename){
    if (numUsers == sizeUser){ //if num of users stored equals max
        return -2;
    }
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[51];
        string username = "";
        while(getline(file,line)){ //loop through file
            int ratings[50]; // create array of ratings for the user
            if(line.length() == 0) continue;
            split(line, ',' , linearr, 51);
            if (numUsers == sizeUser){ // when array fills up, break out of loop
                break;
            }
            username = linearr[0]; // save username as first thing in the line
            for(int i = 1; i <= 50; i++){ //loop through the rest of the line and save into ratings array
                string rate = linearr[i]; //rate equals string
                ratings[i - 1] = stoi(rate); // save into ratings array and convert to int
            }
            users[numUsers] = User(username, ratings, 50); // create new user object using username, ratings array, and max size 50
            numUsers++;
        }
        file.close();
        return numUsers;
    }
    else if((numUsers == sizeUser) && (file.is_open() == false)){
        return -2;
    }
    else{
        return -1;
    }
}


//Algorithm: Take in username and title and return the rating for that user at that title
//1. loop through target username and title and make lower
//2. loop through users and make usernames lowercase, then test if matches target
//3. loop through books and make titles lowercase, thrn test if matches target
//input: username and title
//return: rating
int Library::getRating(string username, string title){
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
    for(int i = 0; i < numUsers; i++){
        string usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){//loop through user object usernames and make lowercase
            usernew += tolower(usercurrent[j]);
        }
        if (usernew == lowerusername){// test if username = target name
            userflag = true;
            userindex = i;
        }
    }
    for(int i = 0; i < numBooks; i++){ 
        string titlecurrent = books[i].getTitle();
        string titlenew = "";
        for(int j = 0; j < titlecurrent.length(); j++){//loop through book object titles and make lowercase
            titlenew += tolower(titlecurrent[j]);
        }
        if (titlenew == lowertitle){// test if username = target name
            titleflag = true;
            titleindex = i;
        }
    }
    if (userflag == true && titleflag == true){ // if title and user exist, return users rating 
        return users[userindex].getRatingAt(titleindex);
    }
    else if(userflag == false || titleflag == false){ //if one or both dont exist, return -3
        return -3;
    }
}

//Algorithm: return the amount of books rated by a given user
//loop through given users ratings
// count each rating that isnt 0
//input: username
//return: amount of ratings that arent 0
int Library::getCountReadBooks(string username){
    int count = 0;
    bool userflag = false;
    string userlower = "";
    string usercurrent = "";
    int userindex = 0;
    for(int i = 0; i < username.length(); i++){ //loop through target username and make lowercase
        userlower += tolower(username[i]);
    }
    for(int i = 0; i < numUsers; i++){
        usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){ //loop through user object usernames and make lowercase
            usernew += tolower(usercurrent[j]);
        }
        if(usernew == userlower){ //test if matches target
            userindex = i;
            userflag = true;
        }
    }
    if(userflag == false){
        return -3;
    } 
    for(int i = 0; i < numBooks; i++){
        if(users[userindex].getRatingAt(i) != 0){ //loop through users ratings and count amount that arent 0
            count++;
        }
    }
    return count;
}


//Algorithm: Print out ratings for a given user
//1. find username in array of user objects
//2. print out books and their ratings from that user
//input: username
//return: none
void Library::viewRatings(string username){
    int count = 0;
    bool userflag = false;
    string userlower = "";
    string usercurrent = "";
    int userindex = 0;
    for(int i = 0; i < username.length(); i++){ //make lower
        userlower += tolower(username[i]);
    }
    for(int i = 0; i < numUsers; i++){
        usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){ //make lower
            usernew += tolower(usercurrent[j]);
        }
        if(usernew == userlower){
            userindex = i;
            userflag = true;
        }
    }
    if(userflag == false){ // if username issn't found, cout 
        cout << username << " does not exist." << endl; 
    } 
    for(int i = 0; i < numBooks; i++){
        if(users[userindex].getRatingAt(i) != 0 && userflag == true){ //loop through ratings and count hpw may arent 0
            count++;
        }
    }
    if(count == 0 && userflag == true){ // if no books are rated, cout
        cout << username << " has not rated any books yet." << endl;
    }
    if(count > 0){ //if there are books rated, cout
        cout << "Here are the books that " << username << " rated" << endl;
    }
    for(int i = 0; i < numBooks; i++){
        if(users[userindex].getRatingAt(i) != 0 && userflag == true){//if there are books rated, cout book title and rating
            cout << "Title : " << books[i].getTitle() << endl;
            cout << "Rating : " << users[userindex].getRatingAt(i) << endl;
            cout << "-----" << endl;
        }
    }
}

//Algorithm: calculate the average rating for a given title 
//1. make sure title exists
//2. loop through users' ratings for that given title
//3. sum up ratings for the title and calculate average.
//input: title
//return: average
double Library::calcAvgRating(string title){
    double count = 0;
    double total = 0;
    double average = 0.0;
    bool titleflag = false;
    int titleindex = 0;
    string lowertitle = "";
    for(int i = 0; i < title.length(); i++){//loop through target title and make lowercase
        lowertitle += tolower(title[i]);
    }
    for(int i = 0; i < numBooks; i++){
        string titlecurrent = books[i].getTitle();
        string titlenew = "";
        for(int j = 0; j < titlecurrent.length(); j++){ //make lower
            titlenew += tolower(titlecurrent[j]);
        }
        if (titlenew == lowertitle){// 
            titleflag = true;
            titleindex = i;
        }
    }
    if(titleflag == false){ // if book isnt found
        return -3;
    }
    for(int i = 0; i < numUsers; i++){
        if(users[i].getRatingAt(titleindex) != 0 && titleflag == true){ // add up ratings from users for given title
            total += users[i].getRatingAt(titleindex);
            count++; // count how many ratings were added
        }
    }
    if(titleflag == true && total == 0){ 
        return 0;
    }
    if(titleflag == true){ //calculate average of ratings for title
        average = double(total / count);
    }
    return average;
}


//Algorithm: add user object to array of user object
int Library::addUser(string username){
    if(numUsers >= 100){// if user array is full
        return -2;
    }
    bool userflag = false;
    int userindex = 0;
    int ratings[50];
    string lowerusername = "";
    for(int i = 0; i < username.length(); i++){ //loop through target username and make lowercase
        lowerusername += tolower(username[i]);
    }
    for(int i = 0; i < numUsers; i++){
        string usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){
            usernew += tolower(usercurrent[j]);
        }
        if (usernew == lowerusername){// test if username = target name, user already exists
            userflag = true;
            return 0;
        }
    }
    users[numUsers] = User(username, ratings, 0); // create new user object 
    numUsers++;
    return 1;
}

//Algorithm: Give a book a rating from a user
//1. test if title and username exist
//2. use setRatingAt to set the rating for the user at that title
//intput: username, title, rating
//return 1 if user was added
int Library::checkOutBook(string username, string title, int rating){
    if(rating < 0 || rating > 5){
        return -4;
    }
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
    for(int i = 0; i < numUsers; i++){
        string usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){
            usernew += tolower(usercurrent[j]);
        }
        if (usernew == lowerusername){// test if username = target name
            userflag = true;
            userindex = i;
        }
    }
    for(int i = 0; i < numBooks; i++){
        string titlecurrent = books[i].getTitle();
        string titlenew = "";
        for(int j = 0; j < titlecurrent.length(); j++){
            titlenew += tolower(titlecurrent[j]);
        }
        if (titlenew == lowertitle){// test if username = target name
            titleflag = true;
            titleindex = i;
        }
    }
    if(userflag == true && titleflag == true){ // if user and title exist, set rating for that user at that title
        users[userindex].setRatingAt(titleindex, rating);
        return 1;
    }
    if(userflag == false || titleflag == false){
        return -3;
    }
}


//Algorithm: Get recommendations for given user from most similar user
//1. see if given user exists
//2. find user whp is most similar using SSD given their ratings
//3. when most similar user is found, print books that given user hasnt rated and most similar user rated between 3-5
//input: username
//return none
void Library::getRecommendations(string username){
    bool userflag = false;
    int userindex = 0;
    string lowerusername = "";
    int matchindex = 0;
    int total = 0;
    int lowest = 0;
    bool recommend = false;
    for(int i = 0; i < username.length(); i++){ //loop through target username and make lowercase
        lowerusername += tolower(username[i]);
    }
    for(int i = 0; i < numUsers; i++){
        string usercurrent = users[i].getUsername();
        string usernew = "";
        for(int j = 0; j < usercurrent.length(); j++){
            usernew += tolower(usercurrent[j]);
        }
        if (usernew == lowerusername){// test if username = target name
            userflag = true;
            userindex = i;
        }
    }
    if(userflag == false){ //if user doesnt exist
        cout << username << " does not exist." << endl;
        return;
    }
    
    for(int i = 0; i < numUsers; i++){
        if(users[i].getUsername() != username){ //loop through each user that isnt the given one
            total = 0;
            for(int j = 0; j < numBooks; j++){
                total += pow((users[userindex].getRatingAt(j) - users[i].getRatingAt(j)),2); // do SSD calculation 
            }
            if(i == 0){
                total = lowest;//make first total the lowest
                matchindex = i;
            }
            else if(total < lowest){ //if new total is lower than previous lowest
                lowest = total; //update new lowest
                matchindex = i; //update which user is best match
            }
        }
    }
    
    for(int i = 0; i < numBooks; i++){ // test if there are books to recommend
        if(users[userindex].getRatingAt(i) == 0 && (users[matchindex].getRatingAt(i) >= 3 && users[matchindex].getRatingAt(i) <= 5 )){
            recommend = true;
        }
    }
    if(recommend == true){ //cout
        cout << "Here are the list of recommendations" << endl;
    }
    else if(recommend == false){ // if their are no books to recommend, cout
        cout << "There are no recommendations for " << username << " at present" << endl;
        return;
    }
    for(int i = 0; i < numBooks; i++){// loop through books and see if users rating is zero and most similar users rating is between 3 and 5
        if(users[userindex].getRatingAt(i) == 0 && (users[matchindex].getRatingAt(i) >= 3 && users[matchindex].getRatingAt(i) <= 5 )){ // if so, cout
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }
    
}
