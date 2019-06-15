/*
Arrange II

You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

        You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
        No stable should be empty and no horse should be left unaccommodated.
        Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements

Example:

Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1*/

int minCost(vector<int>& w, vector<int>& b, int i, int k, vector<vector<int>>& dp) {
    if(i + 1 < k) {
        return INT_MAX;
    }
    if(dp[i][k] != -1)
        return dp[i][k];
    if(k == 1) {
        return (w[i] * b[i]);
    }
    int ans = INT_MAX;
    for(int l = 0; l <= i; l++) {
        int curr;
        int left = minCost(w, b, l, k - 1, dp);
        int right = (w[i] - w[l]) * (b[i] - b[l]);
        if(left == INT_MAX)
            curr = INT_MAX;
        else
            curr = left + right;
        ans = min(ans, curr);    
    }
    return dp[i][k] = ans;
}

int Solution::arrange(string A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(B + 1, -1));
    vector<int> w(n, 0);
    vector<int> b(n, 0);
    w[0] = (A[0] == 'W');
    b[0] = (A[0] == 'B');
    for(int i = 0; i < n; i++) {
        w[i] = (A[i] == 'W') + w[i - 1];
        b[i] = (A[i] == 'B') + b[i - 1];
    }
    int ans = minCost(w, b, n - 1, B, dp);
    return ans != INT_MAX ? ans : -1;
}

