#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll maxPro = a[0], minPro = a[0], ret = maxPro;
        for(int i = 1; i < n; i++) {
            if(a[i] < 0)
                swap(maxPro, minPro);
            maxPro = max(a[i], maxPro * a[i]);
            minPro = min(a[i], minPro * a[i]);
            ret = max(ret, maxPro);
        }
        cout << ret << endl;
    }
	return 0;
}
