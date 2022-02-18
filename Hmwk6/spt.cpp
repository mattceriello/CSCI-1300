#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>


int split(string str, char c, string arr[], int length){
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == c) {
        	if (word.length() == 0) continue;
            cout << word << endl; 
            j++;
            word = "";
        } 
        else {
            word = word + str[i];
        }
    }
    return j ;
}

int main(){
    string words[6];
    cout << split("one small step", ' ', words, 6) << endl;
}