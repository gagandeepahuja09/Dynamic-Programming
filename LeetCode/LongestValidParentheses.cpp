class Solution {
public:
    int longestValidParentheses(string A) {
        int n = A.size(), mx = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++) {
            if(A[i] == ')') {
                if(A[i - 1] == '(') {
                    if(i >= 2)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                }
                else if(A[i - 1] == ')') {
                    int prev = i - dp[i - 1];
                    if(prev >= 1 && A[prev - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + (prev >= 2 ? dp[prev - 2] : 0);
                    }
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
