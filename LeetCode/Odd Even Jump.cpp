class Solution {
public:
    int dp[20001][2];
    int f(vector<int>& A, int i, vector<int>& upper, vector<int>& lower, bool odd) {
        if(i == A.size() - 1) {
            return 1;
        }
        int ans = 0;
        if(dp[i][odd] != -1)
            return dp[i][odd];
        if(odd) {
            if(upper[i] != -1) {
                ans += f(A, upper[i], upper, lower, !odd);
            }
        }
        else {
            if(lower[i] != -1) {
                ans += f(A, lower[i], upper, lower, !odd);
            }
        }
        return dp[i][odd] = ans;
    }
    
    int oddEvenJumps(vector<int>& A) {
        int ans = 0;
        int n = A.size();
        memset(dp, -1, sizeof dp);
        vector<int> lower(n, -1), upper(n, -1);
        map<int, int> mp;
        for(int i = n - 1; i >= 0; i--) {
            auto up = mp.upper_bound(A[i]); // 1st ele > val
            auto down = mp.lower_bound(A[i]); // 1st ele >= val
            if(down != mp.end() && down -> first == A[i]) {
                lower[i] = upper[i] = down -> second;
            }
            else {
                if(up != mp.end()) {
                    upper[i] = up -> second;
                }
                if(down != mp.begin()) {
                    down--;
                    lower[i] = down -> second;
                }
            }
            // cout << upper[i] << " " << lower[i] << endl;
            mp[A[i]] = i;
        }
        for(int i = 0; i < A.size(); i++) {
            ans += f(A, i, upper, lower, true);
        }
        return ans;
    }
};
