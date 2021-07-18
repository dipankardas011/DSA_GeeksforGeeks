/*Implementation of 0/1 Knapsack using Branch and Bound
Difficulty Level : Hard
Last Updated : 26 Nov, 2019
We strongly recommend to refer below post as a prerequisite for this.

Branch and Bound | Set 1 (Introduction with 0/1 Knapsack)

We discussed different approaches to solve above problem and saw that the Branch and Bound solution is the best suited method when item weights are not integers.

In this post implementation of Branch and Bound method for 0/1 knapsack problem is discussed.

How to find bound for every node for 0/1 Knapsack?
The idea is to use the fact that the Greedy approach provides the best solution for Fractional Knapsack problem.
To check if a particular node can give us a better solution or not, we compute the optimal solution (through the node) using Greedy approach. If the solution computed by Greedy approach itself is more than the best so far, then we can’t get a better solution through the node.



Complete Algorithm:

Sort all items in decreasing order of ratio of value per unit weight so that an upper bound can be computed using Greedy Approach.
Initialize maximum profit, maxProfit = 0
Create an empty queue, Q.
Create a dummy node of decision tree and enqueue it to Q. Profit and weight of dummy node are 0.
Do following while Q is not empty.
Extract an item from Q. Let the extracted item be u.
Compute profit of next level node. If the profit is more than maxProfit, then update maxProfit.
Compute bound of next level node. If bound is more than maxProfit, then add next level node to Q.
Consider the case when next level node is not considered as part of solution and add a node to queue with level as next, but weight and profit without considering next level nodes.*/
#include <iostream>
#include <algorithm>
#include <queue>

struct Item
{
    float weight;
    int val;
};

struct Node
{
    /* level  --> Level of node in decision tree (or index in arr[]
     profit --> Profit of nodes on path from root to this node (including this node)
     bound --> Upper bound of maximum profit in subtree of this node
     */
    int level, profit, bound;
    float weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.val / a.weight;
    double r2 = (double)b.val / b.weight;

    return (r1 > r2);
}

int bound(Node u, int n, int W, Item arr[])
{
    // if the weight overcomes the capacity
    if (u.weight >= W)
        return 0;

    int profitBound = u.profit;

    int j = u.level + 1;
    int totweight = u.weight;

    // checking index condition and knapsack capacity condition
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profitBound += arr[j].val;

        j++;
    }

    if (j < n)
        profitBound += (W - totweight) * arr[j].val / arr[j].weight;

    return profitBound;
}

/* returns maximum profit we can get with capacity W */
int exec(int W, Item ar[], int n)
{
    // sort in bases of value/weight
    std::sort(ar, ar + n, cmp);

    std::queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;

    Q.push(u);
    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == -1) //starting node so root
            v.level = 0;

        if (u.level == n - 1) //last node nothing in nextlevel
            continue;

        v.level = u.level + 1; // then increment the level

        // Taking current level's item add current level's weight and value to node u's weight and value
        v.weight = u.weight + ar[v.level].weight;
        v.profit = u.profit + ar[v.level].val;

        // If cumulated weight is less than W and profit is greater than previous profit, update maxprofit
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        // Get the upper bound on profit to decide whether to add v to Q or not.
        v.bound = bound(v, n, W, ar);

        // If bound value is greater than profit, then only push into queue for further consideration
        if (v.bound > maxProfit)
            Q.push(v);

        // Do the same thing,  but Without taking the item in knapsack
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, ar);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main(int argc, char const *argv[])
{
    int W = 10;
    Item a[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(a) / sizeof(a[0]);

    std::cout << "maximum possible profit = $" << exec(W, a, n) << std::endl;
    remove(argv[0]);
    return 0;
}
