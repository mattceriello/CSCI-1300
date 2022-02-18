#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
using namespace std; 

void printSeriesSkipFour(int maxValue){
    int sum = 0;
    for (int i = 1; i <= maxValue; i++){
        if (i % 4 != 0){
            cout << i;
            sum += i;
        }
        else {
            cout << "0";
        }
        if (i != maxValue){
            cout << " + ";
        }
    }
    cout << endl;
    cout << "Result of the series is " <<sum << endl;
}






int main(){
   printSeriesSkipFour(5);
   
}