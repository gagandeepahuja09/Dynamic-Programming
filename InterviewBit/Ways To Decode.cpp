int dp[100001];

int f(string s, int i) {
    if(i == s.size())
        return 1;
    if(dp[i] != -1)
        return dp[i];
    int ans = 0;
    if(s[i] >= '1' && s[i] <= '9')
        ans += f(s, i + 1);
    if(i < s.size() - 1) {    
        string sub = s.substr(i, 2);
        if(sub >= "10" && sub <= "26") {
            ans += f(s, i + 2);
        }
    }
    return ans;
}

int Solution::numDecodings(string A) {
    memset(dp, -1, sizeof dp);
    return f(A, 0);
}

