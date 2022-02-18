#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
using namespace std; 

//ifstream myfile;

void printArray(int arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << endl;
    }
}




int getlinesfromfile(string filename, int arr[], int length){
    
    ifstream fp;
    fp.open(filename);
    if (fp.is_open()){
        string s;
        int i = 0;
        while(getline(fp,s)){
            if(s.length() == 0) continue;
            int number = stoi(s);
            arr[i]= number;
            i++;
        }
        fp.close();
        return i;
    }
    else {
        cout << "Open Failed"<< endl;
    }
}

int main(){
    int arr[4];
    cout << getlinesfromfile("filename.txt",arr, 4 )<< endl;
    printArray(arr,4);
}