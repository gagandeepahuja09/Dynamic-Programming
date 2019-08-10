/*

Given a string ‘S’ consisting of open and closed brackets, the task is find the number of ways in which each character of ‘S’ can be assigned to either a string ‘X’ or string ‘Y’ (both initially empty) such that the strings formed by X and Y are balanced. It can be assumed that ‘S’ is itself balanced.

Examples:

Input: S = "(())"
Output: 6
Valid assignments are :
X = "(())" and Y = "" [All characters in X]
X = "" and Y = "(())" [Nothing in X]
X = "()" and Y = "()" [1st and 3rd characters in X]
X = "()" and Y = "()" [2nd and 3rd characters in X]
X = "()" and Y = "()" [2nd and 4th characters in X]
X = "()" and Y = "()" [1st and 4th characters in X]

*/

#include<bits/stdc++.h>
using namespace std;

int f(string s, int i, int cx, int cy) {
	if(i == s.size())
		return (cx == 0 && cy == 0);
	int ans = 0;
	if(s[i] == '(') {
		ans = f(s, i + 1, cx + 1, cy) + f(s, i + 1, cx, cy + 1);	
	}
	else {
		if(cx)
			ans = f(s, i + 1, cx - 1, cy);
		if(cy)
			ans += f(s, i + 1, cx, cy - 1);
			 
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << f(s, 0, 0, 0) << endl;
	}
}
