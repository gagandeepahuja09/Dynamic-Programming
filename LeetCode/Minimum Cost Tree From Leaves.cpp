class Solution {
public:
    int dp[41][41];
    int mx[41][41];
    
    int f(int i, int j) {
        if(i == j)
            return 0;
        int ret = 1 << 30;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        for(int k = i; k < j; k++) {
            ret = min(ret, mx[i][k] * mx[k + 1][j] + f(i, k) + f(k + 1, j));
        }
        return dp[i][j] = ret;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < arr.size(); i++) {
            mx[i][i] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }
        return f(0, arr.size() - 1);
    }
};
