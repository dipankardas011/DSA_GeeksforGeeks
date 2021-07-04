/*Following is an interesting problem that can be easily solved with the help of qsort() and comparator function.
Given an array of integers, sort it in such a way that the odd numbers appear first and the even numbers appear later. The odd numbers should be sorted in descending order and the even numbers should be sorted in ascending order.

The simple approach is to first modify the input array such that the even and odd numbers are segregated followed by applying some sorting algorithm on both parts(odd and even) separately.

However, there exists an interesting approach with a little modification in comparator function of Quick Sort. The idea is to write a comparator function that takes two addresses p and q as arguments. Let l and r be the number pointed by p and q. The function uses following logic:
1) If both (l and r) are odd, put the greater of two first.
2) If both (l and r) are even, put the smaller of two first.
3) If one of them is even and other is odd, put the odd number first.*/
#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p, const void *q){
    int l=*(const int *)p;
    int r=*(const int *)q;
    // if both odd put the greater of two first
    if((l&1) && (r&1))
        return (r-l);
    // both even put the samalles in first
    if(!(l&1) && !(r&1))
        return (l-r);
    // lis even put r first
    if(!(l&1))
        return 1;

    // if l is odd put l first
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[]={1,6,43,1,445,234,5,2};
    int size=sizeof arr / sizeof arr[0];
    qsort(arr,size,sizeof arr[0], comparator);
    printf("the output: ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    remove(argv[0]);
    return 0;
}
