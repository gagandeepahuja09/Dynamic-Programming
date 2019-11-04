#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 2002

ll n, k;

ll dp[MAX][MAX];

ll f(ll num, ll k) {
    if(k == 0)
        return 1;
    if(dp[num][k] != -1)
        return dp[num][k];
    ll ans = 0;    
    for(ll i = num; i <= n; i += num) {
        ans = (ans % MOD + f(i, k - 1) % MOD) % MOD;
    }
    return dp[num][k] = ans;
}

int main() {
    // ll t;
    // cin >> t; while(t--) {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        ans = (ans % MOD + f(i, k - 1) % MOD) % MOD;
    }
    cout << ans << endl;
    // }
}
