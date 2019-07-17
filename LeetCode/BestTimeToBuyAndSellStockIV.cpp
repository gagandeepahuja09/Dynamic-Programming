class Solution {
public:
    int maxPro(int k, int i, vector<int>& prices, vector<vector<int>>& dp) {
        if(k == 0)
            return 0;
        if(i == prices.size()) {
            return 0;
        }
        if(dp[i][k] != -1)
            return dp[i][k];
        int option1, option2, option3;
        option2 = 0;
        option1 = maxPro(k, i + 1, prices, dp);
        if(k % 2 == 0) {
            option2 = -prices[i] + maxPro(k - 1, i + 1, prices, dp);
        }
        else {
            option2 = prices[i] + maxPro(k - 1, i + 1, prices, dp);
        }
        return dp[i][k] = max(option1, option2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, -1));
        // memset(dp, -1, sizeof dp);
        return maxPro(2 * k, 0, prices, dp);    
    }
};
