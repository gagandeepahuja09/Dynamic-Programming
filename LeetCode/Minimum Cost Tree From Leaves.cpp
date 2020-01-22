class Solution {
public:
    int dp[41][41];
    int f(vector<int>& A, vector<vector<int>>& mx, int i, int j) {
        if(j <= i)
            return 0;
        if(j - i == 1) {
            return A[i] * A[j];
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++) {
            int curr = mx[i][k] * mx[k + 1][j] + f(A, mx, i, k) + f(A, mx, k + 1, j);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    
    int mctFromLeafValues(vector<int>& A) {
        int n = A.size();
        memset(dp, -1, sizeof dp);
        vector<vector<int>> mx(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            int currMax = A[i];
            mx[i][i] = currMax;
            for(int j = i + 1; j < n; j++) {
                currMax = max(currMax, A[j]);
                mx[i][j] = currMax;
            }
        }
        return f(A, mx, 0, n - 1);
    }
};
