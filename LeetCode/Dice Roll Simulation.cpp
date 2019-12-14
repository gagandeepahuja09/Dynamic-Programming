class Solution {
public:
    int dp[5001][7][16];
    long MOD;
    long f(int n, vector<int>& rollMax, int curr, int len) {
        if(curr < 6 && len > rollMax[curr])
            return 0;
        if(n == 0)
            return 1;
        if(dp[n][curr][len] != -1)
            return dp[n][curr][len];
        long ans = 0;
        for(int i = 0; i < 6; i++) {
            if(curr == i) {
                ans += f(n - 1, rollMax, curr, len + 1);
            }
            else {
                ans += f(n - 1, rollMax, i, 1);
            }
        }
        return dp[n][curr][len] = ans % MOD;
    }
        
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof dp);
        MOD = 1e9 + 7;
        return (int)f(n, rollMax, 6, 0);
    }
};
