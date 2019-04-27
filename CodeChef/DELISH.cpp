#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n), mxL(n, 0), mxR(n, 0), mnL(n, 0), 
        mnR(n, 0); 
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        mxL[0] = mnL[0] = v[0];
        for(int i = 1; i < n; i++) {
            mxL[i] = max(mxL[i - 1] + v[i], v[i]);
            mnL[i] = min(mnL[i - 1] + v[i], v[i]);
        }
        mxR[n - 1] = v[n - 1], mnR[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            mxR[i] = max(mxR[i + 1] + v[i], v[i]);
            mnR[i] = min(mnR[i + 1] + v[i], v[i]);
        }
        ll maxDiff = 0;
        for(int i = 0; i < n - 1; i++) {
            maxDiff = max(maxDiff, abs(mxL[i] - mnR[i + 1]));
            maxDiff = max(maxDiff, abs(mxR[i + 1] - mnL[i]));
        }
        cout << maxDiff << endl;
    }
	return 0;
}
