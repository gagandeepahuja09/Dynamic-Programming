#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[41][41];

int f(string s, int i, int j) {
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;    
    if(s[i] == s[j])
        ans = f(s, i + 1, j - 1);
    else    
        ans = min(f(s, i + 1, j), f(s, i, j - 1)) + 1;
    return dp[i][j] = ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        string s;
        cin >> s;
        cout << f(s, 0, s.size() - 1) << endl;
    }
	return 0;
}
