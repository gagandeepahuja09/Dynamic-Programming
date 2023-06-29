class Solution {
public:
    const int maxVal = 1e7;

    int minPathSum(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j) {
        if (i >= triangle.size() || j >= triangle[i].size()) {
            return maxVal;
        }
        if (dp[i][j] != maxVal) {
            return dp[i][j];
        }
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(
            minPathSum(triangle, dp, i + 1, j), minPathSum(triangle, dp, i + 1, j + 1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, maxVal));
        return minPathSum(triangle, dp, 0, 0);
    }
};
