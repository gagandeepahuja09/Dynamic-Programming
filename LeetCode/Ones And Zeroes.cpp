class Solution {
public:
    int dp[101][101];
    int findMaxForm(vector<string>& strs, int zeroes, int ones) {
        memset(dp, 0, sizeof dp);
        for(string s : strs) {
            int c0 = count(s.begin(), s.end(), '0'), c1 = s.size() - c0;
            for(int i = zeroes; i >= c0; i--) {
                for(int j = ones; j >= c1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }
        }
        return dp[zeroes][ones];
    }
};
