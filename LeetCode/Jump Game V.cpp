class Solution {
public:
    int dp[1001];
    int dfs(int i, int d, vector<int>& A) {
        if(i < 0 || i >= A.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int j = i + 1;
        int ans = 0;
        while(j <= i + d && j < A.size() && A[j] < A[i]) {
            ans = max(ans, 1 + dfs(j, d, A));
            j++;
        }
        j = i - 1;
        while(j >= i - d && j >= 0 && A[j] < A[i]) {
            ans = max(ans, 1 + dfs(j, d, A));
            j--;
        }
        return dp[i] = ans;
    }
    
    int maxJumps(vector<int>& A, int d) {
        int n = A.size(), ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) {
            int curr = dfs(i, d, A);
            ans = max(ans, curr);
        }
        return ans + 1;
    }
};
