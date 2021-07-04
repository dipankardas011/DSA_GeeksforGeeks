/*print reverse of a string using recursion*/

#include <iostream>
#include<string>
using namespace std;

void reverse(string str)
{
    if(!str.length())return ;

    reverse(str.substr(1));
    cout<<str[0];
}

int main(){
    string str="dipankar das";
    reverse(str);
    cout<<endl;
    return 0;
}