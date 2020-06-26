#include <bits/stdc++.h>
using namespace std;
#define int long long int


signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        stack<int> stk;
        for(int i = 0; i < n; i++)  cin >> a[i];
        vector<int> grt(n, -1);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && a[i] >= a[stk.top()]) {
                grt[stk.top()] = a[i];
                stk.pop();
            }
            stk.push(i);
        }
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(grt[i] != -1) {
                cnt++;
                ans -= a[i];
            }
            else {
                ans += (a[i] * cnt);
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
}
