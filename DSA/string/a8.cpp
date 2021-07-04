/*Count of words whose i-th letter is either (i-1)-th, i-th, or (i+1)-th letter of given word

Given a string str. The task is to count the words having the same length as str and each letter at the i-th position is either (i-1)-th, i-th, or (i+1)-th position letter of str.
Note: For the first letter consider i-th and (i+1)-th position letter of W. And for last letter consider (i-1)-th and i-th position letter of str.
Examples: 

Input : str[] = "ab"
Output : 4
Words that can be formed: aa, ab, ba, bb.

Input : str[] = "x"
Output : 1*/
#include <iostream>
#include <cstring>
using namespace std;

int countWords(char str[], int len)
{
    int count=1;
    // if word contain single letter, return 1
    if(len==1)
        return count;
    // first letter
    if(str[0]==str[1])
        count *=1;
    else
        count *=2;

    for(int j=1;j<len-1; j++)
    {
        if(str[j]==str[j-1] && str[j]==str[j+1])
            count *=1;
        else if(str[j]==str[j-1] || str[j]==str[j+1] || str[j-1]==str[j+1])
            count *=2;
        // if all 3 are different
        else
            count *=3;
    }
    // last element check
    if(str[len-1] == str[len-2])
        count *=1;
    else
        count *=2;
    
    return count;
}

int main(){
    char str[]="abc";
    int len=strlen(str);
    cout<<"the no. of possibilities= "<<countWords(str,len)<<endl;
    return 0;
}