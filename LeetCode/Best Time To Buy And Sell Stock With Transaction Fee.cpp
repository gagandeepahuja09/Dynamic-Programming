class Solution {
public:
    int dp[50000][2];
    int tFee;
    int f(vector<int>& prices, int i, bool buy) {
        if(i == prices.size())
            return (buy ? 0 : -1e4);
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int op1 = 0, op2 = 0;
        if(buy) {
            op1 = -prices[i] + f(prices, i + 1, 0);
            op2 = f(prices, i + 1, 1);
        }
        else {
            op1 = prices[i] - tFee + f(prices, i + 1, 1);
            op2 = f(prices, i + 1, 0);
        }
        return dp[i][buy] = max(op1, op2);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        tFee = fee;
        memset(dp, -1, sizeof dp);
        return f(prices, 0, 1);
    }
};
