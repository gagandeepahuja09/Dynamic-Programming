class Solution {
public:
    long MOD;
    long dp[20001][5];
    // a 0 1, e 1 0 or 2, i 2 no 2, o 3 2 or 4, u 4 0
    long f(int n, int i) {
        if(n == 0)
            return 1;
        long ans = 0;
        if(dp[n][i] != -1)
            return dp[n][i];
        if(i == 0)
            ans = f(n - 1, 1);
        if(i == 1)
            ans = f(n - 1, 0) + f(n - 1, 2);
        if(i == 2)
            ans = f(n - 1, 0) + f(n - 1, 1) + f(n - 1, 3) + f(n - 1, 4);
        if(i == 3)
            ans = f(n - 1, 2) + f(n - 1, 4);
        if(i == 4)
            ans = f(n - 1, 0);
        ans %= MOD;
        return dp[n][i] = ans;
    }
    
    int countVowelPermutation(int n) {
        long ans = 0;
        MOD = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < 5; i++) {
            ans += f(n - 1, i);
            ans %= MOD;
        }
        return (int)ans;
    }
};
