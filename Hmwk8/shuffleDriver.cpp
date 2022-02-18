// CS1300 Spring 2019
// Author: Matt Ceriello
// Recitation: 304 – Shudong Hao 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mattceriello/work
// Homwework 8 - Problem 1
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


//Algorithm: Take 2 vectors and alternate them
//1. determine size of both vectors
//2. assign values from both vectors into new vector alternating
//3. return new vector
//input: v1 vector - v2 vector
vector<int> shuffle(vector<int> v1, vector<int> v2){
    
    int size1 = v1.size();
    int size2 = v2.size();
    vector<int> v3;
    int size3 = size1 + size2; 
    if(size1 == 0){ //return v2 if v1 is empty
        return v2;
    }
    else if(size2 == 0){//return v1 if v2 is empty
        return v1;
    
    }
    if(size1 > size2){ //if v1 is larger than v2 start with v1
        for (int i = 0; i < size1; i++){
            v3.push_back(v1[i]); //assign to new vector
            if(i < size2){ //only assign while v2 is in bounds
                v3.push_back(v2[i]);
            }
        }
        
    }
    else if(size2 > size1){ //if v2 is larger than v1
        for (int i = 0; i < size2; i++){
            
            v3.push_back(v2[i]);
            
            if(i < size1){ //only assign while v1 is in bounds
                v3.push_back(v1[i]);
             }
            
        }
       
    }
    else if(size1 == size2){ 
        for (int i = 0; i < size1; i++){ //alternate when sizes are equal
            v3.push_back(v1[i]);
            v3.push_back(v2[i]);
        }
    }
    return v3;
}




int main(){
    //test case 1
    //expected output: 3 1 4 2 5
    vector<int> v4{1,2};
    vector<int> v5{3,4,5};
    vector<int> v6 = shuffle(v4,v5);
    for (int i=0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    cout << endl;
    
    
    //test case 2
    //expected output: 1 3 2 4 7 5 6 9
    vector<int> v1{1,2,7,6,9};
    vector<int> v2{3,4,5};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
}
