#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

//Algorithm: split a string and store each part in an array
//1.loop through string and add char to new word
//2. when delimiter is hit, add totaled string to an index in new array
//3. repeat until the whole string is split up
//input: string to split, array to add to, deilimiter, length of array
//return: number of parts added to array




void printArray(string arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}

int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {//test if string length is 0
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;// add delimiter to end
    for (int i = 0; i < str.length(); i++) //loop through string
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            
            words[k] = word;//add part of string to array 
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];// add characters to temp string
        }
    }
    return j;
    
}

int main(){
    
    //test case 1
    //expected ouput: one
    //              small
    //              step
    string words[6];
    split("one small step", ' ', words, 6);
    printArray(words, 6);
    
    //test case 2
    //expected ouput: one
    //              small
    //              step
    string words1[6];
    split("one/small//step", '/', words1, 6);
    printArray(words, 6);
    
    
}