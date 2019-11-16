class Solution {
public:
    int dp[501][501];
    int minDist(string s, int i, string t, int j) {
        if(i == s.size() && j == t.size()) {
            return 0;
        }
        if(i == s.size()) {
            return t.size() - j;
        }
        if(j == t.size()) {
            return s.size() - i;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j]) {
            return minDist(s, i + 1, t, j + 1);
        }    
        int option1 = minDist(s, i + 1, t, j);
        int option2 = minDist(s, i, t, j + 1);
        return dp[i][j] = 1 + min(option1, option2);
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return minDist(word1, 0, word2, 0);
    }
};
