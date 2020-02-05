class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].size(), ret = n - 1, k;
        vector<int> dp(n, 1);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < j; i++) {
                for(k = 0; k < m; ++k) {
                    if(A[k][i] > A[k][j]) {
                        break;
                    }    
                }
                if(k == m && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
                ret = min(ret, n - dp[j]);
            }
        }
        return ret;
    }
};
