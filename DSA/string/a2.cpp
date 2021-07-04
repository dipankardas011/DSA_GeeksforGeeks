/*Sum of two large numbers
Difficulty Level : Medium
Last Updated : 07 Jun, 2021
Given two numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find sum of these two numbers.

Examples: 

Input  : str1 = "3333311111111111", 
         str2 =   "44422222221111"
Output : 3377733333332222

Input  : str1 = "7777555511111111", 
         str2 =    "3332222221111"
Output : 7780887733332222*/
#include <bits/stdc++.h>
using namespace std;

string Adder(string str1, string str2)
{
    int carrynum=0;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    string res="";
    // finding the min length and to dtermine it
    if(str1.length() > str2.length())
        swap(str1,str2);
    // making the str2 as largest and str1 as smallest
    for(int i=0;i<str1.length();i++)
    {
        int sum=(str1.at(i)-'0') + (str2.at(i)-'0') + carrynum;
        res.push_back(sum%10 + '0');
        carrynum=sum/10;
    }
    // remaing digits
    for(int i=str1.length(); i<str2.length(); i++){
        int sum=(str2.at(i) - '0') + carrynum;
        res.push_back(sum%10 + '0');
        carrynum=sum/10;
    }
    if(carrynum>0){
        res.push_back(carrynum+'0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s1=string("3333311111111111");
    string s2=string("44422222221111");
    cout<<"the addition of = "<<Adder(s1,s2)<<endl;

    string s3=string("7777555511111111");
    string s4=string("3332222221111");
    cout<<"the addition of = "<<Adder(s3,s4)<<endl;
    return 0;
}