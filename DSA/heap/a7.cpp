/*Height of a complete binary tree (or Heap) with N nodes
Consider a Binary Heap of size N. We need to find height of it.

Examples :

Input : N = 6
Output : 2
        ()
      /    \
     ()     ()
    /  \    /
  ()    () ()

Input : N = 9
Output :
        ()
      /    \
     ()     ()
    /  \    /  \
  ()    () ()   ()
 / \
()  ()
*/
#include <bits/stdc++.h>

int height(int N)
{
	return ceil(log2(N+1)) -1 ;
}
//ceil(log2(N+1)) – 1.
int main()
{
	int N=6;
	std::cout<<"the size of complete bTree= "<<N<<"\n";
	std::cout<<"the height = "<<height(N)<<std::endl;
	return 0;
}