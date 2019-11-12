class Solution {
public:
    map<pair<string, int>, int> mp;
    int f(string s, int i, string t) {
        if(i == t.size())
            return 0;
        if(s[i] == t[i])
            return f(s, i + 1, t);
        if(mp.find({ s, i }) != mp.end()) {
            return mp[{ s, i }];
        }
        int mn = INT_MAX;
        for(int j = i + 1; j < s.size(); j++) {
            string temp = s;
            swap(temp[j], temp[i]);
            if(temp[i] == t[i]) {
                mn = min(mn, 1 + f(temp, i + 1, t));
            }
        }
        return mp[{ s, i }] = mn;
    }
    
    int kSimilarity(string A, string B) {
        mp.clear();
        return f(A, 0, B);
    }
};
