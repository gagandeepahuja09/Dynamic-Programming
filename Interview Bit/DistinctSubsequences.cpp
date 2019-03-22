int numOfSub(string A, string B, vector<vector<int>>& dp) {
    int ans = 0;
    if(B.length() == 0)
        return 1;
    if(A.length() == 0)
        return 0;
    if(dp[A.length()][B.length()] != -1)
        return dp[A.length()][B.length()];
    if(A[0] == B[0]) {
        ans = ans + numOfSub(A.substr(1), B.substr(1), dp); 
    }
    ans = ans + numOfSub(A.substr(1), B, dp);
    return dp[A.length()][B.length()] = ans;
}

int Solution::numDistinct(string A, string B) {
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, -1));
    return numOfSub(A, B, dp);    
}

