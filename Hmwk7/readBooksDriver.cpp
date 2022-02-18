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
using namespace std;

//split already commented
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

//Algorithm: take file of books and store them in a book object array
//1. use file i/o to open and access file
//2. loop through file and use split function to separate authors and titles
//3. create a book object at each line and store title and author in it
//input: filename, book array, num of books already stores, size of array
//return: number of books stored


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
            books[i] = Book(linearr[1], linearr[0]); // create a new book object for each line 
            i++;
        }
        
        return i;
        
    }
    else{
        return -1;
    }
    file.close();
    
}


int main(){
    
    //test case 1
    //expected output: -2
    
    Book books[2];
    cout << readBooks("books.txt", books, 2, 2) << endl;
    
    //test case 2
    //expected output:50
    
    Book newbooks[50];
    cout << readBooks("book2.txt", newbooks, 0, 50) << endl;
}