#ifndef User_h
#define User_h
using namespace std;
#include <string>


class User{
    
    public:
        User();
        User(string, int [], int);
        string getUsername();
        void setUsername(string);
        int getRatingAt(int);
        bool setRatingAt(int,int);
        int getNumRatings();
        void setNumRatings(int);
        int getSize();
        
        
    private:
        string username;
        int ratings[50];
        int numRatings;
        int size;
    
};

#endif