class Solution {
public:
    int dp[1001][1001];
    int minimax(int l, int h) {
        if(l >= h)
            return 0;
        if(dp[l][h] != -1)
            return dp[l][h];
        int minWorst = INT_MAX;
        for(int i = l; i <= h; i++) {
            int worsti = max(minimax(l, i - 1), minimax(i + 1, h)) + i;
            minWorst = min(minWorst, worsti);
        }
        return dp[l][h] = minWorst;
    }
    
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof dp);
        return minimax(0, n);
    }
};
