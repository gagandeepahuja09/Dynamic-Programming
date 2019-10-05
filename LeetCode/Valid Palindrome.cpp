class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(s[i - 1] == rev[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return (n - dp[n][n] <= k);
    }
};
