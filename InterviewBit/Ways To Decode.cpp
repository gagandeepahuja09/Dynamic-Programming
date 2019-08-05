int f(string s, int i, vector<int>& dp) {
    if(i >= s.size())
        return 1;
    if(dp[i] != -1)
        return dp[i];
    int option1 = 0, option2 = 0;
    if(s[i] != '0')
        option1 = f(s, i + 1, dp);
    if(s.size() - i >= 2) {
        string curr = s.substr(i, 2);
        if(curr >= "10" && curr <= "26")
            option2 = f(s, i + 2, dp);
    }
    return dp[i] = option1 + option2;
}

int Solution::numDecodings(string A) {
    vector<int> dp(A.size() + 1, -1);
    return f(A, 0, dp);
}

