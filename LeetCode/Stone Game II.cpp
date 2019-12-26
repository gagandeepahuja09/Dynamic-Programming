class Solution {
public:
    int dp[101][202];
    int f(vector<int>sums, int i, int m) {
        if(i >= sums.size())
            return 0;
        if(dp[i][m] != -1)
            return dp[i][m]; 
        int mn = INT_MAX;
        for(int x = 1; x <= 2 * m; x++) {
            mn = min(mn, f(sums, i + x, max(m, x)));
        }
        return dp[i][m] = sums[i] - mn;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof dp);
        vector<int> sums(n, 0);
        sums[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sums[i] = sums[i + 1] + piles[i];
        }
        return f(sums, 0, 1);     
    }
};
