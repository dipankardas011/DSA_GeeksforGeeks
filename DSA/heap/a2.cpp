/*Binomial Heap

Difficulty Level : Expert

The main application of Binary Heap is as implement priority queue. Binomial Heap is an extension of Binary Heap that provides faster union or merge operation together with other operations provided by Binary Heap. 

A Binomial Heap is a collection of Binomial Trees 

What is a Binomial Tree? 
A Binomial Tree of order 0 has 1 node. A Binomial Tree of order k can be constructed by taking two binomial trees of order k-1 and making one as leftmost child or other. 
A Binomial Tree of order k has following properties. 
a) It has exactly 2k nodes. 
b) It has depth as k. 
c) There are exactly kCi nodes at depth i for i = 0, 1, . . . , k. 
d) The root has degree k and children of root are themselves Binomial Trees with order k-1, k-2,.. 0 from left to right. 

k = 0 (Single Node)

 o

k = 1 (2 nodes) 
[We take two k = 0 order Binomial Trees, and
make one as child of other]
  o
 /  
o     

k = 2 (4 nodes)
[We take two k = 1 order Binomial Trees, and
make one as child of other]
     o
   /   \
  o     o
 /       
o        

k = 3 (8 nodes)
[We take two k = 2 order Binomial Trees, and
make one as child of other]
      o   
   /  | \ 
  o   o  o
 / \  | 
o   o o   
     \           
      o    

Binomial Heap: 
A Binomial Heap is a set of Binomial Trees where each Binomial Tree follows Min Heap property. And there can be at most one Binomial Tree of any degree. 

Examples Binomial Heap: 

12------------10--------------------20
             /  \                 /  | \
           15    50             70  50  40
           |                  / |    |     
           30               80  85  65 
                            |
                           100
A Binomial Heap with 13 nodes. It is a collection of 3 
Binomial Trees of orders 0, 2 and 3 from left to right. 

    10--------------------20
   /  \                 /  | \
 15    50             70  50  40
 |                  / |    |     
 30               80  85  65 
                  |
                 100
A Binomial Heap with 12 nodes. It is a collection of 2 
Binomial Trees of orders 2 and 3 from left to right. 

Binary Representation of a number and Binomial Heaps 
A Binomial Heap with n nodes has the number of Binomial Trees equal to the number of set bits in the Binary representation of n. For example let n be 13, there 3 set bits in the binary representation of n (00001101), hence 3 Binomial Trees. We can also relate the degree of these Binomial Trees with positions of set bits. With this relation, we can conclude that there are O(Logn) Binomial Trees in a Binomial Heap with ‘n’ nodes. 

Operations of Binomial Heap: 
The main operation in Binomial Heap is union(), all other operations mainly use this operation. The union() operation is to combine two Binomial Heaps into one. Let us first discuss other operations, we will discuss union later.

insert(H, k): Inserts a key ‘k’ to Binomial Heap ‘H’. This operation first creates a Binomial Heap with single key ‘k’, then calls union on H and the new Binomial heap. 
getMin(H): A simple way to getMin() is to traverse the list of root of Binomial Trees and return the minimum key. This implementation requires O(Logn) time. It can be optimized to O(1) by maintaining a pointer to minimum key root. 
extractMin(H): This operation also uses union(). We first call getMin() to find the minimum key Binomial Tree, then we remove the node and create a new Binomial Heap by connecting all subtrees of the removed minimum node. Finally, we call union() on H and the newly created Binomial Heap. This operation requires O(Logn) time. 
delete(H): Like Binary Heap, delete operation first reduces the key to minus infinite, then calls extractMin(). 
decreaseKey(H): decreaseKey() is also similar to Binary Heap. We compare the decreases key with it parent and if parent’s key is more, we swap keys and recur for the parent. We stop when we either reach a node whose parent has a smaller key or we hit the root node. Time complexity of decreaseKey() is O(Logn). 
Union operation in Binomial Heap: 
Given two Binomial Heaps H1 and H2, union(H1, H2) creates a single Binomial Heap. 

The first step is to simply merge the two Heaps in non-decreasing order of degrees. In the following diagram, figure(b) shows the result after merging. 
After the simple merge, we need to make sure that there is at most one Binomial Tree of any order. To do this, we need to combine Binomial Trees of the same order. We traverse the list of merged roots, we keep track of three-pointers, prev, x and next-x. There can be following 4 cases when we traverse the list of roots. 
—–Case 1: Orders of x and next-x are not same, we simply move ahead. 
In following 3 cases orders of x and next-x are same. 
—–Case 2: If the order of next-next-x is also same, move ahead. 
—–Case 3: If the key of x is smaller than or equal to the key of next-x, then make next-x as a child of x by linking it with x. 
—–Case 4: If the key of x is greater, then make x as the child of next. 
The following diagram is taken from 2nd Edition of CLRS book. 
*/
// C++ program to implement different operations
// on Binomial Heap
#include <bits/stdc++.h>
using namespace std;

// A Binomial Tree node.
struct Node
{
	int data, degree;
	Node *child, *sibling, *parent;
};

Node *newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->degree = 0;
	temp->child = temp->parent = temp->sibling = NULL;
	return temp;
}

// This function merge two Binomial Trees.
Node *mergeBinomialTrees(Node *b1, Node *b2)
{
	// Make sure b1 is smaller
	if (b1->data > b2->data)
		swap(b1, b2);

	// We basically make larger valued tree
	// a child of smaller valued tree
	b2->parent = b1;
	b2->sibling = b1->child;
	b1->child = b2;
	b1->degree++;

	return b1;
}

