class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(memo, 0, sizeof(memo));
        int n = A.size();
        double curr = 0;
        for(int i = 0; i < n; i++) {
            curr += A[i];
            memo[i + 1][1] = curr / (i + 1);
        }
        return search(n, K, A);
    }
    
    double search(int n, int k, vector<int>& A) {
        if(memo[n][k] > 0)
            return memo[n][k];
        if(n < k)
            return 0;
        double curr = 0;
        for(int i = n - 1; i > 0; i--) {
            curr += A[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, A) + curr / (double)(n - i));
        }
        return memo[n][k];
    }
};
