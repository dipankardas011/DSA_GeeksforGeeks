/*Check for Palindrome after every character replacement Query

Given a string str and Q queries. Each query contains a pair of integers (i1, i2) and a character ‘ch’. We need to replace characters at indexes i1 and i2 with new character ‘ch’ and then tell if string str is palindrome or not. (0 <= i1, i2 < string_length)

Examples:

Input : str = "geeks"  Q = 2
        query 1: i1 = 3 ,i2 = 0, ch = 'e'
        query 2: i1 = 0 ,i2 = 2 , ch = 's'
Output : query 1: "NO"
         query 2: "YES"
Explanation :
        In query 1 : i1 = 3 , i2 = 0 ch = 'e'
                    After replacing char at index i1, i2
                    str[3] = 'e', str[0] = 'e'
                    string become "eeees" which is not
                    palindrome so output "NO"
        In query 2 : i1 = 0 i2 = 2  ch = 's'
                    After replacing char at index i1 , i2
                     str[0] = 's', str[2] = 's'
                    string become "seses" which is
                    palindrome so output "YES"

Input : str = "jasonamat"  Q = 3
        query 1: i1 = 3, i2 = 8 ch = 'j'
        query 2: i1 = 2, i2 = 6 ch = 'n'
        query 3: i1 = 3, i2 = 7 ch = 'a'
Output :
       query 1: "NO"
       query 2: "NO"
       query 3: "YES"*/
#include <bits/stdc++.h>
using namespace std;

void palindrome (string x)
{
    int left=0;
    int right=x.length()-1;
	while (left < right) {
		if (x[left] == x[right]){
			left++;
			right--;
		}
		else
		{	cout<<"not a palindrome"<<endl; 
			return;
		}
	}
	cout<<"it is palindrome"<<endl;
}

void query(string s, int i1, int i2, char r)
{
    string temp;
    temp.append(s);
    temp[i1] = temp[i2] = r;
    palindrome(temp);
}


int main()
{
    string str="mkdem";
    query(str, 1, 3, 'a');

    string str1="jasonamat";
    query(str, 3, 7, 'a');
    return 0;
}