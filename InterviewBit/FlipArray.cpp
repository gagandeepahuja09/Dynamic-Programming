int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += A[i];
    int capacity = sum/2;
    // No we need to maximize capacity
    // 0 - 1 Knapsack
    pair<int, int> dp[n + 1][capacity + 1];
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<= capacity; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = { 0, 0 };
            else {
                int prevWeight = dp[i-1][j].first;
                int prevItems = dp[i-1][j].second;
                
                if(j - A[i-1] >= 0) {
                    int currWeight = dp[i-1][j-A[i-1]].first + A[i-1];
                    int currItems = dp[i-1][j-A[i-1]].second + 1;
                    if((currWeight > prevWeight) ||
                    (currWeight == prevWeight && currItems < prevItems)) {
                        dp[i][j] = { currWeight, currItems };
                    }
                    else
                        dp[i][j] = dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }    
        }
    }
    return dp[n][capacity].second;
}

