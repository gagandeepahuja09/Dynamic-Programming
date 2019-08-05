// int dp[301][301][301];

/*int f(vector<vector<int>>& B, int i, int j, int k) {
    if(i < 0 || j < 0 || i >= B.size() || j >= B[0].size())
        return 0;
    if(k == 0)
        return B[i][j];
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int mx = B[i][j];
    mx = max(f(B, i - 1, j, k - 1), mx);
    mx = max(f(B, i + 1, j, k - 1), mx);
    mx = max(f(B, i, j - 1, k - 1), mx);
    mx = max(f(B, i, j + 1, k - 1), mx);
    return dp[i][j][k] = mx;
}*/

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    if(!A)
        return B;
    vector<vector<int>> ret = B;
    int n = B.size(), m = B[0].size();
    for(int k = 1; k <= A; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0)
                    ret[i][j] = max(ret[i][j], B[i - 1][j]);
                if(i < n - 1)
                    ret[i][j] = max(ret[i][j], B[i + 1][j]);
                if(j > 0)
                    ret[i][j] = max(ret[i][j], B[i][j - 1]);
                if(j < m - 1)
                    ret[i][j] = max(ret[i][j], B[i][j + 1]);    
            }
        }
        B = ret;
    }
    return ret;
}

