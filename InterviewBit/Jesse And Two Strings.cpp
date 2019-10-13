/*Jesse and two string

Jesse loves playing with strings, so Wanda gives him two strings, A and B, and asks him to find the length of the longest palindrome that can be fomed using the characters from two palindromic subsequences such that one palindromic subsequence is chosen from A and the other palindromic subsequence is chosen from B.*/

int dp[1002][1002];
int dp2[1002][1002];

int get_pal_len(string &A){
    memset(dp, 0, sizeof dp);
    int n = A.size();
    int maxm = 0;
    
    for(int len = n; len >= 2; --len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if(A[i - 1] == A[j - 1]){
                dp[i][j] = 2 + dp[i - 1][j + 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            }
            maxm = max(maxm, dp[i][j]);
        }
    }
    
    for(int i = 1; i <= n; ++i){
        dp[i][i] = 1 + dp[i - 1][i + 1];
        maxm = max(maxm, dp[i][i]);
    }
    return maxm;
}

int get_pal_lenb(string &A){
    memset(dp2, 0, sizeof dp2);
    int n = A.size();
    int maxm = 0;
    
    for(int len = n; len >= 2; --len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if(A[i - 1] == A[j - 1]){
                dp2[i][j] = 2 + dp2[i - 1][j + 1];
            } else {
                dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]);
            }
            maxm = max(maxm, dp2[i][j]);
        }
    }
    
    for(int i = 1; i <= n; ++i){
        dp2[i][i] = 1 + dp2[i - 1][i + 1];
        maxm = max(maxm, dp2[i][i]);
    }
    
    return maxm;
}

int Solution::solve(string A, string B) {
    set< char > ca(A.begin(), A.end());
    set< char > cb(B.begin(), B.end());
    
    int ansa = get_pal_len(A);
    int ansb = get_pal_lenb(B);
    
    if(ansa % 2 == 0 or ansb % 2 == 0){
        return ansa + ansb;
    } else {
        int n = A.size();
        int m = B.size();
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(A[i - 1] == B[j - 1] and dp[i][i] == ansa and dp2[j][j] == ansb){
                    return ansa + ansb;
                }
            }
        }
        
        return ansa + ansb - 1;
    }
}
