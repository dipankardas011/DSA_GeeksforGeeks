/*Replace a character c1 with c2 and c2 with c1 in a string S
Difficulty Level : Basic
Last Updated : 04 May, 2021
Given a string S, c1 and c2. Replace character c1 with c2 and c2 with c1. 
Examples: 
 

Input : grrksfoegrrks,
        c1 = e, c2 = r 
Output : geeksforgeeks 

Input : ratul,
        c1 = t, c2 = h 
Output : rahul*/
#include <iostream>
#include <string>
using namespace std;

void replaceC1_C2(std::string& s, char c1, char c2){
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i) == c1)
            s.at(i)=c2;
        else if(s.at(i)==c2)
            s.at(i)=c1;
        else
            continue;
    }
}
int main(){
    string str="grrksfoegrrks";
    char c1='e', c2='r';
    replaceC1_C2(str,c1,c2);
    cout<<str<<endl;
    return 0;
}