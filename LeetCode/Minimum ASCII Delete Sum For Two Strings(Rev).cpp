class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m + 1);
        vector<int> prev(m + 1, 0);
        for(int j = 1; j <= m; j++)
            dp[j] = dp[j - 1] + t[j - 1];
        prev = dp;
        
        for(int i = 1; i <= n; i++) {
            dp[0] = prev[0] + s[i - 1];
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1])
                    dp[j] = prev[j - 1];
                else
                    dp[j] = min(s[i - 1] + prev[j], t[j - 1] + dp[j - 1]);
            }
            prev = dp;
        }
        return dp[m];
    }
};
