#define ll long long int

int f(string s, int i, int k, vector<vector<int>>& dp) {
    if(i == s.size()) {
        return k == 0 ? 0 : 1e9;
    }
    if(dp[i][k] != -1)
        return dp[i][k];
    int ans = INT_MAX;
    int nW = 0, nB = 0;
    for(int j = i; j < s.size(); j++) {
        if(s[j] == 'W')
            nW++;
        else
            nB++;
        if(k) {    
            int curr = (nW * nB) + f(s, j + 1, k - 1, dp);
            ans = min(ans, curr);
        }
    }
    if(!k)
        return (nW * nB);
    return dp[i][k] = ans;
}

int Solution::arrange(string A, int B) {
    if(B > A.size())
        return -1;
    vector<vector<int>> dp(A.size() + 1, vector<int>(B + 1, -1));
    return f(A, 0, B - 1, dp);
}

