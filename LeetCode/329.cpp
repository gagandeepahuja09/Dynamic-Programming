class Solution {
public:
    int longestPath(vector<vector<int>>& A, vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        
        vector<vector<int>> v = { { -1, 0 }, { 0, -1 }, { 0, 1 },{ 1, 0 } };
        int ans = 1;
        for (int k = 0; k < 4; k++) {
            int ci = i + v[k][0], cj = j + v[k][1];
            if (
                ci >= 0 && ci <= A.size() - 1 
                && cj >= 0 && cj <= A[0].size() - 1 && A[i][j] < A[ci][cj]
               ) {
                ans = max(ans, 1 + longestPath(A, dp, ci, cj));
            }
        }
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& A) {
        int ans = 0;
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, longestPath(A, dp, i, j));
            }
        }
        return ans;
    }
};
