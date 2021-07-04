/*Recursive function to do substring search
Difficulty Level : Easy
Last Updated : 23 May, 2019
Given a text txt[] and a pattern pat[], write a recursive function “contains(char pat[], char txt[])” that returns true if pat[] is present in txt[], otherwise false.

Examples:

1) Input:   txt[] =  "THIS IS A TEST TEXT"
            pat[] = "TEST"
  Output:  true


2) Input:  txt[] =  "geeksforgeeks"
           pat[] = "quiz"
  Output:  false;
We strongly recommend to minimize the browser and try this yourself first.

Below is recursive algorithm.

contains(tex[], pat[])
    1) If the current character is the last character of the text, but pat
       has more characters, return false.

    2) Else If the current character is the last character of the pattern,
       then return true

    3) Else If current characters of pat and text match, then
        return contains(text + 1, pat + 1);

    4) Else If current characters of pat and text don't match
        return contains(text + 1, pat);*/
#include <iostream>
using namespace std;

bool match(char *text, char *pat){
    if(*text=='\0' && *pat!='\0')
        return false;
    if(*pat=='\0')
        return true;
    
    if(*text==*pat)
    return match(text+1,pat+1);
return false;
}

bool contains(char *text, char *pat){
    if(*text=='\0')
        return false;
    
    if(*text==*pat)
    {
        if(match(text,pat)) return 1;
        else    return contains(text+1,pat);
    }
    return contains(text+1,pat);
}


int main(){
    cout<<contains("geeksforgeeks","geeks")<<endl;
    cout<<contains("geeksforgeeks","geeksquiz")<<endl;
    cout<<contains("geeksquizgeeks","quiz")<<endl;

    return 0;
}