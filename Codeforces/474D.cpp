#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 100005


ll t, k;

ll f(ll a) {
    if(a == 0) {
        return 1;
    }
    if(a < 0) {
        return 0;
    }
    return f(a - 1) + f(a - k);
}

int main() {
    cin >> t >> k;
    ll dp[MAX];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= MAX; i++) {
        dp[i] = dp[i - 1] % MOD;
        if(i >= k)
            dp[i] = (dp[i] % MOD + dp[i - k] % MOD) % MOD;
    }
    for(int i = 1; i <= MAX; i++) {
        dp[i] = (dp[i - 1] % MOD + dp[i] % MOD) % MOD;
    }
    while(t--) {
        ll a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + MOD) % MOD << endl;
    }
    // cout << f(1) << " " << f(2) << " " << f(3) << " " << f(4) << endl;
}
