/*Program to find Normal and Trace of a matrix

Given a 2D matrix, the task is to find Trace and Normal of matrix.
Normal of a matrix is defined as square root of sum of squares of matrix elements.
Trace of a n x n square matrix is sum of diagonal elements.
Examples : 
 

Input : mat[][] = {{7, 8, 9},
                   {6, 1, 2},
                   {5, 4, 3}};
Output : Normal = 16  
         Trace  = 11
Explanation : 
Normal = sqrt(7*7+ 8*8 + 9*9 + 6*6 +
              1*1 + 2*2 + 5*5 + 4*4 + 3*3)   
       = 16
Trace  = 7+1+3 = 11

Input :mat[][] = {{1, 2, 3},
                  {6, 4, 5},
                  {2, 1, 3}};
Output : Normal = 10  
         Trace = 8
Explanation : 
Normal = sqrt(1*1 +2*2 + 3*3 + 6*6 + 4*4 + 
             5*5 + 2*2 + 1*1 + 3*3)   
Trace = 8(1+4+3)*/
#include <iostream>
#include <cmath>
using namespace std;
#define N 3
/**
 * @def to find the trace and normal
*/
pair<int, int> calMatrix(int a[][N])
{
    int trace=0;
    int norm=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            norm += pow(a[i][j], 2);
            if(i==j)
                trace += a[i][j];
        }
    }
    norm = sqrt(norm);
    return (make_pair(norm, trace));
}

int main(){
    int mat[][N] = {{1, 2, 3},
                  {6, 4, 5},
                  {2, 1, 3}};
    pair<int, int> re = calMatrix(mat);
    cout<<"norm = "<<re.first<<", trace= "<<re.second<<endl;
    return 0;
}