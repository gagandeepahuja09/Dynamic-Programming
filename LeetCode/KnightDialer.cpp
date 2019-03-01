#define ll long long int
#define MOD 1000000007

class Solution {
public:
    ll knightDial(int i, int j, int N, ll dp[][4][3]) {
        if(i > 3 || i < 0 || j > 2 || j < 0 || (i == 3 && j != 1))
            return 0;
        if(N == 1)
            return 1;
        if(dp[N][i][j] > -1)
            return dp[N][i][j];
        vector<int> dx = {1,  1, -1, -1, 2,  2, -2, -2};
        vector<int> dy = {2, -2, -2,  2, 1, -1,  1, -1};
        ll ans = 0;
        for(int x=0; x<8; x++) {
            ans = (ans%MOD + knightDial(i + dx[x], j + dy[x], N-1, dp)%MOD)%MOD;
        }
        return dp[N][i][j] = ans;
    }
    
    int knightDialer(int N) {
        ll ans = 0;
        ll dp[N + 1][4][3];
        memset(dp, -1, sizeof dp);
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if(i == 3 && j != 1)
                    continue;
                ans = (ans%MOD + knightDial(i, j, N, dp)%MOD)%MOD;
            }
        }
        return (int)ans;
    }
};