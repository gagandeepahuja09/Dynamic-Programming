class Solution {
public:
    void consecDiff(int N, int num, int k, vector<int>& output) {
        if(N == 0) {
            output.push_back(num);
            return;
        }
        int digit = num%10;
        if(digit + k <= 9)
            consecDiff(N-1, num*10 + digit + k, k, output);
        if(digit - k >= 0 && k != 0)
            consecDiff(N-1, num*10 + digit - k, k, output);
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> output;
        if(N == 1)
            output.push_back(0);
        for(int i=1; i <= 9; i++) {
            consecDiff(N - 1, i, K, output);      
        }
        return output;
    }
};