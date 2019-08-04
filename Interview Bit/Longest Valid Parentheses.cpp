int Solution::longestValidParentheses(string A) {
    int ret = 0;
    vector<int> dp(A.size(), 0);
    for(int i = 1; i < A.size(); i++) {
        if(A[i] == ')') {
            if(A[i - 1] == '(') {
                dp[i] = 2 + ((i >= 2) ? dp[i - 2] : 0);
            }
            else {
                int prev = i - 1 - dp[i - 1];
                if(prev >= 0 && A[prev] == '(') {
                    dp[i] = 2 + dp[i - 1] + (prev > 0 ? dp[prev - 1] : 0);
                }
            }
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

