/*
Gary has two string S and V. Now Gary wants to know the length shortest 
subsequence in S such that it is not a subsequence in V.
*/

#include<bits/stdc++.h>
using namespace std;

int func(string s,string t, vector<vector<int>>& dp) {
  	if(s.empty())
    	return 1000000;
  	if(t.empty())
    	return 1;
  	int n = s.length(), m = t.length();
  	if(dp[n][m] != -1)
    	return dp[n][m];
  	int option1 = func(s.substr(1), t, dp);
  	int i;
  	for(i=0; i<t.length(); i++)
      if(t[i] == s[0])
        break;
  	if(i == t.length())
  		return 1;
  	int option2 = 1 + func(s.substr(1), t.substr(i + 1), dp);
  	dp[n][m] = min(option1, option2);
  	return  min(option1, option2);
}

int solve(string s, string t) {
  	int n = s.length();
  	int m = t.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  	return func(s, t, dp);
}
