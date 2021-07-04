/*Minimum cost to sort a matrix of numbers from 0 to n^2 – 1

Given an n x n matrix containing all the numbers in the range 0 to n2-1. The problem is to calculate the total energy required for rearranging all the numbers in the matrix in strictly increasing order, i.e., after the rearrangement, the 1st row contains ‘n’ numbers from 0 to n-1, then 2nd row from n to 2n-1, and so on up to the last or nth row. A number can be moved in any of the four directions left, right, top, or bottom from its current position to reach its destination in the final modified matrix. The number of steps moved in transferring a number from its current location to its required destination is the energy required by the number for its movement. For example, in a 4 x 4 matrix, the number ‘6’ is present at location (2, 3). Its destination location in the modified matrix is (1, 1). So ‘6’ is moved 2 steps towards left and 1 step up to reach location (1, 1). Total 3 steps moved and thus the energy required by ‘6’ is 3 units. In this way, we have to sum up all the energies required in the movement/rearrangement of all the numbers.
Examples : 
 

Input : mat[][] = { {3, 0},
                    {2, 1} }
Output : 4 units
For number '3':
Move it one step right and one step down.
Total 2 steps thus energy required = 2 units.

For number '0':
Move it one step left.
Total 1 step thus energy required = 1 unit.

For number '1':
Move it one step up.
Total 1 step thus energy required = 1 unit.

Total energy required = 4 units.

Input : mat[][] = { {4, 7, 10, 3},
                {8, 5, 6, 1},
                  {9, 11, 10, 2},
            {15, 13, 14, 12} }                      
Output : 22 units*/
/**
 * @def calculateEnergy(mat, n):
    Declare i_des, j_des, q
    Initialize tot_energy = 0
    for i = 0 to n-1
        for j = 0 to n-1
        q = mat[i][j] / n
        i_des = q
        j_des = mat[i][j] - (n * q)
        tot_energy += abs(i_des - i) + abs(j_des - j)    
    return tot_energy
*/
#include <iostream>
using namespace std;
#define N 4

int calculateCostOfSort(int a[][N]){
    int cost=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int q=a[i][j] / N;
            int iD = q;
            int jD=a[i][j] - (N*q);
            cost += abs(iD-i)+abs(jD-j);
        }
    }
    return cost;
}

int main()
{
    int a[][N] = {{4, 7, 0, 3},
                 {8, 5, 6, 1},
                 {9, 11, 10, 2},
                 {15, 13, 14, 12}};
    cout<<"The cost is = $"<<calculateCostOfSort(a)<<endl;
    return 0;
}