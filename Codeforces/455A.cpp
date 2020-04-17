#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MX 100005

ll dp[MX], cnt[MX];

ll f(ll n) {
    if(n < 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    ll op1 = f(n - 1);
    ll op2 = (n * cnt[n]) + f(n - 2);
    return dp[n] = max(op1, op2);
}
 
int main() {
    ll n, mx = -1;
    cin >> n;
    memset(cnt, 0, sizeof dp);
    memset(dp, -1, sizeof dp);
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mx = max(mx, x);
        cnt[x]++;
    }
    cout << f(MX - 1);
}
