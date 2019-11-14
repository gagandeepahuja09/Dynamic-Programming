class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& m) {
        int A[N][N];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                A[i][j] = 1;
            }
        }
        for(int i = 0; i < m.size(); i++) {
            A[m[i][0]][m[i][1]] = 0; 
        }
        vector<vector<int>> top(N, vector<int>(N, 0)), left(N, vector<int>(N, 0)), right(N, vector<int>(N, 0)),
        bottom(N, vector<int>(N, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][j] == 0) {
                    // top[i][j] = 0; left[i][j] = 0;
                    continue;
                }
                else {
                    top[i][j] = 1 + (i > 0 ?  top[i - 1][j] : 0);
                    left[i][j] = 1 + (j > 0 ? left[i][j - 1] : 0);
                }
            }
        }
        int mx = 0;
        for(int i = N - 1; i >= 0; i--) {
            for(int j = N - 1; j >= 0; j--) {
                if(A[i][j] == 0) {
                    // bottom[i][j] = 0; right[i][j] = 0;
                    continue;
                }
                else {
                    bottom[i][j] = 1 + (i < N - 1 ? bottom[i + 1][j] : 0);
                    right[i][j] = 1 + (j < N - 1 ? right[i][j + 1] : 0);
                }
                // cout << left[i][j] << " " << right[i][j] << " " << top[i][j] << " " << bottom[i][j] << endl;
                mx = max(mx, min(min(left[i][j], right[i][j]), min(top[i][j], bottom[i][j])));
            }
        }
        return mx;
    }
};
