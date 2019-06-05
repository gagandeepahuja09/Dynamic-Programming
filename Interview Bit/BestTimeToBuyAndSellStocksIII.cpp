int dp[100001][2][3];

int buySell(const vector<int> &A, int i, bool buy, int trans) {
    if(i == A.size() || !trans) {
        return 0;
    }
    if(dp[i][buy][trans] != -1)
        return dp[i][buy][trans];
    if(buy) {
        int option1 = buySell(A, i + 1, buy ^ 1, trans) - A[i];
        int option2 = buySell(A, i + 1, buy, trans);
        dp[i][buy][trans] = max(option1, option2);
    }
    else {
        int option1 = buySell(A, i + 1, buy ^ 1, trans - 1) + A[i];
        int option2 = buySell(A, i + 1, buy, trans);
        dp[i][buy][trans] = max(option1, option2);
    }
    return dp[i][buy][trans];
}

int Solution::maxProfit(const vector<int> &A) {
    memset(dp, - 1, sizeof dp);
    return max(buySell(A, 0, 1, 2), 0);
}

