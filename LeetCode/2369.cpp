class Solution {
public:
    bool helper(vector<int>& nums, vector<int>& dp, int i) {
        int n = nums.size();
        if (i >= n) {
            return true;
        }
        if (dp[i] != -1) {
            return (dp[i] == 1);
        }
        bool ans = false;
        if (i < n - 1 && nums[i] == nums[i + 1]) {
            ans |= helper(nums, dp, i + 2);
            if (i < n - 2 && nums[i] == nums[i + 2]) {
                ans |= helper(nums, dp, i + 3);
            } 
        }
        if (i < n - 2 && nums[i + 2] == nums[i + 1] + 1 && nums[i + 1] == nums[i] + 1) {
            ans |= helper(nums, dp, i + 3);
        }
       dp[i] = (int)ans;
       return ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, dp, 0);
    }
};
