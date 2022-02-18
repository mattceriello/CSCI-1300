#include "Book.h"
#include <iostream>
#include <cmath>
using namespace std;

//Algorithm: Default Constructor
//1. set title to null
//2 set author to null

Book::Book(){
    
    title = "";
    author = "";
}

//Algorithm: Parameterized constructor
//1. set title to new titlw
//2. set author to new author
//input: strint _title, string _author
Book::Book(string _title, string _author){
    title = _title;
    author = _author;
}

//Algorithm: get title
//1. return title
string Book::getTitle(){
    return title;
}

//Algorithm: set title
//1. set title to inputed title
//input: string new title
void Book::setTitle(string newtitle){
    title = newtitle;
}

//Algorithm: Get Author
//1. return author
string Book::getAuthor(){
    return author;
}


//Algorithm: set author
//1. set author based on inputed author
//input: string new author
void Book::setAuthor(string newauthor){
    author = newauthor;
}

