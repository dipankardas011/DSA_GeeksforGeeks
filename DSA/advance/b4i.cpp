// C++ program to Queries on substring palindrome
// formation.
#include <bits/stdc++.h>
using namespace std;

// Query type 1: update string position i with
// character x.
void qType1(int l, int x, char str[])
{
	str[l - 1] = x;
}

// Print "Yes" if range [L..R] can form palindrome,
// else print "No".
void qType2(int l, int r, char str[])
{
	int freq[27] = { 0 };

	// Find the frequency of each character in
	// S[L...R].
	for (int i = l - 1; i <= r - 1; i++)
		freq[str[i] - 'a']++;

	// Checking if more than one character have
	// frequency greater than 1.
	int count = 0;
	for (int j = 0; j < 26; j++)
		if (freq[j] % 2)
			count++;

	(count <= 1) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

// Driven Program
int main()
{
	char str[] = "geeksforgeeks";
	int n = strlen(str);

	qType1(4, 'g', str);
	qType2(1, 4, str);
	qType2(2, 3, str);
	qType1(10, 't', str);
	qType2(10, 11, str);

	return 0;
}
