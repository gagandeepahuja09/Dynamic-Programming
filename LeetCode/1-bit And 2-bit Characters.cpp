class Solution {
public:
    int dp[1001];
    bool f(vector<int>& bits, int i) {
        if(i < 0)
            return true;
        if(dp[i] != -1)
            return dp[i];
        bool op1 = false, op2 = false;
        if(i >= 1) {
            if(bits[i] == 1 && bits[i - 1] == 1)
                return f(bits, i - 2);
            if(bits[i] == 0 && bits[i - 1] == 1)
                op1  = f(bits, i - 2);
        }
        if(bits[i] == 0)
            op2 = f(bits, i - 1);
        return dp[i] = op1 | op2; 
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.back() == 1)
            return false;
        memset(dp, -1, sizeof dp);
        return f(bits, bits.size() - 2);
    }
};
