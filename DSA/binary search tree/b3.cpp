/*Count pairs from two BSTs whose sum is equal to a given value x
Given two BSTs containing n1 and n2 distinct nodes respectively. Given a value x. The problem is to count all pairs from both the BSTs whose sum is equal to x.

Examples: 

Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are:
(5, 11), (6, 10) and (8, 8)
*/
// plan here is to make 2 vect from the two tree as bst
// then check the sum

#include <bits/stdc++.h>
using std::cout;
using std::vector;

class node
{
    public:
    int data;
    node *left, *right;
};

node *root1=0;
node *root2=0;

node *CreateNode(int key)
{
    node *t=new node;
    t->data=key;
    t->left=t->right=0;
    return t;
}

void find_inorder(vector<int>& vec, node *n){
    if(n){
        find_inorder(vec, n->left);
        vec.push_back(n->data);
        find_inorder(vec,n->right);
    }
}

int main()
{
    root1=CreateNode(5);
    root1->left=CreateNode(3);
    root1->right=CreateNode(7);
    root1->left->left=CreateNode(2);
    root1->left->right=CreateNode(4);
    root1->right->left=CreateNode(6);
    root1->right->right=CreateNode(8);

    root2=CreateNode(10);
    root2->left=CreateNode(6);
    root2->right=CreateNode(15);
    root2->left->left=CreateNode(3);
    root2->left->right=CreateNode(8);
    root2->right->left=CreateNode(11);
    root2->right->right= CreateNode(18);

    vector<int> tree1, tree2;
    find_inorder(tree1, root1);
    find_inorder(tree2, root2);
    int sum=0;
    cout<<"enter the sum for finding...  ";
    std::cin>>sum;
    int i,j;
    cout<<"found pairs:\n";
    int flag=0;
    for(i=0;i<tree1.size();i++)
    {
        int find = sum - tree1[i];
        for(j=0;j<tree2.size();j++)
        {
            if(find == tree2[j])
            {
                //found
                flag=1;
                cout<<"( "<<tree1[i]<<", "<<tree2[j]<<" )\n";
            }
        }
    }
    if(flag==0) cout<<"NULL\n";
    return 0;
}