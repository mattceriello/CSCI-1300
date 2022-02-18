#ifndef Book_h
#define Book_h
using namespace std;
#include <string>


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


#endif
