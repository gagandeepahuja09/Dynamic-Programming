class Solution {
public:
    map<pair<int, vector<int>>, int> mp;
    int f(vector<string>& arr, int i, vector<int> cnt) {
        if(i == arr.size())
            return 0;
        pair<int, vector<int>> p = make_pair(i, cnt);
        if(mp.find(p) != mp.end())
            return mp[p];
        int option1 = f(arr, i + 1, cnt);
        for(int j = 0; j < arr[i].size(); j++) {
            cnt[arr[i][j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            if(cnt[j] > 1)
                return option1;
        }
        int option2 = arr[i].size() + f(arr, i + 1, cnt);
        return mp[p] = max(option1, option2);
    }
    
    int maxLength(vector<string>& arr) {
        mp.clear();
        vector<int> cnt(26, 0);
        return f(arr, 0, cnt);
    }
};
