class Solution {
public:
    int dp[300][11];
    int f(int i, int days, vector<int>& jd) {
        if(days < 0)
            return 1e8;
        if(i == jd.size())
            return (days == 0) ? 0 : 1e8;
        if(dp[i][days] != -1)
            return dp[i][days];
        int currMax = jd[i], ans = 1e8;
        for(int j = i; j < jd.size(); j++) {
            currMax = max(currMax, jd[j]);
            ans = min(ans, currMax + f(j + 1, days - 1, jd));
        }
        return dp[i][days] = ans;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp, -1, sizeof dp);
        int ans = f(0, d, jd);
        return ans >= 1e8 ? -1 : ans;
    }
};
