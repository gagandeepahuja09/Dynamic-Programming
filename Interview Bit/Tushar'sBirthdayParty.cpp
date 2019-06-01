int Solution::solve(const vector<int> &A, const vector<int> &cap, const vector<int> &cost) {
    int mx = INT_MIN;
    for(int i = 0; i < A.size(); i++)
        mx = max(mx, A[i]);
    int n = cost.size();   
    vector<vector<int>> dp(n + 1, vector<int>(mx + 1));    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= mx; j++) {
            if(j == 0) {
                dp[i][j] = 0;
            }
            else if(i == 0) {
                dp[i][j] = 1e6;
            }
            else {
                if(cap[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j], cost[i - 1] + dp[i][j - cap[i - 1]]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < A.size(); i++) {
        ret += dp[n][A[i]];
    }
    return ret;
}

