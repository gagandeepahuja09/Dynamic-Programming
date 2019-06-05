bool search(string A, vector<string> B){
    for(int i = 0; i < B.size(); i++){
        if(B[i] == A){
            return true;
        }
    }
    return false;
}


int word(string A, int i,  vector<string>& B, vector<int>& dp) {
    if(i == A.size())
        return 1;
    if(dp[i] != -1)
        return dp[i];
    // bool ans = false;    
    for(int k = i + 1; k < A.size(); k++) {
        string curr = A.substr(i, k - i + 1);
        if(search(curr, B)) {
            if(word(A, k + 1, B, dp))
                return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
 
    vector<int> temp(n+1, 0);
    temp[n] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string s = A.substr(i, j-i+1);
            if(search(s, B) && temp[j+1] == 1){
                temp[i] = 1;
                break;
            }
        }
    }
    return temp[0];
}

