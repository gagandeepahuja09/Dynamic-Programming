class Solution {
public:
    int dp[51][51][51];
    int f(vector<vector<int>>& g, int r1, int c1, int r2, int c2) {
        if(r1 >= g.size() || r2 >= g.size() || c1 >= g.size() || c2 >= g.size() || g[r1][c1] == -1 || g[r2][c2] == -1)
            return -1e5;
        if(r1 == g.size() - 1 && c1 == g.size() - 1)
            return g[r1][c1];
        if(r2 == g.size() - 1 && c2 == g.size() - 1)
            return g[r2][c2];
        if(dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        int cherries = 0;
        if(r1 == r2 && c1 == c2) {
            cherries = g[r1][c1];
        }
        else {
            cherries = g[r1][c1] + g[r2][c2];
        }
        int ans = f(g, r1 + 1, c1, r2 + 1, c2);
        ans = max(ans, f(g, r1 + 1, c1, r2, c2 + 1));
        ans = max(ans, f(g, r1, c1 + 1, r2 + 1, c2));
        ans = max(ans, f(g, r1, c1 + 1, r2, c2 + 1));
        return dp[r1][c1][c2] = cherries + ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int ans = f(grid, 0, 0, 0, 0);
        return max(ans, 0);
    }
};
