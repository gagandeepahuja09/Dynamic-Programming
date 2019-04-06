pair<long long, long long> parenthesize(vector<vector<pair<long long, long long>>>& dp, 
string s, int start, int end) {
    if(start == end) {
        if(s[start] == 'T')
            return dp[start][end] = {1ll, 0ll};
        else if(s[start] == 'F')
            return dp[start][end] = {0ll, 1ll};
    }
    if(dp[start][end].first != -1ll || dp[start][end].second != -1ll)
        return dp[start][end];
    pair<long, long> p = {0, 0};
    for(int k = start + 1 ; k <= end - 1 ; k++) {
        if(s[k] == '&') {
            p.first += (parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).first);
            p.second += ((parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).second) + 
            (parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).second) + 
            (parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).first));
        }
        else if(s[k] == '|') {
            p.first += ((parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).first) + 
            (parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).second) + 
            (parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).first));
            p.second += (parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).second);
        }
        else if(s[k] == '^') {
            p.first += ((parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).second) + 
            (parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).first));
            p.second += ((parenthesize(dp, s, start, k-1).first * parenthesize(dp, s, k+1, end).first) + 
            (parenthesize(dp, s, start, k-1).second * parenthesize(dp, s, k+1, end).second));
        }
    }
 
    p.first %= 1003;
    p.second %= 1003;
    return dp[start][end] = p;
}

int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(
            n, {-1ll, -1ll}));
    return (int)parenthesize(dp, A, 0, n-1).first;
}

