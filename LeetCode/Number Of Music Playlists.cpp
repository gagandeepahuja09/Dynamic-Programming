class Solution {
public:
    const long MOD = 1e9 + 7;
    int dp[101][101];
    long f(int N, int L, int K) {
        if(N == 0 && L == 0)
            return 1;
        if(N == 0 || L == 0)
            return 0;
        if(dp[N][L] != -1)
            return dp[N][L];
        long op1 = (f(N - 1, L - 1, K) * (N)) % MOD;
        long op2 = (f(N, L - 1, K) * max(0, N - K)) % MOD;
        return dp[N][L] = (op1 + op2) % MOD;
    }
    
    int numMusicPlaylists(int N, int L, int K) {
        memset(dp, -1, sizeof dp);
        return (int)f(N, L, K);
    }
};
