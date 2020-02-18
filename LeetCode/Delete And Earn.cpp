class Solution {
public:
    // int dp[20001];
    /*int maxPoints(vector<int>& coins, int i) {
        if(i == coins.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int pos = i, earned = 0;
        while(pos < coins.size() && coins[pos] == coins[i]) {
            earned += coins[pos++];
        }
        int skipped = maxPoints(coins, pos);
        while(pos < coins.size() && coins[pos] == coins[i] + 1) {
            pos++;
        }
        earned += maxPoints(coins, pos);
        return dp[i] = max(skipped, earned);
    } */
    
    int deleteAndEarn(vector<int>& nums) {
        // memset(dp, -1, sizeof dp);
        sort(nums.begin(), nums.end());
        // return maxPoints(nums, 0);
        int prev2 = 0, prev = 0, curr = 0, i = 0;
        while(i < nums.size()) {
            int pos = i;
            curr = 0;
            while(i < nums.size() && nums[i] == nums[pos])
                curr += nums[i++];
            // we can add prev if diff > 1
            if(pos >= 1 && nums[i - 1] > nums[pos - 1] + 1)
                curr += prev;
            else
                curr = max(curr + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
