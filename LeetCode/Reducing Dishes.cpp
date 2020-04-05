class Solution {
public:
    int dp[501][501];
    int f(vector<int>& st, int i, int t) {
        if(i == st.size())
            return 0;
        if(dp[i][t] != -1)
            return dp[i][t];
        int ans = -1e7;
        ans = max(st[i] * t + f(st, i + 1, t + 1), f(st, i + 1, t));
        return dp[i][t] = ans;
    }
    
    int maxSatisfaction(vector<int>& st) {
        memset(dp, -1, sizeof dp);
        sort(st.begin(), st.end());
        return f(st, 0, 1);
    }
};
