class Solution {
public:
    map<string, int> skill;
    vector<int> res[(1 << 16) + 5];
    int dp[(1 << 16) + 5];
    int person[65];
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        for(int i = 0; i < req_skills.size(); i++) {
            skill[req_skills[i]] = i;
        }
        for(int i = 0; i < people.size(); i++) {
            person[i] = 0;
            for(int j = 0; j < people[i].size(); j++) {
                person[i] |= (1 << skill[people[i][j]]);
            }
        }
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < (1 << req_skills.size()); i++) {
            if(dp[i] == -1)
                continue;
            for(int j = 0; j < people.size(); j++) {
                if(dp[i | person[j]] == -1 || dp[i | person[j]] > dp[i] + 1) {
                    dp[i | person[j]] = dp[i] + 1;
                    res[i | person[j]] = res[i];
                    res[i | person[j]].push_back(j);
                }
            }
        }
        return res[(1 << req_skills.size()) - 1];
    }
};
