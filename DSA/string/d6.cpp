/*Put spaces between words starting with capital letters
You are given an array of characters which is basically a sentence. However, there is no space between different words and the first letter of every word is in uppercase. You need to print this sentence after following amendments: 
(i) Put a single space between these words. 
(ii) Convert the uppercase letters to lowercase.
Examples: 
 

Input : BruceWayneIsBatman
Output : bruce wayne is batman

Input :  You
Output :  you*/
#include <iostream>
#include<string>
#include <cstring>
using namespace std;

string convertString(string s){
    string fr="";
    fr=tolower(s.at(0));
    for(int i=1;i<s.length();i++)
    {
        if(isupper(s.at(i))){
            fr=fr+" ";
            fr+=tolower(s.at(i));
        }
        else{
            fr+=s.at(i);
        }
    }
    return fr;
}

int main(int argc, char const *argv[])
{
    string s1="BruceWayneIsBatman";
    string res=convertString(s1);
    cout<<res<<endl;
    string s2="You";
    string re=convertString(s2);
    cout<<re<<endl;
    return 0;
}
