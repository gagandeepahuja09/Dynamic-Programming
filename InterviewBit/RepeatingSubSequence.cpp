int Solution::anytwo(string A) {
    int n = A.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[i - 1] == A[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return (dp[n][n] > 1);
}

