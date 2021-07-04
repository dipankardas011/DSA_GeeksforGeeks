/*Converting Decimal Number lying between 1 to 3999 to Roman Numerals
Difficulty Level : Medium
Last Updated : 23 May, 2021
Given a number, find its corresponding Roman numeral. 
Examples: 

Input : 9
Output : IX

Input : 40
Output : XL

Input :  1904
Output : MCMIV
Following is the list of Roman symbols which include subtractive cases also:

SYMBOL       VALUE
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900 
M             1000


Explanation: 

Explanation:

Step 1

Initially number = 3549
Since 3549 >= 1000 ; largest base value will be 1000 initially.
Divide 3549/1000. Quotient = 3, Remainder =549. The corresponding symbol M will be repeated thrice.
Step 2

Now, number = 549
1000 > 549 >= 500 ; largest base value will be 500.
Divide 549/500. Quotient = 1, Remainder =49. The corresponding symbol D will be repeated once.
Step 3

Now, number = 49
50 > 49 >= 40 ; largest base value is 40.
Divide 49/40. Quotient = 1, Remainder = 9. The corresponding symbol XL will be repeated once.
Step 4

Now, number = 9
10> 9 >= 9 ; largest base value is 9.
Divide 9/9. Quotient = 1, Remainder = 0. The corresponding symbol IX will be repeated once.
Step 5



Finally number becomes 0, algorithm stops here.
Output obtained MMMDXLIX.*/
#include <iostream>
#include <vector>
using namespace std;

void convertToRoman(int num)
{
    vector<std::pair<int, std::string>> val;
    val.push_back({1,"I"});//0
    val.push_back({4,"IV"});
    val.push_back({5,"V"});
    val.push_back({9,"XI"});
    val.push_back({10,"X"});
    val.push_back({40,"XL"});
    val.push_back({50,"L"});
    val.push_back({90,"XC"});
    val.push_back({100,"C"});
    val.push_back({400,"CD"});
    val.push_back({500,"D"});//10
    val.push_back({900,"CM"});
    val.push_back({1000,"M"});//12

    int size=val.size()-1;
    while(num>0)
    {
        int d=num/val.at(size).first;
        num %= val.at(size).first;
        while(d--)
            cout<<val.at(size).second;
        size--;
    }
    cout<<endl;

}

int main(void){
    int n=3549;
    convertToRoman(n);
    return 0;
}