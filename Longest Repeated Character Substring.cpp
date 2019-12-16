class Solution {
public:
    int maxRepOpt1(string s) {
        int n = s.size();
        vector<vector<int>> l(n, vector<int>(26, 0));
        vector<vector<int>> r(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                l[i][s[i] - 'a'] = 1;
            }
            else {
                l[i][s[i] - 'a'] = l[i - 1][s[i] - 'a'] + 1;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                r[i][s[i] - 'a'] = 1;
            }
            else {
                r[i][s[i] - 'a'] = r[i + 1][s[i] - 'a'] + 1;
            }
        }
        
        int mx = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 0; j < 26; j++) {
                if(s[i] - 'a' != j) {
                    mx = max(mx, l[i - 1][j] + r[i + 1][j] + 1);
                }
                else
                    mx = max(mx, l[i - 1][j] + r[i + 1][j]);
            }
        }
        return mx; 
    }
};
