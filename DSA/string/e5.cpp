/*Program to print all palindromes in a given range
Difficulty Level : Easy
Last Updated : 29 Apr, 2021
Given a range of numbers, print all palindromes in the given range. For example if the given range is {10, 115}, then output should be {11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111}*/
#include <iostream>
using namespace std;

bool isPalindrome(int num){
    int rev=0;
    for(int i=num;i>0;i/=10){
        rev=rev*10 + i%10;
    }
    return (num==rev)?true:false;
}

int main(){
    int a=10,b=115;
    cout<<"{ ";
    for(int i=a;i<=b;i++)
        if(isPalindrome(i))
            cout<<i<<" ";
    cout<<"}"<<endl;
}