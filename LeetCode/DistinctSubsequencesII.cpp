class Solution {
public:
    int distinctSubseqII(string S) {
        int pos[26] = {}, dp[S.size() + 1] = { 1 }, mod = 1e9 + 7;
        for(int i = 1; i <= S.size(); i++) {
            auto idx = S[i - 1] - 'a';
            if(pos[idx])
                dp[i] = mod - dp[pos[idx] - 1];
            dp[i] = (dp[i] + dp[i - 1] * 2 % mod) % mod;
            pos[S[i - 1] - 'a'] = i;
        }
        return dp[S.size()] - 1;
    }
};
