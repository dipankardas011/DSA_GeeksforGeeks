/*Number of subsequences in a string divisible by n

Given a string consisting of digits 0-9, count the number of subsequences in it divisible by m.
Examples: 
 

Input  : str = "1234", n = 4
Output : 4
The subsequences 4, 12, 24 and 124 are 
divisible by 4.
 
Input  : str = "330", n = 6
Output : 4
The subsequences 30, 30, 330 and 0 are 
divisible by n.

Input  : str = "676", n = 6
Output : 3
The subsequences 6, 6 and 66*/
#include <bits/stdc++.h>
using namespace std;
/*This problem can be recursively defined. Let remainder of a string with value x be ‘r’ when divided with n. Adding one more character to this string changes its remainder to (r*10 + newdigit) % n. For every new character, we have two choices, either add it in all current subsequences or ignore it. Thus, we have an optimal substructure. Following shows the brute force version of this:
 

string str = "330";
int n = 6

// idx is value of current index in str
// rem is current remainder
int count(int idx, int rem)
{
    // If last character reached
    if (idx == n)
        return (rem == 0)? 1 : 0;

    int ans = 0;

    // we exclude it, thus remainder
    // remains the same
    ans += count(idx+1, rem);

    // we include it and thus new remainder
    ans += count(idx+1, (rem*10 + str[idx]-'0')%n);

    return ans;
}*/
int subString(string s, int k){
    int len=s.length();
    /**
     * @task
     * division by n can leave only n remainder [0..n-1] dp[i][j] indicates number of subsequences in string [0..i] which leaves remainder j after divisionn by n
     */
    int dp[len][k];
    memset(dp,0,sizeof(dp));
    // filling value for first digit in s
    dp[0][ (s[0]-'0')%k ]++;
    for(int i=1;i<len;i++)
    {
        dp[i][ (s[i]-'0')%k ]++;
        for(int j=0;j<k;j++){
            // excluding the ith char from all the current subsequence of string[0..i-1]
            dp[i][j] += dp[i-1][j];
            
            //including ith character in all cureent subsequences of string [0...i-1]
            dp[i][ (j*10 + (s[i]-'0'))%k ] += dp[i-1][j];
        }
    }
    return dp[len-1][0];
}

int main(){
    cout<<subString("1234",4)<<endl;
    cout<<subString("330",6)<<endl;
    cout<<subString("676",6)<<endl;
    return 0;
}