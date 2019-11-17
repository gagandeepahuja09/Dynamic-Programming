class Solution {
public:
    map<pair<int, vector<bool>>, int> mp;
    int dfs(int N, int i, vector<bool>& vis) {
        if(i > N)
            return 1;
        int ans = 0;
        if(mp.count({ i , vis }))
            return mp[{ i, vis }];
        for(int num = 1; num <= N; num++) {
            if(vis[num])
                continue;
            if(num % i == 0 || i % num == 0) {
                vis[num] = true;
                ans += dfs(N, i + 1, vis);
                vis[num] = false;
            }
        }
        return mp[{ i, vis }] = ans;
    }
    
    int countArrangement(int N) {
        if(N <= 0)
            return 0;
        vector<bool> vis(N, false);
        return dfs(N, 1, vis);
    }
};
