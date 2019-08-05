bool isScrambleUtil(const string A, const string B, unordered_map<string, 
bool>& mp) {
    if(A == B)
        return 1;
    if(mp.count(A + B))
        return mp[A + B];
    int cnt[26] = {0};
    for(int i = 0; i < A.size(); i++) {
        cnt[A[i] - 'a']++;
        cnt[B[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i])
            return false;
    }
    bool res = false;
    for(int i = 1; i < A.size(); i++) {
        res = res || (isScrambleUtil(A.substr(0, i), B.substr(0, i), mp) &&
        isScrambleUtil(A.substr(i), B.substr(i), mp)) || 
        (isScrambleUtil(A.substr(0, i), B.substr(A.size() - i), mp) &&
        isScrambleUtil(A.substr(i), B.substr(0, A.size() - i), mp));
    }
    return mp[A + B] = res;
}

int Solution::isScramble(const string A, const string B) {
    unordered_map<string, bool> mp;
    return isScrambleUtil(A, B, mp);
}

