class Solution {
private:
    int dp[101];
    int decodeWays(string s, int i) {
        if (i == s.size()) {
            return 1;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int total = 0;
        if (s[i] >= '1' && s[i] <= '9') {
            total += decodeWays(s, i + 1);
        }
        if (i < s.size() - 1) {
            int num = ((s[i] - '0') * 10) + (s[i + 1] - '0');
            if (num <= 26 && num >= 10) {
                total += decodeWays(s, i + 2);
            }
        }
        return dp[i] = total;
    }
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return decodeWays(s, 0);
    }
};
