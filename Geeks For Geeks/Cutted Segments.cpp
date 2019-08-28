#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int x, y, z, dp[4001];

int maxCuts(int n) {
    if(n == 0)
        return 0;
    if(n < 0)
        return -1e5;
    if(dp[n] != -1)
        return dp[n];
    int op1 = maxCuts(n - x), op2 = maxCuts(n - y),
    op3 = maxCuts(n - z);
    return dp[n] = 1 + max(op1, max(op2, op3));    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        int n;
        cin >> n >> x >> y >> z;
        cout << maxCuts(n) << endl;
    }
	return 0;
}
