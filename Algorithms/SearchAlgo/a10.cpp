/*Check if there exist two elements in an array whose sum is equal to the sum of rest of the array
Difficulty Level : Easy
Last Updated : 19 Apr, 2021
We have an array of integers and we have to find two such elements in the array such that sum of these two elements is equal to the sum of rest of elements in array. 
Examples: 
 

Input  : arr[] = {2, 11, 5, 1, 4, 7}
Output : Elements are 4 and 11
Note that 4 + 11 = 2 + 5 + 1 + 7

Input  : arr[] = {2, 4, 2, 1, 11, 15}
Output : Elements do not exist

An efficient solution is to find sum of all array elements. Let this sum be “sum”. Now the task reduces to finding a pair with sum equals to sum/2. 
Another optimization is, a pair can exist only if the sum of whole array is even because we are basically dividing it into two parts with equal sum.
1- Find the sum of whole array. Let this sum be “sum” 
2- If sum is odd, return false. 
3- Find a pair with sum equals to “sum/2” using hashing based method discussed here as method 2. If a pair is found, print it and return true. 
4- If no pair exists, return false.*/
#include <iostream>
#include <unordered_set>
using namespace std;

bool checkPair(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i];

    sum /= 2;
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        int val=sum-arr[i];
        if(s.find(val)!=s.end()){
            cout<<"pair elements are "<<arr[i]<<" and "<<val<<endl;
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main(){
    int arr[]={2,11,5,1,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(!checkPair(arr,n))   cout<<"no pair"<<endl;
    return 0;
}