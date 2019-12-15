class Solution {
public:
    int dp[41][41][1601];
    bool vis[41][41];
    int f(vector<vector<int>>& grid, int i, int j, int k) {
        int n = grid.size(), m = grid[0].size();
        if(k < 0)
            return 1e7;
        if(i == n - 1 && j == m - 1)
            return 0;
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 1e7;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        int ans = 1e7;
        if(vis[i][j])
            return ans;
        vis[i][j] = 1;
        vector<int> dx = { 0, 1, 0, -1};
        vector<int> dy = { 1, 0, -1, 0};
        for(int l = 0; l < 4; l++) {
            int x = i + dx[l], y = j + dy[l];
            if(x >= 0 && x < n && y >= 0 && y < m) {
                int nk = k;
                if(grid[x][y] == 1)
                    nk--;
                if(nk >= 0)
                    ans = min(ans, f(grid, x, y, nk) + 1);
            }
        }
        vis[i][j] = 0;
        return dp[i][j][k] = ans;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        memset(dp, -1, sizeof dp);
        if(grid[0][0] == 1)
            k--;
        memset(vis, false, sizeof vis);
        int ans = f(grid, 0, 0, k);
        if(ans >= 1e7)
            return -1;
        return ans;
    }
};
