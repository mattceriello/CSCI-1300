#include "Map.h"
#include "Tile.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <string>
using namespace std;


Map::Map(){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 16; j++){
            map[i][j] = Tile();
        }
    }  
    
}

void Map::usermap(int row, int col){
    //print usermap in 7x7 format
}




