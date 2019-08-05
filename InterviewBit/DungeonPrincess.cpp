

    #define ll long long int
     
    ll f(vector<vector<int>>& A, int i, int j, vector<vector<ll>>& dp) {
        if(i == A.size() - 1 && j == A[0].size() - 1) {
            return 1 - (A[i][j] < 0 ? A[i][j] : 0);
        }
        if(i >= A.size() || j >= A[0].size())
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        ll option1 = max(-A[i][j] + f(A, i + 1, j, dp), 1ll);
        ll option2 = max(-A[i][j] + f(A, i, j + 1, dp), 1ll);
        return dp[i][j] = min(option1, option2);
    }
     
    int Solution::calculateMinimumHP(vector<vector<int> > &A) {
        vector<vector<ll>> dp(A.size(), vector<ll>(A[0].size(), -1));
        return (int)f(A, 0, 0, dp);
    }


