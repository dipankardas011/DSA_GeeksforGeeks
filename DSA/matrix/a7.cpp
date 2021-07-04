/*Number of cells a queen can move with obstacles on the chessborad
Difficulty Level : Medium
Last Updated : 12 May, 2021
Consider a N X N chessboard with a Queen and K obstacles. The Queen cannot pass through obstacles. Given the position (x, y) of Queen, the task is to find the number of cells the queen can move.
Examples: 
 

Input : N = 8, x = 4, y = 4, 
        K = 0
Output : 27


Input : N = 8, x = 4, y = 4, 
        K = 1, kx1 = 3, ky1 = 5
Output : 24*/
/*The idea is to iterate over the obstacles and for those who are in the queen’s path, we calculate the free cells upto that obstacle. If there is no obstacle in the path we have to calculate the number of free cells upto end of board in that direction. 
For any (x1, y1) and (x2, y2): 
 

If they are horizontally at same level: abs(x1 – x2 – 1)
If they are vertically at same level: abs(y1 – y2 – 1) is the number of free cells between.
If they are diagonal: both abs(x1 – x2 – 1) or abs(y1 – y2 – 1) is the number of free cells between.*/
#include <iostream>
using namespace std;

int numberOfPosition(int n, int k, int qX, int qY, int obstX[], int obstY[])
{
    /**
     * @param d11 diagonal distances
     * @param d12 diagonal distances
     * @param d21 diagonal distances
     * @param d22 diagonal distances
     * @param r1 vertical distance row
     * @param r2 vertical distance row
     * @param c1 horizontal distance row
     * @param c2 horizontal distance row
    */
    /**
    * 0   ^
    *  0 ^
    *   0
    *  ^ 0
    * ^   0
    * @param d11 0
    * @param d12 0
    * @param d22 ^
    * @param d21 ^
   */
    int d11, d12, d21, d22, r1, r2, c1, c2;
    d11 = min(qX - 1, qY - 1);
    d12 = min(n - qX, n - qY);
    d21 = min(n - qX, qY - 1);
    d22 = min(qX - 1, n - qY);

    r1 = qY - 1;
    r2 = n - qY;
    c1 = qX - 1;
    c2 = n - qX;

    for(int i=0;i<k;i++){
        // all the obstacles
        if(qX > obstX[i] && qY > obstY[i] && qX-obstX[i] == qY-obstY[i])
            d11=min(d11, qX-obstX[i]-1);
        
        if(qX < obstX[i] && qY < obstY[i] && obstX[i]-qX == obstY[i]-qY)
            d12=min(d12, obstX[i]-1-qX);

        if(qX < obstX[i] && qY > obstY[i] && obstX[i]-qX == obstY[i]-qY)
            d21=min(d21, obstX[i]-1-qX);

        if(qX > obstX[i] && qY < obstY[i] && qX-obstX[i] == obstY[i]-qY)
            d22=min(d22, qX-obstX[i]-1);

        if(qX==obstX[i] && obstY[i]<qY)
            r1=min(r1,qY-obstY[i]-1);

        if(qX==obstX[i] && obstY[i]>qY)
            r2=min(r2,obstY[i]-qY-1);

        if(qY==obstY[i] && obstX[i]<qX)
            c1=min(c1,qX-obstX[i]-1);
        if(qY==obstY[i] && obstX[i]<qX)
            c2=min(c2,obstY[i]-qX-1);
    }
    return d11+d12+d21+d22+r1+r2+c1+c2;
}

int main()
{
    /**
     * @param n chessboard
     * @param k no of obstacles
     * @param qposx queens xposition
     * @param qposy queens yposition
     * @param obstPosX xposition of obstacle
     * @param obstPosY yposition of obstacle
    */
    int n = 8;
    int k = 1;
    int qposx = 4;
    int qposy = 4;
    int obstPosX[] = {3};
    int obstPosY[] = {5};

    cout<<numberOfPosition(n,k,qposx,qposy,obstPosX,obstPosY)<<endl;
    return 0;
}