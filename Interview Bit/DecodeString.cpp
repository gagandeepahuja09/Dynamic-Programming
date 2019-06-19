string recur(string s, int& i) {
    int num = 0;
    string word = "";
    for(; i < s.size(); i++) {
        if(s[i] == '[') {
            string curStr = recur(s, ++i);
            while(num--)
                word += curStr;
        }
        else if(s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }
        else if(s[i] == ']') {
            return word;
        }
        else {
            word += s[i];
        }
    }
    return word;
}

string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    // Normal characters
                word += cur;
            }
        }
        return word;
    }

string Solution::solve(string A) {
    int i = 0;
    return helper(i, A);
}

