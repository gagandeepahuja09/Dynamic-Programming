class Solution {
public:
    int f(int n, vector<pair<int, pair<int, int>>>& times, vector<int>& dp) {
        if(n == -1)
            return 0;
        if(n == 0)
            return times[0].second.second;
        if(dp[n] != -1)
            return dp[n];
        int i = (upper_bound(times.begin(), times.end(), make_pair(times[n].second.first,make_pair(INT_MAX,INT_MAX)))-times.begin());
        i--;
        int op1 = f(n - 1, times, dp);
        int op2 = f(i, times, dp) + times[n].second.second;
        return dp[n] = max(op1, op2);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pair<int, pair<int, int>>> times;
        for(int i = 0; i < p.size(); i++) {
            times.push_back({ e[i], { s[i], p[i] } });
        }
        sort(times.begin(), times.end());
        vector<int> dp(p.size(), -1);
        return f(s.size() - 1, times, dp);
    }
};
