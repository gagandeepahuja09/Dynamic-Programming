int interleavingString(string A, string B, string C, 
vector<vector<int>>& dp) {
    if(A.length() == 0 && B.length() == 0 && C.length() == 0)
        return 1;
    if(C.length() == 0)
        return 0;
    if(dp[A.length()][B.length()] != -1)
        return dp[A.length()][B.length()];
    int option1 = false, option2 = false;    
    if(A[0] == C[0])
        option1 = interleavingString(A.substr(1), B, C.substr(1), dp);
    if(B[0] == C[0])
        option2 = interleavingString(A, B.substr(1), C.substr(1), dp);
    return dp[A.length()][B.length()] = (option1 || option2);
}

int Solution::isInterleave(string A, string B, string C) {
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, -1));
    return interleavingString(A, B, C, dp);
}

