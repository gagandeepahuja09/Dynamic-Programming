class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> currRow(n, 0);
        vector<int> nextRow(triangle[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                currRow[j] = triangle[i][j] + min(nextRow[j], nextRow[j + 1]);
            }
            swap(currRow, nextRow);
        }
        return nextRow[0];
    }
};
