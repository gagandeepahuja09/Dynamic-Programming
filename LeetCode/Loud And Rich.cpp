class Solution {
public:
    pair<int, int> dfs(vector<vector<int>>& adj, int i, vector<int>& quiet, vector<int>& ret, vector<int>& mn) {
        if(ret[i] != -1)
            return { ret[i], mn[i] };
        mn[i] = quiet[i];
        ret[i] = i;
        for(int j = 0; j < adj[i].size(); j++) {
            auto jans = dfs(adj, adj[i][j], quiet, ret, mn);
            if(jans.second < mn[i]) {
                mn[i] = jans.second;
                ret[i] = jans.first;
            }
        }
        return { ret[i], mn[i] };
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> ret(n, -1);
        vector<int> mn(n);
        for(int i = 0; i < richer.size(); i++) {
            int u = richer[i][0], v = richer[i][1];
            adj[v].push_back(u);
        }
        for(int i = 0; i < n; i++) {
            ret[i] = dfs(adj, i, quiet, ret, mn).first;
        }
        return ret;
    }
};
