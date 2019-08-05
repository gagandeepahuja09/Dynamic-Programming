int Solution::solve(vector<vector<int> > &A) {
    int K = 0;
    int cnt = 0;
    for(int i = 0; i < A.size(); i++) {
        unordered_map<int, int> mp;
        vector<int> sum(A[0].size(), 0);
        int t = 0;
        mp[0]++;
        for(int j = i + 1; j < A.size(); j++) {
            for(int k = 0; k < A[0].size(); k++) { 
                sum[k] += A[j][k];
                t += sum[k];
                cnt += mp[t - K];
                mp[t]++;
            }
        }
    }
    return cnt;
}

