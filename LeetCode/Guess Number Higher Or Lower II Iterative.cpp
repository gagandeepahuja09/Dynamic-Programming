class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for(int len = 1; len < n; len++) {
            for(int i = 0; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], max(k - 1 >= i ? dp[i][k - 1] : 0, 
                                                k + 1 <= j ? dp[k + 1][j] : 0) + k);
                }
            }
        }
        return dp[1][n];
    }
};
