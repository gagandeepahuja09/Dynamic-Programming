class Solution {
public:
    int pal[101][101];
    int dp[101][101];
    int f(string s, int i, int k) {
        if(i >= s.size())
            return ((k == 0) ? 0 : 1011);
        int ans = 1011;
        if(k < 0)
            return ans;
        if(dp[i][k] != -1)
            return dp[i][k];
        for(int l = i; l < s.size(); l++) {
            ans = min(ans, pal[i][l] + f(s, l + 1, k - 1));
        }
        return dp[i][k] = ans;
    }
    
    int dfs(string s, int i, int j) {
        if(i >= j || j < 0 || i < 0 || j >= s.size() || i >= s.size())
            return 0;
        int cnt = 0;
        if(s[i] != s[j])
            cnt++;
        return pal[i][j] = dfs(s, i + 1, j - 1) + cnt;
    }
    
    int palindromePartition(string s, int k) {
        int n = s.size(); 
        memset(pal, -1, sizeof pal);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < s.size(); i++) {
            pal[i][i] = 0;
            for(int j = i + 1; j < s.size(); j++) {
                if(pal[i][j] == -1) {
                    pal[i][j] = dfs(s, i, j);
                }
            }
        }
        return f(s, 0, k);
    }
};
