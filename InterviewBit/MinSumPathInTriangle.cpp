int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size(), m = A[n - 1].size();
    vector<int> dp(m);
    for(int i = 0; i < m; i++)
        dp[i] = A[n - 1][i];
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < A[i].size(); j++) {
                dp[j] = min(dp[j], dp[j + 1]) + A[i][j];
        }
    }
    return dp[0];
}