// This function perform union operation on two
// binomial heap i.e. l1 & l2
list<Node *> unionBionomialHeap(list<Node *> l1,
								list<Node *> l2)
{
	// _new to another binomial heap which contain
	// new heap after merging l1 & l2
	list<Node *> _new;
	list<Node *>::iterator it = l1.begin();
	list<Node *>::iterator ot = l2.begin();
	while (it != l1.end() && ot != l2.end())
	{
		// if D(l1) <= D(l2)
		if ((*it)->degree <= (*ot)->degree)
		{
			_new.push_back(*it);
			it++;
		}
		// if D(l1) > D(l2)
		else
		{
			_new.push_back(*ot);
			ot++;
		}
	}

	// if there remains some elements in l1
	// binomial heap
	while (it != l1.end())
	{
		_new.push_back(*it);
		it++;
	}

	// if there remains some elements in l2
	// binomial heap
	while (ot != l2.end())
	{
		_new.push_back(*ot);
		ot++;
	}
	return _new;
}

// adjust function rearranges the heap so that
// heap is in increasing order of degree and
// no two binomial trees have same degree in this heap
list<Node *> adjust(list<Node *> _heap)
{
	if (_heap.size() <= 1)
		return _heap;
	list<Node *> new_heap;
	list<Node *>::iterator it1, it2, it3;
	it1 = it2 = it3 = _heap.begin();

	if (_heap.size() == 2)
	{
		it2 = it1;
		it2++;
		it3 = _heap.end();
	}
	else
	{
		it2++;
		it3 = it2;
		it3++;
	}
	while (it1 != _heap.end())
	{
		// if only one element remains to be processed
		if (it2 == _heap.end())
			it1++;

		// If D(it1) < D(it2) i.e. merging of Binomial
		// Tree pointed by it1 & it2 is not possible
		// then move next in heap
		else if ((*it1)->degree < (*it2)->degree)
		{
			it1++;
			it2++;
			if (it3 != _heap.end())
				it3++;
		}

		// if D(it1),D(it2) & D(it3) are same i.e.
		// degree of three consecutive Binomial Tree are same
		// in heap
		else if (it3 != _heap.end() &&
				 (*it1)->degree == (*it2)->degree &&
				 (*it1)->degree == (*it3)->degree)
		{
			it1++;
			it2++;
			it3++;
		}

		// if degree of two Binomial Tree are same in heap
		else if ((*it1)->degree == (*it2)->degree)
		{
			Node *temp;
			*it1 = mergeBinomialTrees(*it1, *it2);
			it2 = _heap.erase(it2);
			if (it3 != _heap.end())
				it3++;
		}
	}
	return _heap;
}

// inserting a Binomial Tree into binomial heap
list<Node *> insertATreeInHeap(list<Node *> _heap,
							   Node *tree)
{
	// creating a new heap i.e temp
	list<Node *> temp;

	// inserting Binomial Tree into heap
	temp.push_back(tree);

	// perform union operation to finally insert
	// Binomial Tree in original heap
	temp = unionBionomialHeap(_heap, temp);

	return adjust(temp);
}

// removing minimum key element from binomial heap
// this function take Binomial Tree as input and return
// binomial heap after
// removing head of that tree i.e. minimum element
list<Node *> removeMinFromTreeReturnBHeap(Node *tree)
{
	list<Node *> heap;
	Node *temp = tree->child;
	Node *lo;

	// making a binomial heap from Binomial Tree
	while (temp)
	{
		lo = temp;
		temp = temp->sibling;
		lo->sibling = NULL;
		heap.push_front(lo);
	}
	return heap;
}

// inserting a key into the binomial heap
list<Node *> insert(list<Node *> _head, int key)
{
	Node *temp = newNode(key);
	return insertATreeInHeap(_head, temp);
}

// return pointer of minimum value Node
// present in the binomial heap
Node *getMin(list<Node *> _heap)
{
	list<Node *>::iterator it = _heap.begin();
	Node *temp = *it;
	while (it != _heap.end())
	{
		if ((*it)->data < temp->data)
			temp = *it;
		it++;
	}
	return temp;
}

list<Node *> extractMin(list<Node *> _heap)
{
	list<Node *> new_heap, lo;
	Node *temp;

	// temp contains the pointer of minimum value
	// element in heap
	temp = getMin(_heap);
	list<Node *>::iterator it;
	it = _heap.begin();
	while (it != _heap.end())
	{
		if (*it != temp)
		{
			// inserting all Binomial Tree into new
			// binomial heap except the Binomial Tree
			// contains minimum element
			new_heap.push_back(*it);
		}
		it++;
	}
	lo = removeMinFromTreeReturnBHeap(temp);
	new_heap = unionBionomialHeap(new_heap, lo);
	new_heap = adjust(new_heap);
	return new_heap;
}

// print function for Binomial Tree
void printTree(Node *h)
{
	while (h)
	{
		cout << h->data << " ";
		printTree(h->child);
		h = h->sibling;
	}
}

// print function for binomial heap
void printHeap(list<Node *> _heap)
{
	list<Node *>::iterator it;
	it = _heap.begin();
	while (it != _heap.end())
	{
		printTree(*it);
		it++;
	}
}

// Driver program to test above functions
int main()
{
	int ch, key;
	list<Node *> _heap;

	// Insert data in the heap
	_heap = insert(_heap, 10);
	_heap = insert(_heap, 20);
	_heap = insert(_heap, 30);

	cout << "Heap elements after insertion:\n";
	printHeap(_heap);

	Node *temp = getMin(_heap);
	cout << "\nMinimum element of heap "
		 << temp->data << "\n";

	// Delete minimum element of heap
	_heap = extractMin(_heap);
	cout << "Heap after deletion of minimum element\n";
	printHeap(_heap);

	return 0;
}