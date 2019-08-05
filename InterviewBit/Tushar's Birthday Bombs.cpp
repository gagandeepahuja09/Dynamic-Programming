

    vector<int> Solution::solve(int A, vector<int> &B) { 
        int mn = INT_MAX, pos = -1, n = B.size();
        for(int i = 0; i < n; i++) {
            if(B[i] < mn) {
                mn = B[i];
                pos = i;
            }
        }
        int maxKick = A / mn;
        vector<int> ret;
        for(int i = 0; i < maxKick; i++)
            ret.push_back(pos);
        int rem = A - (maxKick * mn);
        int i = 0, j = 0;
        while(i < maxKick) {
            pos = ret[i];
            int idx = -1;
            for(j = 0; j < n; j++) {
                if(rem - B[j] + B[pos] >= 0) {
                    rem = rem - B[j] + B[pos];
                    break;
                }
            }
            if(j == n)
                break;
            ret[i] = j;
            i++;
        }
        return ret;
    }


