class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> posLeft(n, 0), posRight(n, n - k), sum(n + 1, 0), ans(3, 0);
        sum[0] = nums[0];
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for(int i = k, tot = sum[k] - sum[0]; i < n; i++) {
            if(sum[i + 1] - sum[i + 1 - k] > tot) {
                tot = sum[i + 1] - sum[i + 1 - k];
                posLeft[i] = i + 1 - k;
            }
            else
                posLeft[i] = posLeft[i - 1];
        }
        for(int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--) {
            if(sum[i + k] - sum[i] >= tot) {
                tot = sum[i + k] - sum[i];
                posRight[i] = i;
            }
            else
                posRight[i] = posRight[i + 1];
        }
        int maxSum = 0;
        for(int i = k; i <= n - 2 * k; i++) {
            int l = posLeft[i - 1], r = posRight[i + k];
            int tot = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);
            if(tot > maxSum) {
                maxSum = tot;
                ans = { l, i, r };
            }
        }
        return ans;
    }
};
