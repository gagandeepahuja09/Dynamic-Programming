#define ll long long int

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<ll> dp;
    ll f(string &s, int i) {
        if(i == s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        ll ans = 0;
        if(s[i] >= '1' && s[i] <= '9')
            ans = (ans % MOD + f(s, i + 1) % MOD) % MOD;
        if(s[i] == '*')
            ans = (ans % MOD + (9 * f(s, i + 1)) % MOD) % MOD;
        if(i < s.size() - 1) {
            if((s[i] == '1' && s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')) {
                ans = (ans % MOD + f(s, i + 2) % MOD) % MOD;
            }
            else if(s[i] == '1' && s[i + 1] == '*') {
                ans = (ans % MOD + (9 * f(s, i + 2)) % MOD) % MOD;
            }
            else if(s[i] == '2' && s[i + 1] == '*') {
                ans = (ans % MOD + (6  * f(s, i + 2)) % MOD) % MOD;
            }
            else if(s[i] == '*' && s[i + 1] == '*') {
                ans = (ans % MOD + (15 * f(s, i + 2)) % MOD) % MOD;
            }
            else if(s[i] == '*' && s[i + 1] >= '0' && s[i + 1] <= '6') {
                ans = (ans % MOD + (2 * f(s, i + 2)) % MOD) % MOD;
            }
            else if(s[i] == '*' && s[i + 1] >= '7' && s[i + 1] <= '9') {
                ans = (ans % MOD + f(s, i + 2) % MOD) % MOD;
            }
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        dp.clear();
        dp.resize(s.size(), -1);
        if (s.size() > 1000) {
            int idx = s.size() - 1000;
            while (idx >= 0) {
                f(s, idx);
                if (idx == 0) {
                    idx = -1;
                } 
                else {
                    idx -= 1000;
                    idx = std::max(idx, 0);
                }
            }
        }
        return f(s, 0);
    }
};
