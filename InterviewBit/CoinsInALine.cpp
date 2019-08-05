int f(vector<int>& A, int i, int j, bool me, vector<vector<int>>& dp) {
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == j)
        return 0;
    if(me) {    
        int option1 = f(A, i + 1, j, 0, dp) + A[i];
        int option2 = f(A, i, j - 1, 0, dp) + A[j];
        return dp[i][j] = max(option1, option2);
    }
    else {
        int option1 = f(A, i + 1, j, 1, dp);
        int option2 = f(A, i, j - 1, 1, dp);
        return dp[i][j] = min(option1, option2);
    }
}

int Solution::maxcoin(vector<int> &A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    return f(A, 0, A.size() - 1, 1, dp);
}

