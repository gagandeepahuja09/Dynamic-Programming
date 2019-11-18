class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        int n = A.size();
        if(!n)
            return {};
        int dp[n], pre[n], mx = 0, index = -1;
        sort(A.begin(), A.end());
        for(int i = 0; i < n; i++) {
            pre[i] = -1;
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if((A[i] % A[j]) == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    pre[i] = j;
                }
            }
            if(dp[i] > mx) {
                mx = dp[i];
                index = i;
            }
        }
        vector<int> ret;
        while(index != -1) {
            ret.push_back(A[index]);
            index = pre[index];
        }
        return ret;
    }
};
