# Microsoft Full Time Interview Experience (On campus)
## Last Updated : 31 Aug, 2018
<br>
Microsoft conducted online round in August 2018 at our institute. Around 270 students applied for the test.

<h2>Round 1(Online):</h2> It was conducted on CoCubes and consisted 3 questions and time limit was 75 min. The questions were as follows:

- (2 marks) https://www.geeksforgeeks.org/find-the-first-repeated-character-in-a-string/

Input: ch = “geeksforgeeks” 
Output: e 
e is the first element that repeats

Input: str = “hello geeks” 
Output: l
<br>l is the first element that repeats

` Find the first repeated character in a string `
```C++
// CPP program to find the first
// repeated character in a string
#include <bits/stdc++.h>
using namespace std;

// Returns first repeating character in str.
char firstRepeating(string &str)
{
	// Creates an empty hashset
	unordered_set<char> h;

	// Traverse the input array from left to right
	for (int i=0; i<str.length(); i++)
	{
		char c = str[i];

		// If element is already in hash set, update x
		// and then break
		if (h.find(c) != h.end())
			return c;

		else // Else add element to hash set
			h.insert(c);
	}

	// If there was no repeated character
	return '\0';
}

// Driver method to test above method
int main ()
{
	string str = "geeksforgeeks";
	cout << firstRepeating(str);
	return 0;
}

```


- (3 marks) https://www.geeksforgeeks.org/find-patterns-101-given-string/

` Find all the patterns of “1(0+)1” in a given string | SET 1(General Approach)`

Examples:
Input : 1101001
Output : 2

Input : 100001abc101
Output : 2
```C++
/* Code to count 1(0+)1 patterns in a string */
#include <bits/stdc++.h>
using namespace std;

/* Function to count patterns */
int patternCount(string str)
{
	/* Variable to store the last character*/
	char last = str[0];

	int i = 1, counter = 0;
	while (i < str.size())
	{
		/* We found 0 and last character was '1',
		state change*/
		if (str[i] == '0' && last == '1')
		{
			while (str[i] == '0')
				i++;

			/* After the stream of 0's, we got a '1',
			counter incremented*/
			if (str[i] == '1')
				counter++;
		}

		/* Last character stored */
		last = str[i];
		i++;
	}

	return counter;
}

/* Driver Code */
int main()
{
	string str = "1001ab010abc01001";
	cout << patternCount(str) << endl;
	return 0;
}

```

- (5 marks) https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/

` Remove BST keys outside the given range`
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST. For example, consider the following BST and range [-10, 13]. 
The given tree should be changed to the following. Note that all keys outside the range [-10, 13] are removed and the modified tree is BST. 
BinaryTreeModified2
There are two possible cases for every node. 
1. Node’s key is outside the given range. This case has two sub-cases. 
    * Node’s key is smaller than the min value. 
    * Node’s key is greater than the max value. 
2. Node’s key is in range.
We don’t need to do anything for case 2. In case 1, we need to remove the node and change the root of the subtree rooted with this node. 

The idea is to fix the tree in a Post-order fashion. When we visit a node, we make sure that its left and right sub-trees are already fixed. In case 
* we simply remove the root and return the right sub-tree as a new root. In case 
* we remove the root and return the left sub-tree as a new root.
```C++
// A C++ program to remove BST keys outside the given range
#include<bits/stdc++.h>

using namespace std;

// A BST node has key, and left and right pointers
struct node
{
	int key;
	struct node *left;
	struct node *right;
};

// Removes all nodes having value outside the given range and returns the root
// of modified tree
node* removeOutsideRange(node *root, int min, int max)
{
// Base Case
if (root == NULL)
	return NULL;

// First fix the left and right subtrees of root
root->left = removeOutsideRange(root->left, min, max);
root->right = removeOutsideRange(root->right, min, max);

// Now fix the root. There are 2 possible cases for root
// 1.a) Root's key is smaller than min value (root is not in range)
if (root->key < min)
{
	node *rChild = root->right;
	delete root;
	return rChild;
}
// 1.b) Root's key is greater than max value (root is not in range)
if (root->key > max)
{
	node *lChild = root->left;
	delete root;
	return lChild;
}
// 2. Root is in range
return root;
}

// A utility function to create a new BST node with key as given num
node* newNode(int num)
{
	node* temp = new node;
	temp->key = num;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to insert a given key to BST
node* insert(node* root, int key)
{
	if (root == NULL)
	return newNode(key);
	if (root->key > key)
	root->left = insert(root->left, key);
	else
	root->right = insert(root->right, key);
	return root;
}

// Utility function to traverse the binary tree after conversion
void inorderTraversal(node* root)
{
	if (root)
	{
		inorderTraversal( root->left );
		cout << root->key << " ";
		inorderTraversal( root->right );
	}
}

// Driver program to test above functions
int main()
{
	node* root = NULL;
	root = insert(root, 6);
	root = insert(root, -13);
	root = insert(root, 14);
	root = insert(root, -8);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 7);

	cout << "Inorder traversal of the given tree is: ";
	inorderTraversal(root);

	root = removeOutsideRange(root, -10, 13);

	cout << "\nInorder traversal of the modified tree is: ";
	inorderTraversal(root);

	return 0;
}

```

