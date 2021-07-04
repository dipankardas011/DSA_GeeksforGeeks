/*Search a Word in a 2D Grid of characters
Difficulty Level : Medium
Last Updated : 23 Mar, 2021
Given a 2D grid of characters and a word, find all occurrences of the given word in the grid. A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match in this direction (not in zig-zag form).
The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically Down and 4 Diagonal directions.
Example: 

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0
Explanation: 'GEEKS' can be found as prefix of
1st 2 rows and suffix of first row

Input:  grid[][] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
        word = "EEE"

Output: pattern found at 0, 2
        pattern found at 0, 10
        pattern found at 2, 2
        pattern found at 2, 12
Explanation: EEE can be found in first row 
twice at index 2 and index 10
and in second row at 2 and 12

Source: Microsoft Interview Question.*/
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
// searching for in all 8 directions
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool search2D(char *grid, int row, int col, string word, int R, int C)
{
    // if first charcter of word doesn't match with given starting point in grid
    if (*(grid + row * C + col) != word[0])
        return false;
    int len = word.length();

    for (int dir = 0; dir < 8; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];
        // first character is already checked match remaining charaacter
        for (k = 1; k < len; k++)
        {
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
            if (*(grid + rd * C + cd) != word[k])
                break;

            rd += x[dir], cd += y[dir];
        }
        if (k == len)
            return true;
    }
    return false;
}

void patternSearch(char *grid, string word, int R, int C)
{
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern founf at = " << row << ", " << col << endl;
    }
}

int main(int argc, char const *argv[])
{
    int r = 3, c = 13;
    char grid[r][c] = {"geeksforgeeks",
                       "geeksquizgeek",
                       "ideqapractice"};
    patternSearch((char *)grid, "geeks", r, c);
    cout << endl;
    patternSearch((char *)grid, "eee", r, c);
    cout << endl;
    return 0;
}
