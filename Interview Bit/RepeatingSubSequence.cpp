int Solution::anytwo(string A) {
    int n = A.size();
    // LCS(A, A) with restriction that when they are same characters
    // They should not be at the same index
    vector<vector<int>> lcs(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(A[i-1] == A[j-1] && i != j)
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return (lcs[n][n] > 1);
}

