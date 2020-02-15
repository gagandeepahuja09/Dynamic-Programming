class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<map<long, int>> dp(A.size());
        int ans = 0, n = A.size();
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                long diff = (long)A[j] - (long)A[i];
                dp[j][diff] += (1 + dp[i][diff]);
                ans += dp[i][diff];
            }
        }
        return ans;
    }
};
