int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    /*
    // My Solution
    // d - c + c - b + b - a = d - a
    for(int i=1; i<A.size(); i++) {
        ans += max(0, A[i] - A[i-1]);
    }*/
    // LeetCode : Peak And Valley Approach
    int i = 0, valley = A[0], peak = A[0];
    if(!A.size())
        return 0;
    while(i < A.size() - 1) {
        while(i < A.size() - 1 && A[i] >= A[i+1])
            i++;
        valley = A[i];
        while(i < A.size() - 1 && A[i] <= A[i+1])
            i++;
        peak = A[i];
        ans += (peak - valley);
    }
    return ans;
}

