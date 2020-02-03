class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> cnt(26, -1);
        int n = s.size();
        vector<int> dp(n + 1, 1);
        const int MOD = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(cnt[s[i - 1] - 'a'] > 0)
                dp[i] = (dp[i] - dp[cnt[s[i - 1] - 'a'] - 1] + MOD) % MOD;
            cnt[s[i - 1] - 'a'] = i;
        }
        return (dp[n] - 1) % MOD;
    }
};
