int minJump(vector<int>& A, int start, int end, vector<int>& dp) {
    if(start >= end) {
        return 0;
    }
    if(dp[start] != -1)
        return dp[start];
    int ans = INT_MAX;
    for(int i = start + 1; i <= start + A[start] && i < A.size(); i++) {
        int nextStep = minJump(A, i, end, dp);
        if(nextStep != INT_MAX)
            ans = min(ans, 1 + nextStep);
    }
    return dp[start] = ans;
} 

int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n + 1, -1);
    int ans = minJump(A, 0, A.size() - 1, dp);
    if(ans != INT_MAX)
        return ans;
    return -1;    
}

