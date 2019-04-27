#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char a[n + 1][n + 1];
        int rsum[n + 1][n + 1];
        int csum[n + 1][n + 1];
        memset(rsum, 0, sizeof rsum);
        memset(csum, 0, sizeof csum);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                rsum[i][j] += (rsum[i][j + 1] + (a[i][j] == '#'));
                csum[i][j] += (csum[i + 1][j] + (a[i][j] == '#'));
                if(!rsum[i][j] && !csum[i][j])
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
	return 0;
}

