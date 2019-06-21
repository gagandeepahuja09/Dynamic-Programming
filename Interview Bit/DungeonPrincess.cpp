int minHealth(vector<vector<int>>& A, int i, int j, vector<vector<int>>& dp) {
    if(i >= A.size() || j >= A[0].size())
        return 100000000;
    if(i == A.size() - 1 && j == A[0].size() - 1) {
        if(A[i][j] >= 1) {
            return 1;
        }
        else return 1 - A[i][j];
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int option1 = max(-A[i][j] + minHealth(A, i + 1, j, dp), 1);
    int option2 = max(-A[i][j] + minHealth(A, i, j + 1, dp), 1);
    return dp[i][j] = min(option1, option2);
}

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(A[0].size() + 1, -1));
    return minHealth(A, 0, 0, dp);
}

