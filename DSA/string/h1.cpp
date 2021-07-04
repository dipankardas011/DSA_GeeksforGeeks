/*Cost to Balance the parentheses
Difficulty Level : Medium
Last Updated : 25 May, 2021
Parenthesis are said to be balanced when every opening brace has a closing brace like “()()” or “(())” or “(()())” etc. Incorrect balancing includes “)(” or “))((”  etc. The task here is to correct the sequence of parenthesis in such a way that it is done in minimum cost. And shifting of parenthesis by over one parentheses costs 1. If the parenthesis can’t be balanced then print -1.
Examples :

Input : () 
Output : 0 
Explanation : Already balanced
Input : ))(( 
Output : 4 
Explanation : Firstly, ) at position 1st goes to the last position, costing 3, so we get )((). Then, ) at position 1st goes to the 2nd position costing 1. So, finally we get ()(). Therefore, the total cost is 4.

Algorithm :  

Store the braces in string.
Run a loop to string size to store the count of opening and closing braces.
Check if number of opening brace is equal to number of closing brace or not.
If the braces are not equal then print -1 depicting that the string cant be balanced. Else proceed further.
Initially, Check at 0th index that whether the string contains opening brace or closing brace. If we get an opening brace then store +1 in the array at index 0, else if closing brace is present then place -1 at 0th index.
Now run a loop from 1st index to array length.
If opening brace is present at index i then add +1 to value at previous index i.e. i-1 and store sum at index i.
If closing brace is present at index i then add -1 to value at previous index i.e. i-1 and store sum at index i.
If value at index i is negative i.e less than 0, then add the absolute value of array[i] into a variable(ans in below program).
Finally we get the minimum cost in variable ans.*/
#include <bits/stdc++.h>
using namespace std;

int costToBalance(string s){
    if(s.length()==0)
        cout<<0<<endl;
    int ans=0;
    /**
     * @param o for opening brackets
     * @param c for closing brackets
     */
    int o=0,c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')
            o++;
        if(s[i]==')')
            c++;
    }
    if(o!=c)
        return -1;
    int a[s.size()];
    if(s[0]=='(')
        a[0]=1;
    else
        a[0]=-1;

    if(a[0]<0)
        ans+=abs(a[0]);
    for(int i=1;i<s.length();i++)
    {
        if(s[i]=='(')
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1]-1;
        if(a[i]<0)
            ans+=abs(a[i]);
    }
    return ans;
}

int main(){
    string s;
    s=")))(((";
    cout<<costToBalance(s)<<endl;
    s="))((";
    cout<<costToBalance(s)<<endl;
    return 0;
}