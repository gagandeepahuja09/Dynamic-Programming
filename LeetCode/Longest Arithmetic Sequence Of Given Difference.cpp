class Solution {
public:
    int longestSubsequence(vector<int>& A, int d) {
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i = 0; i < A.size(); i++) {
            mp[A[i]] = (mp.count(A[i] - d) ? mp[A[i] - d] : 0) + 1;
            mx = max(mx, mp[A[i]]);
        }
        return mx;
    }
};
