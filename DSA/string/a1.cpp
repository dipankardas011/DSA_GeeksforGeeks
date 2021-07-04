/*Maximum and minimum sums from two numbers with digit replacements
Difficulty Level : Easy
Last Updated : 05 May, 2021
Given two positive numbers calculate the minimum and maximum possible sums of two numbers. We are allowed to replace digit 5 with digit 6 and vice versa in either or both the given numbers.
Examples : 
 

Input  : x1 = 645 x2 = 666
Output : Minimum Sum: 1100 (545 + 555)
         Maximum Sum: 1312 (646 + 666)

Input: x1 = 5466 x2 = 4555
Output: Minimum sum: 10010
        Maximum Sum: 11132*/
#include <iostream>
#include <string>
using namespace std;

int createNum(int num, int from, int dest)
{
    int multp=1;
    int yyy=0;
    while(num>0){
        int d=num%10;
        if(d==from)
            yyy += dest*multp;
        else
            yyy += d*multp;
        num/=10;
        multp*=10;
    }
    return yyy;
}

static void replacementDigit(int n1, int n2){
    cout<<"the min:"<<(createNum(n1, 6, 5)+createNum(n2,6,5))<<endl;
    cout<<"the max:"<<(createNum(n1, 5, 6)+createNum(n2,5,6))<<endl;
}

int main(){
    int num1,num2;
    cout<<"x1: ";
    cin>>num1;
    cout<<"x2: ";
    cin>>num2;
    replacementDigit(num1, num2);
    return 0;
}