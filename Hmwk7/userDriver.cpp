#include <iostream>
#include "User.h"
#include <string>
#include "User.cpp"

using namespace std;

int main(){
    
    //test case 1
    //expected output: Matt Ceriello
    int testRate[10] = {11,22,33,44,55,66,77,88,99,100};
    User me = User("Matt Ceriello", testRate, 10);
    cout << me.getRatingAt(10) << endl;
   
    //test case 2
    //expected output: You
    
    User you = User();
    you.setUsername("You");
    //cout << you.getUsername() << endl;

    
}