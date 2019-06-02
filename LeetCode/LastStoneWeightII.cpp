class Solution {
public:
    int dp[30][6000];
    int totalWeight(vector<int>& stones, int i, int s) {
        if(i == stones.size())
                return s < 0 ? 100 : s;
        if(dp[i][s + 3000] != -1)
            return dp[i][s + 3000];
        int option1 = totalWeight(stones, i + 1, s - stones[i]);
        int option2 = totalWeight(stones, i + 1, s + stones[i]);
        return dp[i][s + 3000] = min(option1, option2);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof dp);
        return totalWeight(stones, 0, 0);
    }
};
