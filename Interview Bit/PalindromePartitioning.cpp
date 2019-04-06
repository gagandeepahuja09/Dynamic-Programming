int minCutUtil(string A, int l, int r, vector<vector<int>>& dp,
vector<vector<int>>& pal) {
    if(l == r || pal[l][r])
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MAX;    
    for(int i = l; i < r; i++) {
        ans = min(ans, 1 + minCutUtil(A, l, i, dp, pal) + 
        minCutUtil(A, i + 1, r, dp, pal));
    }
    return dp[l][r] = ans;
}

int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int l = 0, r = A.size() - 1;
    vector<vector<int>> pal(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < n; i++) {
        pal[i][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            if(A[i] == A[j] && (i - j < 2 || pal[j + 1][i - 1]))
                pal[j][i] = 1;
        }
    }
    return minCutUtil(A, 0, A.size() - 1, dp, pal);
}

