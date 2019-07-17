class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuy = INT_MIN, oneBuyOneSell = 0, twoBuy = INT_MIN, 
        twoBuyTwoSell = 0;
        for(int i = 0; i < prices.size(); i++) {
            twoBuyTwoSell = max(twoBuyTwoSell, prices[i] + twoBuy);
            twoBuy = max(twoBuy, oneBuyOneSell - prices[i]);
            oneBuyOneSell = max(oneBuyOneSell, prices[i] + oneBuy);
            oneBuy = max(oneBuy, -prices[i]);
        }
        return twoBuyTwoSell;
    }
};
