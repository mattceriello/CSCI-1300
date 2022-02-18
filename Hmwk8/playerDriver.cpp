#include "Player.h"
#include "Player.cpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;



int main(){
    //test case 1
    //expected output: 0
    Player me;
    cout << me.getPoints() << endl;
    
    //test case 2
    //expected output: Kobe
    Player kobe("Kobe", 82);
    cout << kobe.getName() <<endl;
    
    
}