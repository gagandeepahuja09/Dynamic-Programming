#define MOD 1000000007

int noOfWays(int N, int S, vector<vector<int>>& dp) {
    if(N == 0 && S == 0)
        return 1;
    if(N == 0)
        return 0;
    if(S == 0)
        return 1;
    if(dp[N][S] != -1)
        return dp[N][S];
    int ans = 0;    
    for(int i=0; i <= 9 && i <= S; i++) {
        ans = (ans%MOD + noOfWays(N-1, S - i, dp)%MOD)%MOD;
    }
    return dp[N][S] = ans%MOD;
}

int Solution::solve(int N, int S) {
    int ans = 0;  
    vector<vector<int>> dp(N+1, vector<int>(S+1, -1));
    for(int i=1; i <= 9 && i <= S; i++) {
        ans = (ans%MOD + noOfWays(N-1, S - i, dp)%MOD)%MOD;
    }
    return ans%MOD;
}

