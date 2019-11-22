class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), mx = 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(A[i] == B[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = 0;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};
