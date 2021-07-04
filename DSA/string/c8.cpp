/*gOOGLE cASE of a given sentence

Given a sentence, the task is to rewrite in Google Case. It is a style of writing where we replace all lower case letters into upper case letters leaving the initial of all the words.

Examples : 

Input : gEEks fOr GeeKs
Output : gEEKS fOR gEEKS 

Input : I got intern at geeksforgeeks
Output : i gOT iNTERN aT gEEKSFORGEEKS */
#include <iostream>
#include <string>
using namespace std;

void convert(string s){
    s=s+ " ";
    s[0]=tolower(s[0]);
    for(int i=1;i<s.length(); i++)
    {
        if(s[i]==' '&& i!=s.length()-1)
        {
            s[i+1]=tolower(s[i+1]);
            i++;
        }
        else
            s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
}

int main(){
    string str="I got intern at geeksforgeeks";
    convert(str);
    return 0;
}