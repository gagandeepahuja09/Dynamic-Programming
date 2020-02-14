class Solution {
public:
    int dp[1 << 20];
    int dfs(int mask, int mx, int total) {
        if(total <= 0)
            return false;
        if(dp[mask] != -1)
            return dp[mask];
        for(int i = 0; i < mx; i++) {
            if((mask & (1 << i)) == 0) {
                if(!dfs(mask | (1 << i), mx, total - i - 1))
                    return dp[mask] = true;
            }
        }
        return dp[mask] = false;
    }
    
    bool canIWin(int mx, int total) {
        memset(dp, -1, sizeof dp);
        if(total == 0)
            return true;
        int maxSum = mx * (mx + 1) / 2;
        if(maxSum < total)
            return false;
        return dfs(0, mx, total);    
    }
};
