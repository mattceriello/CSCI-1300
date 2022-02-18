#ifndef Map_h
#define Map_h
#include "Tile.cpp"
#include <string>
using namespace std;


class Map{
    
    private:
        
        int occupied;
        
        
    public:
        Map();
        void usermap(int, int);
        void updatemap(int,int,bool);
        
    

};
#endif