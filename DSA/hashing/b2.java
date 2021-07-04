/*Maximum possible sum of a window in an array such that elements of same window in other array are unique
Difficulty Level : Medium
Last Updated : 07 May, 2019
Given two arrays A and B of equal number of elements. Task is to find the maximum sum possible of a window in array B such that elements of same window in A[] are unique.

Examples:

Input : A = [0, 1, 2, 3, 0, 1, 4] 
        B = [9, 8, 1, 2, 3, 4, 5]
Output : sum = 20
The maximum sum possible in B[] such that 
all corresponding elements in A[] are unique 
is (9+8+1+2) = 20.

Input : A = [0, 1, 2, 0, 2]
        B = [5, 6, 7, 8, 2]
Output :sum = 21*/
package hashing;
import java.util.HashSet;
import java.util.Set;

class d11
{

	static int findsum(int a[], int b[], int n)
	{
		Set<Integer> mp=new HashSet<Integer>();
		int result=0;
		int curr_sum=0, curr_begin=0;
		for(int i=0;i<n;i++)
		{
			while(mp.contains(a[i]))
			{
				mp.remove(a[curr_begin]);
				curr_sum-=b[curr_begin];
				curr_begin++;
			}
			mp.add(a[i]);
			curr_sum+=b[i];
			result=Integer.max(result, curr_sum);
		}
		return result;
	}
	public static void main(String[] args) {
		int a[]={0,1,2,3,0,1,4};
		int b[]={9,8,1,2,3,4,5};
		int n=a.length;
		System.out.println(findsum(a,b,n));
	}
}