# Expected Number of Trials until Success

Consider the following famous puzzle.

In a country, all families want a boy. They keep having babies till a boy is born. What is the expected ratio of boys and girls in the country?

This puzzle can be easily solved if we know following interesting result in probability and expectation.

If probability of success is p in every trial, then expected number of trials until success is 1/p

Proof: Let R be a random variable that indicates number of trials until success.


```
The expected value of R is sum of following infinite series
E[R] = 1*p + 2*(1-p)*p + 3*(1-p)2*p + 4*(1-p)3*p + ........ 

Taking 'p' out
E[R] = p[1 + 2*(1-p) + 3*(1-p)2 + 4*(1-p)3 + .......] ---->(1)

Multiplying both sides with '(1-p)' and subtracting 
(1-p)*E[R] = p[1*(1-p) + 2*(1-p)2 + 3*(1-p)3 + .......] --->(2)

Subtracting (2) from (1), we get

p*E[R] = p[1 + (1-p) + (1-p)2 + (1-p)3 + ........] 

Canceling p from both sides
E[R] = [1 + (1-p) + (1-p)2 + (1-p)3 + ........] 

Above is an  infinite geometric  progression with ratio (1-p). 
Since (1-p) is less than, we can apply sum formula.
  E[R] = 1/[1 - (1-p)]
       = 1/p
```
Solution of Boys/Girls ratio puzzle:
Let us use the above result to solve the puzzle. In the given puzzle, probability of success in every trial is 1/2 (assuming that girls and boys are equally likely).

Let p be probability of having a baby boy.
```
Number of kids until a baby boy is born = 1/p 
                                        = 1/(1/2)
                                        = 2 
```
Since expected number of kids in a family is 2,
ratio of boys and girls is 50:50. 
Let us discuss another problem that uses above result.

Coupon Collector Problem:
Suppose there are n types of coupons in a lottery and each lot contains one coupon (with probability 1 = n each). How many lots have to be bought (in expectation) until we have at least one coupon of each type.

The solution of this problem is also based on above result.

Let Xi be the number of lots bought before i’th new coupon is collected.

Note that X1 is 1 as the first coupon is always a new coupon (not collected before).

Let ‘p’ be probability that 2nd coupon is collected in next buy. The value of p is (n-1)/n. So the number of trials needed before 2nd new coupon is picked is 1/p which means n/(n-1). [This is where we use above result]

Similarly, the number of trials needed before 3rd new coupon is collected is n/(n-2)

```

Using Linearity of expectation, 
we can say that the total number of expected trials = 
                1 + n/(n-1) + n/(n-2) + n/(n-3) + .... + n/2 + n/1
                = n[1/n + 1/(n-1) + 1/(n-2) + 1/(n-3) + ....+ 1/2 + 1/1]
                = n * Hn
```
Here Hn is n-th Harmonic number

Since Logn <= Hn <= Logn + 1, we need to buy around 
nLogn lots to collect all n coupons. 
Exercise:
1) A 6 faced fair dice is thrown until a '5' is seen as result of dice throw. What is the expected number of throws?

2) What is the ratio of boys and girls in above puzzle if probability of a baby boy is 1/3?

Reference:
http://www.cse.iitd.ac.in/~mohanty/col106/Resources/linearity_expectation.pdf

http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-042j-mathematics-for-computer-science-fall-2010/video-lectures/lecture-22-expectation-i/

# Randomized Algorithms | Set 0 (Mathematical Background)
Conditional Probability Conditional probability P(A | B) indicates the probability of even ‘A’ happening given that the even B happened.
```
 P(A|B) = \frac{P(A\cap B)}{P(B)} 
```
We can easily understand above formula using below diagram. Since B has already happened, the sample space reduces to B. So the probability of A happening becomes P(A ∩ B) divided by P(B)

conditional_probab

Below is Bayes’s formula for conditional probability.


```
 P(A|B) = \frac{P(B|A)P(A)}{P(B)} 

The formula provides relationship between P(A|B) and P(B|A). It is mainly derived form conditional probability formula discussed in the previous post.

Consider the below forrmulas for conditional probabilities P(A|B) and P(B|A)

 P(A|B) = \frac{P(A\cap B)}{P(B)}  ---1 

 P(B|A) = \frac{P(B\cap A)}{P(A)}  ---2 
```
Since P(B ∩ A) = P(A ∩ B), we can replace P(A ∩ B) in first formula with P(B|A)P(A)
After replacing, we get the given formula. Refer this for examples of Bayes’s formula.

 

Random Variables:
A random variable is actually a function that maps outcome of a random event (like coin toss) to a real value.



Example :

Coin tossing game : 
A player pays 50 bucks if result of coin
toss is "Head" 

The person gets 50 bucks if the result is
Tail. 

A random variable profit for person can 
be defined as below : 

Profit = +50 if Head
         -50 if Tail  

