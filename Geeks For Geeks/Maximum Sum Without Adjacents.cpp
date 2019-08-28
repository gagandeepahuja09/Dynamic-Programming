
int dp[1000001];

int f(vector<int>& a, int i) {
    if(i >= a.size())
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int prev1 = f(a, i + 2);
    int prev2 = f(a, i + 1);
    return dp[i] = 
    max(prev2, max(prev1, prev1 + a[i]));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        memset(dp, -1, sizeof dp);
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        // cout << f(a, 0) << endl;
        if(n == 1)
            cout << a[0] << endl;
        else if(n == 2) {
            cout << max(a[0], a[1]) << endl;
        }
        else {
            int prev1 = a[0], prev2 = max(a[0], a[1]), ans = 0;
            for(int i = 2; i < n; i++) {
                ans = max(ans, max(a[i], prev1 + a[i]));
                ans = max(ans, prev2);
                prev1 = prev2;
                prev2 = ans;
            }
            cout << ans << endl;
        }
    }
	return 0;
}
