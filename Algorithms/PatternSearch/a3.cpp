/*Pattern Searching | Set 6 (Efficient Construction of Finite Automata)
Difficulty Level : Hard
Last Updated : 06 Jul, 2021
In the previous post, we discussed Finite Automata based pattern searching algorithm. The FA (Finite Automata) construction method discussed in previous post takes O((m^3)*NO_OF_CHARS) time. FA can be constructed in O(m*NO_OF_CHARS) time. In this post, we will discuss the O(m*NO_OF_CHARS) algorithm for FA construction. The idea is similar to lps (longest prefix suffix) array construction discussed in the KMP algorithm. We use previously filled rows to fill a new row. 
 
![](https://media.geeksforgeeks.org/wp-content/uploads/autometa1.png)
![](https://media.geeksforgeeks.org/wp-content/uploads/autometa2.png)

The above diagrams represent graphical and tabular representations of pattern ACACAGA.
Algorithm: 
1) Fill the first row. All entries in first row are always 0 except the entry for pat[0] character. For pat[0] character, we always need to go to state 1. 
2) Initialize lps as 0. lps for the first index is always 0. 
3) Do following for rows at index i = 1 to M. (M is the length of the pattern) 
…..a) Copy the entries from the row at index equal to lps. 
…..b) Update the entry for pat[i] character to i+1. 
…..c) Update lps “lps = TF[lps][pat[i]]” where TF is the 2D array which is being constructed. 
*/
#include <iostream>
#include <string.h>
#define NO_OF_CHARS 256

void debug(int TF[][NO_OF_CHARS], int M)
{
    /* stored in output.txt 
    g++ a3.cpp && ./a.out > output.txt
    */
    std::cout<<"Debug ---"<<std::endl;
    for(int i=0;i<=M;i++)
    {
        printf("%d\n",i);
        for(int j=0;j<NO_OF_CHARS;j++)
            if(TF[i][j]==M)
                printf("\tindex %d : %d\n",j,TF[i][j]);
    }

}
 
/* This function builds the TF table
which represents Finite Automata for a
given pattern */
void computeTransFun(char* pat, int M, int TF[][NO_OF_CHARS])
{
    int i, lps = 0, x;
 
    // Fill entries in first row
    for (x = 0; x < NO_OF_CHARS; x++)
        TF[0][x] = 0;

    TF[0][pat[0]] = 1;
 
    // Fill entries in other rows
    for (i = 1; i <= M; i++) 
    {
        // Copy values from row at index lps
        for (x = 0; x < NO_OF_CHARS; x++)
            TF[i][x] = TF[lps][x];

        // Update the entry corresponding to this character
        TF[i][pat[i]] = i + 1;

        // Update lps for next row to be filled
        if (i < M)
            lps = TF[lps][pat[i]];
        debug(TF,M+1);
    }
}
 
/* Prints all occurrences of pat in txt */
void search(char pat[], char txt[])
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    int TF[M + 1][NO_OF_CHARS];
 
    computeTransFun(pat, M, TF);
 
    // process text over FA.
    int i, j = 0;
    for (i = 0; i < N; i++) {
        j = TF[j][txt[i]];
        if (j == M) {
            std::cout<<"~~~ Output ~~~\n";
            std::cout << "pattern found at index " << i - M + 1 << std::endl;
        }
    }
}
 
int main(int argc, char const *argv[])
{
    char txt[] = "ACACACACAGAAGA ACACAGAACACAGA GEEKS";
    char pat[] = "ACACAGA";
    search(pat, txt);

    remove(argv[0]);
    return 0;
}
