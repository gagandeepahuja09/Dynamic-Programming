void back(int start, int end, vector<int>& ret, vector<vector<int>>& parent, 
vector<int>& B) {
    if(start + 1 >= end)
        return;
    ret.push_back(B[parent[start][end]]);
    // Since we want lexicographically smallest
    // l part is called first
    back(start, parent[start][end], ret, parent, B);
    back(parent[start][end], end, ret, parent, B);
}

long rodCutUtil(int start, int end, vector<int> &B, 
vector<vector<long>>& dp, vector<vector<int>>& parent) {
    if(start + 1 >= end) {
        return 0;
    }
    if(dp[start][end] != -1)
        return dp[start][end];
    long ans = LLONG_MAX;  
    int bestidx = -1;
    for(int i = start + 1; i < end; i++) {
        long curr =  rodCutUtil(start, i, B, dp, parent) + 
        rodCutUtil(i, end, B, dp, parent) + (long)B[end] - (long)B[start];
        if(curr < ans) {
            ans = curr;
            bestidx = i;
        }
    }
    parent[start][end] = bestidx;
    // cout << parent[start][end] << " ";
    dp[start][end] = ans;
    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.insert(B.begin(), 0);
    B.push_back(A);
    vector<int> ret;
    int n = B.size();
    vector<vector<long>> dp(n, vector<long>(n, -1));
    vector<vector<int>> parent(n, vector<int>(n));
    rodCutUtil(0, B.size() - 1, B, dp, parent);
    back(0, n - 1, ret, parent, B);
    return ret;
}
