class Solution {
public:
    long dp[50001][2];
    long f(vector<int>& A, int i, int score, bool aturn) {
        if(i == A.size())
            return 0;
        if(dp[i][aturn] != -1)
            return dp[i][aturn];
        long a;
        if(aturn) {
            long op1 = -1e14, op2 = -1e14, op3 = -1e14;
            op1 = A[i] + f(A, i + 1, score, !aturn);
            if(i + 1 < A.size())
                op2 = A[i] + A[i + 1] + f(A, i + 2, score, !aturn);
            if(i + 2 < A.size())
                op3 = A[i] + A[i + 1] + A[i + 2] + f(A, i + 3, score, !aturn);
            long ans = max(op1, max(op2, op3));
            a = ans;
        }
        else {
            long op1 = 1e14, op2 = 1e14, op3 = 1e14;
            op1 = -A[i] + f(A, i + 1, score, !aturn);
            if(i + 1 < A.size())
                op2 = -A[i] - A[i + 1] + f(A, i + 2, score, !aturn);
            if(i + 2 < A.size())
                op3 = -A[i] - A[i + 1] - A[i + 2] + f(A, i + 3, score, !aturn);
            long ans = min(op1, min(op2, op3));
            a = ans;
        }
        return dp[i][aturn] = a;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof dp);
        int score = f(stoneValue, 0, 0, 1);
        if(score < 0)
            return "Bob";
        if(score > 0)
            return "Alice";
        return "Tie";
    }
};
