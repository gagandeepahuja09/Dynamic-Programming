#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    int v[n];
	    bool dp[1025] = {0};
	    dp[0] = 1;
	    for(int i = 0; i < n; i++)
	        cin >> v[i];
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j <= 1024; j++) {
	            dp[j ^ v[i]] = dp[j] | dp[j ^ v[i]];
	        }
	    }
	    int mx = 0;
	    for(int i = 0; i <= 1024; i++) {
	        if(dp[i])
	            mx = max(mx, i ^ k);
	    }
	    cout << mx << endl;
	}
	return 0;
}

