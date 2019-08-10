#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[66][11][11];

int f(int R, int W, int B) {
	if(W < 0)
		return 0;
	if(B == 0)
		return (R == 0);
	if(dp[R][W][B] != -1)
		return dp[R][W][B];
	int ans = f(R, W - 1, B - 1) % MOD;
	for(int i = 0; i <= 4; i++) {
		ans += f(R - i, W, B - 1);
		ans %= MOD;
	}
	ans += f(R - 6, W, B - 1);
	return dp[R][W][B] = ans % MOD;
}

int main() {
	int t;
	cin >> t;
	memset(dp, -1, sizeof dp);
	while(t--) {
		int R, W, B;
		cin >> R >> B >> W;
		cout << f(R, W, B) << endl;
	}
}
