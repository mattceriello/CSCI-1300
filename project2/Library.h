#ifndef Library_h
#define Library_h
#include "Book.h"
#include "User.h"
#include <string>
using namespace std;



class Library{
    
    private:
        int const sizeBook = 50;
        int const sizeUser = 100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;
    
    
    
    public:
        Library();
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int readBooks(string);
        void printAllBooks();
        int readRatings(string);
        int getRating(string, string);
        int getCountReadBooks(string);
        void viewRatings(string);
        double calcAvgRating(string);
        int addUser(string);
        int checkOutBook(string, string, int);
        void getRecommendations(string);
    
   
            
};

#endif