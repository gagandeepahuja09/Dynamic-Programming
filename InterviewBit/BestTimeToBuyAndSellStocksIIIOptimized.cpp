int Solution::maxProfit(const vector<int> &A) {
    int a[4];
    a[0] = INT_MIN, a[1] = 0, a[2] = INT_MIN, a[3] = 0;
    for(auto curr : A) {
        a[0] = max(a[0], 0 - curr);
        a[1] = max(a[1], a[0] + curr);
        a[2] = max(a[2], a[1] - curr);
        a[3] = max(a[3], a[2] + curr);
    }
    return max(a[1], a[3]);
}
