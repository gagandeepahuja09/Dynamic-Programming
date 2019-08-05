int vis[100001];

int twoStrings(string s, int i, string t, int j) {
    if(j == t.size())
        return 1;
    if(i == s.size())
        return 0;
    if(s[i] == t[j]) {
        if(twoStrings(s, i + 1, t, j + 1)) {
            vis[i] = 1;
        }
        twoStrings(s, i + 1, t, j + 1);
        twoStrings(s, i + 1, t, j);
    }
    else
        return twoStrings(s, i + 1, t, j);
}

int Solution::solve(string A, string B) {
    memset(vis, 0, sizeof vis);
    twoStrings(A, 0, B, 0);
    for(int i = 0; i < A.size(); i++) {
        if(!vis[i])
            return 0;
    }
    return 1;        
}
