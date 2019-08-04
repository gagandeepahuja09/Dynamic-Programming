int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), mx = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            dp[i][j] = A[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}

