#define MOD 1003

pair<int, int> f(string s, int i, int j, vector<vector<pair<int, int>>>& dp) {
    if(j == i) {
        if(s[j] == 'T')
            return { 1, 0 };
        return { 0, 1 };    
    }
    pair<int, int> p = { -1, -1 };
    if(dp[i][j] != p) {
        return dp[i][j];
    }
    pair<int, int> ret = { 0, 0 };
    for(int k = i; k <= j; k++) {
        if(s[k] == '&' || s[k] == '^' || s[k] == '|') {
            auto l = f(s, i, k - 1, dp), r = f(s, k + 1, j, dp);
            if(s[k] == '&') {
                ret.first += l.first * r.first;
                ret.second += l.second * r.first
                + r.second * (l.first + l.second);
            }
            else if(s[k] == '|') {
                ret.second += l.second * r.second;
                ret.first += l.first * (r.first + r.second)
                + r.first * l.second;
            }
            else if(s[k] == '^') {
                ret.first += l.second * r.first + r.second * l.first;
                ret.second += l.first * r.first
                + r.second * l.second;
            }
            ret.first %= MOD; ret.second %= MOD;
        }
    }
    return dp[i][j] = ret;
}

int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, { -1, -1 }));
    return f(A, 0, A.size() - 1, dp).first;
}

