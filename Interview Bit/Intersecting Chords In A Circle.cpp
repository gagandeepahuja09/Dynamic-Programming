#define MOD 1000000007
#define ll long long int

ll f(ll i, vector<ll>& dp) {
    if(i == 0 || i == 2)
        return 1;
    if(dp[i] != -1)
        return dp[i];
    ll ans = 0;    
    for(int k = 2; k <= i; k += 2) {
        ans = (ans % MOD + ((f(k - 2, dp) % MOD * f(i - k, dp)) % MOD) % MOD) % MOD;
    }
    return dp[i] = ans;
}

int Solution::chordCnt(int A) {
    vector<ll> dp(2 * A + 1, -1);
    return (int)f(2 * A, dp);
}

