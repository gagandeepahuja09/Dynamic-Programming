int pal[501][501];
int dp[501][501];

int minCuts(string A, int l, int r) {
    if(l == r || pal[l][r])
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MAX;    
    for(int i = l; i < r; i++) {
        ans = min(ans, 1 + minCuts(A, l, i) + minCuts(A, i + 1, r));
    }
    return dp[l][r] = ans;
}

int Solution::minCut(string A) {
    int n = A.size();
    memset(pal, 0, sizeof pal);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        pal[i][i] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            if(A[i] == A[j] && (i - j < 2 || pal[j + 1][i - 1]))
                pal[j][i] = 1;
        }
    }
    return minCuts(A, 0, A.size() - 1);
}

