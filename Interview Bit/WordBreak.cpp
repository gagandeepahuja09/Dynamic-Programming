bool f(string s, unordered_set<string>& st, int i, vector<int>& dp) {
    if(i == s.size())
        return true;
    if(dp[i] != -1)
        return dp[i];
    bool ans = false;
    for(int j = i; j < s.size(); j++) {
        if(st.find(s.substr(i, j - i + 1)) != st.end()) {
            ans |= f(s, st, j + 1, dp);
        }
    }
    return dp[i] = ans;
}

int Solution::wordBreak(string A, vector<string> &B) {
    vector<int> dp(A.size() + 1, 0);
    unordered_set<string> st;
    for(string s : B)
        st.insert(s);   
    for(int i = A.size() - 1; i >= 0; i--) {
        for(int j = i; j < A.size(); j++) {
            string curr = A.substr(i, j - i + 1);
            if(st.find(curr) != st.end() && dp[j + 1] == 1) {
                dp[i] = 1;
                break;
            }
        }
    }    
    return dp[0];
    // return f(A, st, 0, dp);
}

