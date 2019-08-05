int Solution::longestValidParentheses(string A) {
    int n = A.size();
    int dp[n + 1];
    int mx = 0;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i < n; i++) {
        if(A[i] == ')' && A[i - 1] == '(') {
            dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
        }
        else if(A[i] == ')' && A[i - 1] == ')') {
            int dist = i - dp[i - 1] - 1;
            if(dist >= 0 && A[dist] == '(') {
                dp[i] = dp[i - 1] + 2 + (dist - 1 >= 0 ? dp[dist - 1] : 0);
            }
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}

