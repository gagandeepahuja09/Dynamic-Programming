class Solution {
public:
    int dp[1001][1001] = {};
    int minHeightShelves(vector<vector<int>>& b, int maxW, int i = 0, int h = 0, int w = 0) {
        if(i >= b.size())
            return h;
        if(dp[i][w])
            return dp[i][w];
        int option1 = h + minHeightShelves(b, maxW, i + 1, b[i][1], b[i][0]);
        int option2 = INT_MAX;
        if(maxW >= w + b[i][0]) {
            option2 = minHeightShelves(b, maxW, i + 1, max(b[i][1], h), w + b[i][0]);
        }
        return dp[i][w] = min(option1, option2);
    }
};
