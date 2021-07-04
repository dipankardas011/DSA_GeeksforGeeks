/*Reverse words in a given string

Example: Let the input string be “i like this program very much”. The function should change the string to “much very program this like i”

reverse-words

Examples: 

Input: s = “geeks quiz practice code” 
Output: s = “code practice quiz geeks”

Input: s = “getting good at coding needs a lot of practice” 
Output: s = “practice of lot a needs coding at good getting” */
#include <iostream>
#include <vector>
using namespace std;

void revWord(string s)
{
    s=s+" ";
    string word="";
    vector<string> cWord;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
            word += s[i];
        else{
            cWord.push_back(word);
            word.clear();
        }
    }
    for(int i=cWord.size()-1 ; i>=0; i--)
        cout<<cWord.at(i)<<" ";
    cout<<endl;
}

int main(){
    string ss="i am dipankar das";
    revWord(ss);
    return 0;
}