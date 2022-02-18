#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std; 

//Algorithm: Take lines from file and add them to an array
//1. use file i/o to open and access file
//2. loop thriough file and add numbers to array
//3. print numbers from file and return amount of nums
//input: filename, array, length of array
//return: number of nums in array 

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}

int getLinesFromFile(string filename, int arr[], int length){
    
    ifstream fp;//create file stream
    fp.open(filename); //open file
    if (fp.is_open()){ //test if file is open
        string s;
        int i = 0;
        while(getline(fp,s)){ // take line from file and make string
            
            if(s.length() == 0) continue;
            int number = stoi(s); // number becomes int version of string
            arr[i]= number;
            i++; //number of numbers in array
            if (i == length){ // if its full break out of loop
                break;
            }
            
        }
        fp.close();
        return i;
    }
    else {
        return -1;
    }
}

int main(){
    
    //test case 1
    //expected output: 4,1,2,3,4
    
    int arr[4];
    cout << getLinesFromFile("file.txt",arr, 4 )<< endl;
    printArray(arr,4);
    
    //test case 2
    //expected output: 3,1,2,3
    int arr1[3];
    cout << getLinesFromFile("file.txt",arr1, 3 )<< endl;
    printArray(arr1,3);
}