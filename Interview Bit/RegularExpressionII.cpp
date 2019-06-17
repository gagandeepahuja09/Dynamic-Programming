/*bool ismatch(const string s, int i, const string p, int j, vector<vector<int>>& dp) {
    if(j >= p.size())
        return i >= s.size();
    if(i >= s.size()) {
        if(j < p.size() - 1 && p[j + 1] == '*')
                return ismatch(s, i, p, j + 2, dp);
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(j < p.size() - 1 && p[j + 1] == '*') {
        // Skip this character from pattern
        bool option1 = ismatch(s, i, p, j + 2, dp);
        // Skip a sequence of characters of string if they match curr char
        // of pattern
        bool option2 = ((s[i] == p[j] || p[j] == '.') && 
                        ismatch(s, i + 1, p, j, dp));
        return dp[i][j] = option1 || option2;
    }
    if(s[i] == p[j] || p[j] == '.')
        return dp[i][j] = ismatch(s, i + 1, p, j + 1, dp);
    return 0;    
}*/

int Solution::isMatch(const string s, const string p) {
    // vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    // return ismatch(A, 0, B, 0, dp);     
    int m = s.size(), n = p.size();
        vector<bool> pre(n + 1, false), cur(n + 1, false);
        cur[0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2] || (i && pre[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    cur[j] = i && pre[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
            fill(pre.begin(), pre.end(), false);
			swap(pre, cur);
        }
        return pre[n];
}

