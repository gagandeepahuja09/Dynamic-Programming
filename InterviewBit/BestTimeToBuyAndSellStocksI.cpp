int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    int mn = INT_MAX;
    int maxDiff = 0;
    for(int i=0; i<n; i++) {
        mn = min(mn, A[i]);
        maxDiff = max(maxDiff, A[i] - mn);
    }
    return maxDiff;
}

