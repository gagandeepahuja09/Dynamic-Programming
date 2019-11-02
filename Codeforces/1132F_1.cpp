#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int dp[501][501];

int minCost(int i, int j) {
    if(i > j)
        return 0;
    if(i == j)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    int res = minCost(i + 1, j) + 1;
    for(int k = i + 1; k <= j; k++) {
        if(s[i] == s[k]) {
            res = min(res, minCost(i + 1, k - 1) + minCost(k, j));
        }
    }
    return dp[i][j] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    cout << minCost(0, n - 1);
	return 0;
}
