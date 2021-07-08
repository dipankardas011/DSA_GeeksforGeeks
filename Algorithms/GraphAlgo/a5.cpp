/*Snake and Ladder Problem
Difficulty Level : Hard
Last Updated : 09 Nov, 2020
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if reaches a cell is mouth of the snake, has to go down to the tail of snake without a dice throw.

![snakesandladders](https://media.geeksforgeeks.org/wp-content/uploads/snake-and-ladders.jpg)

For example, consider the board shown, the minimum number of dice throws required to reach cell 30 from cell 1 is 3.
Following are the steps:

a) First throw two on dice to reach cell number 3 and then ladder to reach 22
b) Then throw 6 to reach 28.
c) Finally through 2 to reach 30.



There can be other solutions as well like (2, 2, 6), (2, 4, 4), (2, 3, 5).. etc.*/
// its simple we just have to map the whole matrix in graph and traverse
// it there is chance to to go lower then the reference then we must go indicating the ladder "@//me@"
/*
given algorithm
The idea is to consider the given snake and ladder board as a directed graph with number of vertices equal to the number of cells in the board. The problem reduces to finding the shortest path in a graph. Every vertex of the graph has an edge to next six vertices if next 6 vertices do not have a snake or ladder. If any of the next six vertices has a snake or ladder, then the edge from current vertex goes to the top of the ladder or tail of the snake. Since all edges are of equal weight, we can efficiently find shortest path using Breadth First Search of the graph.

Following is the implementation of the above idea. The input is represented by two things, first is ‘N’ which is number of cells in the given board, second is an array ‘move[0…N-1]’ of size N. An entry move[i] is -1 if there is no snake and no ladder from i, otherwise move[i] contains index of destination cell for the snake or the ladder at i.*/
#include <iostream>
#include <queue>
#include <cstring>
struct queueEntry{
    int v;      // vertex number
    int dist;   // distance of this vertex from src
};

// we are going to use the BFS
int getMinDiceThrows(int move[], int N)
{
    bool *visited=new bool [N];
    memset(visited, false, sizeof(visited));

    std::queue<queueEntry> que;
    visited[0]=true;                    // mark the node 0 as visited and enqueue it

    queueEntry s={0,0};                 // distance of 0th vertex is 0
    que.push(s);

    queueEntry x;                       //var of type queueEntry
    while(!que.empty())
    {
        x=que.front();
        int v=x.v;                      // vertex number in v

        if(v==N-1)                      // if the vertex is the destination reached the finish
            break; 
        
        que.pop();
        for(int j=v+1; j<=(v+6) && j<N; j++) // this loop is for the simulation of dice [1..6] increments from
        {                                    // the corrent vertex v
        
            if(!visited[j])             // the cell is not visited claculate the diatance
            {
                queueEntry a;
                a.dist=(x.dist+1);      // it mmeans that we have rolled the dice once more!
                visited[j]=true;

                 
                if(move[j]!=-1)         // here comes the jumping
                    a.v=move[j];
                else
                    a.v=j;
                
                que.push(a);
            }
        }
    }
    
    return x.dist;            // We reach here when 'x' has last vertex return the distance of vertex in 'x'
}
int main(int argc, char const *argv[])
{
    int n=30;
    int moves[n];
    for(int i=0;i<n;i++)
        moves[i]=-1;
    // ladders
    moves[2]=21;
    moves[4]=7;
    moves[10]=25;
    moves[19]=28;

    //snakes
    moves[26]=0;
    moves[20]=8;
    moves[16]=3;
    moves[18]=6;

    std::cout<<"min dice throws required = "<<getMinDiceThrows(moves,n)<<std::endl;
    remove(argv[0]);
    return 0;
}
