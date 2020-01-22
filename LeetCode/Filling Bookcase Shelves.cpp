class Solution {
public:
    int dp[1001][1001];
    int W;
    int f(vector<vector<int>>& A, int i = 0, int w = 0, int h = 0) {
        if(i == A.size())
            return h;
        if(dp[i][w] != -1)
            return dp[i][w];
        int op1 = h + f(A, i + 1, A[i][0], A[i][1]);
        int op2 = INT_MAX;
        if(A[i][0] + w <= W) {
            op2 = f(A, i + 1, A[i][0] + w, max(h, A[i][1]));
        }
        return dp[i][w] = min(op1, op2);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int width) {
        W = width;
        memset(dp, -1, sizeof dp);
        return f(books);
    }
};
