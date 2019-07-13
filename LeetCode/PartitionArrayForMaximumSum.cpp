class Solution {
public:
    int dp[501][501];
    int maxSum(vector<int>& A, int k, int i, int mx, int K) {
        if(i == A.size())
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int ans = 0;
        if(k == 1) {
            mx = max(mx, A[i]);
            ans = mx * K + maxSum(A, K, i + 1, 0, K);
        }
        else {
            int curr = max(A[i], mx);
            int option1 = curr * (K - k + 1) + maxSum(A, K, i + 1, 0, K);
            int option2 = maxSum(A, k - 1, i + 1, max(A[i], mx), K); 
            ans = max(option1, option2);
        }
        return dp[i][k] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        memset(dp, -1, sizeof dp);
        return maxSum(A, K, 0, 0, K);
    }
};
