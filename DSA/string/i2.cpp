/*Program to validate an IP address
Difficulty Level : Medium
Last Updated : 09 Nov, 2020
Write a program to Validate an IPv4 Address. 
According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1

Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Following are steps to check whether a given string is a valid IPv4 address or not:

step 1) Parse string with “.” as delimiter using “strtok()” function. 

e.g.ptr = strtok(str, DELIM);

step 2) 
A) If ptr contains any character which is not digit then return 0 
B) Convert “ptr” to decimal number say ‘NUM’ 
C) If NUM is not in range of 0-255 return 0 
D) If NUM is in range of 0-255 and ptr is non-NULL increment “dot_counter” by 1 
E) if ptr is NULL goto step 3 else goto step 1
step 3) if dot_counter != 3 return 0 else return 1*/
#include <bits/stdc++.h>
using namespace std;

bool isNumrange(int num){
    if(num>=0 && num<=255)  return true;
    else    return false;
}

bool isValidIP(string str)
{
    // there must be 3 dots
    int countDots = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);
        if (ch == '.')
            countDots++;
        else
        {
            if (ch < 48 and ch > 57)
            {
                return false;
            }
        }
    }
    if (countDots != 3)
        return false;
    
    // now extract the numbers
    str+='.';
    string word;
    int number=0;
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)!='.')
            word+=str.at(i);
        else{
            if(word.length()==0)    return false;
            int num=stoi(word);
            if(isNumrange(num)){
                number++;
            }
            else{
                return false;
            }

            word.clear();
        }
    }
    if(number==4)
        return true;
    else    return false;
}

int main()
{
    string ip1 = "128.0.0.1";
    string ip2 = "125.16.100.1";
    string ip3 = "125.512.100.1";
    string ip4 = "125.512.100.abc";
    cout<<((isValidIP(ip1))?"Valid":"InValid")<<endl;
    cout<<((isValidIP(ip2))?"Valid":"InValid")<<endl;
    cout<<((isValidIP(ip3))?"Valid":"InValid")<<endl;
    cout<<((isValidIP(ip4))?"Valid":"InValid")<<endl;
    return 0;
}