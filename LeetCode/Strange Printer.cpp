class Solution {
public:
    int dp[101][101];
    int minTurns(string s, int l, int r) {
        if(l > r)
            return 0;
        if(dp[l][r])    
            return dp[l][r];
        int i = l, j = r;
        while(i <= r && s[i] == s[l]) i++;
        while(j >= i && s[j] == s[l]) j--;
        dp[l][r] = 1 + minTurns(s, i, j);
        for(int k = i; k <= j; k++) {
            if(s[k] == s[l]) {
                int pos = k;
                while(k <= j && s[k] == s[l])
                    k++;
                dp[l][r] = min(dp[l][r], 1 + minTurns(s, i, pos - 1) + minTurns(s, k, r));
                
            }
        }
        return dp[l][r];
    }
    
    int strangePrinter(string s) {
        memset(dp, 0, sizeof dp);
        return minTurns(s, 0, s.size() - 1);
    }
};
