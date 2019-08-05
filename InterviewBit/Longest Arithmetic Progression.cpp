int Solution::solve(const vector<int> &A) {
    int n = A.size(), ans = 0;
    if(n <= 2)
        return n;
    unordered_map<int, int> mp;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int j = n - 1; j >= 0; j--) {
        for(int i = j - 1; i >= 0; i--) {
            int diff = A[j] - A[i];
            int val = A[j] + diff;
            if(mp.find(val) != mp.end()) {
                int k = mp[val];
                dp[i][j] = 1 + dp[j][k];
            }
            else
                dp[i][j] = 2;
            ans = max(ans, dp[i][j]);
        }
        mp[A[j]] = j;
    }
    return ans;
}

