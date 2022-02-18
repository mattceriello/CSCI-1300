#ifndef Warrior_h
#define Warrior_h
#include <string>
using namespace std;


class Warrior{
    
    private:
        string name;
        int strength;
        int loyalty;
        int morale;
        bool isfree;
        bool ship;
        bool dragonGlass;
        int row;
        int col;
        
        
    public:
        Warrior();
        Warrior(string, int, int, int, bool, bool, bool);
        string getname();
        int getstrength();
        void setstrength(int);
        void addstrength(int);
        int getloyalty();
        void setloyalty(int);
        void addloyalty(int);
        int getmorale();
        void setmorale(int);
        void addmorale(int);
        bool getisfree();
        void setisfree(bool);
        void setlocation(int, int);
        int getrow();
        int getcol();
        bool getship();
        bool getdragonglass();
        
};
#endif