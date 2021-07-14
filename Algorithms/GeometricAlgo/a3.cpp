/*Convex Hull | Set 1 (Jarvis’s Algorithm or Wrapping)
Difficulty Level : Hard
Last Updated : 28 Mar, 2021
Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.


![](https://media.geeksforgeeks.org/wp-content/uploads/ConvexHull.png)

How to check if two given line segments intersect?

The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) and we keep wrapping points in counterclockwise direction. The big question is, given a point p as current point, how to find the next point in output? The idea is to use orientation() here. Next point is selected as the point that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, we have “orientation(p, q, r) = counterclockwise”. Following is the detailed algorithm.

1) Initialize p as leftmost point.
2) Do following while we don’t come back to the first (or leftmost) point.
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r. To find this, we simply initialize q as next point, then we traverse through all points. For any point i, if i is more counterclockwise, i.e., orientation(p, i, q) is counterclockwise, then we update q as i. Our final value of q is going to be the most counterclockwise point.
…..b) next[p] = q (Store q as next of p in the output convex hull).
…..c) p = q (Set p as q for next iteration).

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20210324150207/Jarvis-March_1_60.jpg)
*/
#include <iostream>
#include <vector>
struct point
{
    int x, y;
};

int orientation(point p, point q, point r)
{
    int val=(q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

    if(!val)
        return 0;//colinear
    
    return (val>0)? 1:2; // 1 for +ve 2 for -ve
}

void convexHull(point po[], int n)
{
    // must be atleast 3 points
    if(n<3)
        return ;

    std::vector<point> hull;
    // find the left most point
    int l=0;
    for(int i=1;i<n;i++)
        if(po[i].x < po[l].x)
            l=i;

    // Start from leftmost point, keep moving counterclockwise until reach the start point again.  This loop runs O(h) times where h is number of points in result or output.
    int p=l, q;
    do{
        hull.push_back(po[p]);

        q=(p+1)%n;
        // Search for a point 'q' such that orientation(p, q, x) is counterclockwise for all points 'x'. The idea is to keep track of last visited most counterclock- wise point in q. If any point 'i' is more counterclock- wise than q, then update q.
        for(int i=0;i<n;i++)
            if(orientation(po[p],po[i],po[q]) == 2)
                q=i;
        // Now q is the most counterclockwise with respect to p Set p as q for next iteration, so that q is added to result 'hull'
        p=q;

    }while(p!=l);

    for(auto i:hull)
        std::cout<<"("<<i.x<<", "<<i.y<<")"<<std::endl;
}

int main(int argc, char const *argv[])
{
    point p[] = {{0, 3},
                 {2, 2},
                 {1, 1},
                 {2, 1},
                 {3, 0},
                 {0, 0},
                 {3, 3}};
    int n=sizeof(p)/sizeof(p[0]);
    convexHull(p,n);
    remove(argv[0]);
    return 0;
}
