class Solution {
public:
    unordered_map<string, bool> wordPresent;
    int wordBreakRec(string s, vector<string>& wordDict, vector<int>& dp, int start) {
        if (start >= s.size()) {
            return start == s.size();
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        string temp = "";
        bool ans = false;
        for (int i = start; i < s.size(); i++) {
            temp += s[i];
            if (wordPresent[temp]) {
                ans |= wordBreakRec(s, wordDict, dp, i + 1);
            }
        }
        return dp[start] = ans ? 1 : 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // vector<int> dp(n + 1, -1);
        for (int i = 0; i < wordDict.size(); i++) {
            wordPresent[wordDict[i]] = true;
        }
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        string temp;
        for (int j = n - 1; j >= 0; j--) {
            temp = "";
            for (int i = j; i >= 0; i--) {
                temp = s[i] + temp;
                if (wordPresent[temp] && dp[j + 1]) {
                    dp[i] = true;
                }
            }   
        }
        return dp[0];
    }
};
