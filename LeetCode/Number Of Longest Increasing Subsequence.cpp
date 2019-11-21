class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> lis(n, { 1, 1 });
        int mx = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    if(lis[j].first < 1 + lis[i].first) {
                        lis[j].first = 1 + lis[i].first;
                        lis[j].second = lis[i].second;
                    }
                    else if(lis[j].first == 1 + lis[i].first) {
                        lis[j].second += lis[i].second;
                    }
                    mx = max(mx, lis[j].first);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(lis[i].first == mx) {
                ans += lis[i].second;
            }
        }
        return ans;
    }
};
