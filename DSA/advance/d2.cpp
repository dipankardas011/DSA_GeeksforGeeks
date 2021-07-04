/*Number of ways to traverse an N-ary tree
Difficulty Level : Medium
Last Updated : 10 Nov, 2017
Given an n-ary tree, count number of ways to traverse an n-ary (or a Directed Acyclic Graph) tree starting from the root vertex.

Suppose we have a given N-ary tree as shown below.

maryintial

Now we have to find the number of ways of traversing the whole tree starting from the root vertex. There can be many such ways. Some of them are listed below.

1) N->M->K->J->B->F->D->E->C->H->I->L->A (kind-of depth first traversal).
2) A->B->F->D->E->K->J->G->C->H->I->N->M->L (level order traversal)
3) ………
4) ………
.
.
.
and so on….



We strongly recommend you to minimize your browser and try this yourself first.

The count of all ways to traverse is the product of factorials of the number of children of each node. Refer to the below figure for clear understanding-

marynew

Here,

‘A’ has four children, so 4! permutations possible
‘B’ has two children, so 2! permutations possible
‘F’ has no children, so 0! permutations possible
…..
And so on

Hence all such ways are- 4 ! * 2 ! * 0 ! * 1 ! * 3 ! * 2 ! * 0 ! * 0 ! * 0 ! * 0 ! * 1 ! * 0 ! * 0 ! = 576 way*/
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
    char key;
    vector<node *> child;
};

node *newNode(int k)
{
    node *t = new node;
    t->key = k;
    return t;
}
// gamma(n+1) = n!
// gamma(n) = (n-1)!
int calculateWays(node *root)
{
    int ways = 1;

    if (!root)
        return 0;

    queue<node *> que;
    que.push(root);

    while (!que.empty())
    {
        node *t = que.front();
        que.pop();

        ways *= (int)tgamma(t->child.size() + 1);

        for (int i = 0; i < t->child.size(); i++)
            que.push(t->child[i]);
    }

    return ways;
}

int main()
{
    /*   Let us create below tree
   *           A
   *         / /  \  \
   *       B  F   D  E
   *      / \     |  /|\
   *     K  J    G  C H I
   *      /\            \
   *    N   M            L
   */

    node *root = newNode('A');
    (root->child).push_back(newNode('B'));
    (root->child).push_back(newNode('F'));
    (root->child).push_back(newNode('D'));
    (root->child).push_back(newNode('E'));
    (root->child[0]->child).push_back(newNode('K'));
    (root->child[0]->child).push_back(newNode('J'));
    (root->child[2]->child).push_back(newNode('G'));
    (root->child[3]->child).push_back(newNode('C'));
    (root->child[3]->child).push_back(newNode('H'));
    (root->child[3]->child).push_back(newNode('I'));
    (root->child[0]->child[0]->child).push_back(newNode('N'));
    (root->child[0]->child[0]->child).push_back(newNode('M'));
    (root->child[3]->child[2]->child).push_back(newNode('L'));

    cout << calculateWays(root);
    return 0;
}