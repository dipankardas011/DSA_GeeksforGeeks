/*Given an array of size n and a number k, find all elements that appear more than n/k times
Difficulty Level : Hard
Last Updated : 22 Jun, 2021
Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3. */
#include <iostream>
#include <map>
using namespace std;

void printElements(int arr[],int n ,int k)
{
    int x=n/k;
    map<int, int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    
    for(int it=0;it<mp.size();it++)
        if(mp[it]>x)
            cout<<(it)<<endl;

}

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    printElements(arr, n, k);
    return 0;
}
