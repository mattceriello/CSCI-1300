#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std; 

//Algorithm: print a map depending on values in a 2d array
//1. loop though with nested for loop and test each value
//2. if value is less than or equal to water level, print "*"
//3. if value is over water value, print "_"
//input: array, row, water level
//ouput: none

void floodMap(double arr[][4], int row, double water){
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < 4; j++ ){
            if (arr[i][j] <= water){ //test if value in array is under water level
                
                cout << '*';
            }
            else if(arr[i][j] > water){//test if value in array is over water level
                 
                 cout << '_';
            }
        }
        cout<< endl;
    }
    
    
    
}


int main(){
    
    //test case 1
    //expected output:*__*
                    //**_*
    double arr[][4] = {{0.2, 0.8, 0.8, 0.2},
                       {0.2, 0.2, 0.8, 0.5}};
    floodMap(arr,2,0.5);
    
    //test case 2
    //expected output:____
                    //____
    double arr1[][4] = {{0.2, 0.8, 0.8, 0.2},
                       {0.2, 0.2, 0.8, 0.5}};
    floodMap(arr,2,0.0);
}