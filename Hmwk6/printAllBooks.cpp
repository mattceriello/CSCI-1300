#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

//Algorithm: print books formatted title by author
//1. use while loop to loop until num is reached
//2. print author and title at index

void printAllBooks(string titles[], string authors[], int num){
    if(num <= 0){ //test if no books are stored
        cout<< "No books are stored" << endl;
    }
    int i = 0;
    if (num > 0){ // print heading
        cout << "Here is a list of books" << endl;
    }
    while(i < num){ //print title and author at index
        cout << titles[i] << " by " << authors[i] << endl;
        i++;
    }
}


int main(){
    
    // test cases can be done by reading in data first 
    // then using stored titles and authors
}