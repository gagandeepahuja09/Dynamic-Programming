class Solution {
public:
    int dp[501];
    int f(vector<int>& A, int k, int i) {
        if(i == A.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int mx = 0, ans = 0;
        for(int j = i; j < i + k && j < A.size(); j++) {
            mx = max(mx, A[j]);
            ans = max(ans, mx * (j - i + 1) + f(A, k, j + 1));
        }
        return dp[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        memset(dp, -1, sizeof dp);
        return f(A, K, 0);
    }
};
