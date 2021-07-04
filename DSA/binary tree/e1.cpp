/*Find sum of all left leaves in a given Binary Tree
*/
#include <iostream>

using namespace std;

struct btree{
    int data;
    struct btree *left, *right;
};

btree *root=NULL;
btree *create(int v){
    btree *t=new btree;
    t->data=v;
    t->left=t->right=0;

    return t;
}
// void insert(int val){
//     if(root==NULL){
//         root=create(val);
//         return;
//     }
    
//     btree *t=create(val);

//     btree *temp = root;
//     int b = 0; // 0 if not found 1 if found
//     while (b == 0)
//     {
//         while (getchar() != '\n'); // clear the input buffer
//         printf("enter 'l' for left 'r' for right: ");
//         char k = getchar();
//         switch(k){
//             case 'l': 
//             if(temp->left!=NULL)  temp=temp->left;
//             else    {b=1; temp->left=t;}
//             break;

//             case 'r':
//             if(temp->right!=NULL)   temp=temp->right;
//             else    {b=1; temp->right=t;}
//             break;

//             default: cout<<"^~~~error wrong key pressed\n";
//         }
//     }
// }

void preorder(btree *t){
    if(t){
        // root-left-right
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}

bool isleaf(btree *f){
    if(f==0)    return false;
    if(f->left==NULL && f->right==NULL)     return true;
    return false;
}

int sumLeftLeaves(btree *t){
    int res=0;
    if(t!=0){
        if(isleaf(t->left))
            res+=t->left->data;
        else
            res+=sumLeftLeaves(t->left);
        res+=sumLeftLeaves(t->right);
    }
    return res;
}

int main(){
    // int k=0;
    // do{
    //     cout<<"enter the data= ";
    //     cin>>k;
    //     insert(k);
    //     cout<<"enter non-zero integer to continue... ";
    //     cin>>k;
    // }while(k!=0);
    root=create(20);
    root->left                = create(9);
    root->right               = create(49);
    root->right->left         = create(23);
    root->right->right        = create(52);
    root->right->right->left  = create(50);
    root->left->left          = create(5);
    root->left->right         = create(12);
    root->left->right->right  = create(12);
    preorder(root);
    cout<<"the sum of left leaves in btree= "<<sumLeftLeaves(root)<<endl;
    return 0;
}