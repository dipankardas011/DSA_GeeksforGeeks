/*Count minimum steps to get the given desired array
onsider an array with n elements and value of all the elements is zero. 
We can perform following operations on the array.

Incremental operations:Choose 1 element from the array and increment its value 
by 1.
Doubling operation: Double the values of all the elements of array.
Examples:

Input: target[] = {2, 3}
Output: 4
To get the target array from {0, 0}, we 
first increment both elements by 1 (2 
operations), then double the array (1 
operation). Finally increment second
element (1 more operation)

Input: target[] = {2, 1}
Output: 3
One of the optimal solution is to apply the 
incremental operation 2 times to first and 
once on second element.

Input: target[] = {16, 16, 16}
Output: 7
The output solution looks as follows. First 
apply an incremental operation to each element. 
Then apply the doubling operation four times. 
Total number of operations is 3+4 = 7
*/
#include <stdio.h>
int i,j;
int find_steps(int target[], int n){
    int arr[n];
    for(i=0;i<n;i++)
        arr[i]=0;
    
    int no_steps=0;
    while(1){
        int count_zero=0;
        for(i=0;i<n;i++)
            if(arr[i] == target[i])
                count_zero++;
        if(count_zero == n)
            break;
        
        for(i=0;i<n;i++){
            if(arr[i] == target[i])
                continue;

            if((target[i]-arr[i])%2 == 0)
                arr[i] += 2;
            else
                arr[i]++;
            // printf("%d\t",arr[i]);
            
        }no_steps++;
        // printf("\n");
    }

    return no_steps;
}

int main(){
    int N;
    printf("enter the size for the target arr[]: ");
    scanf("%d",&N);

    int target[N];

    printf("enter the element\n");
    for(i=0;i<N;i++)
        scanf("%d",target+i);

    printf("\nminimum steps to get the given target array: %d\n",find_steps(target, N));
}