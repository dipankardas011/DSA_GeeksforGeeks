/*Program to generate CAPTCHA and verify user
Difficulty Level : Easy
Last Updated : 08 Mar, 2021
A CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) is a test to determine whether the user is human or not.
So, the task is to generate unique CAPTCHA every time and to tell whether the user is human or not by asking user to enter the same CAPTCHA as generated automatically and checking the user input with the generated CAPTCHA.
Examples: 
 

CAPTCHA: x9Pm72se
Input: x9Pm62es
Output: CAPTCHA Not Matched

CAPTCHA: cF3yl9T4
Input: cF3yl9T4
Output: CAPTCHA Matched*/
#include <iostream>
#include <string>
#include <cstring>
bool checkCaptacha(std::string &cap, std::string &usr)
{
    return (cap.compare(usr) == 0);
}

std::string generateCaptacha(int n)
{
    time_t t;
    srand((unsigned)time(&t));

    const char *chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::string captacha="";
    while(n--)
        captacha.push_back( chars[rand()%62] );

    return captacha;
}

int main(int argc, char const *argv[])
{
    std::string captcha=generateCaptacha(9);
    std::cout<<"+==========+\n| ";
    std::cout<<captcha<<" |\n+==========+"<<std::endl;

    std::string usr;
    std::cout<<"Enter above CAPTCHA.. ";
    std::cin>>usr;
    if(checkCaptacha(captcha, usr))
        printf("✅\n");
    else
        printf("❌\n");
    remove(argv[0]);
    return 0;
}
