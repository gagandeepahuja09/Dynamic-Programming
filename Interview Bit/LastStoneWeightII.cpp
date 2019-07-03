class Solution {
public:
    int dp[31][6001];
    int f(vector<int>& s, int i, int sum) {
        if(i == s.size()) {
            if(sum < 0)
                return INT_MAX;
            return sum;
        }
        if(dp[i][sum + 3000] != -1)
            return dp[i][sum + 3000];
        int op1 = f(s, i + 1, sum + s[i]);
        int op2 = f(s, i + 1, sum - s[i]);
        return dp[i][sum + 3000] = min(op1, op2);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof dp);
        return f(stones, 0, 0);
    }
};
