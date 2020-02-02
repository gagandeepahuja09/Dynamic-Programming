class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        const int MOD = 1e9 + 7;
        // substring(0 ... i) with j as end
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                if(s[i - 1] == 'D') {
                    // Use larger digits
                    for(int k = j; k <= i - 1; k++) {
                        dp[i][j] = dp[i][j] % MOD + dp[i - 1][k] % MOD;
                    }
                }
                else {
                    for(int k = 0; k <= j - 1; k++) {
                        dp[i][j] = dp[i][j] % MOD + dp[i - 1][k] % MOD;
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i <= n; i++)
            ret = ret % MOD + dp[n][i] % MOD;
        return ret % MOD;
    }
};
