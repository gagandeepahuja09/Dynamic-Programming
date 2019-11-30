class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty())
            return 0;
        int ans = 0;
        vector<map<int, int>> dp(A.size());
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < i; j++) {
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN)
                    continue;
                int diff = A[i] - A[j];
                dp[i][diff]++;
                dp[i][diff] += dp[j][diff];
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};
