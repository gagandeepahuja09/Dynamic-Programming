int maxCoin(vector<int> &A, int start, int end, bool turn, vector<vector<int>>& dp) {
    if(start > end)
        return 0;
    int option1, option2;    
    if(dp[start][end] != -1)
        return dp[start][end];
    if(turn) {    
        option1 = A[start] + maxCoin(A, start + 1, end, false, dp);     
        option2 = A[end] + maxCoin(A, start, end - 1, false, dp);
        return dp[start][end] = max(option1, option2);
    }
    else {
        option1 = maxCoin(A, start + 1, end, true, dp);
        option2 = maxCoin(A, start, end - 1, true, dp);
        return dp[start][end] = min(option1, option2);
    }
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return maxCoin(A, 0, n-1, true, dp);
}

