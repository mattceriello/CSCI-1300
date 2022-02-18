#ifndef Game_h
#define Game_h
#include "Hero.h"
//#include "Map.h"
#include "City.h"
#include "Tile.h"
#include <string>
#include <vector> 
using namespace std;


class Game{
    
    private:
        
        Hero user;
        Tile map[25][16];
        char minimap[7][7];
        int turns;
        bool gameover;
        bool outofbounds;
        vector<Hero> heroes;
        vector<Warrior> warriors1;
        vector<City> cities;
        

        
        
    public:
        Game();
        void intro();
        void userencounter();
        void otherecnounter();
        void initiatedg();
        void setwarriors();
        void printminimap();
        void promptturn();
        bool travel();
        bool rest();
        bool consult();
        int randommove();
        bool givespeech(int);
        bool buyout(int);
        bool battle(int);
        bool isoutofbounds(int,int);
        bool gainwarrior();
        bool getgameover();
        void updateotherheroes();
        void setgameover(bool);
        void readmap(string);
        void readhero(string);
        void readwarrior(string);
        void readcity(string);
        void findfreewar(int, int);
        int generaterow();
        int generatecol();
        void randomevents();
        void adddragon();
        void stannis();
        void sansa();
        void cersei();
        void mandatory();
        
        
        
    
};
#endif