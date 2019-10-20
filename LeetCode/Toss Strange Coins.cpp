class Solution {
public:
    double f(vector<double>& prob, int i, int target, vector<vector<double>>& dp) {
        if(i == prob.size())
            return (target == 0) ? 1.0 : 0.0;
        if(dp[i][target] != -1.0f)
            return dp[i][target];
        double op1 = 0.0;
        if(target)
            op1 = prob[i] * f(prob, i + 1, target - 1, dp);
        double op2 = (1 - prob[i]) * f(prob, i + 1, target, dp);
        return  dp[i][target] = op1 + op2;
    }
    
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n, vector<double>(target + 1, -1.0));
        return f(prob, 0, target, dp);
    }
};
