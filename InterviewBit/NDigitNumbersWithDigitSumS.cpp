#define MOD 1000000007

int f(int N, int S, vector<vector<int>>& dp) {
    if(N == 0)
        return (S == 0);
    if(dp[N][S] != -1)
        return dp[N][S];
    int ret = 0;
    for(int i = 0; i <= 9 && i <= S; i++) {
        ret = (ret % MOD + f(N - 1, S - i, dp) % MOD) % MOD;
    }
    return dp[N][S] = ret % MOD;
}

int Solution::solve(int A, int B) {
    int ret = 0;
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, - 1));
    for(int i = 1; i <= 9 && i <= B; i++) {
        ret = (ret % MOD + f(A - 1, B - i, dp) % MOD) % MOD;
    }
    return ret % MOD;
}

