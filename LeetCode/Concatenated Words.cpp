static bool cmp(string a, string b) {
    return a.size() < b.size();
}

class Solution {
public:
    
    unordered_set<string> st;
    int f(string s) {
        if(!s.size() || st.find(s) != st.end()) {
            return true;
        }
        bool ans = false;
        string curr;
        for(int i = 0; i < s.size(); i++) {
            curr += s[i];
            if(st.find(curr) != st.end()) {
                ans |= f(s.substr(i + 1));
            }
        }
        return ans;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<string> ret;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].size() && f(words[i]))
                ret.push_back(words[i]);
            st.insert(words[i]);
        }
        return ret;
    }
};
