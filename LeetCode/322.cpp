class Solution {
public:
    const int MAX_VAL = 1e9;
    int coinChangeRec(vector<int>& coins, vector<int>& dp, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return MAX_VAL;
        }
        if (dp[amount] != MAX_VAL) {
            return dp[amount];
        }
        int minCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int coinsUsed = 1 + coinChangeRec(coins, dp, amount - coins[i]);
            minCoins = min(minCoins, coinsUsed);
        }
        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1e4 + 1, MAX_VAL);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        // int res = coinChangeRec(coins, dp, amount);
        // if (res >= MAX_VAL) {
        //     res = -1;
        // }
        return dp[amount] == MAX_VAL ? -1 : dp[amount];
    }
};
