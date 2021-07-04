/*Length of Longest sub-string that can be removed

Given a binary string (consists of only 0 and 1). If there is “100” as a sub-string in the string, then we can delete this sub-string. The task is to find the length of longest sub-string which can be make removed?
Examples: 
 

Input  : str = "1011100000100"
Output : 6
// Sub-strings present in str that can be make removed 
// 101{110000}0{100}. First sub-string 110000-->100-->null,
// length is = 6. Second sub-string 100-->null, length is = 3

Input  : str = "111011"
Output : 0
// There is no sub-string which can be make null

Take a vector arr of pair type. Each element in arr stores two values character and it’s respective index in string.
Store pair(‘@’,-1) as a base in arr. Take variable maxlen = 0 which stores the final result.
Now one by one iterate for all characters in string, make pair of characters and it’s respective index and store it in arr. In parallel also check the condition if after inserting i’th character last three elements of ‘arr’ are making sub-string “100”.
If sub-string exist then delete it from ‘arr’. Repeat this loop by number of times till you are getting sub-string “100” in arr and make it null by deleting continuously.
The difference of indexs of i’th character and index of last element currently present in arr after deletion gives the length of sub-string that can be make null by continuous deletion of sub-string “100”, update maxlen.*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestNull(string str){
    vector<pair<char, int>> arr;
    // store {'@', -1} in arr, here this value will work as base index
    arr.push_back({'@', -1});
    int maxlen=0;
    for(int i=0;i<str.length();i++)
    {
        arr.push_back({str.at(i),i});

        while(arr.size()>=3 && 
            arr[arr.size()-3].first=='1' && 
            arr[arr.size()-2].first=='0' &&
            arr[arr.size()-1].first=='0')
        {
            arr.pop_back();
            arr.pop_back();
            arr.pop_back();
        }// index of current last element in arr[]
        int temp=arr.back().second;
        // This is important, here 'i' is the index of
        // current character inserted into arr[]
        // and 'tmp' is the index of last element in arr[]
        // after continuous deletion of sub-string
        // "100" from arr[] till we make it null, difference
        // of these to 'i-tmp' gives the length of current
        // sub-string that can be make null by continuous
        // deletion of sub-string "100"
        maxlen=max(maxlen,i-temp);
    }
    return maxlen;
}

int main(){
    cout<<longestNull("1011100000100")<<endl;
    return 0;
}