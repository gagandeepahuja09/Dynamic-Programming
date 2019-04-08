int minDist(string A, string B, vector<vector<int>>& dp) {
    if(!B.size())
        return A.size();
    if(!A.size())
        return B.size();
    if(dp[A.size()][B.size()] != -1)
        return dp[A.size()][B.size()];
    int option1 = minDist(A.substr(0, A.size() - 1), 
    B.substr(0, B.size() - 1), dp);
    int option2 = minDist(A.substr(0, A.size() - 1), B, dp);
    int option3 = minDist(A, B.substr(0, B.size() - 1), dp);
    int ans;
    if(A.back() == B.back())
        ans = option1;
    else 
    ans = 1 + min(option1, min(option2, option3));
    return dp[A.size()][B.size()] = ans;
}

int Solution::minDistance(string A, string B) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    return minDist(A, B, dp);
}

