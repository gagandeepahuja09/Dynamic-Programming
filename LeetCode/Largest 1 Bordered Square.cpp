class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& A) {
        int n = A.size();
        if(!n)
            return 0;
        int ans = 0;
        int m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    ans = 1;
                    for(int k = 1; k < min(n, m); k++) {
                        if(i + k >= n || j + k >= m)
                            break;
                        if(A[i][j + k] == 0 || A[i + k][j] == 0)
                            break;
                        dp[i][j] = k + 1;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    for(int k = 1; k < min(n, m); k++) {
                        if(i - k < 0 || j - k < 0)
                            break;
                        if(A[i][j - k] == 0 || A[i - k][j] == 0)
                            break;
                        if(dp[i - k][j - k] >= k + 1) {
                            ans = max(ans, (k + 1) * (k + 1));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
