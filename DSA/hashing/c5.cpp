/*Maximum number of chocolates to be distributed equally among k students
Difficulty Level : Hard
Last Updated : 01 Aug, 2018
Given n boxes containing some chocolates arranged in a row. There are k number of students. The problem is to distribute maximum number of chocolates equally among k students by selecting a consecutive sequence of boxes from the given lot. Consider the boxes are arranged in a row with numbers from 1 to n from left to right. We have to select a group of boxes which are in consecutive order that could provide maximum number of chocolates equally to all the k students. An array arr[] is given representing the row arrangement of the boxes and arr[i] represents number of chocolates in that box at position ‘i’.

Examples:

Input : arr[] = {2, 7, 6, 1, 4, 5}, k = 3
Output : 6
The subarray is {7, 6, 1, 4} with sum 18.
Equal distribution of 18 chocolates among
3 students is 6.
Note that the selected boxes are in consecutive order
with indexes {1, 2, 3, 4}.*/
#include <bits/stdc++.h>
using namespace std;

void MaxNoOfChoco(int a[], int n, int k)
{
    int sum[n];
    sum[0]=a[0];
    for(int i=1;i<n;i++)    sum[i]=sum[i-1]+a[i];

    int maxchoco=0;
    unordered_map <int, int> map;
    int currChoco=0;
    for(int i=0;i<n;i++)
    {
        currChoco=sum[i]%k;
        if(currChoco==0)
        {
            // can be divided equally
            // then
            if(maxchoco<sum[i])     
                maxchoco=sum[i];
        }
        else if (map.find(currChoco) == map.end())
        {
            // not present
            map[currChoco] = i;
        }
        // if found
        else
        {
            if (maxchoco < (sum[i] - sum[map[currChoco]]))
                maxchoco = sum[i] - sum[map[currChoco]];
        }
    }
    cout<<"the no of chocolate "<<maxchoco/k<<endl;
}


int main()
{
    int a[] = {2, 7, 6, 1, 4, 5};
    int n=sizeof(a)/sizeof(int);
    MaxNoOfChoco(a,n,3);
    return 0;
}