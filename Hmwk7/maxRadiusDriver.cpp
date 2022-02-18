#include <iostream>
#include "Planet.h"
#include <string> 
#include "Planet.cpp"

//Algorithm: Find the index of the largest radius in the set
//1. loop through planets
//2. if the radius is larger than the temp largest, updats with new largest value
//3. if there is a duplicate for largest raius, return the first
//input: array of planet pbjects, int size
//return: index of largest radius

int maxRadius(Planet objects[], int size){
    int maxidx = 0;
    if (objects[0].getName() == ""){ //test if the array is empty
        return -1;
    }
    for (int i = 0; i < size; i++){ //loop through array of planets
        if (i != 0){
            if(objects[i].getRadius() > objects[maxidx].getRadius()){ // test if radius is bigger than previous biggest radius
                maxidx = i; //if so, update variable
            }
            else if(objects[i].getRadius() == objects[maxidx].getRadius()){ // if largest radius appears twice, return first
                return maxidx;
            }
        }
    }
    return maxidx;
}

int main(){
    
    
    //test case 1
    //expected output: -1
    Planet planets1[3];
    int idx1 = maxRadius(planets1, 0);
    cout << idx1 << endl;
    
    //test case 2
    //expected ouput: hEllo
    //                20
    //                33510.3
    Planet planets[3];
    planets[0] = Planet("hELLO",20);
    planets[1] = Planet("YES",10);
    planets[2] = Planet("9",20);
    int idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    
}