class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>& nums, int l, int r) {
        if(l > r)
            return 0;
        if(l == r) {
            return nums[l - 1] * nums[l] * nums[l + 1];
        }
        if(dp[l][r] != -1)
            return dp[l][r];
        for(int i = l; i <= r; i++) {
            dp[l][r] = max(dp[l][r], nums[i] * nums[l - 1] * nums[r+1] 
            + maxCoins(nums, l, i - 1) + maxCoins(nums, i + 1, r));
        }
        return dp[l][r];
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return maxCoins(nums, 1, nums.size() - 2);
    }
};
