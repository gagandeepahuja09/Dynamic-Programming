#define ll long long int
#define MOD 1000000007

class Solution {
public:
    int dp[100001][2][2][2];
    ll f(int n, bool abs, bool prev, bool prevprev) {
        if(n == 0)
            return 1;
        ll op1 = 0, op2 = 0, op3 = 0;
        if(dp[n][abs][prev][prevprev] != -1)
            return dp[n][abs][prev][prevprev];
        if(!abs)
            op1 = f(n - 1, 1, false, prev);
        op2 = f(n - 1, abs, false, prev);
        if(prev && prevprev) {
            op3 = 0;
        }
        else
            op3 = f(n - 1, abs, true, prev);
        return dp[n][abs][prev][prevprev] = (op1 % MOD + op2 % MOD + op3 % MOD) % MOD;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        return (int)f(n, 0, false, false);
    }
};
