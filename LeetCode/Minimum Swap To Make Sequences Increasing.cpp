class Solution {
public:
    int dp[1001][2];
    int f(vector<int>& A, vector<int>& B, int i, int prevA, int prevB, bool swapped) {
        if(i == A.size())
            return 0;
        if(dp[i][swapped] != -1)
            return dp[i][swapped];
        int steps = INT_MAX;
        if(A[i] > prevA && B[i] > prevB) {
            steps = f(A, B, i + 1, A[i], B[i], 0);
        }
        if(A[i] > prevB && B[i] > prevA) {
            steps = min(1 + f(A, B, i + 1, B[i], A[i], 1), steps);
        }
        return dp[i][swapped] = steps;
    }
    
    int minSwap(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof dp);
        return f(A, B, 0, -1, -1, 0);
    }
};
