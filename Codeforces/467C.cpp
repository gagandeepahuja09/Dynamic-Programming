#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define MAX 5001
 
ll n, m, k;
ll a[MAX];
ll dp[MAX][MAX];
 
ll f(ll i, ll k) {
    if(i >= n) {
        if(k == 0)
            return 0;
        return -1e8;
    }
    if(k == 0)
        return 0;
    if(dp[i][k] != -1)
        return dp[i][k];
    ll op1 = f(i + 1, k);
    ll op2 = 0;
    if(i + m <= n) 
        op2 = a[i + m - 1] - (i > 0 ? a[i - 1] : 0) + f(i + m, k - 1);
    return dp[i][k] = max(op1, op2);
} 
 
int main() {
    cin >> n >> m >> k;
    ll sum = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] = sum;
    }
    cout << f(0, k);
}
