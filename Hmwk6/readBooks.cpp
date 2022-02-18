#include "Book.h"
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

//Algorithm: take file of books and authors and store them in respective arrays
//1. use file i/o to open and access file
//2. loop through file and use split function to separate authors and titles
//3. store each in respective arrays
//input: filename, title array, author array, num of books already stores, size of array
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
            books[i] = Book(linearr[1], linearr[0]);
            
            //authors[i] = linearr[0]; // add author to array
            //titles[i] = linearr[1]; // add title to array
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
    
    string titles[3] = {"Book1","Book2"};
    string authors[3] = {"Someone", "Sometwo"};
    cout << readBooks("books.txt", titles, authors, 2, 2) << endl;
    
    //test case 2
    //expected output:3
    
    string titles1[3] = {"Book1","Book2"};
    string authors1[3] = {"Someone", "Sometwo"};
    cout << readBooks("books.txt", titles1, authors1, 2, 3) << endl;
}