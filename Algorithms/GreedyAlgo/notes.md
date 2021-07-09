# Huffman Coding | Greedy Algo-3
Difficulty Level : Hard
Last Updated : 23 Mar, 2021
Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code.
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 
Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is the prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.
See this for applications of Huffman Coding. 
There are mainly two major parts in Huffman Coding

Build a Huffman Tree from input characters.
Traverse the Huffman Tree and assign codes to characters.
Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree. 

Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
 
Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.
Let us understand the algorithm with an example:
    character   Frequency
        a            5
        b           9
        c           12
        d           13
        e           16
        f           45
Step 1. Build a min heap that contains 6 nodes where each node represents root of a tree with single node.
Step 2 Extract two minimum frequency nodes from min heap. Add a new internal node with frequency 5 + 9 = 14. 

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-1-300x129.jpeg)

Now min heap contains 5 nodes where 4 nodes are roots of trees with single element each, and one heap node is root of tree with 3 elements

    character           Frequency
        c               12
        d               13
    Internal Node         14
        e               16
        f                45
Step 3: Extract two minimum frequency nodes from heap. Add a new internal node with frequency 12 + 13 = 25
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-2-300x132.jpg)

Now min heap contains 4 nodes where 2 nodes are roots of trees with single element each, and two heap nodes are root of tree with more than one nodes

    character           Frequency
    Internal Node          14
        e               16
    Internal Node          25
        f               45
Step 4: Extract two minimum frequency nodes. Add a new internal node with frequency 14 + 16 = 30
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-3-300x162.jpg)

Now min heap contains 3 nodes.

    character          Frequency
    Internal Node         25
    Internal Node         30
        f               45 
Step 5: Extract two minimum frequency nodes. Add a new internal node with frequency 25 + 30 = 55
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-4-300x121.jpg)

Now min heap contains 2 nodes.

    character     Frequency
        f         45
    Internal Node    55
Step 6: Extract two minimum frequency nodes. Add a new internal node with frequency 45 + 55 = 100
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-5-300x167.jpg)

Now min heap contains only one node.

character      Frequency
Internal Node    100
Since the heap contains only one node, the algorithm stops here.
Steps to print codes from Huffman Tree:
Traverse the tree formed starting from the root. Maintain an auxiliary array. While moving to the left child, write 0 to the array. While moving to the right child, write 1 to the array. Print the array when a leaf node is encountered.
 
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-6-300x167.jpg)

The codes are as follows:

    character   code-word
        f          0
        c          100
        d          101
        a          1100
        b          1101
        e          111

----->>[  `a1.c`  ]

# Job Sequencing Problem
Difficulty Level : Medium
Last Updated : 03 May, 2021
 
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

    Examples: 

    Input: Four Jobs with following 
    deadlines and profits
    JobID  Deadline  Profit
    a      4        20   
    b      1        10
    c      1        40  
    d      1        30
    Output: Following is maximum 
    profit sequence of jobs
            c, a   


    Input:  Five Jobs with following
    deadlines and profits
    JobID   Deadline  Profit
    a       2        100
    b       1        19
    c       2        27
    d       1        25
    e       3        15
    Output: Following is maximum 
    profit sequence of jobs
            c, a, e

A Simple Solution is to generate all subsets of a given set of jobs and check individual subsets for the feasibility of jobs in that subset. Keep track of maximum profit among all feasible subsets. The time complexity of this solution is exponential. 
This is a standard Greedy Algorithm problem. 

Following is the algorithm.

1) Sort all jobs in decreasing order of profit. 
2) Iterate on jobs in decreasing order of profit.For each job , do the following :

    .For each job find an empty time slot from deadline to 0. If found empty slot put the job in the slot and mark this slot filled.

---->> [ `a2.cpp`  ]

# Minimum Number of Platforms Required for a Railway/Bus Station
Difficulty Level : Medium
Last Updated : 04 May, 2021
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.

    Examples: 

    Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00} 
    dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
    Output: 3 
    Explanation: There are at-most three trains at a time (time between 11:00 to 11:20)

    Input: arr[] = {9:00, 9:40} 
    dep[] = {9:10, 12:00} 
    Output: 1 
    Explanation: Only one platform is needed. 


Efficient Solution:

Approach: The idea is to consider all events in sorted order. Once the events are in sorted order, trace the number of trains at any time keeping track of trains that have arrived, but not departed.
For example, consider the above example. 

arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events are sorted by time.
Total platforms at any time can be obtained by
subtracting total departures from total arrivals
by that time.

    Time      Event Type     Total Platforms Needed 
                                at this Time                               
    9:00       Arrival                  1
    9:10       Departure                0
    9:40       Arrival                  1
    9:50       Arrival                  2
    11:00      Arrival                  3 
    11:20      Departure                2
    11:30      Departure                1
    12:00      Departure                0
    15:00      Arrival                  1
    18:00      Arrival                  2 
    19:00      Departure                1
    20:00      Departure                0

Minimum Platforms needed on railway station 
= Maximum platforms needed at any time 
= 3
Note: This approach assumes that trains are arriving and departing on the same date. 
 

Algorithm:

Sort the arrival and departure times of trains.
Create two pointers i=0, and j=0 and a variable to store ans and current count plat
Run a loop while i < n and j< n and compare the ith element of arrival array and jth element of departure array.
If the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat– and increment j
Update the ans, i.e ans = max(ans, plat).