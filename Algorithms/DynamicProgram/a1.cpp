/*Longest Common Subsequence | DP-4
Difficulty Level : Medium
Last Updated : 30 Sep, 2019
We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively. We also discussed one example problem in Set 3. Let us discuss Longest Common Subsequence (LCS) problem as one more example problem that can be solved using Dynamic Programming.

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2n. So a string of length n has 2n-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2n). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.

It is a classic computer science problem, the basis of diff (a file comparison program that outputs the differences between two files), and has applications in bioinformatics.

Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
optimized sol
#include <iostream>
#include <cstring>

int lcs(char* x, char* y, int m, int n)
{
    if(m==0 || n==0)
        return 0;
    if(x[m-1] == y[n-1])    // same element
        return 1+lcs(x,y,m-1,n-1);

    else
        return std::max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
}

int main(int argc, char const *argv[])
{
    char x[]="aggtab";
    char y[]="gxtxayb";
    int m=strlen(x);
    int n=strlen(y);
    std::cout<<"length of longest subsequence = "<<lcs(x,y,m,n)<<std::endl;
    remove(argv[0]);
    return 0;
}
Output:
Length of LCS is 4
Time complexity of the above naive recursive approach is O(2^n) in worst case and worst case happens when all characters of X and Y mismatch i.e., length of LCS is 0.
Considering the above implementation, following is a partial recursion tree for input strings “AXYT” and “AYZX”

                         lcs("AXYT", "AYZX")
                       /                 
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /               
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")

to traace back the longest subsequence 
we need to start from the right hand corner 
step 1-->>
if ele is not the max of top and left ele then ✔
    move diagonally up
step 2-->>
else
        if it is can from the max of top || left go there
        then check the step 1<<-->>

        and when the ele ==  0 then (STOP)
*/
#include <iostream>
#include <cstring>

int lcs(char* x, char* y, int m, int n)
{
    int L[m+1][n+1];
    int i,j;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){

            if(i==0 || j==0)
                L[i][j]=0;
            else if(x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1]+1;    // diagonal element + 1 if it matches

            else
                L[i][j]=std::max(L[i-1][j],L[i][j-1]);  // maximum of left and top cell
        }
    }
    return L[m][n];// return last element
}
int main(int argc, char const *argv[])
{
    char x[]="aggtab";
    char y[]="gxtxayb";
    int m=strlen(x);
    int n=strlen(y);
    std::cout<<"length of longest subsequence = "<<lcs(x,y,m,n)<<std::endl;
    remove(argv[0]);
    return 0;
}