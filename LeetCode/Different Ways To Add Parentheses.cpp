class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for(int i = 0; i < input.size(); i++) {
            char ch = input[i];
            if(ch == '+' || ch == '-' || ch == '*') {
                vector<int> lefts = diffWaysToCompute(input.substr(0, i)), rights = diffWaysToCompute(input.substr(i + 1)); 
                for(int l : lefts) {
                    for(int r : rights) {
                        if(ch == '+')
                            ret.push_back(l + r);
                        else if(ch == '-')
                            ret.push_back(l - r);
                        else
                            ret.push_back(l * r);
                    }
                }
            }
        }
        if(!ret.size())
            ret.push_back(atoi(input.c_str()));
        return ret;
    }
};
