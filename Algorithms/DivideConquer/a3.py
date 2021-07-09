# Divide and Conquer | Set 5 (Strassen’s Matrix Multiplication)
# Difficulty Level : Medium
# Last Updated : 15 Jun, 2021
 
# Given two square matrices A and B of size n x n each, find their multiplication matrix. 
# Naive Method 
# Following is a simple way to multiply two matrices. 
# void multiply(int A[][N], int B[][N], int C[][N])
# {
#     for (int i = 0; i < N; i++)
#     {
#         for (int j = 0; j < N; j++)
#         {
#             C[i][j] = 0;
#             for (int k = 0; k < N; k++)
#             {
#                 C[i][j] += A[i][k]*B[k][j];
#             }
#         }
#     }
# }

# Simple Divide and Conquer also leads to O(N3), can there be a better way? 
# In the above divide and conquer method, the main component for high time complexity is 8 recursive calls. The idea of Strassen’s method is to reduce the number of recursive calls to 7. Strassen’s method is similar to above simple divide and conquer method in the sense that this method also divide matrices to sub-matrices of size N/2 x N/2 as shown in the above diagram, but in Strassen’s method, the four sub-matrices of result are calculated using following formulae.
 

# ![stressen_formula_new_new](https://www.geeksforgeeks.org/wp-content/uploads/stressen_formula_new_new.png)

# Time Complexity of Strassen’s Method 
# Addition and Subtraction of two matrices takes O(N2) time. So time complexity can be written as 
 

# T(N) = 7T(N/2) +  O(N2)

# From Master's Theorem, time complexity of above method is 
# O(NLog7) which is approximately O(N2.8074)
# Generally Strassen’s Method is not preferred for practical applications for following reasons. 
# 1) The constants used in Strassen’s method are high and for a typical application Naive method works better. 
# 2) For Sparse matrices, there are better methods especially designed for them. 
# 3) The submatrices in recursion take extra space. 
# 4) Because of the limited precision of computer arithmetic on noninteger values, larger errors accumulate in Strassen’s algorithm than in Naive Method (Source: CLRS Book) 
import numpy as np
 
def split(matrix):
    """
    Splits a given matrix into quarters.
    Input: nxn matrix
    Output: tuple containing 4 n/2 x n/2 matrices corresponding to a, b, c, d
    """
    row, col = matrix.shape
    row2, col2 = row//2, col//2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]
 
def strassen(x, y):
    """
    Computes matrix product by divide and conquer approach, recursively.
    Input: nxn matrices x and y
    Output: nxn matrix, product of x and y
    """
 
    # Base case when size of matrices is 1x1
    if len(x) == 1:
        return x * y
 
    # Splitting the matrices into quadrants. This will be done recursively
    # untill the base case is reached.
    a, b, c, d = split(x)
    e, f, g, h = split(y)
 
    # Computing the 7 products, recursively (p1, p2...p7)
    p1 = strassen(a, f - h) 
    p2 = strassen(a + b, h)       
    p3 = strassen(c + d, e)       
    p4 = strassen(d, g - e)       
    p5 = strassen(a + d, e + h)       
    p6 = strassen(b - d, g + h) 
    p7 = strassen(a - c, e + f) 
 
    # Computing the values of the 4 quadrants of the final matrix c
    c11 = p5 + p4 - p2 + p6 
    c12 = p1 + p2          
    c21 = p3 + p4           
    c22 = p1 + p5 - p3 - p7 
 
    # Combining the 4 quadrants into a single matrix by stacking horizontally and vertically.
    c = np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))
 
    return c