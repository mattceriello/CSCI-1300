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
using namespace std;

//Algorithm: test if user and title exists and return user's rating for that title
//1. *Lowercase all strings being tested*
//2. Loop through array of users and see if it exists
//3. loop through titles and see if title exists
//4. if both exist, print rating for user at that title
//input: username, title, array of users, array of titles, array of ratings, num of users, num of books
//return: rating for title


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

int main(){
    
    //test case 1
    //expected oputput: 4
    
    string users[2] = {"User1", "User2"};
    string titles[3] = {"Title1", "Title2", "Title3"};
    int ratings[2][3] = {{1,4,2},{0,5,3}};
    int rating = getRating("User1", "Title2", users, titles, ratings, 2, 3);
    cout << rating;
    
}