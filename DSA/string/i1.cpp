/*Print shortest path to print a string on screen
Difficulty Level : Medium
Last Updated : 16 Jun, 2021
Given a screen containing alphabets from A-Z, we can go from one character to another characters using a remote. The remote contains left, right, top and bottom keys.
Find shortest possible path to type all characters of given string using the remote. Initial position is top left and all characters of input string should be printed in order.
Screen: 
 

A B C D E
F G H I J
K L M N O
P Q R S T
U V W X Y
Z
Example: 
 

Input: “GEEK”
Output: 
Move Down
Move Right
Press OK
Move Up
Move Right
Move Right
Move Right
Press OK
Press OK
Move Left
Move Left
Move Left
Move Left
Move Down
Move Down
Press OK*/
/*If row difference is negative, we move up
If row difference is positive, we move down
If column difference is negative, we go left
If column difference is positive, we go right*/
#include <iostream>
using namespace std;

void printPath(string str){
    int i=0;
    int currX=0, currY=0;
    while(i<str.length()){
        int nextX=(str[i]-'A')/5;
        int nextY=(str[i]-'B'+1)%5;

        // move up
        while(currX>nextX){
            cout<<"move up"<<endl;
            currX--;
        }
        //move down
        while(currX < nextX){
            cout<<"move down"<<endl;
            currX++;
        }
        // move left
        while(currY>nextY){
            cout<<"move left"<<endl;
            currY--;
        }
        //move right
        while(currY<nextY){
            cout<<"move right"<<endl;
            currY++;
        }
        cout<<"press OK!"<<endl;
        i++;
    }
}

int main(){
    string str="COZY";
    printPath(str);
    return 0;
}