` Advise:` Always read previous interview experiences.

`Outcome:` _68 out of 270_ students made it to the second round i.e. group flyer
<br><br>
<h2>Round 2( Group Flyer ):</h2> Students were divided into groups of 7/8 students and provided a mentor.

2 questions are given and you have to discuss the approach with the mentor and write the optimised approach on a paper.

- Question 1: https://www.geeksforgeeks.org/word-break-problem-using-backtracking/

` Word Break Problem using Backtracking `
Given a valid sentence without any spaces between the words and a dictionary of valid English words, find all possible ways to break the sentence in individual dictionary words.

Example 

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  and, cream, icecream, man, go, mango}

Input: "ilikesamsungmobile"
Output: i like sam sung mobile
        i like samsung mobile

Input: "ilikeicecreamandmango"
Output: i like ice cream and man go
        i like ice cream and mango
        i like icecream and man go
        i like icecream and mango

```C++
// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;

/* A utility function to check whether a word
is present in dictionary or not. An array of
strings is used for dictionary. Using array
of strings for dictionary is definitely not
a good idea. We have used for simplicity of
the program*/
int dictionaryContains(string &word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango", "icecream","and",
							"go","i","love","ice","cream"};
	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < n; i++)
		if (dictionary[i].compare(word) == 0)
			return true;
	return false;
}

// Prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);

// Prints all possible word breaks of given string
void wordBreak(string str)
{
	// Last argument is prefix
	wordBreakUtil(str, str.size(), "");
}

// Result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
	//Process all prefixes one by one
	for (int i=1; i<=n; i++)
	{
		// Extract substring from 0 to i in prefix
		string prefix = str.substr(0, i);

		// If dictionary conatins this prefix, then
		// we check for remaining string. Otherwise
		// we ignore this prefix (there is no else for
		// this if) and try next
		if (dictionaryContains(prefix))
		{
			// If no more elements are there, print it
			if (i == n)
			{
				// Add this element to previous prefix
				result += prefix;
				cout << result << endl;
				return;
			}
			wordBreakUtil(str.substr(i, n-i), n-i,
								result + prefix + " ");
		}
	}	
}

//Driver Code
int main()
{

	// Function call
	cout << "First Test:\n";
	wordBreak("iloveicecreamandmango");

	cout << "\nSecond Test:\n";
	wordBreak("ilovesamsungmobile");
	return 0;
}
```

- Question 2: Students of different heights are attending an assembly. The problem is that if a student has less or equal height than the student standing above him  then he/she cannot see the assembly. Task was to find the minimum number of students randomly such that maximum number of students can see the assembly.

Ex: 9 1 2 3 1 5

output : 2 students i.e. 9 and 1 has to be removed so that 4 students can see the assembly.



`Advise:` Always discuss your approach with the mentor as much as possible and write a very neat and clean code on the paper. Always try to give the time and space complexity of the solution you are providing.This round is a group flyer but you have to code individually.

`Outcome:` 30 out of 68 made it to the next round.

