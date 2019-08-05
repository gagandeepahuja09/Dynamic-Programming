int distSubs(string s, string t, int i, int j, int m, int n, vector<vector<int>>& dp) {
    if(j == n)
        return 1;
    if(i == m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == t[j]) {
        return dp[i][j] = distSubs(s, t, i + 1, j + 1, m, n, dp) + 
        distSubs(s, t, i + 1, j, m, n, dp);
    }
    return dp[i][j] = distSubs(s, t, i + 1, j, m, n, dp);
}

int Solution::numDistinct(string A, string B) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    return distSubs(A, B, 0, 0, A.size(), B.size(), dp);
}

