/*Iterative Postorder Traversal | Set 1 (Using Two Stacks)

We have discussed iterative inorder and iterative preorder traversals. 
In this post, iterative postorder traversal is discussed, which is more 
complex than the other two traversals (due to its nature of non-tail recursion, 
there is an extra statement after the final recursive call to itself). 
Postorder traversal can easily be done using two stacks, though.
The idea is to push reverse postorder traversal to a stack. 
Once we have the reversed postorder traversal in a stack, 
we can just pop all items one by one from the stack and print them; this order of
printing will be in postorder because of the LIFO property of stacks. 
Now the question is, how to get reversed postorder elements in a stack – 
the second stack is used for this purpose. For example, in the following tree, 
we need to get 1, 3, 7, 6, 2, 5, 4 in a stack. If take a closer look at this sequence, 
we can observe that this sequence is very similar to the preorder traversal. 
The only difference is that the right child is visited before left child, and therefore the sequence 
is “root right left” instead of “root left right”. 
So, we can do something like iterative preorder traversal with the following differences:
a) Instead of printing an item, we push it to a stack.
b) We push the left subtree before the right subtree.

Following is the complete algorithm. After step 2, 
we get the reverse of a postorder traversal in the second stack. 
We use the first stack to get the correct order.

1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
*/
#include <stdio.h>
#include <stdlib.h>
#define max 30

typedef struct nodes
{
	int data;
	struct node *left, *right;
} tree;

typedef struct snodes
{
	int size;
	int top;
	// as the arr will store the arr[]
	tree **arr;
} stack;

tree *root = NULL;

tree *createtree(int val)
{
	tree *t = (tree *)malloc(sizeof(tree));
	t->data = val;
	t->left = t->right = 0;
	return t;
}

stack *createstack(int size)
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->size = size;
	s->top = -1;
	s->arr = (tree **)malloc(s->size * sizeof(tree *));
	return s;
}

int isempty(stack *s)
{
	return (s->top == -1) ? 1 : 0;
}

int isfull(stack *s)
{
	return (s->top == s->size - 1) ? 1 : 0;
}

void push(stack *s, tree *t)
{
	if (isfull(s) == 1)
		return;
	s->arr[++(s->top)] = t;
}

tree *pop(stack *s)
{
	if (isempty(s) == 1)
		return NULL;
	return s->arr[(s->top)--];
}

void input(int val)
{
	tree *new = createtree(val);
	if (root == 0)
	{
		root = new;
		printf("@Echo@: %d\n", val);
		return;
	}
	else
	{
		int ch=0;

		int m = 0;
		tree *temp = root;
		while (m == 0)
		{
			printf("give the directions\n~~~	1 for left 0 for right		~~~\n");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
			{
				if (temp->left == NULL)
				{
					m = 1;
					temp->left = new;
				}
				else
				{
					temp = temp->left;
				}
				break;
			}
			case 0:
			{
				if (temp->right == NULL)
				{
					m = 1;
					temp->right = new;
				}
				else
				{
					temp = temp->right;
				}
				break;
			}
			}
		}
		printf("@Echo@: %d\n", new->data);
	}
}

void postorder_display()
{
	if (root == NULL)
	{
		return;
	}
	stack *s1 = createstack(max);
	stack *s2 = createstack(max);

	push(s1, root);
	tree *t;
	while (isempty(s1) != 0)
	{
		// run till the stack 1 is not empty
		t = pop(s1);
		push(s2, t);

		if (t->left)
			push(s1, t->left);
		if (t->right)
			push(s1, t->right);
	}
	while (isempty(s2) != 0)
	{
		t = pop(s2);
		printf("%d ", t->data);
	}
}

void delete_tree(tree *t)
{
	if (t == 0)
		return;

	delete_tree(t->left);
	delete_tree(t->right);

	free(t);
}

int main()
{
	input(3);
	input(5);
	input(7);
	input(8);
	input(9);
	postorder_display();
	delete_tree(root);
	return 0;
}