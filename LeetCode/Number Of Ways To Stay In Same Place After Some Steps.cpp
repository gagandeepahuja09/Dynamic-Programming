#define ll long long int

class Solution {
public:
        
    int dp[501][501];
    ll MOD = 1e9 + 7;
    ll f(int steps, int i, int len) {
        if(i >= len || i < 0)
            return 0;
        if(steps == 0)
            return (i == 0);
        if(dp[steps][i] != -1)
            return dp[steps][i];
        ll op1 = f(steps - 1, i + 1, len) % MOD;
        ll op2 = f(steps - 1, i - 1, len) % MOD;
        ll op3 = f(steps - 1, i, len) % MOD;
        return dp[steps][i] = (op1 + op2 + op3) % MOD;
    }
    
    int numWays(int steps, int len) {
        memset(dp, -1, sizeof dp);
        if(len > steps)
            len = steps;
        return (int)(f(steps, 0, len) % MOD);
        return 0;
    }
};
