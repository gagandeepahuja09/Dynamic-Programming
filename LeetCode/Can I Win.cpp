class Solution {
public:
    int dp[1 << 20];
    
    int dfs(int M, int T, int k) {
        if(T <= 0)
            return false;
        if(dp[k] != -1)
            return dp[k];
        // try all available numbers
        for(int i = 0; i < M; i++) {
            // if i + 1 is available and my opponent can't win after i picked ==> i win
            if(((k & (1 << i)) == 0) && !dfs(M, T - i - 1, k | (1 << i))) {
                return dp[k] = 1;
            }
        }
        return dp[k] = 0;
    }
    
    bool canIWin(int M, int T) {
        memset(dp, -1, sizeof dp);
        int sum = (M * (M + 1)) / 2;
        if(T < 2)
            return true;
        // Nobody can win
        if(sum < T)
            return false;
        if(sum == T)
            return M % 2;
        
        // initial state total = T, k = 0; no one picked
        return dfs(M, T, 0);
    }
};
