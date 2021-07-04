/*Count number of substrings with exactly k distinct characters

Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters. 
Examples: 
 

Input: abc, k = 2
Output: 2
Possible substrings are {"ab", "bc"}

Input: aba, k = 2
Output: 3
Possible substrings are {"ab", "ba", "aba"}

Input: aa, k = 1
Output: 3
Possible substrings are {"a", "a", "aa"}*/

#include<bits/stdc++.h>
using namespace std;

// Function to count number of substrings
// with exactly k unique characters
int countkDist(string str, int k)
{
	int n = str.length();

	// Initialize result
	int res = 0;

	int cnt[26];

	// Consider all substrings beginning with
	// str[i]
	for (int i = 0; i < n; i++)
	{
		int dist_count = 0;

		memset(cnt, 0, sizeof(cnt));

		// Consider all substrings between str[i..j]
		for (int j=i; j<n; j++)
		{

			if (cnt[str[j] - 'a'] == 0)
				dist_count++;

			cnt[str[j] - 'a']++;

			if (dist_count == k)
				res++;
			if(dist_count > k) break;
		}
	}

	return res;
}


int main()
{
	string str = "abcbaa";
	int k = 3;
	cout << "Total substrings with exactly "
		<< k <<" distinct characters :"
		<< countkDist(str, k) << endl;
	return 0;
}
