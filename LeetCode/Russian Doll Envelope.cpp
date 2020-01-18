class Solution {
public:
    int dp[1000001];
    int f(vector<vector<int>>& A, int i) {
        if(i == A.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = 1;
        for(int j = i + 1; j < A.size(); j++) {
            if(A[j][0] > A[i][0] && A[j][1] > A[i][1]) {
               ans = max(ans, 1 + f(A, j)); 
            }
        }
        return dp[i] = ans;
    }
    
    int maxEnvelopes(vector<vector<int>>& A) {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); i++) {
            ans = max(ans, f(A, i));    
        }
        return ans;
    }
};
