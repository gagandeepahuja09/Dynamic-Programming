class Solution {
public:
    int dp[301][301];
    int dfs(vector<vector<int>>& A, int i, int j) {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] != 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        int l = dfs(A, i, j + 1), r = dfs(A, i + 1, j), t = dfs(A, i + 1, j + 1);
        ans = 1 + min(l, min(r, t));
        return dp[i][j] = ans;
    }
    
    int countSquares(vector<vector<int>>& A) {
        int ans = 0;
        int n = A.size(), m = A[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                if(A[i][j]) {
                    int sz = dfs(A, i, j); 
                    ans += sz;
                }
            }
        }
        return ans;
    }
};
