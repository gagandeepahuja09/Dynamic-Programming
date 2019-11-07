#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX1 1001
#define MAX2 101

ll n1, n2, k1, k2;

ll dp[MAX1][MAX1][2];

int main() {
    const ll MOD = 1e8;
    memset(dp, 0, sizeof dp);
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = dp[0][0][1] = 1;
    for(ll i = 0; i <= n1; i++) {
        for(ll j = 0; j <= n2; j++) {
            for(ll k = 1; k <= k1; k++) {
                if(i >= k)
                    dp[i][j][0] = (dp[i][j][0] % MOD + dp[i - k][j][1] % MOD) % MOD;
            }
            for(ll k = 1; k <= k2; k++) {
                if(j >= k)
                    dp[i][j][1] = (dp[i][j][1] % MOD + dp[i][j - k][0] % MOD) % MOD;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD;
	return 0;
}
  
