class Solution {
public:
    int dp[201][201];
    int f(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j)
                continue;
            int curr = arr[i][j] + f(arr, i + 1, k);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }
        return ans;
    }
};