3/4 face to face interviews are lined up and each round is an elimination round.
<br><br>
<h2>Round 3(1st Technical F2F):</h2> The interviewer seemed very friendly, he calmed me down by asking about me. He asked about my projects. I had live projects in my basket. He asked me to provide the link( do not lie about your projects it’s normal to have not done a good project). Moving forward he asked me Data Structures based questions.

- Find the grandparent of a given node in a Binary Tree.

I gave a brute force implementation using O(n) space. He asked me to optimize my solution. I thought a while and gave my approach.

Take two nodes i.e. parent and grandparent initialized as NULL. Call recursively for left and right subtrees when you find the given node return the grandparent. Before calling recursively make grandparent=parent and pass root as parent. return the left or right answer which ever is not NULL.

He then asked me to write down the code on a paper.

O(1) space if recursive stack used is not considered.

- https://www.geeksforgeeks.org/count-pairs-with-given-sum/

` Count pairs with given sum`

Given an array of integers, and a number ‘sum’, find the number of pairs of integers in the array whose sum is equal to ‘sum’.

Examples:  

Input  :  arr[] = {1, 5, 7, -1}, 
          sum = 6
Output :  2
Pairs with sum 6 are (1, 5) and (7, -1)

Input  :  arr[] = {1, 5, 7, -1, 5}, 
          sum = 6
Output :  3
Pairs with sum 6 are (1, 5), (7, -1) &
                     (1, 5)         

Input  :  arr[] = {1, 1, 1, 1}, 
          sum = 2
Output :  6
There are 3! pairs with sum 2.

Input  :  arr[] = {10, 12, 10, 15, -1, 7, 6, 
                   5, 4, 2, 1, 1, 1}, 
          sum = 11
Output :  9
Expected time complexity O(n)

O(n) time and O(n) space complexity.
```C++
/*Efficient solution – 
A better solution is possible in O(n) time. Below is the Algorithm – 

Create a map to store frequency of each number in the array. (Single traversal is required)
In the next traversal, for every element check if it can be combined with any other element (other than itself!) to give the desired sum. Increment the counter accordingly.
After completion of second traversal, we’d have twice the required value stored in counter because every pair is counted two times. Hence divide count by 2 and return.*/
// C++ implementation of simple method to find count of
// pairs with given sum.
#include <bits/stdc++.h>
using namespace std;

// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
int getPairsCount(int arr[], int n, int sum)
{
	unordered_map<int, int> m;

	// Store counts of all elements in map m
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	int twice_count = 0;

	// iterate through each element and increment the
	// count (Notice that every pair is counted twice)
	for (int i = 0; i < n; i++) {
		twice_count += m[sum - arr[i]];

		// if (arr[i], arr[i]) pair satisfies the condition,
		// then we need to ensure that the count is
		// decreased by one such that the (arr[i], arr[i])
		// pair is not considered
		if (sum - arr[i] == arr[i])
			twice_count--;
	}

	// return the half of twice_count
	return twice_count / 2;
}

// Driver function to test the above function
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	cout << "Count of pairs is "
		<< getPairsCount(arr, n, sum);
	return 0;
}

```

`Advise:` Always have a correct image of the questions in your head before writing a the final solution. Ask as much valid doubts as possible always give the brute force solution as soon it strikes your head. Then discuss the optimised solution with the interviewer and write code for it. Make test cases on your own and test it with your code, if something fails fix the code. Always discuss what you are doing, the interviewer always gives hints if you are going in the wrong direction. Always ask good questions if the interviewer gives you a chance to ask one. Have a smile on your face throughout and just don’t panic.

`Outcome:` I along with 15-16 students made it to the next round.
<br><br>
<h2>Round 4 (2nd Technical F2F):</h2> This was a tough one for me and a decider you can say. He asked whether I am comfortable with data structures or not (obviously answer was yes) .

- Question 1: https://www.geeksforgeeks.org/the-celebrity-problem/


* Method 1: This uses Graph to arrive at the particular solution.

Approach: 
Model the solution using graphs. Initialize indegree and outdegree of every vertex as 0. If A knows B, draw a directed edge from A to B, increase indegree of B and outdegree of A by 1. Construct all possible edges of the graph for every possible pair [i, j]. There are NC2 pairs. If a celebrity is present in the party, there will be one sink node in the graph with outdegree of zero and indegree of N-1. 
 

