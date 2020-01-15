class Solution {
public:
    map<pair<int, int>, int> dp;
    
    int dfs(vector<int>& rods, int i, int s1, int s2) {
        if(i == rods.size())
            return s1 == s2 ? s1 : -1;
        pair<int, int> key = { i, s1 - s2 };
        if(dp.count(key))
            return dp[key] == -1 ? -1 : dp[key] + max(s1, s2);
        int op1 = dfs(rods, i + 1, s1, s2);
        int op2 = dfs(rods, i + 1, s1 + rods[i], s2);
        int op3 = dfs(rods, i + 1, s1, s2 + rods[i]);
        int ans = max(op1, max(op2, op3));
        dp[key] = (ans == -1) ? ans : ans - max(s1, s2);
        return ans;
    }
    
    int tallestBillboard(vector<int>& rods) {
        return dfs(rods, 0, 0, 0);        
    }
};
