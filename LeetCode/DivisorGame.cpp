class Solution {
public:
    int dp[1001] = {};
    bool divisorGame(int N, bool res = false) {
        // return (N % 2 == 0);
        if(dp[N] != 0)
            return dp[N] == 1;
        for(int i = 1; !res && i * i < N; i++) {
            if(N % i == 0)
                res = !divisorGame(N - i);
        }
        dp[N] = res ? 1 : -1;
        return res;
    }
};
