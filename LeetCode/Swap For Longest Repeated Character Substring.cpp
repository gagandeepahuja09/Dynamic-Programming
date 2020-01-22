class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> cnt(26, 0);
        for(char c : text) {
            cnt[c - 'a']++;
        }
        vector<int> l(n, 1), r(n, 1);
        for(int i = 1; i < n; i++) {
            l[i] = (text[i] == text[i - 1]) ? l[i - 1] + 1 : 1;
        }
        for(int i = n - 2; i >= 0; i--) {
            r[i] = (text[i] == text[i + 1]) ? r[i + 1] + 1 : 1;
        }
        int ret = *max_element(l.begin(), l.end());
        for(int i = 1; i < n - 1; i++) {
            if(text[i - 1] == text[i + 1]) {
                if(l[i - 1] + r[i + 1] == cnt[text[i - 1] - 'a']) {
                    ret = max(ret, l[i - 1] + r[i + 1]);
                }
                else {
                    ret = max(ret, l[i - 1] + r[i + 1] + 1);
                }
            }
            else {
                if(l[i - 1] != cnt[text[i] - 'a'])
                    ret = max(ret, l[i - 1] + 1);
                if(r[i + 1] != cnt[text[i] - 'a'])
                    ret = max(ret, r[i + 1] + 1);
            }
        }
        return ret;
    }
};
