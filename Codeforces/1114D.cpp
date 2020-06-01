#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'
#define N 300002
 
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(v.empty() || x != v.back())
                v.pb(x);
        }
        int dp[5001][5001];
        for(int r = 0; r < v.size(); r++) {
            for(int l = r; l >= 0; l--) {
                dp[l][r] = 1e9;
                if(l == r) {
                    dp[l][r] = 0;
                }
                else {
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
                    if(v[l] == v[r]) {
                        dp[l][r] = min(dp[l][r], 1 + dp[l + 1][r - 1]);
                    }
                }
            }
        }
        cout << dp[0][v.size() - 1] << endl;
    }
	return 0;
}
