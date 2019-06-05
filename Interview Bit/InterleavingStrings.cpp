int interleave(string A, string B, string C, vector<vector<int>>& dp) {
    if(!C.size() && !A.size() && !B.size())
        return 1;
    if(!C.size())
        return 0;
    if(dp[A.size()][B.size()] != -1)
        return dp[A.size()][B.size()];
    int ans = 0;
    if(A[0] == C[0])
        ans = ans || interleave(A.substr(1), B, C.substr(1), dp);
    if(B[0] == C[0])
        ans = ans || interleave(A, B.substr(1), C.substr(1), dp);
    return dp[A.size()][B.size()] = ans;    
}

int Solution::isInterleave(string A, string B, string C) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    return interleave(A, B, C, dp);
}


