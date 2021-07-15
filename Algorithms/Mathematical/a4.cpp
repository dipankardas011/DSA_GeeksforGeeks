/*Space and time efficient Binomial Coefficient
Difficulty Level : Medium
Last Updated : 22 Mar, 2021
Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k). 
Example: 
 

Input: n = 4 and k = 2
Output: 6
Explanation: 4 C 2 is 4!/(2!*2!) = 6

Input: n = 5 and k = 2
Output: 10
Explanation: 5 C 2 is 5!/(3!*2!) = 20
We have discussed a O(n*k) time and O(k) extra space algorithm in this post. The value of C(n, k) can be calculated in O(k) time and O(1) extra space.
Solution:
 

C(n, k) 
= n! / (n-k)! * k!
= [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) * 
                            ( k * (k-1) * .... * 1 ) ]
After simplifying, we get
C(n, k) 
= [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]

Also, C(n, k) = C(n, n-k)  
// r can be changed to n-r if r > n-r 
 

Change r to n-r if r is greater than n-r. and create a variable to store the answer.
Run a loop from 0 to r-1
In every iteration update ans as (ans*(n-i))/(i+1) where i is the loop counter.
So the answer will be equal to ((n/1)*((n-1)/2)*…*((n-r+1)/r!) which is equal to nCr.*/
#include <iostream>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n = 8, k = 2;
    std::cout << "Value of C(" << n << ", " << k << ") is " << binomialCoeff(n, k) << std::endl;

    remove(argv[0]);
    return 0;
}