/**/
#include <iostream>
#include <string>
using namespace std;
/**
 * @def maxSum() calculete the max using + and *
*/
int maxSum(string str){
    int res=str[0]-'0';
    for(int i=1;i<str.length();i++)
    {
        if(str[i]=='0' || str[i]=='1' || res<2)
            //addition
            res+= (str[i]-'0');
        else
            res*=(str[i]-'0');
    }
    return res;
}

int main(){
    string num="891";
    cout<<"the max sum= "<<maxSum(num)<<endl;
    return 0;
}