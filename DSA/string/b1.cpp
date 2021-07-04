/*Given a binary string, count number of substrings that start and end with 1.

Given a binary string, count number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int numberOfSubstring(string f){
    int count=0;
    // the formula m(m-1)/2
    for(int i=0;i<f.length();i++)
        if(f[i]=='1')   count++;

    return (count*(count-1)/2);
}

int main(){
    string a="00100101";
    cout<<"the number of substrings = "<<numberOfSubstring(a)<<endl;
    return 0;
}