#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <locale>
#include <sstream>
#include <iomanip>
using namespace std;

int split (string str, char c, string words[], int length)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int j = 0;
    int k = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            
            words[k] = word;
            k++;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j;
}







int calcPay(string filename){
    int entries = 0;
    double total = 0.0;
    ifstream file;
    file.open(filename);
    if(file.is_open()){
        string line = "";
        string linearr[3];
        double hours;
        double rate;
        double emppay = 0.0;
        
        
        while(getline(file,line)){
            if(line.length() == 0) continue;
            split(line, ',', linearr, 3);
            hours = stod(linearr[1]);
            rate = stod(linearr[2]);
            emppay = hours*rate;
            cout << linearr[0] << ": " << emppay <<endl;
            total += emppay;
            entries++;
        }

        
    }
    else{
        return -1;
    }
    
    cout <<"Total: " << total<< endl;
    
    return entries;
    
}





int main(){
    cout << calcPay("test.txt") <<endl;
}