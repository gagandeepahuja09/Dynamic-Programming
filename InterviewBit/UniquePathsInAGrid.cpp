int paths(vector<vector<int>>& A, int r, int c, int n, int m, 
vector<vector<int>>& dp) {
    if(r == n - 1 && c == m - 1 && A[r][c] == 0)
        return 1;
    if(r >= n || c >= m || A[r][c] == 1)
        return 0;
    if(dp[r][c] != -1)
        return dp[r][c];
    int option1 = paths(A, r + 1, c, n, m, dp);
    int option2 = paths(A, r, c + 1, n, m, dp);
    int ans;
    ans = option1 + option2;
    return dp[r][c] = ans;    
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return paths(A, 0, 0, n, m, dp);
}

