/*Maximum consecutive repeating character in string
Difficulty Level : Easy
Last Updated : 10 May, 2021
Given a string, the task is to find the maximum consecutive repeating character in a string.
Note: We do not need to consider the overall count, but the count of repeating that appears in one place.
Examples: 
 

Input : str = "geeekk"
Output : e

Input : str = "aaaabbcbbb"
Output : a*/
#include <iostream>
#include <string>
using namespace std;

const char consecutiveLetters(string x)
{
    x=x+" ";
    int len = x.length();
    char ch;
    int count=0;
    int max=0;
    for (int i = 0; i < len - 1; i++)
    {
        if (x.at(i) == x.at(i + 1))
            count++;
        if(count>0 && x.at(i)!=x.at(i+1))
        {
            //adding 1 to the last comparasion because if 3 consequetive then count only 2 times so add one to make it complete
            count++;
            if(max<count){
                max=count;
                ch=x.at(i);
                count=0;
            }
        }
    }

    return (max==0)?'?':ch;
}

int main(int argc, char const *argv[])
{
    const char re=consecutiveLetters("geeekk");
    cout<<re<<endl;
    const char r=consecutiveLetters("aaaabbcbbb");
    cout<<r<<endl;
    return 0;
}
