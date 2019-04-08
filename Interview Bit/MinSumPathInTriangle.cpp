/*int minPath(vector<vector<int>>& A, int i, int j, int r, 
vector<vector<int>>& dp) {
    int c = i;
    if(j > c)
        return INT_MAX;
    if(i == r + 1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans;    
    int option1 = minPath(A, i + 1, j + 1, r, dp);
    int option2 = minPath(A, i + 1, j, r, dp);
    if(option1 == INT_MAX)
        ans = option2;
    else if(option2 == INT_MAX)
        ans = option1;
    else
        ans = A[i][j] + min(option1, option2);
    return dp[i][j] = ans;    
}*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Recursive Approach
    // vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
    // return minPath(A, 0, 0, A.size() - 1, dp);
    
    // Bottom Up Manner
    int n = A.size();
    int memo[n];
    for(int i = 0; i < A[n - 1].size(); i++)
        memo[i] = A[n - 1][i];
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < A[i].size(); j++) {
            memo[j] = A[i][j] + min(memo[j], memo[j + 1]);
        }
    }
    return memo[0];
}

