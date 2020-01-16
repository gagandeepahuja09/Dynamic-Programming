class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> pre(n, 0);
        vector<int> suff(n, 0);
        for(int i = 0, j = n - 1; i < n; i++, j--) {
            pre[i] = (i > 0 ? pre[i - 1] : 0) + (s[i] == '1' ? 1 : 0);
            suff[j] = (j < n - 1 ? suff[j + 1] : 0) + (s[j] == '0' ? 1 : 0);
        }
        int ans = min(pre[n - 1], suff[0]);
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, pre[i] + suff[i + 1]);
        }
        return ans;
    }
};
