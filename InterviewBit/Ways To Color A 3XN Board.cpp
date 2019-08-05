#define MOD 1000000007
#define ll long long int

ll dp[150001][4][4][4];

struct triplet {
    int x, y, z;
};

ll f(int i, int j, int k, int n, vector<triplet>& trip) {
    if(n == 0)
        return 1;
    if(dp[n][i][j][k] != -1)
        return dp[n][i][j][k];
    ll ans = 0;
    for(int a = 0; a < trip.size(); a++) {
        if(trip[a].x != i && trip[a].y != j && trip[a].z != k) {
            ans = (ans % MOD + f(trip[a].x, trip[a].y, trip[a].z, n - 1, trip) % MOD) % MOD;
        }
    }
    return dp[n][i][j][k] = ans % MOD;
}

int Solution::solve(int A) {
    memset(dp, -1, sizeof dp);
    vector<triplet> trip;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                if(i != j && j != k) {
                    trip.push_back({ i, j, k });
                }
            }
        }
    }
    ll ret = 0;
    for(int i = 0; i < trip.size(); i++) {
        ret = (ret % MOD + f(trip[i].x, trip[i].y, trip[i].z, A - 1, trip) % MOD) % MOD;
    }
    return (int)ret;
}
