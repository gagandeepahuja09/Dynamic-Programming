class Solution {
public:
    int N;
    int dp[1001][1001];
    int f(int n, int selected) {
        if(n == N) {
            return 0;
        }
        if(n > N) {
            return 1e7;
        }
        if(dp[n][selected] != -1)
            return dp[n][selected];
        int copy = 1e7, paste = 1e7;
        if(selected)
            paste = 1 + f(n + selected, selected);
        copy = 2 + f(n + n, n);
        return min(copy, paste);
    }
    
    int minSteps(int n) {
        memset(dp, -1, sizeof dp);
        N = n;
        return f(1, 0);
    }
};
