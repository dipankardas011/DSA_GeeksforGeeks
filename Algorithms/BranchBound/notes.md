# 0/1 Knapsack using Branch and Bound
Difficulty Level : Medium
Last Updated : 20 Nov, 2018
Branch and bound is an algorithm design paradigm which is generally used for solving combinatorial optimization problems. These problems typically exponential in terms of time complexity and may require exploring all possible permutations in worst case. Branch and Bound solve these problems relatively quickly.

Let us consider below 0/1 Knapsack problem to understand Branch and Bound.

Given two integer arrays val[0..n-1] and wt[0..n-1] that represent values and weights associated with n items respectively. Find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to Knapsack capacity W.

Let us explore all approaches for this problem.

1. A Greedy approach is to pick the items in decreasing order of value per unit weight. The Greedy approach works only for fractional knapsack problem and may not produce correct result for 0/1 knapsack.
2. We can use Dynamic Programming (DP) for 0/1 Knapsack problem. In DP, we use a 2D table of size n x W. The DP Solution doesn’t work if item weights are not integers.
3. Since DP solution doesn’t alway work, a solution is to use Brute Force. With n items, there are 2n solutions to be generated, check each to see if they satisfy the constraint, save maximum solution that satisfies constraint. This solution can be expressed as tree.
![i2](https://media.geeksforgeeks.org/wp-content/uploads/knapsack1.jpg)

4. We can use Backtracking to optimize the Brute Force solution. In the tree representation, we can do DFS of tree. If we reach a point where a solution no longer is feasible, there is no need to continue exploring. In the given example, backtracking would be much more effective if we had even more items or a smaller knapsack capacity.

![i4](https://media.geeksforgeeks.org/wp-content/uploads/knapsack2.jpg)

### Branch and Bound

The backtracking based solution works better than brute force by ignoring infeasible solutions. We can do better (than backtracking) if we know a bound on best possible solution subtree rooted with every node. If the best in subtree is worse than current best, we can simply ignore this node and its subtrees. So we compute bound (best solution) for every node and compare the bound with current best solution before exploring the node.
Example bounds used in below diagram are, A down can give $315, B down can $275, C down can $225, D down can $125 and E down can $30. In the next article, we have discussed the process to get these bounds.

![i5](https://media.geeksforgeeks.org/wp-content/uploads/knapsack3.jpg)

Branch and bound is very useful technique for searching a solution but in worst case, we need to fully calculate the entire tree. At best, we only need to fully calculate one path through the tree and prune the rest of it.

Source:
Above images and content is adopted from following nice link. http://www.cse.msu.edu/~torng/Classes/Archives/cse830.03fall/Lectures/Lecture11.ppt

---->> [a1.cpp]

# 8 puzzle Problem using Branch And Bound
Difficulty Level : Hard
Last Updated : 07 Jul, 2021
We have introduced Branch and Bound and discussed the 0/1 Knapsack problem in the below posts. 

Branch and Bound | Set 1 (Introduction with 0/1 Knapsack)
Branch and Bound | Set 2 (Implementation of 0/1 Knapsack)
In this puzzle solution of the 8 puzzle problem is discussed. 
Given a 3×3 board with 8 tiles (every tile has one number from 1 to 8) and one empty space. The objective is to place the numbers on tiles to match the final configuration using the empty space. We can slide four adjacent (left, right, above, and below) tiles into the empty space. 

For example, 

![8puzzle](https://media.geeksforgeeks.org/wp-content/uploads/puzzle8init.jpg)

1. DFS (Brute-Force) 
We can perform a depth-first search on state-space (Set of all configurations of a given problem i.e. all states that can be reached from the initial state) tree. 
 

![image(6)](https://media.geeksforgeeks.org/wp-content/uploads/puzzle-1.jpg)

State Space Tree for 8 Puzzle
In this solution, successive moves can take us away from the goal rather than bringing us closer. The search of state-space tree follows the leftmost path from the root regardless of the initial state. An answer node may never be found in this approach.
2. BFS (Brute-Force) 
We can perform a Breadth-first search on the state space tree. This always finds a goal state nearest to the root. But no matter what the initial state is, the algorithm attempts the same sequence of moves like DFS.
3. Branch and Bound 
The search for an answer node can often be speeded by using an “intelligent” ranking function, also called an approximate cost function to avoid searching in sub-trees that do not contain an answer node. It is similar to the backtracking technique but uses a BFS-like search.
There are basically three types of nodes involved in Branch and Bound 
1. Live node is a node that has been generated but whose children have not yet been generated. 
2. E-node is a live node whose children are currently being explored. In other words, an E-node is a node currently being expanded. 
3. Dead node is a generated node that is not to be expanded or explored any further. All children of a dead node have already been expanded.
Cost function: 
Each node X in the search tree is associated with a cost. The cost function is useful for determining the next E-node. The next E-node is the one with the least cost. The cost function is defined as 
```
   C(X) = g(X) + h(X) where
   g(X) = cost of reaching the current node 
          from the root
   h(X) = cost of reaching an answer node from X.
```
The ideal Cost function for an 8-puzzle Algorithm : 
We assume that moving one tile in any direction will have a 1 unit cost. Keeping that in mind, we define a cost function for the 8-puzzle algorithm as below: 
```
   c(x) = f(x) + h(x) where
   f(x) is the length of the path from root to x 
        (the number of moves so far) and
   h(x) is the number of non-blank tiles not in 
        their goal position (the number of mis-
        -placed tiles). There are at least h(x) 
        moves to transform state x to a goal state
```
An algorithm is available for getting an approximation of h(x) which is an unknown value.

Complete Algorithm: 
```
/* Algorithm LCSearch uses c(x) to find an answer node
 * LCSearch uses Least() and Add() to maintain the list 
   of live nodes
 * Least() finds a live node with least c(x), deletes
   it from the list and returns it
 * Add(x) adds x to the list of live nodes
 * Implement list of live nodes as a min-heap */

struct list_node
{
   list_node *next;

   // Helps in tracing path when answer is found
   list_node *parent; 
   float cost;
} 

algorithm LCSearch(list_node *t)
{
   // Search t for an answer node
   // Input: Root node of tree t
   // Output: Path from answer node to root
   if (*t is an answer node)
   {
       print(*t);
       return;
   }
   
   E = t; // E-node

   Initialize the list of live nodes to be empty;
   while (true)
   {
      for each child x of E
      {
          if x is an answer node
          {
             print the path from x to t;
             return;
          }
          Add (x); // Add x to list of live nodes;
          x->parent = E; // Pointer for path to root
      }

      if there are no more live nodes
      {
         print ("No answer node");
         return;
      }
       
      // Find a live node with least estimated cost
      E = Least(); 

      // The found node is deleted from the list of 
      // live nodes
   }
}
```
The below diagram shows the path followed by the above algorithm to reach the final configuration from the given initial configuration of the 8-Puzzle. Note that only nodes having the least value of cost function are expanded.

![](https://media.geeksforgeeks.org/wp-content/uploads/20210129083853/puzzle81-215x300.jpg)

----->> [a2.cpp]


# Job Assignment Problem using Branch And Bound
Difficulty Level : Expert
Last Updated : 01 Jun, 2021
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

![jobassignment](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment.png)

Let us explore all approaches for this problem.

Solution 1: Brute Force 
We generate n! possible job assignments and for each such assignment, we compute its total cost and return the less expensive assignment. Since the solution is a permutation of the n jobs, its complexity is O(n!).

Solution 2: Hungarian Algorithm 
The optimal assignment can be found using the Hungarian algorithm. The Hungarian algorithm has worst case run-time complexity of O(n^3).



Solution 3: DFS/BFS on state space tree 
A state space tree is a N-ary tree with property that any path from root to leaf node holds one of many solutions to given problem. We can perform depth-first search on state space tree and but successive moves can take us away from the goal rather than bringing closer. The search of state space tree follows leftmost path from the root regardless of initial state. An answer node may never be found in this approach. We can also perform a Breadth-first search on state space tree. But no matter what the initial state is, the algorithm attempts the same sequence of moves like DFS.

Solution 4: Finding Optimal Solution using Branch and Bound 
The selection rule for the next node in BFS and DFS is “blind”. i.e. the selection rule does not give any preference to a node that has a very good chance of getting the search to an answer node quickly. The search for an optimal solution can often be speeded by using an “intelligent” ranking function, also called an approximate cost function to avoid searching in sub-trees that do not contain an optimal solution. It is similar to BFS-like search but with one major optimization. Instead of following FIFO order, we choose a live node with least cost. We may not get optimal solution by following node with least promising cost, but it will provide very good chance of getting the search to an answer node quickly.

There are two approaches to calculate the cost function:  

For each worker, we choose job with minimum cost from list of unassigned jobs (take minimum entry from each row).
For each job, we choose a worker with lowest cost for that job from list of unassigned workers (take minimum entry from each column).
In this article, the first approach is followed.

Let’s take below example and try to calculate promising cost when Job 2 is assigned to worker A. 

![jobassignment2](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment2.png)

Since Job 2 is assigned to worker A (marked in green), cost becomes 2 and Job 2 and worker A becomes unavailable (marked in red). 

![jobassignment3](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment3.png)



Now we assign job 3 to worker B as it has minimum cost from list of unassigned jobs. Cost becomes 2 + 3 = 5 and Job 3 and worker B also becomes unavailable. 

![jobassignment4](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment4.png)

Finally, job 1 gets assigned to worker C as it has minimum cost among unassigned jobs and job 4 gets assigned to worker C as it is only Job left. Total cost becomes 2 + 3 + 5 + 4 = 14. 

![jobassignment5](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment5.png)

Below diagram shows complete search space diagram showing optimal solution path in green. 

![jobassignment6](https://media.geeksforgeeks.org/wp-content/cdn-uploads/jobassignment6.png)

Complete Algorithm: 
```
/* findMinCost uses Least() and Add() to maintain the
   list of live nodes

   Least() finds a live node with least cost, deletes
   it from the list and returns it

   Add(x) calculates cost of x and adds it to the list
   of live nodes

   Implements list of live nodes as a min heap */


// Search Space Tree Node
node
{
   int job_number;
   int worker_number;
   node parent;
   int cost;
}

// Input: Cost Matrix of Job Assignment problem
// Output: Optimal cost and Assignment of Jobs
algorithm findMinCost (costMatrix mat[][])
{
   // Initialize list of live nodes(min-Heap)
   // with root of search tree i.e. a Dummy node
   while (true)
   {
      // Find a live node with least estimated cost
      E = Least();

      // The found node is deleted from the list
      // of live nodes
      if (E is a leaf node)
      {
         printSolution();
         return;
      }

     for each child x of E
     {
         Add(x); // Add x to list of live nodes;
         x->parent = E; // Pointer for path to root
     }
   }
} 
```

---->> [a3.cpp]

# N Queen Problem using Branch And Bound

The N queens puzzle is the problem of placing N chess queens on an N×N chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

Backtracking Algorithm for N-Queen is already discussed here. In backtracking solution we backtrack when we hit a dead end. In Branch and Bound solution, after building a partial solution, we figure out that there is no point going any deeper as we are going to hit a dead end. 

Let’s begin by describing backtracking solution. “The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes, then we backtrack and return false.”
![](https://media.geeksforgeeks.org/wp-content/uploads/backqueen.jpg)
![NQueenNQueen](https://media.geeksforgeeks.org/wp-content/uploads/queen.jpg)

1. For the 1st Queen, there are total 8 possibilities as we can place 1st Queen in any row of first column. Let’s place Queen 1 on row 3.
2. After placing 1st Queen, there are 7 possibilities left for the 2nd Queen. But wait, we don’t really have 7 possibilities. We cannot place Queen 2 on rows 2, 3 or 4 as those cells are under attack from Queen 1. So, Queen 2 has only 8 – 3 = 5 valid positions left.
3. After picking a position for Queen 2, Queen 3 has even fewer options as most of the cells in its column are under attack from the first 2 Queens.
We need to figure out an efficient way of keeping track of which cells are under attack. In previous solution we kept an 8­-by­-8 Boolean matrix and update it each time we placed a queen, but that required linear time to update as we need to check for safe cells.
Basically, we have to ensure 4 things: 
1. No two queens share a column. 
2. No two queens share a row. 
3. No two queens share a top-right to left-bottom diagonal. 
4. No two queens share a top-left to bottom-right diagonal.

Number 1 is automatic because of the way we store the solution. For number 2, 3 and 4, we can perform updates in O(1) time. The idea is to keep three Boolean arrays that tell us which rows and which diagonals are occupied.



Lets do some pre-processing first. Let’s create two N x N matrix one for / diagonal and other one for \ diagonal. Let’s call them slashCode and backslashCode respectively. The trick is to fill them in such a way that two queens sharing a same /­diagonal will have the same value in matrix slashCode, and if they share same \­diagonal, they will have the same value in backslashCode matrix.
For an N x N matrix, fill slashCode and backslashCode matrix using below formula –
slashCode[row][col] = row + col 
backslashCode[row][col] = row – col + (N-1)

Using above formula will result in below matrices 

![NQueen2](https://media.geeksforgeeks.org/wp-content/uploads/king.jpg)

![NQueen2](https://media.geeksforgeeks.org/wp-content/uploads/kingqueen.jpg)

The ‘N – 1’ in the backslash code is there to ensure that the codes are never negative because we will be using the codes as indices in an array.
Now before we place queen i on row j, we first check whether row j is used (use an array to store row info). Then we check whether slash code ( j + i ) or backslash code ( j – i + 7 ) are used (keep two arrays that will tell us which diagonals are occupied). If yes, then we have to try a different location for queen i. If not, then we mark the row and the two diagonals as used and recurse on queen i + 1. After the recursive call returns and before we try another position for queen i, we need to reset the row, slash code and backslash code as unused again, like in the code from the previous notes.

------->> [a4.cpp]

# Traveling Salesman Problem using Branch And Bound
Difficulty Level : Expert
Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible tour that visits every city exactly once and returns to the starting point.

![Euler1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/TSP.png)

For example, consider the graph shown in figure on right side. A TSP tour in the graph is 0-1-3-2-0. The cost of the tour is 10+25+30+15 which is 80.

We have discussed following solutions
1) Naive and Dynamic Programming
2) Approximate solution using MST

 
 



Branch and Bound Solution
As seen in the previous articles, in Branch and Bound method, for current node in tree, we compute a bound on best possible solution that we can get if we down this node. If the bound on best possible solution itself is worse than current best (best computed so far), then we ignore the subtree rooted with the node.

Note that the cost through a node includes two costs.
1) Cost of reaching the node from the root (When we reach a node, we have this cost computed)
2) Cost of reaching an answer from current node to a leaf (We compute a bound on this cost to decide whether to ignore subtree with this node or not).

In cases of a maximization problem, an upper bound tells us the maximum possible solution if we follow the given node. For example in 0/1 knapsack we used Greedy approach to find an upper bound.
In cases of a minimization problem, a lower bound tells us the minimum possible solution if we follow the given node. For example, in Job Assignment Problem, we get a lower bound by assigning least cost job to a worker.
In branch and bound, the challenging part is figuring out a way to compute a bound on best possible solution. Below is an idea used to compute bounds for Traveling salesman problem.

Cost of any tour can be written as below.
```
Cost of a tour T = (1/2) * ∑ (Sum of cost of two edges
                              adjacent to u and in the
                              tour T) 
                   where u ∈ V
For every vertex u, if we consider two edges through it in T,
and sum their costs.  The overall sum for all vertices would
be twice of cost of tour T (We have considered every edge 
twice.)

(Sum of two tour edges adjacent to u) >= (sum of minimum weight
                                          two edges adjacent to
                                          u)

Cost of any tour >=  1/2) * ∑ (Sum of cost of two minimum
                              weight edges adjacent to u) 
                   where u ∈ V
```
For example, consider the above shown graph. Below are minimum cost two edges adjacent to every node.
```
Node     Least cost edges   Total cost            
0     (0, 1), (0, 2)            25
1     (0, 1), (1, 3)         35
2    (0, 2), (2, 3)            45
3     (0, 3), (1, 3)            45

Thus a lower bound on the cost of any tour = 
         1/2(25 + 35 + 45 + 45)
       = 75
```
Refer this for one more example.
Now we have an idea about computation of lower bound. Let us see how to how to apply it state space search tree. We start enumerating all possible nodes (preferably in lexicographical order)

1. The Root Node: Without loss of generality, we assume we start at vertex “0” for which the lower bound has been calculated above.

Dealing with Level 2: The next level enumerates all possible vertices we can go to (keeping in mind that in any path a vertex has to occur only once) which are, 1, 2, 3… n (Note that the graph is complete). Consider we are calculating for vertex 1, Since we moved from 0 to 1, our tour has now included the edge 0-1. This allows us to make necessary changes in the lower bound of the root.


```
Lower Bound for vertex 1 = 
   Old lower bound - ((minimum edge cost of 0 + 
                    minimum edge cost of 1) / 2) 
                  + (edge cost 0-1)
```
How does it work? To include edge 0-1, we add the edge cost of 0-1, and subtract an edge weight such that the lower bound remains as tight as possible which would be the sum of the minimum edges of 0 and 1 divided by 2. Clearly, the edge subtracted can’t be smaller than this.

Dealing with other levels: As we move on to the next level, we again enumerate all possible vertices. For the above case going further after 1, we check out for 2, 3, 4, …n.
Consider lower bound for 2 as we moved from 1 to 1, we include the edge 1-2 to the tour and alter the new lower bound for this node.
```
Lower bound(2) = 
     Old lower bound - ((second minimum edge cost of 1 + 
                         minimum edge cost of 2)/2)
                     + edge cost 1-2)
```
Note: The only change in the formula is that this time we have included second minimum edge cost for 1, because the minimum edge cost has already been subtracted in previous level.

----->> [a5.cpp]