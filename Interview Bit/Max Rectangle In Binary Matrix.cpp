int largestRect(vector<int>& A) {
    int n = A.size();
    stack<int> stk;
    vector<int> left(n, -1);
    vector<int> right(n, n);
    for(int i = 0; i < n; i++) {
        while(stk.size() && A[stk.top()] >= A[i])
            stk.pop();
        if(stk.size())
            left[i] = stk.top();
        stk.push(i);
    }
    while(stk.size())
        stk.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(stk.size() && A[stk.top()] >= A[i])
            stk.pop();
        if(stk.size())
            right[i] = stk.top();
        stk.push(i);
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, A[i] * (right[i] - left[i] - 1));
    }
    return mx;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int mx = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = A[i][j] + (i > 0 ? dp[i - 1][j] : 0);
        }
        mx = max(mx, largestRect(dp[i]));
    }
    return mx;
}

