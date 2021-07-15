/*Program for Newton Raphson Method
Difficulty Level : Medium
Last Updated : 06 Apr, 2021
Given a function f(x) on floating number x and an initial guess for root, find root of function in interval. Here f(x) represents algebraic or transcendental equation. 
For simplicity, we have assumed that derivative of function is also provided as input.
Example:

Input: A function of x (for example x3 – x2 + 2),
       derivative function of x (3x2 – 2x for above example)
       and an initial guess x0 = -20
Output: The value of root is : -1.00
        OR any other value close to root.
We have discussed below methods to find root in set 1 and set 2 
Set 1: The Bisection Method 
Set 2: The Method Of False Position
Comparison with above two methods: 
 

In previous methods, we were given an interval. Here we are required an initial guess value of root.
The previous two methods are guaranteed to converge, Newton Rahhson may not converge in some cases.
Newton Raphson method requires derivative. Some functions may be difficult to 
impossible to differentiate.
For many problems, Newton Raphson method converges faster than the above two methods.
Also, it can identify repeated roots, since it does not look for changes in the sign of f(x) explicitly
The formula: 
Starting from initial guess x1, the Newton Raphson method uses below formula to find next value of x, i.e., xn+1 from previous value xn. 
 

newtonraphsonformula

Algorithm: 
Input: initial x, func(x), derivFunc(x) 
Output: Root of Func() 
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/newtonraphsonformula.png)



Compute values of func(x) and derivFunc(x) for given initial x
Compute h: h = func(x) / derivFunc(x)
While h is greater than allowed error ε 
h = func(x) / derivFunc(x)
x = x – h   */
#include<bits/stdc++.h>
#define EPSILON 0.001
using namespace std;
 
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x*x - x*x + 2;
}
 
// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
    return 3*x*x - 2*x;
}
 
// Function to find the root
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);
  
        // x(i+1) = x(i) - f(x) / f'(x) 
        x = x - h;
    }
 
    cout << "The value of the root is : " << x;
}
 
int main(int argc, char const *argv[])
{
    double x0 = -20; // Initial values assumed
    newtonRaphson(x0);
    remove(argv[0]);
    return 0;
}