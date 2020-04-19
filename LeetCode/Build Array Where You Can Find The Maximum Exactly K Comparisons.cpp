#define ll long long int

class Solution {
public:
    int dp[51][101][51];
    ll MOD;
    int f(int n, int mx, int m, int k) {
        if(n == 0) {
            return k == 0;
        }
        if(k < 0)
            return 0;
        if(dp[n][mx][k] != -1)
            return dp[n][mx][k];
        ll ans = 0;
        for(int j = 1; j <= mx; j++) {
            ans = (ans + f(n - 1, mx, m, k)) % MOD;
        }
        for(int j = mx + 1; j <= m; j++) {
            ans = (ans + f(n - 1, j, m, k - 1)) % MOD;
        }
        return dp[n][mx][k] = (int)ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        ll ans = 0;
        if(m < k)
            return 0;
        MOD = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= m; i++)
            ans = (ans + f(n - 1, i, m, k - 1)) % MOD;
        return (int)ans;
    }
};
