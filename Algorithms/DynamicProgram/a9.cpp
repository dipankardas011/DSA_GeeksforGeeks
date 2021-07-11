/*Count possible ways to construct buildings
Difficulty Level : Medium
Last Updated : 31 Mar, 2021
Given an input number of sections and each section has 2 plots on either sides of the road. Find all possible ways to construct buildings in the plots such that there is a space between any 2 buildings.

Example : 

N = 1
Output = 4
Place a building on one side.
Place a building on other side
Do not place any building.
Place a building on both sides.

N = 3 
Output = 25
3 sections, which means possible ways for one side are 
BSS, BSB, SSS, SBS, SSB where B represents a building 
and S represents an empty space
Total possible ways are 25, because a way to place on 
one side can correspond to any of 5 ways on other side.

N = 4 
Output = 64*

We can simplify the problem to first calculate for one side only. If we know the result for one side, we can always do square of the result and get result for two sides.

A new building can be placed on a section if section just before it has space. A space can be placed anywhere (it doesn’t matter whether the previous section has a building or not).

Let countB(i) be count of possible ways with i sections
              ending with a building.
    countS(i) be count of possible ways with i sections
              ending with a space.

// A space can be added after a building or after a space.
countS(N) = countB(N-1) + countS(N-1)

// A building can only be added after a space.
countB[N] = countS(N-1)

// Result for one side is sum of the above two counts.
result1(N) = countS(N) + countB(N)

// Result for two sides is square of result1(N)
result2(N) = result1(N) * result1(N) */
/*Optimized Solution: 
Note that the above solution can be further optimized. If we take closer look at the results, for different values, we can notice that the results for two sides are squares of Fibonacci Numbers.
N = 1, result = 4 [result for one side = 2] 
N = 2, result = 9 [result for one side = 3] 
N = 3, result = 25 [result for one side = 5] 
N = 4, result = 64 [result for one side = 8] 
N = 5, result = 169 [result for one side = 13] 
…………………… 
……………………
In general, we can say */
#include <iostream>

// or using memorization
/*0 1 2 3 4 5 6 7 ..
0 1 1 (2 3 5 8 13)..*/
int fib(int n)
{
    // bottom up manner
    // just increasing the storage
    int L[n+3];
    L[0]=0;
    L[1]=1;
    for(int i=2;i<=n+2;i++)
    {
        L[i]=L[i-1]+L[i-2];
    }
    // printf("~~~ %d\n",L[n+2]);
    return L[n+2];
}

int countways(int n)
{
    if(n==1)
        return 4;// 2 for one side and 4 in total

    // countB is count of ways with a building at the end
    // countS is count of ways with a space at the end
    // prev_countB and prev_countS are previous values of
    // countB and countS respectively.
    int countB=1,
        countS=1,
        prevCountB,
        prevCountS;

    for(int i=2;i<=n;i++)
    {
        prevCountB=countB;
        prevCountS=countS;

        countS=prevCountB+prevCountS;
        countB=prevCountS;
    }
    int res=countS+countB;
    return (res*res);
}

int main(int argc, char const *argv[])
{
    int N = 3;
    std::cout << "Count of ways for " << N
         << " sections is " << countways(N)<<std::endl;

    std::cout<<"count of ways for 1 section= "<<(fib(1))*(fib(1))<<std::endl;
    std::cout<<"count of ways for 2 section= "<<(fib(2))*(fib(2))<<std::endl;
    std::cout<<"count of ways for 3 section= "<<(fib(3))*(fib(3))<<std::endl;
    std::cout<<"count of ways for 4 section= "<<(fib(4))*(fib(4))<<std::endl;
    remove(argv[0]);
    return 0;
}
