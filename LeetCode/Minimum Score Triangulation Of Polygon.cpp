class Solution {
public:
    int dp[51][51];
    int f(vector<int>& A, int i, int j) {
        if(j - i <= 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min(ans, A[k] * A[j] * A[i] + f(A, i, k) + f(A, k, j));
        }
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& A) {
        memset(dp, -1, sizeof dp);
        return f(A, 0, A.size() - 1);
    }
};