Generally gambling games are not fair for players, 
the organizer takes a share of profit for all 
arrangements. So expected profit is negative for 
a player in gambling and positive for the organizer. 
That is how organizers make money.
```
Expected Value of Random Variable :
Expected value of a random variable R can be defined as following

    E[R] = r1*p1 + r2*p2 + ... rk*pk 
    
    ri ==> Value of R with probability pi
```
Expected value is basically sum of product of following two terms (for all possible events)
a) Probability of an event.
b) Value of R at that even
```
Example 1:
In above example of coin toss,
Expected value of profit = 50 * (1/2) + 
                          (-50) * (1/2)
                         = 0

Example 2:
Expected value of six faced dice throw is 
  = 1*(1/6) + 2*(1/6) + .... + 6*(1/6)
  = 3.5
 
Linearity of Expectation:
Let R1 and R2 be two discrete random variables on some probability space, then

     E[R1 + R2] = E[R1] + E[R2] 
```
For example, expected value of sum for 3 dice throws is = 3 * 7/2 = 7

Refer this for more detailed explanation and examples.

 
Expected Number of Trials until Success
If probability of success is p in every trial, then expected number of trials until success is 1/p. For example, consider 6 faced fair dice is thrown until a ‘5’ is seen as result of dice throw. The expected number of throws before seeing a 5 is 6. Note that 1/6 is probability of getting a 5 in every trial. So number of trials is 1/(1/6) = 6.
As another example, consider a QuickSort version that keeps on looking for pivots until one of the middle n/2 elements is picked. The expected time number of trials for finding middle pivot would be 2 as probability of picking one of the middle n/2 elements is 1/2. This example is discussed in more detail in Set 1.
Refer this for more detailed explanation and examples.

# Randomized Algorithms | Set 1 (Introduction and Analysis)
Difficulty Level : Hard
Last Updated : 28 Sep, 2020
What is a Randomized Algorithm?
An algorithm that uses random numbers to decide what to do next anywhere in its logic is called a Randomized Algorithm. For example, in Randomized Quick Sort, we use a random number to pick the next pivot (or we randomly shuffle the array). And in Karger’s algorithm, we randomly pick an edge. 

 

How to analyse Randomized Algorithms?
Some randomized algorithms have deterministic time complexity. For example, this implementation of Karger’s algorithm has time complexity is O(E). Such algorithms are called Monte Carlo Algorithms and are easier to analyse for worst case. 
On the other hand, time complexity of other randomized algorithms (other than Las Vegas) is dependent on value of random variable. Such Randomized algorithms are called Las Vegas Algorithms. These algorithms are typically analysed for expected worst case. To compute expected time taken in worst case, all possible values of the used random variable needs to be considered in worst case and time taken by every possible value needs to be evaluated. Average of all evaluated times is the expected worst case time complexity. Below facts are generally helpful in analysis os such algorithms. 
Linearity of Expectation 
Expected Number of Trials until Success. 

For example consider below a randomized version of QuickSort. 

A Central Pivot is a pivot that divides the array in such a way that one side has at-least 1/4 elements. 

```
// Sorts an array arr[low..high]
randQuickSort(arr[], low, high)

1. If low >= high, then EXIT.

2. While pivot 'x' is not a Central Pivot.
  (i)   Choose uniformly at random a number from [low..high]. 
        Let the randomly picked number number be x.
  (ii)  Count elements in arr[low..high] that are smaller 
        than arr[x]. Let this count be sc.
  (iii) Count elements in arr[low..high] that are greater 
        than arr[x]. Let this count be gc.
  (iv)  Let n = (high-low+1). If sc >= n/4 and
        gc >= n/4, then x is a central pivot.

3. Partition arr[low..high] around the pivot x.

4. // Recur for smaller elements
   randQuickSort(arr, low, sc-1) 

5. // Recur for greater elements
   randQuickSort(arr, high-gc+1, high) 
```
The important thing in our analysis is, time taken by step 2 is O(n). 

How many times while loop runs before finding a central pivot? 
The probability that the randomly chosen element is central pivot is 1/n. 

Therefore, expected number of times the while loop runs is n (See this for details) 

Thus, the expected time complexity of step 2 is O(n). 

What is overall Time Complexity in Worst Case? 
In worst case, each partition divides array such that one side has n/4 elements and other side has 3n/4 elements. The worst case height of recursion tree is Logbase(3/4) n which is O(Log n). 
```
T(n) < T(n/4) + T(3n/4) + O(n)
T(n) < 2T(3n/4) + O(n)
```
Solution of above recurrence is O(n Log n) 

Note that the above randomized algorithm is not the best way to implement randomized Quick Sort. The idea here is to simplify the analysis as it is simple to analyse. 
Typically, randomized Quick Sort is implemented by randomly picking a pivot (no loop). Or by shuffling array elements. Expected worst case time complexity of this algorithm is also O(n Log n), but analysis is complex, the MIT prof himself mentions same in his lecture here. 

Randomized Algorithms | Set 2 (Classification and Applications) 

References: 
http://www.tcs.tifr.res.in/~workshop/nitrkl_igga/randomized-lecture.pdf 

# Randomized Algorithms | Set 2 (Classification and Applications)

Randomized Algorithms | Set 1 (Introduction and Analysis)

Classification
Randomized algorithms are classified in two categories.

