int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), mx = INT_MIN;
    vector<int> prev(m + 1, 0), dp(m + 1, 0);
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            dp[j] = A[i][j] + prev[j] + dp[j + 1] - prev[j + 1];
            // dp[i][j] = A[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            // mx = max(mx, dp[i][j]);
            mx = max(mx, dp[j]);
        }
        prev = dp;
    }
    return mx;
}

