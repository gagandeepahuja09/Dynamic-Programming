class Solution {
public:
    int dfs(vector<vector<int>>& A, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        vector<int> dx = { 0, -1, 0,  1 };
        vector<int> dy = { 1,  0, -1, 0 };
        for(int k = 0; k < 4; k++) {
            int cx = i + dx[k], cy = j + dy[k];
            if(cx < 0 || cy < 0 || cx >= A.size() || cy >= A[0].size() 
               || A[cx][cy] <= A[i][j])
                continue;
            ans = max(ans, 1 + dfs(A, cx, cy, dp));
        }
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& A) {
        int ans = 0;
        if(!A.size())
            return 0;
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                ans = max(ans, dfs(A, i, j, dp));
                ans = max(ans, dp[i][j]);
            }
        }
        return ans + 1;
    }
};
