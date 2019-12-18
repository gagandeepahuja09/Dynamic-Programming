class Solution {
public:
    long MOD;
    long dp[51][51][51];
    long f(int i, int j, int m, int n, int N) {
        if(N < 0)
            return 0;
        if(i >= m || j >= n || i < 0 || j < 0)
            return 1;
        if(dp[i][j][N] != -1)
            return dp[i][j][N];
        long ans = (f(i + 1, j, m, n, N - 1) % MOD + f(i, j + 1, m, n, N - 1) % MOD) % MOD 
            + (f(i - 1, j, m, n, N - 1) % MOD + f(i, j - 1, m, n, N - 1) % MOD) % MOD;
        return dp[i][j][N] = ans % MOD;
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        MOD = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        return (int)f(i, j, m, n, N);
    }
};
