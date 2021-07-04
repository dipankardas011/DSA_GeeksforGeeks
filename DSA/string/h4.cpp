/*Expression contains redundant bracket or not
Difficulty Level : Medium
Last Updated : 10 Jun, 2021
Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.
Example: 
 

Input: 
((a+b))
(a+(b)/c)
(a+b*(c-d))
Output: 
Yes
Yes
No

Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.*/
#include <iostream>
#include <stack>

bool checkRedundancy(std::string str)
{
    std::stack<char> st;
    for(auto& ch:str){
        if(ch==')')
        {
            char top=st.top();
            st.pop();
            // if flag = true : that there is immediate open () 
            bool flag=true;
            while(!st.empty() and top!='('){
                if(top=='+' || top=='-' || top=='*' || top=='/')
                    flag=false;
                top=st.top();
                st.pop();
            }
            if(flag==true)
                return true;
        }
        else{
            st.push(ch);
        }
    }
    return false;
}

int main(){
    std::string str="((a+b))";
    std::cout<<((checkRedundancy(str))?"YES":"NO")<<std::endl;

    str="(a+(B)/c)";
    std::cout<<((checkRedundancy(str))?"YES":"NO")<<std::endl;

    str="(a+b*(c-d))";
    std::cout<<((checkRedundancy(str))?"YES":"NO")<<std::endl;

    return 0;
}