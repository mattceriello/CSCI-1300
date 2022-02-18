#include <iostream>
#include "Book.h"
#include <string>
#include "Book.cpp"

using namespace std;

int main(){
    
    //test case 1
    //expected output: title
    
    Book newbook = Book();
    string t = "title";
    newbook.setTitle(t);
    cout << newbook.getTitle() << endl;
    
    //test case 2
    //expected output: author
    Book book = Book();
    string a = "author";
    book.setAuthor(a);
    cout << book.getAuthor() << endl;
    
}