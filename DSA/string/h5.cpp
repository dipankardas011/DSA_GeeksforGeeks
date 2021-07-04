/*Find index of closing bracket for a given opening bracket in an expression
Difficulty Level : Basic
Last Updated : 10 Jan, 2019
Given a string with brackets. If the start index of the open bracket is given, find the index of the closing bracket.

Examples:

Input : string = [ABC[23]][89]
        index = 0
Output : 8
The opening bracket at index 0 corresponds
to closing bracket at index 8.*/

#include <bits/stdc++.h>
using namespace std;

// Function to find index of closing bracket for given opening bracket.
void test(string expression, int index){
	int i;
	
	// If index given is invalid and is not an opening bracket.
	if(expression[index]!='['){
		cout << expression << ", " <<index << ": -1\n";
		return;
	}
	
	// Stack to store opening brackets.
	stack <int> st;
	
	// Traverse through string starting from given index.
	for(i = index; i < expression.length(); i++){
		
		// If current character is an opening bracket push it in stack.
		if(expression[i] == '[')
		st.push(expression[i]);
		
		// If current character is a closing bracket, pop from stack. If stack is empty, then this closing bracket is required bracket.
		else if(expression[i] == ']'){
			st.pop();
			if(st.empty()){
				cout << expression << ", " <<index << ": " << i << "\n";
				return;
			}
		}
	}
	
	// If no matching closing bracket is found.
	cout << expression << ", " <<index << ": -1\n";
}

int main() {
	test("[ABC[23]][89]", 0); // should be 8
	test("[ABC[23]][89]", 4); // should be 7
	test("[ABC[23]][89]", 9); // should be 12
	test("[ABC[23]][89]", 1); // No matching bracket
	return 0;
}
