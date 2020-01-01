class Solution {
public:
    int dp[501][501][2];
    int f(vector<int>& A, int l, int r, bool alexTurn) {
        if(l > r) {
            return 0;
        }
        if(dp[l][r][alexTurn] != -1)
            return dp[l][r][alexTurn];
        int score = 0;
        if(alexTurn) {
            score = max(f(A, l + 1, r, !alexTurn) + A[l], f(A, l, r - 1, !alexTurn) + A[r]);
        }
        else {
            score = min(f(A, l + 1, r, !alexTurn) - A[l], f(A, l, r - 1, !alexTurn) - A[r]);
        }
        return dp[l][r][alexTurn] = score;
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        return f(piles, 0, piles.size() - 1, 1) >= 0;
        // return true;
    }
};
