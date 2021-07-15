/*Sieve of Eratosthenes
Difficulty Level : Medium
Last Updated : 31 Mar, 2021
 
Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 

Example: 

Input : n =10
Output : 2 3 5 7 

Input : n = 20 
Output: 2 3 5 7 11 13 17 19

The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so (Ref Wiki).
*/
#include <iostream>
#include <string.h>

void sieveOfEratosthenes(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(int p=2; p*p<=n;p++){
        if(prime[p]==true)
        {
            for(int i=p*p; i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int p=2;p<=n;p++)
        if(prime[p]) // when it is true
            std::cout<<p<<' ';
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    int n=30;sieveOfEratosthenes(n);
    remove(argv[0]);
    return 0;
}
/*https://www.codecogs.com/eqnedit.php?latex=\frac{n}{2}&space;+&space;\frac{n}{3}&space;+&space;\frac{n}{5}&space;+&space;\frac{n}{7}&space;+&space;......&space;p*/