/*Split numeric, alphabetic and special symbols from a String
Difficulty Level : Easy
Last Updated : 16 Jun, 2021
Given string str, divide the string into three parts one containing a numeric part, one containing alphabetic, and one containing special characters. 

Examples: 

Input : geeks01for02geeks03!!!
Output :geeksforgeeks
        010203
        !!!
Here str = "Geeks01for02Geeks03!!!", we scan every character and 
append in res1, res2 and res3 string accordingly.

Input : **Docoding123456789everyday##
Output :Docodingeveryday
        123456789
        **##
        */
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str="**Docoding123456789everyday##";
    string r1,r2,r3;
    for(int i=0;i<str.length();i++)
    {
        if(isalpha(str[i]))
            r1+=str[i];
        
        else if(isdigit(str[i]))
            r2+=str[i];
        else
            r3+=str[i];
    }
    cout<<r1<<endl<<r2<<endl<<r3<<endl;

    return 0;
}