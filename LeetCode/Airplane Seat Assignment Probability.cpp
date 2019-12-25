class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(n);
        dp[0] = 1.0;
        for(int i = 1; i < n; i++) {
            dp[i] = (1.0 / (i + 1)) + (0.0 / (i + 1)) + (dp[i - 1] * (i - 1) / (i + 1));
        }
        return dp[n - 1];
    }
};
