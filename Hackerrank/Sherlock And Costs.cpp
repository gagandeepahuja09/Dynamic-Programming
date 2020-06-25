#include <bits/stdc++.h>
using namespace std;

int dp[2][100001];

int cost(vector<int>& B, int i = 0, int prev = -1) {
    
    if(i == B.size())   return 0;
    if(prev == -1) {
        return max(cost(B, i + 1, 1), cost(B, i + 1, 0));
    }
    if(dp[prev][i] != -1)   return dp[prev][i];
    int ele = 1;
    if(prev == 0)   ele = B[i - 1];
    int op1 = abs(B[i] - ele) + cost(B, i + 1, 0);
    int op2 = abs(1 - ele) + cost(B, i + 1, 1);
    return dp[prev][i] = max(op1, op2);
}

int main()
{    
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        int n;
        cin >> n;
        vector<int> B(n);
        for(int i = 0; i < n; i++)  cin >> B[i];
        int result = cost(B);
        cout << result << endl;
    }
    return 0;
}
