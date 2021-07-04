/*Iterative Method to find Height of Binary Tree
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
    int data;
    struct nodes *lchild, *rchild;
}btree;

btree *root;


btree *creatememory(int v){
    btree *t=(btree *)malloc(sizeof(btree));
    t->data = v;
    t->lchild=t->rchild=NULL;
    return t;
}

void push(int val){
    btree *new=creatememory(val);
    if(root==NULL){
        root=new;
        return ;
    }
    int ch;
    do{
        int found=0;
        btree *i = root;
        while(!found){
            printf("ENTER -1 TO GO LEFT AND 1 TO GO RIGHT: ");
            scanf("%d",&ch);
            switch(ch){
                case -1:
                    if(i->lchild==NULL){
                        found=1;
                        i->lchild = new;
                    }
                    else{
                        i=i->lchild;
                    }
                    break;
                case 1:
                    if(i->rchild==NULL){
                        found=1;
                        i->rchild=new;
                    }
                    else{
                        i=i->rchild;
                    }
                    break;
                default: printf("^~~ WARNING! - wrong key pressed\n");
            }
        }
        printf("-> ENTER 1 TO CONTINUE....\n");
        scanf("%d",&ch);
    }while(ch==1);
}

