class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> ret(n, 0);
        for(auto &v : b) {
            ret[v[0] - 1] += v[2];
            if(v[1] < n)
                ret[v[1]] -= v[2];
        }
        for(int i = 1; i < n; i++)
            ret[i] += ret[i - 1];
        return ret;
    }
};
