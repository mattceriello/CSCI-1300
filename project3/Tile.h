#ifndef Tile_h
#define Tile_h
#include <string>
using namespace std;

class Tile{
    
    private:
        
        bool dragonglass;
        int money;
        int points;
        int armysize;
        string letter;
        
        
    public:
        Tile();
        Tile(string);
        bool isWater();
        bool isLand();
        bool isCity();
        bool isFree();
        bool controlledBy();
        string getLetter();
        int getpoints();
        void setpoints(int);
        int getarmysize();
        void setarmysize(int);
        void setdragonglass(bool);
    
};
#endif