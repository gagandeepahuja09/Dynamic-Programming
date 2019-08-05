long f(int i, int j, vector<int>& cuts, vector<vector<long>>& dp, 
vector<vector<int>>& parent) {
    if(j - i == 1)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    long ans = LLONG_MAX, idx = -1;    
    for(int k = i + 1; k < j; k++) {
        long curr = cuts[j] - cuts[i] + f(i, k, cuts, dp, parent) + 
        f(k, j, cuts, dp, parent);
        if(curr < ans) {
            ans = curr;
            idx = k;
        }
    }
    parent[i][j] = idx;
    return dp[i][j] = ans;
}

void rec(vector<int>& B, vector<int>& ret, vector<vector<int>>& parent, int i, int j) {
    if(j - i == 1)
        return;
    int idx = parent[i][j];
    ret.push_back(B[idx]);
    rec(B, ret, parent, i, idx); rec(B, ret, parent, idx, j);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    B.insert(B.begin(), 0);
    B.push_back(A);
    vector<int> ret;
    vector<vector<long>> dp(B.size(), vector<long>(B.size(), -1));
    vector<vector<int>> parent(B.size(), vector<int>(B.size(), -1));
    f(0, B.size() - 1, B, dp, parent);
    rec(B, ret, parent, 0, B.size() - 1);
    return ret;
}
