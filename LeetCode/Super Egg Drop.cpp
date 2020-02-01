class Solution {
public:
    int dp[101][10001];
    int f(int e, int h) {
        if(e == 1)  return h;
        if(h == 0 || h == 1)  return h;
        if(dp[e][h] != -1)
            return dp[e][h];
        int ans = INT_MAX;
        for(int i = 1; i <= h; i++) {
            ans = min(ans, 1 + max(f(e, h - i), f(e - 1, i - 1)));
        }
        return dp[e][h] = ans;
    }
    
    int superEggDrop(int e, int h) {
        memset(dp, -1, sizeof dp);
        return f(e, h);
    }
};
