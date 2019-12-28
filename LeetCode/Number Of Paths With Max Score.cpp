class Solution {
public:
    long MOD;
    pair<int, long> dp[101][101];
    pair<int, long> f(vector<string>& A, int i, int j) {
        int n = A.size(), m = A[0].size();
        if(i >= n || j >= m || A[i][j] == 'X')
            return { -1e5, 0 };
        int val = A[i][j] - '0';
        if(A[i][j] == 'E')
            val = 0;
        if(i == n - 1 && j == m - 1)
            return { 0, 1 };
        pair<int, long> p1 = { -1, -1ll };
        if(dp[i][j] != p1)
            return dp[i][j];
        auto op1 = f(A, i + 1, j);
        auto op2 = f(A, i, j + 1);
        auto op3 = f(A, i + 1, j + 1);
        int cnt = 0;
        int ans = val + max(op1.first, max(op2.first, op3.first));
        if(val + op1.first == ans) cnt += op1.second; cnt %= MOD;
        if(val + op2.first == ans) cnt += op2.second; cnt %= MOD;
        if(val + op3.first == ans) cnt += op3.second; cnt %= MOD;
        return dp[i][j] = { ans, cnt % MOD };
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        MOD = 1e9 + 7;
        pair<int, int> p1 = { -1, -1ll };
        for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++)
                dp[i][j] = p1;
        auto p = f(board, 0, 0);
        if(p.first <= 0)
            p.first = 0;
        return { p.first, (int)p.second };
    }
};
