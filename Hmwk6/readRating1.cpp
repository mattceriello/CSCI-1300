#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

int readRatings(string filename){
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        int i = 0;
        string line = "";
        while(getline(file,line)){
            if(line.length() == 0) continue;
            cout << i << ": "<< line << endl;
            i++;
        }
        
        file.close();
        
    }
    
}

int main(){
    
    readRatings("ratings.txt");
}