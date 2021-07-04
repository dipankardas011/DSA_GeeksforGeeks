/*Make largest palindrome by changing at most K-digits
Difficulty Level : Medium
Last Updated : 11 May, 2021
Given a string containing all digits, we need to convert this string to a palindrome by changing at most K digits. If many solutions are possible then print lexicographically largest one.
Examples: 

Input   : str = “43435”    
          k = 3
Output  : "93939" 
Explanation:
Lexicographically largest palindrome 
after 3 changes is "93939" 

Input :  str = “43435”    
         k = 1
Output : “53435”
Explanation:
Lexicographically largest palindrome 
after 3 changes is “53435”

Input  : str = “12345”    
         k = 1
Output : "Not Possible"
Explanation:
It is not possible to make str palindrome
after 1 change.

Approach:

* Solve this problem using two pointers method. We start from left and right and if both digits are not equal then we replace the smaller value with larger value and decrease k by 1. S
* top when the left and right pointers cross each other, after they stop if value of k is negative, then it is not possible to make string palindrome using k changes. If k is positive, then we can further maximize the string by looping once again in the same manner from left and right and converting both the digits to 9 and decreasing k by 2.
* If k value remains to 1 and string length is odd then we make the middle character as 9 to maximize whole value.*/
#include <iostream>
#include <string>
using namespace std;

string maxPalindromeKCng(string s, int k)
{
    string palin = s;
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            palin[l] = palin[r] = std::max(s[l], s[r]);
            k--;
        }
        l++;
        r--;
    }
    if (k < 0)
        return "not possible";
    l = 0;
    r = s.length() - 1;
    while (l <= r)
    {
        // at mid character if k>0 then change
        // it to 9
        if (l == r)
        {
            if (k > 0)
                palin[l] = '9';
        }
        // if character at lth (same as rth) is
        // less than 9
        if (palin[l] < '9')
        {
            if (k >= 2 && palin[l] == s[l] && palin[r] == s[r])
            {
                k -= 2;
                palin[l] = palin[r] = '9';
            }
            else if (k >= 1 && (palin[l] != s[l] || palin[r] != s[r]))
            {
                k--;
                palin[l] = palin[r] = '9';
            }
        }
        l++;
        r--;
    }
    return palin;
}

int main()
{
    string str = "43435";
    int k = 3;
    cout << maxPalindromeKCng(str, k) << endl;
    return 0;
}