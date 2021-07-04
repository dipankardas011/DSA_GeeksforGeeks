/*Camel case of a given sentence
Difficulty Level : Easy
Last Updated : 03 May, 2021
Given a sentence, task is to remove spaces from the sentence and rewrite in Camel case. It is a style of writing where we don’t have spaces and all words begin with capital letters.
Examples: 
 

Input  : I got intern at geeksforgeeks
Output : IGotInternAtGeeksforgeeks

Input :  Here comes the garden
Output : HereComesTheGarden*/
#include <iostream>
#include <string>
using std::string;;
using std::cout;
using std::endl;

void camelCase(string s){
    string fr="";
    fr=toupper(s[0]);
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            fr+=toupper(s[i+1]);
            i++;
        }
        else
            fr+=tolower(s[i]);
    }
    cout<<fr<<endl;
}

int main(int argc, char const *argv[])
{
    string str="I got intern at geeksforgeeks";
    camelCase(str);
    return 0;
}
