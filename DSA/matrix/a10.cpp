/*Find row number of a binary matrix having maximum number of 1s

Given a binary matrix (containing only 0 and 1) of order n×n. All rows are sorted already, We need to find the row number with the maximum number of 1s. Also, find the number of 1 in that row. 
Note: in case of a tie, print the smaller row number.
 

Examples : 

Input : mat[3][3] = {0, 0, 1,
                     0, 1, 1,
                     0, 0, 0}
Output : Row number = 2, MaxCount = 2

Input : mat[3][3] = {1, 1, 1,
                     1, 1, 1,
                     0, 0, 0}
Output : Row number = 1, MaxCount = 3

Efficient Approach: Start with the top left corner with index (1, n) and try to go left until you reach the last 1 in that row (jth column), now if we traverse left to that row, we will find 0, so switch to the row just below, with the same column. Now your position will be (2, j) again in the 2nd row if the jth element is 1 try to go left until you find the last 1 otherwise in the 2nd row if jth element is 0 goes to the next row. So Finally say if you are at any ith row and jth column which is the index of last 1 from right in that row, increment i. So now if we have Aij = 0 again increment i otherwise keep decreasing j until you find the last 1 in that particular row. 
Sample Illustration :

Algorithm : 

for (int i=0, j=n-1; i<n;i++)
{
    // find left most position of 1 in a row
    // find 1st zero in a row
    while (arr[i][j]==1) 
    {
        row = i;
        j--;
    }
}
cout << "Row number =" << row+1;
cout << "MaxCount =" << n-j;*/
#include <iostream>
using namespace std;
#define N 4

void maxNoOf1s(int a[][N])
{
    /**
     * @param i is the row iterator
     * @param j is the col iterator
     * @def we need to find the last 1 in that row and use that as reference
    */
    int row=0,j;
    for(int i=0, j=N-1;i<N;i++){
        // find the left most 1
        while(a[i][j]==1 && j>=0){
            row=i;
            j--;
        }
    }
    cout<<"row number= "<<(row+1)<<endl;
    cout<<"the max number"<<(N-1-j)<<endl;
    return;
}

int main(){
    int arr[N][N] = {0, 0, 0, 1,
                     0, 0, 0, 1,
                     0, 0, 0, 0,
                     0, 1, 1, 1};
    maxNoOf1s(arr);
    return 0;
}