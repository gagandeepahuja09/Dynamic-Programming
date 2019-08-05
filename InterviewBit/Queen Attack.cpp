vector<vector<int>> dp[8];

bool valid(int i, int j, vector<string>& A) {
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size())
        return 0;
    return 1;    
}

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int f(int i, int j, int k, vector<string>& A) {
    if(dp[k][i][j] != -1)
        return dp[k][i][j];
    int ret = 0;
    int ni = i + dx[k], nj = j + dy[k];
    if(valid(ni, nj, A)) {
        if(A[ni][nj] == '1')
            ret++;
        else
            ret += f(ni, nj, k, A);
    }
    return dp[k][i][j] = ret;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size(), m = A[0].size();
    for(int i = 0; i < 8; i++){
        dp[i].clear();
        dp[i].resize(n, vector<int>(m, -1));
    }
    vector<vector<int>> ret(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 8; k++) {
                ret[i][j] += f(i, j, k, A);
            }
        }
    }
    return ret;
}

