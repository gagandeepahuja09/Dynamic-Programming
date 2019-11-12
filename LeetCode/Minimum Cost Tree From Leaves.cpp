class Solution {
public:
    int mx[41][41];
    int dp[41][41];
    int f(int i, int j) {
        if(i == j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1e8;
        for(int k = i; k < j; k++) {
            ans = min(ans, mx[i][k] * mx[k + 1][j] + f(i, k) + f(k + 1, j));
        }
        return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) {
            mx[i][i] = arr[i];
            for(int j = i + 1; j < n; j++) {
                mx[i][j] = max(arr[j], mx[i][j - 1]);
                // cout << mx[i][j] << endl;
            }
        }
        return f(0, n - 1);
    }
};
