#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), dp(n, 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            if((a[i] > 0) ^ (a[i + 1] > 0) == 1) {
                dp[i] = dp[i + 1] + 1;
            }
            else 
                dp[i] = 1;
        }
        for(int i = 0; i < n; i++)
            cout << dp[i] << " ";
        cout << endl;    
    }
	return 0;
}

