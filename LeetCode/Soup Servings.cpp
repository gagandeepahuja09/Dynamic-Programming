class Solution {
public:
    double dp[200][200];
    double f(int a, int b) {
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a <= 0)
            return 1;
        if(b <= 0)
            return 0;
        if(dp[a][b] > 0)
            return dp[a][b];
        dp[a][b] = .25 * 
            (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));
        return dp[a][b];
    }
    double soupServings(int N) {
        return N >= 4800 ? 1.0 : f((N + 24) / 25, (N + 24) / 25);
    }
};
