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

class Solution {
public:
    double dp[101][101];
    double f(vector<double>& sum, int i, int K) {
        if(K == 1) {
            int j = sum.size() - 1;
            dp[i][K] = (sum[j] - (i == 0 ? 0 : sum[i - 1])) / (double)(j - i + 1);
            return dp[i][K];
        }
        if(dp[i][K] != -1.0)
            return dp[i][K];
        double ans = 0;
        for(int j = i; j + K <= sum.size(); j++) {
            double avg = (sum[j] - (i == 0 ? 0 : sum[i - 1])) / (double)(j - i + 1);
            ans = max(ans, avg + f(sum, j + 1, K - 1));
        }
        return dp[i][K] = ans;
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> sum(n, 0);
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                dp[i][j] = -1.0;
            }
        }
        sum[0] = A[0];
        for(int i = 1; i < A.size(); i++)
            sum[i] = A[i] + sum[i - 1];
        return f(sum, 0, K);
    }
};
