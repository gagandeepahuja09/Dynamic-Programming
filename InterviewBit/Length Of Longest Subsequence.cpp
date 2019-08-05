int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size(), mx = 0;
    vector<int> lis(n + 1, 1);
    vector<int> lds(n + 1, 1);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(A[i] <= A[j] && lis[j] < lis[i] + 1)
                lis[j] = lis[i] + 1;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(A[j] >= A[i] && lds[j] < lds[i] + 1)
                lds[j] = lds[i] + 1;
        }
    }
}

