class Solution {
private:
    int dp[501][501];
public:
    int f(vector<int>& nums, int l, int r) {
        if(l == r)
            return nums[l - 1] * nums[l]  * nums[l + 1];
        if(dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        for(int i = l; i <= r; i++) {
            ans = max(ans, f(nums, l, i - 1) + f(nums, i + 1, r) + nums[l - 1] * nums[i] * nums[r + 1]);
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return f(nums, 1, nums.size() - 2);        
    }
};
