class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> overlaps(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int m = min(A[i].size(), A[j].size());
                for(int k = m; k >= 0; k--) {
                    if(A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }
        
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        
        for(int mask = 0; mask < (1 << n); mask++) {
            for(int bit = 0; bit < n; bit++) {
                if(mask & (1 << bit)) {
                    int pmask = mask ^ (1 << bit);
                    if(pmask == 0)
                        continue;
                    for(int i = 0; i < n; i++) {
                        if(pmask & (1 << i)) {
                            if(dp[pmask][i] + overlaps[i][bit] > dp[mask][bit]) {
                                dp[mask][bit] = dp[pmask][i] + overlaps[i][bit];
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }
        
        int mask = (1 << n) - 1;
        int currP = 0;
        for(int i = 1; i < n; i++) {
            if(dp[mask][i] > dp[mask][currP]) {
                currP = i;
            }
        }
        
        vector<int> perm;
        vector<bool> seen(n);
        
        while(currP != -1) {
            perm.push_back(currP);
            seen[currP] = true;
            int newP = parent[mask][currP];
            mask ^= (1 << currP);
            currP = newP;
        }
        
        reverse(perm.begin(), perm.end());
        
        for(int i =0; i < n; i++) {
            if(!seen[i]) {
                perm.push_back(i);
            }
        }
        
        string ret = A[perm[0]];
        for(int i = 1; i < n; i++) {
            int overlap = overlaps[perm[i - 1]][perm[i]];
            ret += A[perm[i]].substr(overlap);
        }
        return ret;
    }
};
