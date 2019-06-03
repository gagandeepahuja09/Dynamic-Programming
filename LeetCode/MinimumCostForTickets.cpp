class Solution {
public:
    bool cost[366];
    int dp[366];
    int minCost(vector<int>& costs, int start) {
        if(start > 365)
            return 0;
        if(dp[start] != -1)
            return dp[start];
        int option1, option2, option3;
        if(!cost[start]) {
            return dp[start] = minCost(costs, start + 1);
        }
        option1 = costs[0] + minCost(costs, start + 1);
        option2 = costs[1] + minCost(costs, start + 7);
        option3 = costs[2] + minCost(costs, start + 30);
        return dp[start] = min(option1, min(option2, option3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(cost, false, sizeof cost);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<days.size(); i++) {
            cost[days[i]] = true;
        }
        return minCost(costs, 0);
    }
};
