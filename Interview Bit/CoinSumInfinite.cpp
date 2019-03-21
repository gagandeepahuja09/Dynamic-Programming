#define MOD 1000007

/*int coinChange(vector<int> &A, int n, int m, vector<vector<int>>& dp) {
    if(m < 0)
        return 0;
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(dp[m][n] != -1)
        return dp[m][n];
    int ans = 0;    
    ans = (coinChange(A, n - A[m], m, dp)%MOD + coinChange(A, n, m-1, dp)%MOD)%MOD;
    ans = ans%MOD;
    return dp[m][n] = ans; 
}*/
int Solution::coinchange2(vector<int> &A, int B) {
    int m = A.size();
    // vector<vector<int>> dp(m, vector<int>(B+1, -1));
    vector<int> dp(B+1, 0);
    // return coinChange(A, B, m - 1, dp)%MOD;
    dp[0] = 1;
    for(int i=0; i<A.size(); i++) {
        for(int j = A[i]; j <= B; j++) {
            dp[j] = dp[j] + dp[j - A[i]];
            dp[j] %= MOD;
        }
    }
    return dp[B];
}

