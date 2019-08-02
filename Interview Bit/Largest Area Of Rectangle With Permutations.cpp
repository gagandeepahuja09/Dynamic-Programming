bool cmp(int a, int b) {
    return (a > b);
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> hist(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0)
                hist[i][j] = A[i][j];
            else
                hist[i][j] = (A[i][j]) ? 1 + hist[i - 1][j] : 0;
        }
    }
    for(int i = 0; i < n; i++) {
        sort(hist[i].begin(), hist[i].end(), cmp);
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mx = max(mx, hist[i][j] * (j + 1));
        }
    }
    return mx;
}

