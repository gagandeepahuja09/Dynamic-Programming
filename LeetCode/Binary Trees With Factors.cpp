class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size();
        long mod = 1e9 + 7, ans = 0;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for(int i = 0; i < A.size(); i++) {
            dp[A[i]] = 1;
            for(int j = 0; j < i; j++) {
                if(A[i] % A[j] == 0)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
            }
            ans+= dp[A[i]];
            ans %= mod;
        }
        return (int)ans;
    }
};
