int birthdayParty(vector<int> &A, 
int n, const vector<int> &B, const vector<int> &C) {
    if(n == A.size())
        return 0;
        
    if(A[n] == 0)
        return birthdayParty(A, n + 1, B, C);
    int ans = INT_MAX;    
    for(int i = 0; i<B.size(); i++) {
        if(B[i] <= A[n]) {
            A[n] -= B[i];
            ans = min(ans, C[i] + birthdayParty(A, n, B, C));
            A[n] += B[i];
        }
    }
    return ans;
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    vector<int> v = A;
    return birthdayParty(v, 0, B, C);
}

