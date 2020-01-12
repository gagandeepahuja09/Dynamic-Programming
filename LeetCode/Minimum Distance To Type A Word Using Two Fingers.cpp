class Solution {
public:
    vector<vector<char>> mat;
    int dp[300][7][7][7][7];
    
    int move(int x1, int y1, int x2, int y2) {
        if(x1 == -1 && y1 == -1)
            return 0;
        return abs(x2 - x1) + abs(y2 - y1);
    }
    
    pair<int, int> pos(char c) {
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == c) {
                    return { i, j };
                } 
            }
        }
        return { -10, -10 };
    }
    
    int f(string s, int i, int f1x, int f1y, int f2x, int f2y) {
        if(i == s.size())
            return 0;
        if(dp[i][f1x + 1][f1y + 1][f2x + 1][f2y + 1] != -1)
            return dp[i][f1x + 1][f1y + 1][f2x + 1][f2y + 1];
        pair<int, int> p = pos(s[i]);
        int cx = p.first, cy = p.second;
        int op1 = move(f1x, f1y, cx, cy) + f(s, i + 1, cx, cy, f2x, f2y);
        int op2 = move(f2x, f2y, cx, cy) + f(s, i + 1, f1x, f1y, cx, cy);
        return dp[i][f1x + 1][f1y + 1][f2x + 1][f2y + 1] = min(op1, op2);
    }
    
    int minimumDistance(string word) {
        mat = {
            {
                'A', 'B', 'C', 'D', 'E', 'F'
            },
            {
                'G', 'H', 'I', 'J', 'K', 'L'
            },
            {
                'M', 'N', 'O', 'P', 'Q', 'R'
            },
            {
                'S', 'T', 'U', 'V', 'W', 'X'
            },
            {
                'Y', 'Z'
            },
        };
        memset(dp, -1, sizeof dp);
        return f(word, 0, -1, -1, -1, -1);
    }
};