1. Las Vegas: These algorithms always produce correct or optimum result. Time complexity of these algorithms is based on a random value and time complexity is evaluated as expected value. For example, Randomized QuickSort always sorts an input array and expected worst case time complexity of QuickSort is O(nLogn).

2. Monte Carlo: Produce correct or optimum result with some probability. These algorithms have deterministic running time and it is generally easier to find out worst case time complexity. For example this implementation of Karger’s Algorithm produces minimum cut with probability greater than or equal to 1/n2 (n is number of vertices) and has worst case time complexity as O(E). Another example is Fermet Method for Primality Testing.

Example to Understand Classification:

Consider a binary array where exactly half elements are 0
and half are 1. The task is to find index of any 1.  
A Las Vegas algorithm for this task is to keep picking a random element until we find a 1. A Monte Carlo algorithm for the same is to keep picking a random element until we either find 1 or we have tried maximum allowed times say k.
The Las Vegas algorithm always finds an index of 1, but time complexity is determined as expect value. The expected number of trials before success is 2, therefore expected time complexity is O(1).
The Monte Carlo Algorithm finds a 1 with probability [1 – (1/2)k]. Time complexity of Monte Carlo is O(k) which is deterministic

Applications and Scope:
* Consider a tool that basically does sorting. Let the tool be used by many users and there are few users who always use tool for already sorted array. If the tool uses simple (not randomized) QuickSort, then those few users are always going to face worst case situation. On the other hand if the tool uses Randomized QuickSort, then there is no user that always gets worst case. Everybody gets expected O(n Log n) time.
* Randomized algorithms have huge applications in Cryptography.
* Load Balancing.
* Number-Theoretic Applications: Primality Testing
* Data Structures: Hashing, Sorting, Searching, Order Statistics and Computational Geometry.
* Algebraic identities: Polynomial and matrix identity verification. Interactive proof systems.
* Mathematical programming: Faster algorithms for linear programming, Rounding linear program solutions to integer program solutions
* Graph algorithms: Minimum spanning trees, shortest paths, minimum cuts.
* Counting and enumeration: Matrix permanent Counting combinatorial structures.
* Parallel and distributed computing: Deadlock avoidance distributed consensus.
* Probabilistic existence proofs: Show that a combinatorial object arises with non-zero probability among objects drawn from a suitable probability space.
* Derandomization: First devise a randomized algorithm then argue that it can be derandomized to yield a deterministic algorithm.
Sources:
http://theory.stanford.edu/people/pragh/amstalk.pdf
https://en.wikipedia.org/wiki/Randomized_algorithm

# Randomized Algorithms | Set 3 (1/2 Approximate Median)
Difficulty Level : Basic
Last Updated : 19 Sep, 2018
We strongly recommend to refer below articles as a prerequisite of this.

Randomized Algorithms | Set 1 (Introduction and Analysis)
Randomized Algorithms | Set 2 (Classification and Applications)

In this post, a Monte Carlo algorithm is discussed.

Problem Statement : Given an unsorted array A[] of n numbers and ε > 0, compute an element whose rank (position in sorted A[]) is in the range [(1 – ε)n/2, (1 + ε)n/2].
For ½ Approximate Median Algorithm &epsilom; is 1/2 => rank should be in the range [n/4, 3n/4]

We can find k’th smallest element in O(n) expected time and O(n) worst case time.



What if we want in less than O(n) time with low probable error allowed?
Following steps represent an algorithm that is O((Log n) x (Log Log n)) time and produces incorrect result with probability less than or equal to 2/n2.

Randomly choose k elements from the array where k=c log n (c is some constant)
Insert then into a set.
Sort elements of the set.
Return median of the set i.e. (k/2)th element from the set

-->> [a1.cpp]
Output:

Approximate Median is 4
Time Complexity:
We use a set provided by the STL in C++. In STL Set, insertion for each element takes O(log k). So for k insertions, time taken is O (k log k).
Now replacing k with c log n
```
=>O(c log n (log (clog n))) =>O (log n (log log n))
```
How is probability of error less than 2/n2?
Algorithm makes an error if the set S has at least k/2 elements are from the Left Quarter or Right Quarter.
median

It is quite easy to visualize this statement since the median which we report will be (k/2)th element and if we take k/2 elements from the left quarter(or right quarter) the median will be from the left quarter (or the right quarter).

An array can be divided into 4 quarters each of size n/4. So P(selecting left quarter) is 1/4. So what is the probability that at least k/2 elements are from the Left Quarter or Right Quarter? This probability problem is same as below :

Given a coin which gives HEADS with probability 1/4 and TAILS with 3/4. The coin is tossed k times. What is the probability that we get at least k/2 HEADS is less than or equal to?

Explanation:probability

```

If we put k = c log n for c = 10, we get 
P <= (1/2)2log n
P <= (1/2)log n2
P <= n-2
Probability of selecting at least k/2 elements from the left quarter) <= 1/n2
Probability of selecting at least k/2 elements from the left or right quarter) <= 2/n2
```
Therefore algorithm produces incorrect result with probability less that or equal to 2/n2.


References:www.cse.iitk.ac.in/users/sbaswana/CS648/Lecture-2-CS648.pptx