#ifndef Hero_h
#define Hero_h
#include "Warrior.h"
#include <string>
#include <vector> 
using namespace std;


class Hero{
    
    private:
        string name;
        int money;
        int influence;
        int armysize;
        vector<Warrior> warriors;
        int size;
        int herorow;
        int herocol;
        bool ship;
        int points;
        bool hasbattled;

        
        
    public:
        Hero();
        Hero(string, int, int, int, vector<Warrior>, int, int, bool);
        bool crossWater();
        string getname();
        void setname(string);
        int getmoney();
        void addmoney(int);
        void setmoney(int);
        int getinfluence();
        void setinfluence(int);
        void addinfluence(int);
        int getarmysize();
        void setarmysize(int);
        void addarmysize(int);
        void fillvector(vector<Warrior>);
        int getrow();
        void setrow(int);
        int getcol();
        void setcol(int);
        int getvectorsize();
        bool getship();
        void setship(bool);
        int getpoints();
        void addpoints(int);
        void addwarrior(Warrior);
        void removewarrior();
        void erasewarrior(string);
        Warrior getwarrior(int);
        bool gethasbattled();
        void sethasbattled(bool);
        
};
#endif