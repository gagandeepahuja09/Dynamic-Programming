class Solution {
public:
    long dp[102][102][101];
    const long MOD = 1e9 + 7;
    long f(int currG, int currP, int i, vector<int>& g, vector<int>& p) {
        if(i == g.size())
            return (currG >= 0 && currP <= 0);
        if(currG < -1)   currG = -1;
        if(currP < -1)   currP = -1;
        if(dp[currG + 1][currP + 1][i] != -1)
            return dp[currG + 1][currP + 1][i];
        long op1 = f(currG, currP, i + 1, g, p);
        long op2 = f(currG - g[i], currP - p[i], i + 1, g, p);
        return dp[currG + 1][currP + 1][i] = (op1 + op2) % MOD;
    }
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof dp);
        return (int)f(G, P, 0, group, profit);
    }
};
