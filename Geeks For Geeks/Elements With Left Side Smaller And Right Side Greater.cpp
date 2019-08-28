#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), largest(n), smallest(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i == 0)
                largest[i] = a[i];
            if(i > 0)
                largest[i] = max(largest[i - 1], a[i]);
        }
        smallest[n - 1] = a[n - 1];
        int ret = -1;
        for(int i = n - 2; i >= 0; i--) {
            smallest[i] = min(smallest[i + 1], a[i]);
        }
        for(int i = 1; i < n - 1; i++) {
            if(a[i] >= largest[i - 1] && a[i] <= smallest[i + 1]) {
                ret = a[i];
                break;
            }
        }
        cout << ret << endl;
    }
	return 0;
}
