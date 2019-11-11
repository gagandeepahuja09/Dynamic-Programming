class Solution {
public:
    int f(vector<string>& words, vector<int>& freq, vector<int>& score, int i) {
        if(i == words.size())
            return 0;
        int option1 = f(words, freq, score, i + 1);
        int option2 = 0, flag = 1, gain = 0;
        vector<int> f1(begin(freq), end(freq));
        for(auto ch : words[i]) {
            if(--f1[ch - 'a'] < 0)
                flag = 0;
            gain += score[ch - 'a'];
        }
        if(flag) {
            option2 = f(words, f1, score, i + 1) + gain;
        }
        return max(option1, option2);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        vector<int> freq(26, 0);
        for(int i = 0; i < letters.size(); i++) {
            freq[letters[i] - 'a']++;
        }
        return f(words, freq, score, 0);
    }
};
