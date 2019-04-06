int minPath(vector<vector<int>>& A, int r1, int r2, int c1, int c2, 
vector<vector<int>>& dp) {
    if(r1 == r2 && c1 == c2) {
        return A[r1][c1];
    }
    if(r1 < 0 || r1 > r2 || c1 < 0 || c1 > c2) {
        return INT_MAX;
    }
    if(dp[r1][c1] != -1)
        return dp[r1][c1];
    int option1 = minPath(A, r1 + 1, r2, c1, c2, dp);
    int option2 = minPath(A, r1, r2, c1 + 1, c2, dp);
    if(option1 == INT_MAX)
        dp[r1][c1] = A[r1][c1] + option2;
    else if(option2 == INT_MAX)
        dp[r1][c1] = A[r1][c1] + option1;    
    else
        dp[r1][c1] = A[r1][c1] + min(option1, option2);
    return dp[r1][c1];    
}

int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return minPath(A, 0, m - 1, 0, n - 1, dp);
}

