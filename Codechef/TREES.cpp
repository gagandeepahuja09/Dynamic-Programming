#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> adj[65];
ll way[65][65][2];

ll ways(ll root, ll k, bool selRoot) {
    vis[root] = true;
    if(way[root][k][selRoot] != -1)
        return way[root][k][selRoot];
    ll ans = 0;
    if(selRoot) {
        k--;
        int sz = adj[root].size();
        for(int i = 0; i < sz; i++) {
            int ch = adj[root][i];
            if(!vis[ch]) {
                for(int j = 0; j <= k; j++) {
                    ans += (ways(ch, j, 1) * dp[sz - 1][k - j]);   
                }
            }
        }
    }
    
    else {
        int sz = adj[root].size();
        for(int i = 0; i < sz; i++) {
            ans += ways(ch, k, 1);        
        }
    }
    return way[root][ll][selRoot] = ans;
}

int finddp(int n, int k) {
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        memset(way, -1, sizeof way);
        adj.clear();
        int n, k;
        cin >> n >> k;
        dp[0][0] = 1;
        for(int i = 0; i < n; i++)
            dp[i][0] = 0;
        finddp(n, k); 
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                memset(vis, 0, sizeof vis);
                ans += (ways(i, j, 0) + ways(i, j, 1));
            }
        }
        cout << ans << endl;
    }
}
