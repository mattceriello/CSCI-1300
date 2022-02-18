#include "Library.h"
#include "Library.cpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

int main(){
    //Library myLibrary = Library();
    //myLibrary.readBooks("test.txt");
    //int rv1 = myLibrary.readRatings("test2.txt");
    //int rate = myLibrary.getRating("Ninja", "Book 2");
    //int count = myLibrary.getCountReadBooks("Sphyer");
    //myLibrary.viewRatings("Ninja");
    //myLibrary.getRecommendations("Myth");'
    //cout << rv1<<endl;
    //cout << myLibrary.getNumUsers();
    Library l22 = Library();
    int numBooks = l22.readBooks("books.txt");
    int numUsers = l22.readRatings("ratings.txt");
    cout << "rating (before) = " << l22.getRating("sharon", "Watership Down") << endl;
    int rv = l22.checkOutBook("sharon","Watership Down",5);
    cout << "Returned : "<< rv <<endl;
    cout << "rating (after) = " << l22.getRating("sharon", "Watership Down");   

    
    
}