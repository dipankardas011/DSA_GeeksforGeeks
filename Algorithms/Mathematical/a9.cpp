/*Calculate the angle between hour hand and minute hand
Difficulty Level : Easy
Last Updated : 09 Mar, 2021
This problem is known as Clock angle problem where we need to find angle between hands of an analog clock at a given time.
Examples: 

Input:  
h = 12:00
m = 30.00
Output: 
165 degree

Input:  
h = 3.00
m = 30.00
Output: 
75 degree 
The idea is to take 12:00 (h = 12, m = 0) as a reference. Following are detailed steps.

1. Calculate the angle made by hour hand with respect to 12:00 in h hours and m minutes. 
2. Calculate the angle made by minute hand with respect to 12:00 in h hours and m minutes. 
3. The difference between the two angles is the angle between the two hands.

How to calculate the two angles with respect to 12:00? 
The minute hand moves 360 degrees in 60 minute(or 6 degrees in one minute) and hour hand moves 360 degrees in 12 hours(or 0.5 degrees in 1 minute). In h hours and m minutes, the minute hand would move (h*60 + m)*6 and hour hand would move (h*60 + m)*0.5.*/
#include <iostream>

int calAngle(double h, double m)
{
    if(h<0 || m<0 || h>12 || m>60)
    {
        std::cout<<"Wrong input";
        return -1;
    }
    if(h==12) h=0;
    if(m==60){
        m=0;
        h+=1;
        if(h>12)
            h -=12;
    }
    float hourAngle=0.5 * (h * 60 + m);
    float minAngle=6*m;

    float angle=abs(hourAngle-minAngle);

    return std::min(360-angle, angle);
    
}

int main(int argc, char const *argv[])
{
    std::cout << calAngle(9, 60) << std::endl;
    std::cout << calAngle(3, 30) << std::endl;
    remove(argv[0]);
    return 0;
}
