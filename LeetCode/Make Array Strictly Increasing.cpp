class Solution {
private:
    map<pair<int, int>, int> mp;
    int dfs(vector<int>& A, vector<int>& B, int i, int prev) {
        if(i == A.size())
            return 0;
        if(mp.count({ i, prev }))
            return mp[{ i, prev }];
        int res = 0;
        int j = upper_bound(B.begin(), B.end(), prev) - B.begin();
        if(A[i] <= prev) {
            if(j >= B.size())
                res = 3000;
            else
                res = 1 + dfs(A, B, i + 1, B[j]);
        }
        else {
            if(j >= B.size() || B[j] >= A[i]) {
                res = dfs(A, B, i + 1, A[i]);
            }
            else {
                res = min(dfs(A, B, i + 1, A[i]), 1 + dfs(A, B, i + 1, B[j]));
            }
        }
        return mp[{ i, prev }] = res;
    }
    
public:    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() <= 1)
            return 0;
        mp.clear();
        sort(arr2.begin(), arr2.end());
        int ret = dfs(arr1, arr2, 0, -1); 
        return ret >= 3000 ? -1 : ret;
    }
};
