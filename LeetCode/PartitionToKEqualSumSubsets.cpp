class Solution {
public:
    int target;
    bool dfs(int start, vector<int>& nums, vector<bool>& vis, int k, int sum) {
        if(k == 1)
            return true;
        if(sum == target)
            return dfs(0,nums,vis,k-1,0);
        for(int i=start; i<nums.size(); i++) {
            if(!vis[i])
            {
                vis[i] = true;
                if(dfs(i+1, nums, vis, k, sum + nums[i])) 
                    return true;
                vis[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        target = sum/k;
        vector<bool> vis(nums.size(), false);
        return ((sum%k == 0) && (k != 0) && dfs(0, nums, vis, k, 0));
    }
};
