#include <iostream>
#include "Planet.h"
#include <string>
#include "Planet.cpp"

using namespace std;

int main(){
    //test case 1
    //expected output: 10
    
    string a = "A";
    Planet p2(a, 10);
    cout << p2.getRadius() << endl;
    
    //test case 2
    //expected ouput: A

    string name = "A";
    Planet earth(name, 10);
    cout << earth.getName() << endl;
}