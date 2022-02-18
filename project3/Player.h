#ifndef Player_h
#define Player_h
#include "Hero.cpp"
#include <string>
#include <vector> 
using namespace std;


class Player{
    
    private:
        string name;
        Hero hero;
        int points;

        
        
    public:
        string getname();
        int getpoints();
        void setpoints(int);
    
};
#endif