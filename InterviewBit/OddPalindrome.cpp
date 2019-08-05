/*
Odd Palindrome

A palindrome string is a string which reads the same forward and backward. 
If a palindrome string is of odd length l, then (l+1)/2th character (1 index based) 
is said to be the centre of the palindrome.

You are given a string A. Return an array X of integers where X[i] = 
(number of odd length palindrome subsequence of A with A[i] as the centre) 
modulo 1000000007.

A subsequence of A is a string which can be derived from A by deleting 
some of its character.*/

#define MOD 1000000007

vector<int> Solution::solve(string A) {
    int n = A.size();
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int len = n - 1; len >= 0; len--) {
        for(int i = 0; i + len < n; i++) {
            int j = i + len;
            if(i == 0 && j == n - 1) {
                if(A[i] == A[j]) {
                    dp[i][j] = 2;
                }
                else
                    dp[i][j] = 1;
            }
            else {
                if(i - 1 >= 0) 
                    dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j] % MOD ) % MOD;
                if(j + 1 <= n - 1)
                    dp[i][j] = (dp[i][j] % MOD + dp[i][j + 1] % MOD) % MOD;
                if(A[i] != A[j] && (i - 1 >= 0 && j + 1 <= n - 1))
                    dp[i][j] = (dp[i][j] % MOD - dp[i - 1][j + 1] % MOD + MOD) % MOD;
                if(A[i] == A[j] && (i - 1 < 0 || j + 1 > n - 1))
                    dp[i][j] = (1 % MOD+ dp[i][j] % MOD) % MOD;
            }
        }
    }
    vector<int> ret;
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1)
            ret.push_back(1);
        else
            ret.push_back(dp[i - 1][i + 1]);
    }
    return ret;
}

