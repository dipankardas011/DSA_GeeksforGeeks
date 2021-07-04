/*How to efficiently sort a big list dates in 20’s
Difficulty Level : Medium
Last Updated : 31 May, 2021
Geek-O-Lympics
Given a big list of dates in ’20s, how to efficiently sort the list. 
Example: 

Input:
       Date arr[] = {{20,  1, 2014},
                    {25,  3, 2010},
                    { 3, 12, 2000},
                    {18, 11, 2001},
                    {19,  4, 2015},
                    { 9,  7, 2005}}
Output:
      Date arr[] = {{ 3, 12, 2000},
                    {18, 11, 2001},
                    { 9,  7, 2005},
                    {25,  3, 2010},
                    {20,  1, 2014},
                    {19,  4, 2015}}*/
// C++ program to sort an array
// of dates using Radix Sort

#include <bits/stdc++.h>
using namespace std;

// Utilitiy function to obtain
// maximum date or month or year
int getMax(int arr[][3], int n, int q)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i][q]);
    }
    return maxi;
}
// using th eradix sort where every digit wise sorting
// A function to do counting sort of arr[]
// according to given q i.e.
// (0 for day, 1 for month, 2 for year)
void sortDatesUtil(int arr[][3],int n, int q)
{
    int maxi = getMax(arr, n, q);
    int p = 1;
    while (maxi > 0)
    {
        //to extract last digit divide
        // by p then %10
        // Store count of occurrences in cnt[]
        int cnt[10] = {0};

        for (int i = 0; i < n; i++)
        {
            cnt[(arr[i][q] / p) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            cnt[i] += cnt[i - 1];
        }
        int ans[n][3];
        for (int i = n - 1; i >= 0; i--)
        {
            int lastDigit = (arr[i][q] / p) % 10;

            // Build the output array
            for (int j = 0; j < 3; j++)
            {
                ans[cnt[lastDigit] - 1][j] = arr[i][j];
            }
            cnt[lastDigit]--;
        }
        // Copy the output array to arr[],
        // so that arr[] now
        // contains sorted numbers
        // according to current digit
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = ans[i][j];
            }
        }
        // update p to get
        // the next digit
        p *= 10;
        maxi /= 10;
    }
}

// The main function that sorts
// array of dates
// using Radix Sort
void sortDates(int dates[][3], int n)
{
    // First sort by day
    sortDatesUtil(dates, n, 0);

    // Then by month
    sortDatesUtil(dates, n, 1);
    // Finally by year
    sortDatesUtil(dates, n, 2);
}

// A utility function to print an array
void printArr(int arr[][3], int n)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int dates[][3] = {{20, 1, 2014},
                      {25, 3, 2010},
                      {3, 12, 2000},
                      {18, 11, 2000},
                      {19, 4, 2015},
                      {9, 7, 2005}};
    int n = sizeof(dates) / sizeof(dates[0]);

    // Function Call
    sortDates(dates, n);
    cout << "\nSorted Dates\n";
    printArr(dates, n);
    remove(argv[0]);
    return 0;
}
