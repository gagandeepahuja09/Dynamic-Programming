#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> h(n), k(n);
	    for(int i = 0; i < n; i++)
	        cin >> h[i];
	    for(int i = 0; i < n; i++)
	        cin >> k[i];    
	    int mx = *max_element(h.begin(), h.end()); 
	    vector<int> dp(2 * mx + 1, 1e5);
	    dp[0] = 0;
	    for(int i = 0; i < n; i++) {
	        for(int j = k[i]; j <= 2 * mx; j++) {
	            dp[j] = min(dp[j], dp[j - k[i]] + 1);
	        }
	    }
	    int ans = 0;
	    for(int i = 0; i < n; i++)
	        ans += dp[2 * h[i]];
	    cout << ans << endl; 
	}
	return 0;
}

