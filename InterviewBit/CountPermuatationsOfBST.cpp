/*#define ll long long int
#define MOD 1000000007

ll dp[51][51];
ll choose[102][102];

void build(int N) {
    choose[0][0] = 1;
    for(int i = 1; i <= 2 * N; i++) {
        choose[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i - 1][j] % MOD + choose[i - 1][j - 1] % MOD) % MOD;
        }
    }
}

ll ways(int N, int M) {
    if(M < 0)
        return 0;
    if(N <= 1)
        return (M == 0);
    ll ret = dp[N][M];
    if(ret != -1)
        return ret;
    ret = 0;    
    for(int i = 1; i <= N; i++) {
        int x = i - 1, y = N - x - 1;
        
        for(int j = 0; j <= M - 2; j++) {
            ret = ret % MOD + (ways(x, j) % MOD * ways(y, M - 1) % MOD) % MOD;
            ret = ret % MOD + (ways(x, M - 1) % MOD * ways(y, j) % MOD) % MOD;    
        }
        ret = ret % MOD + (ways(x, M - 1) % MOD * ways(y, M - 1) % MOD) % MOD;
        ret = (ret % MOD * choose[x + y][x] % MOD) % MOD;
        return dp[N][M] = ret;
    }
}

int Solution::cntPermBST(int N, int M) {
    memset(dp, -1, sizeof dp);
    memset(choose, 0, sizeof choose);
    build(N);
    return (int)ways(N, M);
}
*/

#define MOD 1000000007ll
typedef long long LL;

//adds y to x, modulo MOD
void add(int &x, int y){
    x += y;
    if(x>=MOD)x-=MOD;
}

//choose and dp tables
vector< vector<int > > choose,dp;

//build choose table
void build(int N){
    choose[0][0]=1;
    for(int i=1; i<=2*N; i++){
        choose[i][0]=1;
        for(int j=1; j<=i; j++){
            choose[i][j]=choose[i-1][j];
            add(choose[i][j], choose[i-1][j-1]);
        }
    }
}

//reccurence function as defined in hint_2
int rec(int n, int h){ 
    if(n<=1)return (h==0);
    if(h<0)return 0;
    int &ret=dp[n][h];
    if(ret!=-1)return ret;
    ret=0;
    int x, y;
    for(int i=1; i<=n; i++){
        x=i-1;
        y=n-x-1;
        int sum1=0,sum2=0,ret1=0;
        for(int j=0; j<=h-2; j++) {
            add(sum1, rec(x, j));
            add(sum2, rec(y, j));
        }
        add(ret1, ((LL)sum1*(LL)rec(y, h-1))%MOD);
        add(ret1, ((LL)sum2*(LL)rec(x, h-1))%MOD);
        add(ret1, ((LL)rec(x, h-1)*(LL)rec(y, h-1))%MOD);
        ret1 = ((LL)ret1*(LL)choose[x+y][y])%MOD;
        add(ret, ret1);
    }
    return ret;
}

int Solution::cntPermBST(int A, int B) {
    int n=50;
    choose.clear();
    dp.clear();
    choose.resize(2*n+1,vector<int>(2*n+1, 0));
    dp.resize(n+1,vector<int>(n+1, -1));
    build(n);
    return rec(A, B);
}

