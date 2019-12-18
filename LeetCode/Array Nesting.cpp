class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& ans, int i, int j) {
        if(i == j)
            return 1;
        if(ans[j] > 1)
            return ans[j];
        ans[j] = 1 + dfs(nums, ans, i, nums[j]);
        return ans[j];
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<int> ans(n, 1);
        for(int i = 0; i < nums.size(); i++) {
            if(ans[i] == 1)
                ans[i] = dfs(nums, ans, i, nums[i]);
            mx = max(mx, ans[i]);
        }
        return mx;
    }
};
