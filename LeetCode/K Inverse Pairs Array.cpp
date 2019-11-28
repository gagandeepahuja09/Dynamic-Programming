class Solution {
public:
    int MOD = 1e9 + 7;
    /* int dp[1001][1001];
    int f(int n, int k) {
        if(n == 0)
            return 0;
        if(k == 0)
            return 1;
        if(dp[n][k] != -1)
            return dp[n][k];
        int ans = 0;
        for(int i = 0; i <= min(k, n - 1); i++)
            ans = (ans + f(n - 1, k - i)) % MOD;
        return dp[n][k] = ans;
    } */
    
    int kInversePairs(int n, int k) {
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for(int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if(j >= i)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
            }
        }
        return dp[n][k];
        // return f(n, k);
    }
};
