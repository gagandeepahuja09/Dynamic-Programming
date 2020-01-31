class Solution {
public:
    int dp[501][501];
    int f(vector<int>& A, int i, int j, bool alexTurn) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int score = 0;
        if(alexTurn) {
            int op1 = A[i] + f(A, i + 1, j, !alexTurn);
            int op2 = A[j] + f(A, i, j - 1, !alexTurn);
            score = max(op1, op2);
        }
        else {
            int op1 = -A[i] + f(A, i + 1, j, !alexTurn);
            int op2 = -A[j] + f(A, i, j - 1, !alexTurn);
            score = min(op1, op2);    
        }
        return dp[i][j] = score;
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return f(piles, 0, piles.size() - 1, 1) >= 0;
    }
};
