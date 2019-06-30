class Solution {
public:
    bool okNot(const string& s, int& i) {
        i += 2;
        bool ans = ok(s, i);
        i++;
        return !ans;
    }
    
    bool okAnd(const string& s, int& i) {
        i += 2;
        bool ans = true;
        ans &= ok(s, i);
        while(i != ')') {
            i++;
            ans &= ok(s, i);
        }
        i++;
        return ans;
    }
    
    bool okOr(const string& s, int& i) {
        i += 2;
        bool ans = false;
        ans |= ok(s, i);
        while(i != ')') {
            i++;
            ans |= ok(s, i);
        }
        i++;
        return ans;
    }
    
    bool ok(const string& s, int& i) {
        if(s[i] == 'f') {
            i++;
            return false;
        }
        else if(s[i] == 't') {
            i++;
            return true;
        }
        else if(s[i] == '!') {
            return okNot(s, i);
        }
        else if(s[i] == '&') {
            return okAnd(s, i);
        }
        return okOr(s, i);
    }
    
    bool parseBoolExpr(string expression) {
        int i = 0;
        return ok(expression, i);
    }
