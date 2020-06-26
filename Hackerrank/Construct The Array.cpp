#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int MOD = 1e9 + 7;

signed main() {
    int n, k, x;
    cin >> n >> k >> x;
    int dp[n + 1][2];
    if(x == 1) {
        dp[1][1] = 1;
        dp[1][0] = 0;
    }
    else {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][0] % MOD;
        dp[i][0] = ((k - 1) * (dp[i - 1][0] + dp[i - 1][1])) % MOD;
        dp[i][0] = (dp[i][0] - dp[i][1] + MOD) % MOD;
    }
    cout << dp[n][1];
}
