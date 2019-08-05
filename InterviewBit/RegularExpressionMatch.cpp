int Solution::isMatch(const string A, const string B) {
    int m = A.size(), n = B.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = 1;
            else if(i == 0 && B[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1];
            }
            else if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(A[i - 1] == B[j - 1] || B[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(B[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[m][n];
}

