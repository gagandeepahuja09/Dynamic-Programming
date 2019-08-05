int maxSum(vector<vector<int>>& A, int start, vector<int>& dp) {
    if(start >= A[0].size())
        return 0;
    if(dp[start] != -1)
        return dp[start];
    int option1 = A[0][start] + maxSum(A, start + 2, dp);
    int option2 = A[1][start] + maxSum(A, start + 2, dp);
    int option3 = maxSum(A, start + 1, dp);
    return dp[start] = max(option1, max(option2, option3));
}

int Solution::adjacent(vector<vector<int> > &A) {
    vector<int> dp(A[0].size(), -1);
    return maxSum(A, 0, dp);
}

