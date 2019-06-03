class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i + 1; j < A.size(); j++) {
                int d = A[j] - A[i];
                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
                res = max(res, dp[d][j]);
            }
        }
        return res;
    }
};