`Algorithm:`
Create two arrays indegree and outdegree, to store the indegree and outdegree
Run a nested loop, the outer loop from 0 to n and inner loop from 0 to n.
For every pair i, j check if i knows j then increase the outdegree of i and indegree of j
For every pair i, j check if j knows i then increase the outdegree of j and indegree of i
Run a loop from 0 to n and find the id where the indegree is n-1 and outdegree is 0
Implementation:

```C++
// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;
  
// Max # of persons in the party
#define N 8
  
// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
  
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
  
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    //the graph needs not be constructed
    //as the edges can be found by
    //using knows function
     
    //degree array;
    int indegree[n]={0},outdegree[n]={0};
     
    //query for all edges
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x = knows(i,j);
             
            //set the degrees
            outdegree[i]+=x;
            indegree[j]+=x;
        }
    }
     
    //find a person with indegree n-1
    //and out degree 0
    for(int i=0; i<n; i++)
    if(indegree[i] == n-1 && outdegree[i] == 0)
        return i;
     
    return -1;
}
  
// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}
```
Output : 

Celebrity ID 2
Complexity Analysis: 

Time Complexity: O(n2). 
A nested loop is run traversing the array, SO the time complexity is O(n2)
Space Complexity: O(n). 
Since extra space of size n is required.

* Approach 2: 
The problem can be solved using recursion. Say, if the ‘potential celebrity’ of N-1 persons is known, can the solution to N be found from it? A potential celebrity is one who is the only one left after eliminating n-1 people. n-1 people are eliminated with the following strategy: 

If A knows B, then A cannot be a celebrity. But B could be.
Else If B knows A, then B cannot be a celebrity. But A could be.
The above-mentioned approach use Recursion to find the potential celebrity among n persons, recursively calls n-1 persons, till the base case of 0 persons is reached. For 0 persons -1 is returned indicating that there are no possible celebrities since there are 0 people. In the ith stage of recursion, the ith person and (i-1)th person are compared to check if anyone of them know the other. And using the above logic (in the bullet points) the potential celebrity is returned to the (i+1)th stage.

Once the recursive function returns an id. We check if this id does not know anybody else, but all others know this id. If this is true, then this id will be the celebrity.

`Algorithm : `

Create a recursive function that takes an integer n.
Check the base case, if the value of n is 0 then return -1.
Call the recursive function and get the ID of the potential celebrity from the first n-1 elements.
If the id is -1 then assign n as the potential celebrity and return the value.
If the potential  celebrity of first n-1 elements knows n-1 then return n-1, (0 based indexing)
If the celebrity of first n-1 elements does not know n-1 then return id of celebrity of n-1 elements, (0 based indexing)
Else return -1
Create a wrapper function and check whether the id returned by the function is really the celebrity or not.
```C++
// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;
 
// Max # of persons in the party
#define N 8
 
// Person with 2 is celebrity
bool MATRIX[N][N] = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };
 
bool knows(int a, int b) { return MATRIX[a][b]; }
 
// Returns -1 if a 'potential celebrity'
// is not present. If present,
// returns id (value from 0 to n-1).
int findPotentialCelebrity(int n)
{
    // base case - when n reaches 0 , returns -1
    // since n represents the number of people,
    // 0 people implies no celebrity(= -1)
    if (n == 0)
        return -1;
 
    // find the celebrity with n-1
    // persons
    int id = findPotentialCelebrity(n - 1);
 
    // if there are no celebrities
    if (id == -1)
        return n - 1;
 
    // if the id knows the nth person
    // then the id cannot be a celebrity, but nth person
    // could be one
    else if (knows(id, n - 1)) {
        return n - 1;
    }
    // if the nth person knows the id,
    // then the nth person cannot be a celebrity and the id
    // could be one
    else if (knows(n - 1, id)) {
        return id;
    }
 
    // if there is no celebrity
    return -1;
}
 
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
// a wrapper over findCelebrity
int Celebrity(int n)
{
    // find the celebrity
    int id = findPotentialCelebrity(n);
 
    // check if the celebrity found
    // is really the celebrity
    if (id == -1)
        return id;
    else {
        int c1 = 0, c2 = 0;
 
        // check the id is really the
        // celebrity
        for (int i = 0; i < n; i++)
            if (i != id) {
                c1 += knows(id, i);
                c2 += knows(i, id);
            }
 
        // if the person is known to
        // everyone.
        if (c1 == 0 && c2 == n - 1)
            return id;
 
        return -1;
    }
}
 
// Driver code
int main()
{
    int n = 4;
    int id = Celebrity(n);
    id == -1 ? cout << "No celebrity"
             : cout << "Celebrity ID " << id;
    return 0;
}
```
Output :

