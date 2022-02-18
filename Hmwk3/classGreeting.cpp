// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 3 - Problem 3

#include <vector>
#include <iostream>
using namespace std;

//Algorithm: Take an argument and use it to output
//Input parameters: Course Number (int)
//Output: Hello, CS (course Number) World
//Returns: nothing

void classGreeting(int course_number){
    
   cout << "Hello, CS " << course_number << " World!" << endl; //output phrase with number
     
}


int main(){
    vector<int> yo;
    for(int i =0 ; i < 10; i++){
        yo.push_back(i);
    }
    
    yo.erase(yo.begin() + 5);
    
    for(int i =0; i < yo.size();i++){
        cout << yo[i] << endl;
    }
}