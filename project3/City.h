#ifndef City_h
#define City_h
#include <string>
#include <vector> 
using namespace std;


class City{
    
    private:
       string letter;
       string name;
       int money;
       int armysize;
       int points;

        
        
    public:
        City();
        City(string, string, int, int, int);
        string getname();
        int getmoney();
        void setmoney(int);
        int getarmysize();
        void setarmysize(int);
        int getpoints();
        void setpoints(int);
        string getletter();
        
        
        
    
};
#endif