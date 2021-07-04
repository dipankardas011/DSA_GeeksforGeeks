/*Disjoint Set Data Structures

Consider a situation with a number of persons and following tasks to be performed on them.

Add a new friendship relation, i.e., a person x becomes friend of another person y.
Find whether individual x is a friend of individual y (direct or indirect friend)
Example:

We are given 10 individuals say,
a, b, c, d, e, f, g, h, i, j

Following are relationships to be added.
a <-> b  
b <-> d
c <-> f
c <-> i
j <-> e
g <-> j

And given queries like whether a is a friend of d
or not.

We basically need to create following 4 groups
and maintain a quickly accessible connection
among group items:
G1 = {a, b, d}
G2 = {c, f, i}
G3 = {e, g, j}
G4 = {h}
Problem : To find whether x and y belong to same group or not, i.e., to find if x and y are direct/indirect friends.

Solution : Partitioning the individuals into different sets according to the groups in which they fall. This method is known as disjoint set data structure which maintains collection of disjoint sets and each set is represented by its representative which is one of its members.

Approach:



How to Resolve sets ? Initially all elements belong to different sets. After working on the given relations, we select a member as representative. There can be many ways to select a representative, a simple one is to select with the biggest index.
Check if 2 persons are in the same group ? If representatives of two individuals are same, then they’ll become friends.
 
Data Structures used:
Array : An array of integers, called parent[]. If we are dealing with n items, i’th element of the array represents the i’th item. More precisely, the i’th element of the array is the parent of the i’th item. These relationships create one, or more, virtual trees.

Tree : It is a disjoint set. If two elements are in the same tree, then they are in the same disjoint set. The root node (or the topmost node) of each tree is called the representative of the set. There is always a single unique representative of each set. A simple rule to identify representative is, if i is the representative of a set, then parent[i] = i. If i is not the representative of his set, then it can be found by traveling up the tree until we find the representative.

 
Operations :

Find : Can be implemented by recursively traversing the parent array until we hit a node who is parent of itself.

// Finds the representative of the set  
// that i is an element of
int find(int i) 
{
    // If i is the parent of itself
    if (parent[i] == i) 
    {
        // Then i is the representative of 
        // this set
        return i;
    }
    else 
    {
        // Else if i is not the parent of 
        // itself, then i is not the 
        // representative of his set. So we 
        // recursively call Find on its parent
        return find(parent[i]);
    }
}
Union: It takes, as input, two elements. And finds the representatives of their sets using the find operation, and finally puts either one of the trees (representing the set) under the root node of the other tree, effectively merging the trees and the sets.

// Unites the set that includes i 
// and the set that includes j
void union(int i, int j) 
{
    // Find the representatives
    // (or the root nodes) for the set
    // that includes i
    
    int irep = this.Find(i),

    // And do the same for the set 
    // that includes j    
    int jrep = this.Find(j);

    // Make the parent of i’s representative
    // be j’s  representative effectively 
    // moving all of i’s set into j’s set)
    this.Parent[irep] = jrep;
}
Improvements (Union by Rank and Path Compression)
The efficiency depends heavily on the height of the tree. We need to minimize the height of tree in order improve the efficiency. We can use Path Compression and Union by rank methods to do so.

Path Compression (Modifications to find()) : It speeds up the data structure by compressing the height of the trees. It can be achieved by inserting a small caching mechanism into the Find operation. Take a look at the code for more details:

// Finds the representative of the set that i
// is an element of.
int find(int i) 
{
    // If i is the parent of itself
    if (Parent[i] == i) 
    {
        // Then i is the representative 
        return i;
    }
    else
    { 
        // Recursively find the representative.
        int result = find(Parent[i]);

        // We cache the result by moving i’s node 
        // directly under the representative of this
        // set
        Parent[i] = result;
       
        // And then we return the result
        return result;
     }
}
Union by Rank: First of all, we need a new array of integers called rank[]. Size of this array is same as the parent array. If i is a representative of a set, rank[i] is the height of the tree representing the set.
Now recall that, in the Union operation, it doesn’t matter which of the two trees is moved under the other (see last two image examples above). Now what we want to do is minimize the height of the resulting tree. If we are uniting two trees (or sets), let’s call them left and right, then it all depends on the rank of left and the rank of right.



If the rank of left is less than the rank of right, then it’s best to move left under right, because that won’t change the rank of right (while moving right under left would increase the height). In the same way, if the rank of right is less than the rank of left, then we should move right under left.
If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will always be one greater than the rank of the trees.

// Unites the set that includes i and the set 
// that includes j
void union(int i, int j) 
{
    // Find the representatives (or the root nodes) 
    // for the set that includes i
    int irep = this.find(i);

    // And do the same for the set that includes j
    int jrep = this.Find(j);

    // Elements are in same set, no need to 
    // unite anything.    
    if (irep == jrep)
        return;

    // Get the rank of i’s tree
    irank = Rank[irep],

    // Get the rank of j’s tree
    jrank = Rank[jrep];

    // If i’s rank is less than j’s rank
    if (irank < jrank) 
    {
        // Then move i under j
        this.parent[irep] = jrep;
    } 

    // Else if j’s rank is less than i’s rank
    else if (jrank < irank) 
    {
        // Then move j under i
        this.Parent[jrep] = irep;
    } 

    // Else if their ranks are the same
    else
    {

        // Then move i under j (doesn’t matter
        // which one goes where)
        this.Parent[irep] = jrep;

        // And increment the result tree’s 
        // rank by 1
        Rank[jrep]++;
    }
}
*/
// C++ implementation of disjoint set
#include <iostream>
using namespace std;
class DisjSet {
    int *rank, *parent, n;
  
public:
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
  
    // Creates n single item sets
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
  
    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
  
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);
  
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
  
        return parent[x];
    }
  
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
  
        // If they are already in same set
        if (xset == yset)
            return;
  
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
  
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
  
int main()
{
    DisjSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
  
    return 0;
}