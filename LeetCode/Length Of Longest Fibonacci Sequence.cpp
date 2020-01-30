class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int maxLen = 0;
        int n = A.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < A.size(); i++) {
            int l = 0, r = i - 1;
            while(l < r) {
                if(A[l] + A[r] < A[i]) {
                    l++;
                }
                else if(A[l] + A[r] > A[i]) {
                    r--;
                }
                else {
                    dp[i][r] = 1 + dp[r][l];
                    maxLen = max(maxLen, dp[i][r]);
                    l++; r--;
                }
            }
        }
        return maxLen == 0 ? 0 : maxLen + 2;
    }
};