Celebrity ID 2
Complexity Analysis: 

Time Complexity: O(n). 
The recursive function is called n times, so the time complexity is O(n).
Space Complexity: O(1). 
As no extra space is required.

* Approach 3: There are some observations based on elimination technique (Refer Polya’s How to Solve It book). 

If A knows B, then A can’t be a celebrity. Discard A, and B may be celebrity.
If A doesn’t know B, then B can’t be a celebrity. Discard B, and A may be celebrity.
Repeat above two steps till there is only one person.
Ensure the remained person is a celebrity. (What is the need of this step?)
`Algorithm: `

Create a stack and push all the id’s in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
If A knows B, then A can’t be a celebrity and push B in stack. Else if A doesn’t know B, then B can’t be a celebrity push A in stack.
Assign the remaining element in the stack as the celebrity.
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
Implementation: 

```C++
// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;
 
// Max # of persons in the party
#define N 8
 
// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
 
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial
    // case of size = 2
    stack<int> s;
 
    // Celebrity
    int C;
 
    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);
 
    // Extract top 2
  
 
    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
   
   
    // Potential candidate?
    C = s.top();
    s.pop();
 
    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) ||
                 !knows(i, C)) )
            return -1;
    }
 
    return C;
}
 
// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}
```
Output : 

Celebrity ID 2
Complexity Analysis: 

Time Complexity: O(n). 
Total number of comparisons 3(N-1), so the time complexity is O(n).
Space Complexity: O(n). 
n extra space is needed to store the stack.


- Question 2: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

### Boundary Traversal of binary tree 
`
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.`

* 2 OS based questions: What is deadlock? and What is page fault?

Questions were very basic and needed basic OS knowledge.

`Advise:` If nothing strikes you ask as many questions as possible because you are anyways out if you don’t ask one and don’t give the solution, luckily you might get a hint which you can use to reach a solution . Reaching a solution is very very important when many students are in the same league.

`Outcome:` I made it to the next F2F round along with 9-10 students.
<br><br>
<h2>Round 5 (3rd Technical F2F): </h2> This round was to test my fundamental concepts. He gave me a problem which was that given n boxes with x1, x2, x3, ….xn balls in each of them. You need to reach a final state by transfering balls so that at the end every basket contains same number of balls . Tell whether one can reach the stable state or not. The condition was that if box n2 has x2 balls if box n1 is transfering to n2 then he has to transfer x2 balls or the same number of balls which is already present in any box has to be transfered in the same box.

He discussed the approach with me, and asked me how will I predict whether a transfer is possible or not and whether it will reach a stable state or not. I used hashing to predict a given state then he asked me the implementation of hash table. I told him everything I knew about it. He was convinced. He asked me to ask any questions from him. This marked the end of this round.
<br><br>
<h2> Round 6 (4th HR + Technical): </h2> Asked about my academics, my projects which I did in Ruby on rails, asked about Semaphores its implementation. At the end he left me with a question i.e. Alien Dictionary. He asked me to ask any questions from him. This marked the end of this round.

The interviews went on till 1 a.m. at night. The result came at 5:00 a.m. in the morning 5 students where offered FTE at MICROSOFT and I was one of them . It was the best day of my life.

`I thank GeeksForGeeks, regular practice on geeksforgeeks helped me alot during the interviews. Focus on finding a solution rather than knowing a solution during practice.`

Contributed by Yash Kapoor( iamaverage)