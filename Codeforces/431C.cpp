#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 105

ll n, k, d;
ll dp[MAX][2];

ll f(ll n, bool taken) {
    if(n == 0 && taken)
        return 1;
    if(n <= 0)
        return 0;
    if(dp[n][taken] != -1)
        return dp[n][taken];
    ll ans = 0;    
    for(ll i = 1; i <= k; i++) {
        bool tk = taken;
        if(i >= d)
            tk = 1;
        ans = (ans % MOD + f(n - i, tk) % MOD) % MOD;
    }    
    return dp[n][taken] = ans;
}

int main() {
    // ll t;
    // cin >> t; while(t--) {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    cout << f(n, 0) << endl;
    // }
}
