class Solution {
public:
    int dp[501][501];
    int f(vector<int>& A, vector<int>& B, int i, int j) {
        if(i == A.size() || j == B.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if(A[i] == B[j])
            ans = 1 + f(A, B, i + 1, j + 1);
        else
            ans = max(f(A, B, i + 1, j), f(A, B, i, j + 1));
        return dp[i][j] = ans;
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof dp);
        return f(A, B, 0, 0);
    }
};
