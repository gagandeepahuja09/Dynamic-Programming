class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(A[0].size(), 1);
        for(int i = 0; i < A[0].size(); i++) {
            for(int j = 0; j < i; j++) {
                for(int k = 0; k <= A.size(); k++) {
                    if(k == A.size())
                        dp[i] = max(dp[i], dp[j] + 1);
                    else if(A[k][j] > A[k][i])
                        break;
                }
            }
        }
        return A[0].size() - *max_element(dp.begin(), dp.end());
    }
};
