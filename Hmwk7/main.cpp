#include <iostream>
#include "Planet.h"

using namespace std;

int main(){
    Planet p1;
    string a = "A";
    Planet p2(a, 10);
    cout << p2.getRadius() << endl;
}