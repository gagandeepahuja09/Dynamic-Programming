#define MOD 1000007

int coinWays(vector<int> &A, int m, int i) {
    if(m == 0)
        return 1;
    if(i == A.size() || m < 0)
        return 0;
    int ans = coinWays(A, m, i + 1) + coinWays(A, m - A[i], i);
    return ans;
}

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    vector<int> dp(B + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = A[i]; j <= B; j++) {
            dp[j] = (dp[j] % MOD + dp[j - A[i]] % MOD) % MOD;
        }
    }
    return dp[B];
}

